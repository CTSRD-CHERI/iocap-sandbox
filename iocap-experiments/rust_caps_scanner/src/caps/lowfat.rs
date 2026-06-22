use crate::caps::{align_down_to, align_up_to_128, BasicCustomCap};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct LowFatCap {
    pub a: u64,
    pub b: u8,
    pub i: u8,
    pub m: u8,
}
impl LowFatCap {
    fn dunder_dover(&self) -> (u64, u128) {
        // From reference implementation
        // Note: reference impl used u46 for carry etc
        // Using u128 as carry extends length allowance up to the limit of what b can encode
        let carry: u128 = 64 << self.b;
        assert_ne!(carry, 0);
        let ones: u128 = carry - 1;

        let a_belowb = ones & (self.a as u128);

        let a_aboveb: u128 = (self.a as u128) >> self.b;
        let i_shiftb: u128 = (self.i as u128) << self.b;
        let m_shiftb: u128 = (self.m as u128) << self.b;

        let selector = (a_aboveb & 0b111_111) as u8;

        let dunder = if self.i > selector {
            (carry | a_belowb) - i_shiftb
        } else {
            a_belowb - i_shiftb
        }
        .try_into()
        .expect("In practice self.a is 46-bit, so it can never go 64-bits above the base");

        let dover = if self.m < selector {
            (carry | m_shiftb) - a_belowb - 1
        } else {
            m_shiftb - a_belowb - 1
        };

        (dunder, dover)
    }
}
impl BasicCustomCap for LowFatCap {
    const BASE_WIDTH: u32 = 46;

    fn new_unchecked(base: u64, len: u128) -> Self {
        // Brute-force: just go through all block sizes until we find one that fits
        let intended_base = base;
        let intended_top = base as u128 + len as u128;
        for block_size in 0..=63 {
            let rounded_base = align_down_to(base, block_size);
            let max_length = 64u128 << block_size;

            let required_length = intended_top - (rounded_base as u128);
            if required_length <= max_length {
                let i = (intended_base >> block_size) & 0b111_111;
                let m = (align_up_to_128(intended_top, block_size) >> block_size) & 0b111_111;

                // This is required.
                // Low-Fat treats the bounds as inclusive, which means dunder = 0 AND dover = 0 are both allowed (see mkBIMA.addp, only treated as invalid if it moves either one negative).
                // If you pick an encoding where i == m, you risk the scenario i == m == (a[5:0] >> b), which implies ZERO length - effectively i == m would imply an extra top bit to the length.
                // You could change the dover encoding to use self.m <= selector, not self.m < selector, to treat i == m as (top = carry + {m, a_bottom}) and create an implicit top bit.
                // However this would make (addr = top) unrepresentable, which does not seem to be how BIMA.bsv works.
                if i as u8 != m as u8 {
                    let s = Self {
                        a: base,
                        b: block_size as u8,
                        i: i as u8,
                        m: m as u8,
                    };
                    return s;
                }
            }
        }
        unreachable!("Can't fit!")
    }

    fn base(&self) -> u64 {
        self.a - self.dunder_dover().0
    }

    fn len(&self) -> u128 {
        let (dunder, dover) = self.dunder_dover();
        (dunder as u128) + dover + 1
    }

    fn len_precision(&self) -> u32 {
        self.b as u32
    }

    fn check_bits(&self) {
        super::assert_fits!(self.a, 46);
        super::assert_fits!(self.b, 6);
        super::assert_fits!(self.i, 6);
        super::assert_fits!(self.m, 6);
    }
}
