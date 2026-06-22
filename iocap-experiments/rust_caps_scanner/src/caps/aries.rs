use crate::caps::{align_down_to, nth_multiple_of_pow2_128, BasicCustomCap};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct AriesCap {
    pub addr: u64,
    pub f: u8,
    pub b_p: u8,
    pub l_p: u8,
}

impl BasicCustomCap for AriesCap {
    const BASE_WIDTH: u32 = 64;

    fn new_unchecked(addr: u64, len: u128) -> Self {
        if len == 0 {
            panic!("Cannot encode length 0");
        }
        if len <= 16 {
            // small-segment
            return Self {
                addr,
                f: 0,
                b_p: 63,
                l_p: (len as u8) - 1,
            };
        }

        // Brute-force: just go through all block sizes until we find one that fits
        let intended_base = addr;
        let intended_top = addr as u128 + len as u128;
        for block_size in 0..=62 {
            let rounded_base = align_down_to(addr, block_size);
            let max_length = 32u128 << block_size;

            let required_length = intended_top - (rounded_base as u128);
            if required_length <= max_length {
                let f = (rounded_base - align_down_to(intended_base, block_size)) >> block_size;
                let l: u8 = nth_multiple_of_pow2_128(required_length, block_size)
                    .try_into()
                    .expect("l_p should always fit");
                assert!(l > 16);
                return Self {
                    addr: intended_base,
                    f: f.try_into().expect("f should always fit"),
                    b_p: block_size as u8,
                    l_p: l - 17,
                };
            }
        }
        unreachable!("Can't fit!")
    }
    fn base(&self) -> u64 {
        let block_size = if self.b_p == 63 {
            // small-segment case
            0
        } else {
            // large-segment case
            self.b_p
        };
        let address_block = self.addr >> block_size;
        let base_block = address_block - self.f as u64;
        base_block << block_size
    }
    fn len(&self) -> u128 {
        if self.b_p == 63 {
            // small-segment case
            (self.l_p as u128) + 1
        } else {
            // large-segment case
            ((self.l_p as u128) + 17) << self.b_p
        }
    }
    fn len_precision(&self) -> u32 {
        if self.b_p == 63 {
            0
        } else {
            self.b_p as u32
        }
    }

    fn check_bits(&self) {
        super::assert_fits!(self.f, 5);
        super::assert_fits!(self.b_p, 6);
        super::assert_fits!(self.l_p, 4);
    }
}
