use dbg_hex::dbg_hex;
use nonmax::NonMaxU8;

use crate::caps::{
    align_down_to, align_up_to, align_up_to_128, assert_fits, extract_bits, nth_multiple_of_pow2,
    nth_multiple_of_pow2_128, round_up_as_pow2, round_up_as_pow2_128, BasicCustomCap,
};

#[derive(Debug, Clone, Copy)]
pub struct GenericIocapInitialRegion<
    const A: usize,
    const E_0: usize,
    const M_0: usize,
    const TWO_TO_W: usize,
    const N: usize,
    const E_STEP: usize,
> {
    pub w: u8,
    pub b_m: u128,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct WidthClass {
    pub w: u8,
    pub e: u8,
    pub m_top: u8,
    pub m_bits: u8,
    pub b_bits: u8,
    pub b_align: u8,
    pub max_encodable_pow2: u8,
    pub min_used_pow2: u8,
}
impl WidthClass {
    const DEFAULT: Self = Self {
        w: 0,
        e: 0,
        m_top: 0,
        m_bits: 0,
        b_bits: 0,
        b_align: 0,
        max_encodable_pow2: 0,
        min_used_pow2: 0,
    };
    pub const fn min_used_pow2_incl(&self) -> bool {
        self.w == 0
    }
}

impl<
        const A: usize,
        const E_0: usize,
        const M_0: usize,
        const TWO_TO_W: usize,
        const N: usize,
        const E_STEP: usize,
    > GenericIocapInitialRegion<A, E_0, M_0, TWO_TO_W, N, E_STEP>
{
    // Using tricks from https://gendignoux.com/blog/2024/06/17/const-array-from-fn.html

    pub const TWO_TO_W_MINUS_LOGN: usize = TWO_TO_W / N;
    pub const DELTA_E: usize = Self::TWO_TO_W_MINUS_LOGN - 2 + E_STEP;
    pub const MAX_LENGTH_POW2: usize =
        E_0 + M_0 + (2 * N - 2) * (E_STEP - 1) + (2 * N - 1) * (Self::TWO_TO_W_MINUS_LOGN - 1);

    pub const WIDTH_CLASSES: [WidthClass; TWO_TO_W] = {
        let mut out = [WidthClass::DEFAULT; TWO_TO_W];
        let mut w = 0;
        let mut e = E_0 as u8;
        let mut nth_split = 0;
        let mut nth_within_split = 0;
        let mut m_bits = M_0 as u8;
        let mut b_bits = A as u8 - E_0 as u8;
        let mut b_align = E_0 as u8;
        while w < TWO_TO_W {
            let m_top = if nth_within_split == 0 { 0 } else { 1 };
            let min_encodable_pow2 = e + (m_top * m_bits);
            let max_encodable_pow2 = e + m_top + m_bits;
            let min_used_pow2 = if w > 0 {
                let prior_max = out[w - 1].max_encodable_pow2;
                if prior_max > min_encodable_pow2 {
                    prior_max
                } else {
                    min_encodable_pow2
                }
            } else {
                min_encodable_pow2
            };

            out[w] = WidthClass {
                w: w as u8,
                e,
                b_align,
                m_top,
                m_bits,
                b_bits,
                max_encodable_pow2,
                min_used_pow2,
            };

            // Step forwards
            w += 1;
            if nth_within_split + 1 == Self::TWO_TO_W_MINUS_LOGN {
                nth_within_split = 0;
                nth_split += 1;

                e += E_STEP as u8;
                m_bits += Self::DELTA_E as u8;
                b_bits -= Self::DELTA_E as u8;
                b_align += Self::DELTA_E as u8;
            } else {
                nth_within_split += 1;

                if nth_within_split >= 2 {
                    e += 1;
                }
            }
        }
        out
    };

    // This only needs to be up to MAX_LENGTH_POW2 i.e. [64] must be accessible for a 64-bit length, so it will always take up two cache lines
    pub const LENGTH_POW2_TO_WIDTH_CLASS: [Option<NonMaxU8>; 128] = {
        let mut out = [None; 128];
        let mut i = 0;
        while i < 128 && i <= Self::MAX_LENGTH_POW2 as u8 {
            if i < E_0 as u8 {
                out[i as usize] = Some(NonMaxU8::ZERO);
                i += 1;
                continue;
            }

            let mut j: u8 = 0;
            while j < TWO_TO_W as u8 {
                let class = Self::WIDTH_CLASSES[j as usize];
                if class.min_used_pow2_incl() {
                    if class.min_used_pow2 <= i && i <= class.max_encodable_pow2 {
                        break;
                    }
                } else {
                    if class.min_used_pow2 < i && i <= class.max_encodable_pow2 {
                        break;
                    }
                }
                j += 1;
            }

            if j == TWO_TO_W as u8 {
                break;
            } else {
                out[i as usize] = NonMaxU8::new(j);
                assert!(out[i as usize].is_some());
            }

            i += 1;
        }
        out
    };

    fn two_pass_new(base: u64, len: u128) -> Self {
        if A < 64 && (base >> A) != 0 {
            panic!("{base:x} is not an encodable base");
        }
        let intended_top = (base as u128) + (len as u128);

        let width_class = Self::LENGTH_POW2_TO_WIDTH_CLASS[round_up_as_pow2_128(len) as usize];
        let width_class = match width_class {
            Some(w) => Self::WIDTH_CLASSES[w.get() as usize],
            None => panic!("Length 0x{len:x} is too big to be representable!"),
        };

        // Try first width_class
        let (width_class, aligned_base, aligned_len) = {
            let aligned_base = align_down_to(base, width_class.b_align as u32);
            let aligned_len =
                align_up_to_128(intended_top - aligned_base as u128, width_class.e as u32);
            if aligned_len > (1u128 << width_class.max_encodable_pow2) {
                // We've gone up, find and try width_class_2
                let width_class_2 = width_class.w + 1;
                let width_class_2 = match width_class_2 {
                    w if w < TWO_TO_W as u8 => Self::WIDTH_CLASSES[w as usize],
                    _ => panic!("Length 0x{aligned_len:x} is too big to be representable!"),
                };

                let aligned_base_2 = align_down_to(base, width_class_2.b_align as u32);
                let aligned_len_2 =
                    align_up_to_128(intended_top - aligned_base_2 as u128, width_class_2.e as u32);

                assert!(
                    aligned_len_2 <= (1u128 << width_class_2.max_encodable_pow2),
                    "Needed to travel up two width classes due to base realignment - shouldn't happen!\nbase {base:16x}\tlen {len:16x}\nwidth class {} max 2^{}\nbase {aligned_base:16x}\tlen {aligned_len:16x}\nwidth class {} max 2^{}\nbase {aligned_base_2:16x}\tlen {aligned_len_2:16x}\n",
                    width_class.w, width_class.max_encodable_pow2,
                    width_class_2.w, width_class_2.max_encodable_pow2,
                );

                (width_class_2, aligned_base_2, aligned_len_2)
            } else {
                (width_class, aligned_base, aligned_len)
            }
        };

        // We now have our final width_class
        let encoded_b = aligned_base >> width_class.b_align;
        let encoded_m = (aligned_len >> width_class.e) - 1;
        assert_eq!(encoded_m >> width_class.m_bits, width_class.m_top as u128, "Placed aligned_len {aligned_len:x} into width class {width_class:?} but top mantissa bit didn't match");

        let encoded_m = encoded_m & ((1u128 << width_class.m_bits) - 1);
        Self {
            w: width_class.w,
            b_m: (encoded_b as u128) | (encoded_m << width_class.b_bits),
        }
    }
}

impl<
        const A: usize,
        const E_0: usize,
        const M_0: usize,
        const TWO_TO_W: usize,
        const N: usize,
        const E_STEP: usize,
    > BasicCustomCap for GenericIocapInitialRegion<A, E_0, M_0, TWO_TO_W, N, E_STEP>
{
    const BASE_WIDTH: u32 = A as u32;

    fn check_bits(&self) {}

    fn new_unchecked(base: u64, len: u128) -> Self {
        // Brute-force: just go through all width classes until we find one that fits
        let intended_top = base as u128 + len as u128;
        for width_class in Self::WIDTH_CLASSES {
            let rounded_base = align_down_to(base, width_class.b_align as u32);

            let required_length = intended_top - (rounded_base as u128);
            let required_m_plus_one =
                nth_multiple_of_pow2_128(required_length, width_class.e as u32);
            let required_m = if required_m_plus_one == 0 {
                // round up to 1 then decrement
                0
            } else {
                required_m_plus_one - 1
            };
            let max_m = (width_class.m_top as u128 + 1) << width_class.m_bits;
            if required_m < max_m {
                let encoded_b = rounded_base >> width_class.b_align;
                // let encoded_m = (required_length >> width_class.e) - 1;
                let encoded_m = required_m;
                assert_eq!(encoded_m >> width_class.m_bits, width_class.m_top as u128, "Placed aligned_len {required_length:x} into width class {width_class:?} but top mantissa bit didn't match");

                let encoded_m = encoded_m & ((1u128 << width_class.m_bits) - 1);
                let s = Self {
                    w: width_class.w,
                    b_m: (encoded_b as u128) | (encoded_m << width_class.b_bits),
                };
                return s;
            }
        }
        // This is possible if e_step is not big enough and we can't represent lengths up to (1 << A)
        panic!("Can't fit base {base:x} len {len:x}!")
    }

    fn base(&self) -> u64 {
        let width_class = Self::WIDTH_CLASSES[self.w as usize];
        let b = extract_bits(self.b_m, width_class.b_bits as u32 - 1, 0);
        (b << width_class.b_align) as u64
    }

    fn len(&self) -> u128 {
        let width_class = Self::WIDTH_CLASSES[self.w as usize];
        let encoded_m = extract_bits(self.b_m, 127, width_class.b_bits as u32);
        let encoded_m_with_top = ((width_class.m_top as u128) << width_class.m_bits) | encoded_m;
        let m = encoded_m_with_top + 1;
        m << width_class.e
    }

    fn len_precision(&self) -> u32 {
        Self::WIDTH_CLASSES[self.w as usize].e as u32
    }
}

pub trait InitialRegion: BasicCustomCap {
    fn get_width_class(&self) -> WidthClass;
}

impl<
        const A: usize,
        const E_0: usize,
        const M_0: usize,
        const TWO_TO_W: usize,
        const N: usize,
        const E_STEP: usize,
    > InitialRegion for GenericIocapInitialRegion<A, E_0, M_0, TWO_TO_W, N, E_STEP>
{
    fn get_width_class(&self) -> WidthClass {
        Self::WIDTH_CLASSES[self.w as usize]
    }
}

#[derive(Debug, Clone, Copy)]
pub struct GenericIocapGuaranteedTwoDepthInitialRegion<
    const A: usize,
    const E_0: usize,
    const M_0: usize,
    const TWO_TO_W: usize,
    const N: usize,
    const E_STEP: usize,
>(pub GenericIocapInitialRegion<A, E_0, M_0, TWO_TO_W, N, E_STEP>);

impl<
        const A: usize,
        const E_0: usize,
        const M_0: usize,
        const TWO_TO_W: usize,
        const N: usize,
        const E_STEP: usize,
    > BasicCustomCap
    for GenericIocapGuaranteedTwoDepthInitialRegion<A, E_0, M_0, TWO_TO_W, N, E_STEP>
{
    const BASE_WIDTH: u32 = A as u32;

    fn check_bits(&self) {}

    fn new_unchecked(base: u64, len: u128) -> Self {
        Self(GenericIocapInitialRegion::two_pass_new(base, len))
    }

    fn base(&self) -> u64 {
        self.0.base()
    }

    fn len(&self) -> u128 {
        self.0.len()
    }

    fn len_precision(&self) -> u32 {
        self.0.len_precision()
    }
}

impl<
        const A: usize,
        const E_0: usize,
        const M_0: usize,
        const TWO_TO_W: usize,
        const N: usize,
        const E_STEP: usize,
    > InitialRegion
    for GenericIocapGuaranteedTwoDepthInitialRegion<A, E_0, M_0, TWO_TO_W, N, E_STEP>
{
    fn get_width_class(&self) -> WidthClass {
        GenericIocapInitialRegion::<A, E_0, M_0, TWO_TO_W, N, E_STEP>::WIDTH_CLASSES
            [self.0.w as usize]
    }
}

pub trait Caveat1: BasicCustomCap {
    type InitialRegion: BasicCustomCap;

    fn exponent_c1(&self) -> u32;
    fn smallest_reduction_of(initial_region: Self::InitialRegion) -> Self;
}

pub trait Caveat2: BasicCustomCap {
    type PriorRegion: Caveat1;

    fn exponent_c2(&self) -> u32;
    fn smallest_reduction_of(prior_region: Self::PriorRegion) -> Self;
}

#[derive(Debug, Clone, Copy)]
pub struct IndexCaveatOf<
    T: InitialRegion + BasicCustomCap,
    const WIDTH_SIZE_DIV: usize,
    const NONZERO_INDEX_NULL: bool,
> {
    pub initial_region: T,
    pub size_div: u8,
    pub idx: u64,
}

impl<
        T: InitialRegion + BasicCustomCap,
        const WIDTH_SIZE_DIV: usize,
        const NONZERO_INDEX_NULL: bool,
    > IndexCaveatOf<T, WIDTH_SIZE_DIV, NONZERO_INDEX_NULL>
{
    pub const MAX_SIZE_DIV: usize = (1usize << WIDTH_SIZE_DIV) - 1;

    pub fn create_for(initial_region: T, target_base: u64, target_len: u128) -> Self {
        let initial_base = initial_region.base();
        let initial_len = initial_region.len();
        let initial_e = initial_region.get_width_class().max_encodable_pow2;

        let min_pow2_of_cav = initial_e.saturating_sub(Self::MAX_SIZE_DIV as u8);

        let intended_base_rel = target_base - initial_base;
        let intended_top_rel = (target_base - initial_base) as u128 + target_len as u128;
        let top_rel_rounded_up = align_up_to_128(intended_top_rel, min_pow2_of_cav as u32) - 1;

        if (top_rel_rounded_up >= initial_len) && !NONZERO_INDEX_NULL {
            return Self {
                initial_region,
                size_div: 0,
                idx: 0,
            };
        }

        let b_offset_at_min = intended_base_rel >> min_pow2_of_cav;
        let t_offset_at_min = top_rel_rounded_up >> min_pow2_of_cav;
        let t_offset_at_min: u64 = t_offset_at_min.try_into().unwrap();

        // We want to find the smallest final exponent where b_offset >> selected_exponent  == (t_offset >> selected_exponent) - 1

        /*
        let mut selected_index = 0;
        let mut selected_size_div = 0;
        for fifteen_minus_size_div in 0..=15 {
            // cav1 behaves as if we split the initial resource into slices of a specific pow2, and select one.
            // We want to select the smallest pow2 (the largest size_div, thus the smallest fifteen_minus_size_div)
            // where the intended base and intended top both fit in the same slice.
            // We evaluate this by checking the slice *index* the base and top would reside in, and increasing fifteen_minus_size_div until they are equal.
            let base_index = base_top16 >> fifteen_minus_size_div;
            let top_index = top_top16 >> fifteen_minus_size_div;
            if base_index == top_index {
                selected_index = base_index;
                selected_size_div = 15 - fifteen_minus_size_div;
                break
            }
        }
        */

        // The above can be performed quicker through XOR.
        // XOR them.
        // Consider example: base_top16 = 0..0010
        //                    top_top16 = 0..0100
        // Target shift = 3
        //                          XOR = 0..0110
        //                        index = ---3210
        // Find the index of the end of the string of zeroes from the left side,
        // that's your target shift
        let x = t_offset_at_min ^ b_offset_at_min;
        let target_shift = 64 - x.leading_zeros();
        assert!(target_shift as usize <= Self::MAX_SIZE_DIV);

        let size_div = (Self::MAX_SIZE_DIV as u32 - target_shift) as u8;
        let idx = b_offset_at_min >> target_shift;

        Self {
            initial_region,
            size_div,
            idx,
        }
    }
}
impl<
        T: InitialRegion + BasicCustomCap,
        const WIDTH_SIZE_DIV: usize,
        const NONZERO_INDEX_NULL: bool,
    > Caveat1 for IndexCaveatOf<T, WIDTH_SIZE_DIV, NONZERO_INDEX_NULL>
{
    type InitialRegion = T;

    fn exponent_c1(&self) -> u32 {
        let initial_width_class = self.initial_region.get_width_class();
        // let initial_e = initial_width_class.e + initial_width_class.m_bits + initial_width_class.m_top;
        let initial_e = initial_width_class.max_encodable_pow2;
        initial_e.saturating_sub(self.size_div) as u32
    }
    
    fn smallest_reduction_of(initial_region: Self::InitialRegion) -> Self {
        Self {
            initial_region,
            size_div: Self::MAX_SIZE_DIV as u8, 
            idx: 0,
        }
    }    
}

impl<
        T: InitialRegion + BasicCustomCap,
        const WIDTH_SIZE_DIV: usize,
        const NONZERO_INDEX_NULL: bool,
    > BasicCustomCap for IndexCaveatOf<T, WIDTH_SIZE_DIV, NONZERO_INDEX_NULL>
{
    const BASE_WIDTH: u32 = T::BASE_WIDTH;
    const LENGTH_PRECISION_EXACT: bool = false; // The real length precision may be more precise than we state

    fn check_bits(&self) {
        self.initial_region.check_bits();

        assert_fits!(self.size_div, WIDTH_SIZE_DIV);
        assert_fits!(self.idx, Self::MAX_SIZE_DIV);

        let initial_e = self.initial_region.get_width_class().max_encodable_pow2;
        assert!(
            initial_e >= self.size_div,
            "Tried to shrink an exponent of {initial_e} by {}",
            self.size_div
        );

        let t_offset = ((self.idx + 1) as u128) << (initial_e - self.size_div);
        if t_offset > self.initial_region.len() {
            assert!(
                self.idx == 0 || !NONZERO_INDEX_NULL,
                "Nonzero idx with overly-long size when not allowed {:?}",
                self
            );
        }

        let b_offset = (self.idx as u128) << (initial_e - self.size_div);
        assert!(
            b_offset < self.initial_region.len(),
            "b_offset {:x} exceeds initial length {:x} {:?}",
            b_offset,
            self.initial_region.len(),
            self
        );
    }

    fn new_unchecked(base: u64, len: u128) -> Self {
        let initial_region = T::new(base, len);
        Self::create_for(initial_region, base, len)
    }

    fn base(&self) -> u64 {
        self.check_bits();
        let initial_e = self.initial_region.get_width_class().max_encodable_pow2;
        let exponent_c1 = initial_e - self.size_div;
        let b_offset = if exponent_c1 >= 64 {
            assert_eq!(self.idx, 0);
            0
        } else {
            (self.idx as u64) << exponent_c1
        };
        self.initial_region.base() + b_offset
    }

    fn len(&self) -> u128 {
        self.check_bits();
        let initial_e = self.initial_region.get_width_class().max_encodable_pow2;
        let exponent_c1 = initial_e - self.size_div;
        let t_offset = ((self.idx + 1) as u128) << exponent_c1;
        let b_offset = if exponent_c1 >= 64 {
            assert_eq!(self.idx, 0);
            0
        } else {
            (self.idx as u64) << exponent_c1
        };
        if t_offset > self.initial_region.len() {
            self.initial_region.len() - b_offset as u128
        } else {
            t_offset - b_offset as u128
        }
    }

    fn len_precision(&self) -> u32 {
        // Cannot assert that len_precision is *always* a power of two.
        // Consider an index caveat that shrinks a region but goes a little OOB and gets capped. That length is not a big pow2-alignment.        
        // core::cmp::min(self.exponent_c1(), self.len().trailing_zeros())
        // However, this breaks things...
        self.exponent_c1()
    }
}


#[derive(Debug, Clone, Copy)]
pub struct SubalignIndexCaveatOf<
    T: InitialRegion + BasicCustomCap,
    const WIDTH_SIZE_DIV: usize,
> {
    pub initial_region: T,
    pub size_div: u8,
    pub idx: u64,
}

/// In the thesis, I propose two optimizations for the index caveat ($5.5.4).
/// This implements the precision mitigation, i.e. "allowing the base to be aligned to half the length". 
impl<
        T: InitialRegion + BasicCustomCap,
        const WIDTH_SIZE_DIV: usize,
    > SubalignIndexCaveatOf<T, WIDTH_SIZE_DIV>
{
    pub const MAX_SIZE_DIV: usize = (1usize << WIDTH_SIZE_DIV) - 2;
    pub const WIDTH_INDEX: usize = Self::MAX_SIZE_DIV + 1;

    fn initial_e(initial_region: &T) -> u8 {
        initial_region.get_width_class().max_encodable_pow2
    }

    pub fn create_for(initial_region: T, target_base: u64, target_len: u128) -> Self {
        let initial_base = initial_region.base();
        let initial_len = initial_region.len();
        let initial_e = Self::initial_e(&initial_region);

        let min_pow2_of_cav = initial_e.saturating_sub(Self::MAX_SIZE_DIV as u8);

        let intended_base_rel = target_base - initial_base;
        let intended_top_rel = (target_base - initial_base) as u128 + target_len as u128;
        let top_rel_rounded_up = align_up_to_128(intended_top_rel, min_pow2_of_cav as u32);

        let b_offset_at_min = intended_base_rel >> min_pow2_of_cav;
        let t_offset_at_min = top_rel_rounded_up >> min_pow2_of_cav;
        let t_offset_at_min: u64 = t_offset_at_min.try_into().unwrap();

        // let (size_div, idx) = {
            // Compute a one-bit mantissa encoding for b_offset_at_min to t_offset_at_min relative to min_pow2_of_cav
            let mut aligned_len_pow2 = round_up_as_pow2(t_offset_at_min - b_offset_at_min) as u8;
            let mut base_align = aligned_len_pow2.saturating_sub(1);
            let mut aligned_base = align_down_to(b_offset_at_min, base_align as u32);
            
            if (t_offset_at_min - aligned_base) > (1 << aligned_len_pow2) {
                aligned_len_pow2 += 1;
                base_align = aligned_len_pow2.saturating_sub(1);
                aligned_base = align_down_to(b_offset_at_min, base_align as u32);

                assert!((t_offset_at_min - aligned_base) <= (1 << aligned_len_pow2));
            }


            let intended_len = (1 << aligned_len_pow2);

            let size_div = (Self::MAX_SIZE_DIV as u8) - aligned_len_pow2;
            let idx = aligned_base >> base_align;

            // dbg_hex!(initial_base, initial_len, target_base, target_len, intended_base_rel, intended_top_rel, min_pow2_of_cav, b_offset_at_min, t_offset_at_min);
            // dbg_hex!(intended_len, aligned_len_pow2, base_align, aligned_base, size_div, idx);

            // (size_div, idx)
        // };

        let s = Self {
            initial_region,
            size_div,
            idx,
        };
        s.check_bits();
        let (b_offset, t_offset) = s.offsets();
        assert_eq!(b_offset, aligned_base << min_pow2_of_cav);
        assert_eq!(t_offset, b_offset as u128 + (1 << (aligned_len_pow2 + min_pow2_of_cav)));
        // dbg_hex!(s.offsets());
        s
    }

    fn offsets(&self) -> (u64, u128) {
        let initial_e = Self::initial_e(&self.initial_region);
        
        let offsets_aligned_len_pow2 = ((Self::MAX_SIZE_DIV as u8) - self.size_div);
        let offsets_base_align = offsets_aligned_len_pow2.saturating_sub(1);


        let t_shift = initial_e - self.size_div;
        let b_shift = initial_e - Self::MAX_SIZE_DIV as u8 + offsets_base_align;
        // dbg_hex!(initial_e, offsets_base_align, b_shift);
        let b_offset = if b_shift >= 64 {
            0
        } else {
            self.idx << b_shift
        };
        let t_offset = b_offset as u128 + (1u128 << t_shift);

        (b_offset.try_into().expect("b_offset should never be >2^64"), t_offset)
    }
}
impl<
        T: InitialRegion + BasicCustomCap,
        const WIDTH_SIZE_DIV: usize,
    > Caveat1 for SubalignIndexCaveatOf<T, WIDTH_SIZE_DIV>
{
    type InitialRegion = T;

    fn exponent_c1(&self) -> u32 {
        let initial_e = Self::initial_e(&self.initial_region);
        initial_e.saturating_sub(self.size_div) as u32
    }
    
    fn smallest_reduction_of(initial_region: Self::InitialRegion) -> Self {
        Self {
            initial_region,
            size_div: Self::MAX_SIZE_DIV as u8, 
            idx: 0,
        }
    }    
}

impl<
        T: InitialRegion + BasicCustomCap,
        const WIDTH_SIZE_DIV: usize,
    > BasicCustomCap for SubalignIndexCaveatOf<T, WIDTH_SIZE_DIV>
{
    const BASE_WIDTH: u32 = T::BASE_WIDTH;
    const LENGTH_PRECISION_EXACT: bool = false; // The real length precision may be more precise than we state

    fn check_bits(&self) {
        self.initial_region.check_bits();

        assert_fits!(self.size_div, WIDTH_SIZE_DIV);
        assert!(self.size_div as usize <= Self::MAX_SIZE_DIV, "size_div: {}, max: {}", self.size_div, Self::MAX_SIZE_DIV);
        assert_fits!(self.idx, Self::WIDTH_INDEX);

        let initial_e = Self::initial_e(&self.initial_region);
        assert!(
            initial_e >= self.size_div,
            "Tried to shrink an exponent of {initial_e} by {}",
            self.size_div
        );

        let (b_offset, t_offset) = self.offsets();

        assert!(
            (b_offset as u128) < self.initial_region.len(),
            "b_offset {:x} exceeds initial length {:x} {:?}",
            b_offset,
            self.initial_region.len(),
            self
        );
    }

    fn new_unchecked(base: u64, len: u128) -> Self {
        let initial_region = T::new(base, len);
        Self::create_for(initial_region, base, len)
    }

    fn base(&self) -> u64 {
        self.check_bits();
        let (b_offset, _) = self.offsets();
        // dbg_hex!(self, b_offset, self.initial_region.base());
        self.initial_region.base() + b_offset
    }

    fn len(&self) -> u128 {
        self.check_bits();

        let (b_offset, t_offset) = self.offsets();

        if t_offset > self.initial_region.len() {
            self.initial_region.len() - b_offset as u128
        } else {
            t_offset - b_offset as u128
        }
    }

    fn len_precision(&self) -> u32 {
        // Cannot assert that len_precision is *always* a power of two.
        // Consider an index caveat that shrinks a region but goes a little OOB and gets capped. That length is not a big pow2-alignment.        
        // core::cmp::min(self.exponent_c1(), self.len().trailing_zeros())
        // However, this breaks the scan...
        self.exponent_c1()
    }
}

/// In the thesis, I propose two optimizations for the index caveat ($5.5.4).
/// On top of the the precision mitigation, i.e. "allowing the base to be aligned to half the length", this implements the reduction mitigation i.e. "compute its exponent relative to the actual initial length".
/// This also assumes null caveats can encode with non-zero 'index'. 
#[derive(Debug, Clone, Copy)]
pub struct SubalignTightIndexCaveatOf<
    T: InitialRegion + BasicCustomCap,
    const WIDTH_SIZE_DIV: usize,
> {
    pub initial_region: T,
    pub size_div: u8,
    pub idx: u64,
}

impl<
        T: InitialRegion + BasicCustomCap,
        const WIDTH_SIZE_DIV: usize,
    > SubalignTightIndexCaveatOf<T, WIDTH_SIZE_DIV>
{
    pub const MAX_SIZE_DIV: usize = (1usize << WIDTH_SIZE_DIV) - 2;
    pub const WIDTH_INDEX: usize = Self::MAX_SIZE_DIV + 1;

    fn initial_e(initial_region: &T) -> u8 {
        round_up_as_pow2_128(initial_region.len()).try_into().unwrap()
    } 

    pub fn create_for(initial_region: T, target_base: u64, target_len: u128) -> Self {
        let initial_base = initial_region.base();
        let initial_len = initial_region.len();
        let initial_e = Self::initial_e(&initial_region);

        let min_pow2_of_cav = initial_e.saturating_sub(Self::MAX_SIZE_DIV as u8);

        let intended_base_rel = target_base - initial_base;
        let intended_top_rel = (target_base - initial_base) as u128 + target_len as u128;
        let top_rel_rounded_up = align_up_to_128(intended_top_rel, min_pow2_of_cav as u32);

        let b_offset_at_min = intended_base_rel >> min_pow2_of_cav;
        let t_offset_at_min = top_rel_rounded_up >> min_pow2_of_cav;
        let t_offset_at_min: u64 = t_offset_at_min.try_into().unwrap();

        // let (size_div, idx) = {
            // Compute a one-bit mantissa encoding for b_offset_at_min to t_offset_at_min relative to min_pow2_of_cav
            let mut aligned_len_pow2 = round_up_as_pow2(t_offset_at_min - b_offset_at_min) as u8;
            let mut base_align = aligned_len_pow2.saturating_sub(1);
            let mut aligned_base = align_down_to(b_offset_at_min, base_align as u32);
            
            if (t_offset_at_min - aligned_base) > (1 << aligned_len_pow2) {
                aligned_len_pow2 += 1;
                base_align = aligned_len_pow2.saturating_sub(1);
                aligned_base = align_down_to(b_offset_at_min, base_align as u32);

                assert!((t_offset_at_min - aligned_base) <= (1 << aligned_len_pow2));
            }


            let intended_len = (1 << aligned_len_pow2);

            let size_div = core::cmp::min(Self::MAX_SIZE_DIV as u8, initial_e) - aligned_len_pow2;
            let idx = aligned_base >> base_align;

            // dbg_hex!(initial_base, initial_len, target_base, target_len, intended_base_rel, intended_top_rel, min_pow2_of_cav, b_offset_at_min, t_offset_at_min);
            // dbg_hex!(intended_len, aligned_len_pow2, base_align, aligned_base, size_div, idx);

            // dbg_hex!(size_div, initial_e, (min_pow2_of_cav + aligned_len_pow2), idx);

            // (size_div, idx)
        // };

        let s = Self {
            initial_region,
            size_div,
            idx,
        };
        let (b_offset, t_offset) = s.offsets();
        assert_eq!(b_offset, aligned_base << min_pow2_of_cav);
        assert_eq!(t_offset, b_offset as u128 + (1 << (aligned_len_pow2 + min_pow2_of_cav)));
        // dbg_hex!(s.offsets());
        s.check_bits();
        s
    }

    fn offsets(&self) -> (u64, u128) {
        let initial_e = Self::initial_e(&self.initial_region);
        
        // let size_div = core::cmp::min(Self::MAX_SIZE_DIV as u8, initial_e) - aligned_len_pow2;
        // b_offset = self.idx << (aligned_len_pow2.saturating_sub(1) + min_pow2_of_cav), where min_pow2_of_cav = initial_e.saturating_sub(Self::MAX_SIZE_DIV as u8)
        // so b_offset = if MAX_SIZE_DIV > initial_e {
        //    self.idx << (aligned_len_pow2.saturating_sub(1) + 0), where aligned_len_pow2 = (initial_e - size_div) 
        // } else {
        //    self.idx << ((MAX_SIZE_DIV - size_div).saturating_sub(1) + initial_e - MAX_SIZE_DIV)
        // }
        // l_shift = aligned_len_pow2 +  = core::cmp::min(Self::MAX_SIZE_DIV as u8, initial_e) - size_div
        let offsets_aligned_len_pow2 = (core::cmp::min(Self::MAX_SIZE_DIV as u8, initial_e) - self.size_div);
        let offsets_base_align = offsets_aligned_len_pow2.saturating_sub(1);
        let min_pow2_of_cav = initial_e.saturating_sub(Self::MAX_SIZE_DIV as u8);

        let t_shift = offsets_aligned_len_pow2 + min_pow2_of_cav;
        let b_shift = offsets_base_align + min_pow2_of_cav;
        // dbg_hex!(initial_e, offsets_base_align, b_shift);
        let b_offset = if b_shift >= 64 {
            0
        } else {
            self.idx << b_shift
        };
        let t_offset = b_offset as u128 + (1u128 << t_shift);

        (b_offset.try_into().expect("b_offset should never be >2^64"), t_offset)
    }
}
impl<
        T: InitialRegion + BasicCustomCap,
        const WIDTH_SIZE_DIV: usize,
    > Caveat1 for SubalignTightIndexCaveatOf<T, WIDTH_SIZE_DIV>
{
    type InitialRegion = T;

    fn exponent_c1(&self) -> u32 {
        let initial_e = Self::initial_e(&self.initial_region);
        initial_e.saturating_sub(self.size_div) as u32
    }
    
    fn smallest_reduction_of(initial_region: Self::InitialRegion) -> Self {
        Self {
            size_div: core::cmp::min(Self::MAX_SIZE_DIV as u8, Self::initial_e(&initial_region)), 
            idx: 0,
            initial_region,
        }
    }    
}

impl<
        T: InitialRegion + BasicCustomCap,
        const WIDTH_SIZE_DIV: usize,
    > BasicCustomCap for SubalignTightIndexCaveatOf<T, WIDTH_SIZE_DIV>
{
    const BASE_WIDTH: u32 = T::BASE_WIDTH;
    const LENGTH_PRECISION_EXACT: bool = false; // The real length precision may be more precise than we state

    fn check_bits(&self) {
        self.initial_region.check_bits();

        assert_fits!(self.size_div, WIDTH_SIZE_DIV);
        assert!(self.size_div as usize <= Self::MAX_SIZE_DIV, "size_div: {}, max: {}", self.size_div, Self::MAX_SIZE_DIV);
        assert_fits!(self.idx, Self::WIDTH_INDEX);

        let initial_e = Self::initial_e(&self.initial_region);
        assert!(
            initial_e >= self.size_div,
            "Tried to shrink an exponent of {initial_e} by {}",
            self.size_div
        );

        let (b_offset, t_offset) = self.offsets();

        assert!(
            (b_offset as u128) < self.initial_region.len(),
            "b_offset {:x} exceeds initial length {:x} {:?}",
            b_offset,
            self.initial_region.len(),
            self
        );
    }

    fn new_unchecked(base: u64, len: u128) -> Self {
        let initial_region = T::new(base, len);
        Self::create_for(initial_region, base, len)
    }

    fn base(&self) -> u64 {
        self.check_bits();
        let (b_offset, _) = self.offsets();
        // dbg_hex!(self, b_offset, self.initial_region.base());
        self.initial_region.base() + b_offset
    }

    fn len(&self) -> u128 {
        self.check_bits();

        let (b_offset, t_offset) = self.offsets();

        if t_offset > self.initial_region.len() {
            self.initial_region.len() - b_offset as u128
        } else {
            t_offset - b_offset as u128
        }
    }

    fn len_precision(&self) -> u32 {
        // Cannot assert that len_precision is *always* a power of two.
        // Consider an index caveat that shrinks a region but goes a little OOB and gets capped. That length is not a big pow2-alignment.        
        // core::cmp::min(self.exponent_c1(), self.len().trailing_zeros())
        // However, this breaks the scan...
        self.exponent_c1()
    }
}


#[derive(Debug, Clone, Copy)]
pub struct RangeCaveatOf<
    T: Caveat1,
    const WIDTH_RANGE: usize,
    const NONZERO_RANGE_X_NULL: bool,
> {
    pub prior_region: T,
    pub x: u64,
    // TODO make this definition of y consistent with the other rust and the equation?
    pub y: u64,
}
impl<
        T: Caveat1,
        const WIDTH_RANGE: usize,
        const NONZERO_RANGE_X_NULL: bool,
    > RangeCaveatOf<T, WIDTH_RANGE, NONZERO_RANGE_X_NULL>
{
    pub fn create_for(
        prior_region: T,
        target_base: u64,
        target_len: u128,
    ) -> Self {
        let exponent_c1 = prior_region.exponent_c1() as usize;

        let (x, y_plus_1) = if exponent_c1 >= WIDTH_RANGE {
            // In the normal case the region is split into 16,384 sub-regions and we take a contiguous set
            let slice_pow2 = exponent_c1 - WIDTH_RANGE;

            // cav1_range encompasses base and base + len
            // =>  (base - cav1_range.base())       <  2^cav1_pow2
            // and (base + len - cav1_range.base()) <= 2^cav1_pow2
            // => when shifted down by (cav1_pow2 - WIDTH_RANGE), they are both <=2^WIDTH_RANGE

            let top_offset = (target_base - prior_region.base()) as u128 + target_len as u128;
            let range_y: u64 = nth_multiple_of_pow2_128(top_offset, slice_pow2 as u32).try_into().unwrap();
            assert!(range_y <= (1u64 << WIDTH_RANGE), "range_y 0x{:x}, range: 0x{:x}", range_y, 1u64 << WIDTH_RANGE);

            let len_shifted = nth_multiple_of_pow2_128(target_len, slice_pow2 as u32);
            let range_x = if range_y >= len_shifted.try_into().unwrap() && !NONZERO_RANGE_X_NULL {
                // range_y can't be expressed at a fine enough granularity to not go beyond initial length.
                // This forces range_x = 0.
                0
            } else {
                (target_base - prior_region.base()) >> slice_pow2
            };

            (range_x, range_y)
        } else {
            // If cav1_pow2 is already smaller than 2^MAX_RANGE, we can go down to the byte level
            // *but* range_x range_y need to be *left* aligned

            // cav1_range encompasses base and base + len
            // =>  (base - cav1_range.base())       <  2^cav1_pow2
            // and (base + len - cav1_range.base()) <= 2^cav1_pow2
            // => when shifted left by (WIDTH_RANGE - cav1_pow2), they are both <=2^WIDTH_RANGE

            let x_lhs: u64  = target_base - prior_region.base();
            let y_lhs: u64 = (target_base as u128 - prior_region.base() as u128 + target_len).try_into().unwrap();
            (
                x_lhs << (WIDTH_RANGE - exponent_c1),
                y_lhs << (WIDTH_RANGE - exponent_c1),
            )
        };

        Self { prior_region, x, y: y_plus_1 - 1 }
    }

    pub fn base_len(&self) -> (u64, u128) {
        let exponent_c1 = self.prior_region.exponent_c1() as usize;
        let (b_offset, len) = if exponent_c1 >= WIDTH_RANGE {
            // Compute b_offset and len to match original implementation
            let b_offset = self.x << (exponent_c1 - WIDTH_RANGE);
            let len = ((self.y + 1 - self.x) as u128) << (exponent_c1 - WIDTH_RANGE);

            (b_offset, len)
        } else {
            let b_offset = self.x >> (WIDTH_RANGE - exponent_c1);
            let len = ((self.y + 1 - self.x) as u128) >> (WIDTH_RANGE - exponent_c1);

            (b_offset, len)
        };

        if (len + b_offset as u128) > self.prior_region.len() {
            assert!(b_offset as u128 <= self.prior_region.len());
            (self.prior_region.base() + b_offset, self.prior_region.len() as u128 - b_offset as u128)
        } else {
            (self.prior_region.base() + b_offset, len)
        }
    }
}

impl<
        T: Caveat1,
        const WIDTH_RANGE: usize,
        const NONZERO_RANGE_X_NULL: bool,
    > Caveat2 for RangeCaveatOf<T, WIDTH_RANGE, NONZERO_RANGE_X_NULL>
{
    type PriorRegion = T;
    
    fn exponent_c2(&self) -> u32 {
        self.prior_region
            .exponent_c1()
            .saturating_sub(WIDTH_RANGE as u32)
    }
    
    fn smallest_reduction_of(prior_region: Self::PriorRegion) -> Self {
        Self {
            prior_region,
            x: 0,
            y: 0,
        }
    }    
}

impl<
        T: Caveat1,
        const WIDTH_RANGE: usize,
        const NONZERO_RANGE_X_NULL: bool,
    > BasicCustomCap
    for RangeCaveatOf<T, WIDTH_RANGE, NONZERO_RANGE_X_NULL>
{
    const BASE_WIDTH: u32 = T::BASE_WIDTH;
    const LENGTH_PRECISION_EXACT: bool = false;

    fn check_bits(&self) {
        self.prior_region.check_bits();
        assert_fits!(self.x, WIDTH_RANGE);
        assert_fits!(self.y, WIDTH_RANGE);
        assert!(self.y >= self.x, "y > x {self:?}");

        let exponent_c1 = self.prior_region.exponent_c1() as usize;
        let (b_offset, len) = if exponent_c1 >= WIDTH_RANGE {
            // Compute b_offset and len to match original implementation
            let b_offset = self.x << (exponent_c1 - WIDTH_RANGE);
            let len = ((self.y + 1 - self.x) as u128) << (exponent_c1 - WIDTH_RANGE);

            (b_offset, len)
        } else {
            let b_offset = self.x >> (WIDTH_RANGE - exponent_c1);
            let len = ((self.y + 1 - self.x) as u128) >> (WIDTH_RANGE - exponent_c1);

            (b_offset, len)
        };

        if (len + b_offset as u128) > self.prior_region.len() {
            assert!(
                self.x == 0 || NONZERO_RANGE_X_NULL,
                "Nonzero x with overly-long size when not allowed {self:?}",
            )
        }

        assert!(
            b_offset as u128 <= self.prior_region.len(),
            "b_offset {:x} greater then len {:x} {:?}",
            b_offset,
            self.prior_region.len(),
            self
        );
    }

    fn new_unchecked(base: u64, len: u128) -> Self {
        let prior_region = T::new(base, len);
        Self::create_for(prior_region, base, len)
    }

    fn base(&self) -> u64 {
        self.base_len().0
    }

    fn len(&self) -> u128 {
        self.base_len().1
    }

    fn len_precision(&self) -> u32 {
        // Cannot assert that len_precision is *always* a power of two.
        // Consider an index caveat that shrinks a region but goes a little OOB and gets capped. That length is not a big pow2-alignment.        
        // core::cmp::min(self.exponent_c2(), self.len().trailing_zeros())
        // However, that breaks things
        self.exponent_c2()
    }
}

pub type InitialIOCap2024_11 = GenericIocapGuaranteedTwoDepthInitialRegion<54, 10, 5, 32, 4, 1>;
pub type Cav1IOCap2024_11 = IndexCaveatOf<
    InitialIOCap2024_11,
    4,
    false,
>;

pub type Cav12IOCap2024_11 = RangeCaveatOf<
    Cav1IOCap2024_11,
    14,
    false,
>;

pub type Cav12IOCap2024_11_Improved = RangeCaveatOf<
    Cav1IOCap2024_11,
    14,
    true,
>;
