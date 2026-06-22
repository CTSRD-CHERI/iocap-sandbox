use std::fmt::Debug;

pub mod aries;
pub mod iocap_general;
pub mod lowfat;
pub mod mmachine;

/// Given x, round it up to the nearest pow2 and return that pow2
/// ```
/// use rust_caps_scanner::caps::round_up_as_pow2;
/// assert_eq!(round_up_as_pow2(0), 0);
/// assert_eq!(round_up_as_pow2(1), 0);
/// assert_eq!(round_up_as_pow2((1u64 << 12) - 1), 12);
/// assert_eq!(round_up_as_pow2((1u64 << 12)), 12);
/// assert_eq!(round_up_as_pow2((1u64 << 12) + 1), 13);
/// assert_eq!(round_up_as_pow2(!0), 64);
/// ```
pub fn round_up_as_pow2(x: u64) -> u32 {
    if x == 0 {
        return 0;
    }
    let bit_len = 63 - x.leading_zeros();
    let top_pow2_of_x = 1u64 << bit_len;
    if top_pow2_of_x >= x {
        bit_len
    } else {
        bit_len + 1
    }
}

/// Given 128-bit x, round it up to the nearest pow2 and return that pow2
/// ```
/// use rust_caps_scanner::caps::round_up_as_pow2_128;
/// assert_eq!(round_up_as_pow2_128(0), 0);
/// assert_eq!(round_up_as_pow2_128(1), 0);
/// assert_eq!(round_up_as_pow2_128((1u128 << 102) - 1), 102);
/// assert_eq!(round_up_as_pow2_128((1u128 << 102)), 102);
/// assert_eq!(round_up_as_pow2_128((1u128 << 102) + 1), 103);
/// assert_eq!(round_up_as_pow2_128(!0), 128);
/// ```
pub fn round_up_as_pow2_128(x: u128) -> u32 {
    if x == 0 {
        return 0;
    }
    let bit_len = 127 - x.leading_zeros();
    let top_pow2_of_x = 1u128 << bit_len;
    if top_pow2_of_x >= x {
        bit_len
    } else {
        bit_len + 1
    }
}

/// Given x, round it up to the nearest pow2 and return the full number.
/// ```
/// use rust_caps_scanner::caps::round_up_to_pow2;
/// assert_eq!(round_up_to_pow2(0), 1);
/// assert_eq!(round_up_to_pow2(1), 1);
/// assert_eq!(round_up_to_pow2((1u64 << 12) - 1), 1u128 << 12);
/// assert_eq!(round_up_to_pow2((1u64 << 12)),     1u128 << 12);
/// assert_eq!(round_up_to_pow2((1u64 << 12) + 1), 1u128 << 13);
/// assert_eq!(round_up_to_pow2(!0), 1u128 << 64);
/// ```
pub fn round_up_to_pow2(x: u64) -> u128 {
    if x == 0 {
        return 1;
    }
    let bit_len = 63 - x.leading_zeros();
    let top_pow2_of_x = 1u64 << bit_len;
    if top_pow2_of_x >= x {
        1u128 << (bit_len)
    } else {
        1u128 << (bit_len + 1)
    }
}

/// Given x and a base b, round x down so it is aligned to a b-boundary.
/// ```
/// use rust_caps_scanner::caps::align_down_to;
/// assert_eq!(align_down_to(0xabcdef, 0), 0xabcdef);
/// assert_eq!(align_down_to(0xabcdef, 1), 0xabcdee);
/// assert_eq!(align_down_to(0xabcdef, 2), 0xabcdec);
/// assert_eq!(align_down_to(0xabcdef, 3), 0xabcde8);
/// assert_eq!(align_down_to(0xabcdef, 4), 0xabcde0);
/// assert_eq!(align_down_to(0xabcdef, 12), 0xabc000);
/// assert_eq!(align_down_to(0xabcdef, 24), 0x000000);
/// assert_eq!(align_down_to(!0u64, 63), 1u64 << 63);
/// assert_eq!(align_down_to(!0u64, 64), 0);
/// // b >= 64 implies total zeroing
/// assert_eq!(align_down_to(!0u64, 65), 0);
/// ```
pub fn align_down_to(x: u64, b: u32) -> u64 {
    let mask = if b < 64 { (1u64 << b) - 1 } else { !0u64 };
    x & (!mask)
}

/// Given x and a base b, round x up so it is aligned to a b-boundary.
/// ```
/// # use rust_caps_scanner::caps::align_up_to;
/// assert_eq!(align_up_to(0xabcdef, 0), 0xabcdef);
/// assert_eq!(align_up_to(0xabcdef, 1), 0xabcdf0);
/// assert_eq!(align_up_to(0xabcdef, 2), 0xabcdf0);
/// assert_eq!(align_up_to(0xabcdef, 3), 0xabcdf0);
/// assert_eq!(align_up_to(0xabcdef, 4), 0xabcdf0);
/// assert_eq!(align_up_to(0xabcdef, 12), 0xabd000);
/// assert_eq!(align_up_to(0xabcdef, 24), 0x1_000000);
/// ```
/// ```should_panic
/// # use rust_caps_scanner::caps::align_up_to;
/// // overflowing u64 has a descriptive panic
/// assert_eq!(align_up_to(!0u64, 63), 1u64 << 63);
/// ```
/// ```should_panic
/// # use rust_caps_scanner::caps::align_up_to;
/// // b >= 64 panics
/// align_up_to(!0u64, 64);
/// ```
/// ```should_panic
/// # use rust_caps_scanner::caps::align_up_to;
/// align_up_to(!0u64, 65);
/// ```
pub fn align_up_to(x: u64, b: u32) -> u64 {
    if b >= 64 {
        panic!("Cannot align_up_to when x is u64 and b = {b}");
    }
    let mask = (1u64 << b) - 1;
    let rounded_down = x & !mask;
    if x > rounded_down {
        if u64::MAX - mask - 1 < rounded_down {
            panic!("Cannot align_up_to, x is too large. x = 0x{x:x} b = {b}");
        }
        rounded_down + mask + 1
    } else {
        rounded_down
    }
}

pub fn align_up_to_128(x: u128, b: u32) -> u128 {
    if b >= 128 {
        panic!("Cannot align_up_to when x is u128 and b = {b}");
    }
    let mask = (1u128 << b) - 1;
    let rounded_down = x & !mask;
    if x > rounded_down {
        if u128::MAX - mask - 1 < rounded_down {
            panic!("Cannot align_up_to, x is too large. x = 0x{x:x} b = {b}");
        }
        rounded_down + mask + 1
    } else {
        rounded_down
    }
}

/// Round x up to the closest `n * 2^b` and return x.
/// Another name for [align_up_to].
pub fn as_multiple_of_pow2(x: u64, b: u32) -> u64 {
    align_up_to(x, b)
}

/// Round x up to the closest `n * 2^b` and return n.
pub fn nth_multiple_of_pow2(x: u64, b: u32) -> u64 {
    if b >= 64 {
        panic!("Cannot nth_multiple_of_pow2 when x is u64 and b = {b}");
    }
    let mask = (1u64 << b) - 1;
    let rounded_off = x & mask;
    (x >> b) + if rounded_off > 0 { 1 } else { 0 }
}

/// Round x up to the closest `n * 2^b` and return n.
pub fn nth_multiple_of_pow2_128(x: u128, b: u32) -> u128 {
    if b >= 128 {
        panic!("Cannot nth_multiple_of_pow2 when x is u128 and b = {b}");
    }
    let mask = (1u128 << b) - 1;
    let rounded_off = x & mask;
    (x >> b) + if rounded_off > 0 { 1 } else { 0 }
}

pub trait BasicCustomCap: Debug + Sized {
    const BASE_WIDTH: u32;
    const LENGTH_PRECISION_EXACT: bool = true;

    fn check_bits(&self);
    fn new_unchecked(base: u64, len: u128) -> Self;
    fn base(&self) -> u64;
    fn len(&self) -> u128;

    fn len_precision(&self) -> u32;

    fn new(base: u64, len: u128) -> Self {
        let s = Self::new_unchecked(base, len);
        s.check_bits();
        let true_base = s.base();
        let true_len = s.len();
        assert!(true_base <= base, "Capability {s:?} throws base out-of-bounds\nbase {base:x} len {len:x} true_base {true_base:x} true_len {true_len:x}");
        assert!(len as u128 + (base as u128 - true_base as u128) <= true_len, "Capability {s:?} throws top out-of-bounds.\nbase {base:x} len {len:x} true_base {true_base:x} true_len {true_len:x}");
        if Self::LENGTH_PRECISION_EXACT {
            assert_eq!(
                align_up_to_128(true_len, s.len_precision()),
                true_len,
                "Capability {s:?} giving incorrect len_precision {}",
                s.len_precision()
            );
        }
        s
    }
}

macro_rules! assert_fits {
    ($val: expr, $bits: expr) => {
        assert!(
            (($val) as u128) < (1u128 << ($bits)),
            "{} must be {}-bit, was {}",
            stringify!($val),
            stringify!($bits),
            ($val)
        );
    };
}
pub(crate) use assert_fits;

/// Verilog-rules bit extraction
pub fn extract_bits(x: u128, end: u32, start: u32) -> u128 {
    assert!(end >= start);
    let mask = (1u128 << (end - start + 1)) - 1;
    (x >> start) & mask
}
