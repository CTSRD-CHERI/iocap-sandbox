use crate::caps::{BasicCustomCap, align_down_to, round_up_as_pow2, round_up_as_pow2_128};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct MMachineCap {
    pub ptr: u64,
    pub block: u32,
}

impl BasicCustomCap for MMachineCap {
    const BASE_WIDTH: u32 = 54;

    fn new_unchecked(ptr: u64, length: u128) -> Self {
        if ptr >= (1u64 << 54) {
            panic!("Can only represent 54-bit pointers! base {ptr:x} len {length:x}");
        }
        // Only intended within the 54-bit addrspace even if it can go further
        if (ptr as u128) + (length as u128) >= (1u128 << 55) {
            panic!("Can only represent regions inside the 55-bit address space! base {ptr:x} len {length:x}");
        }

        let mut tentative_block_size = round_up_as_pow2_128(length);
        /* // NOTE: We have to have a loop here, because pathological cases can push us out.
        if length + (ptr - tentative_base) > (1 << tentative_block_size) {
            // We've bumped up by one power of two
            Self {
                ptr,
                block: tentative_block_size + 1,
            }
        } else {
            Self {
                ptr,
                block: tentative_block_size
            }
        }
        */
        while tentative_block_size < 64 {
            let tentative_base: u64 = align_down_to(ptr, tentative_block_size);
            if length as u128 + (ptr - tentative_base) as u128 <= (1u128 << tentative_block_size) {
                // We fit!
                return Self {
                    ptr,
                    block: tentative_block_size,
                };
            }
            tentative_block_size += 1;
        }
        panic!("Can't fit! target base 0x{ptr:x} len 0x{length:x},\n");
    }

    fn base(&self) -> u64 {
        align_down_to(self.ptr, self.block)
    }
    fn len(&self) -> u128 {
        1u128 << self.block
    }
    fn len_precision(&self) -> u32 {
        self.block
    }

    fn check_bits(&self) {
        super::assert_fits!(self.ptr, 54);
        super::assert_fits!(self.block, 6);
    }
}
