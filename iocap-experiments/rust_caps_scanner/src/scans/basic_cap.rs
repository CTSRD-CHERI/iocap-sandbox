use std::marker::PhantomData;

use crate::caps::BasicCustomCap;

use crate::scans::LogScan;

pub struct BaseAlign<T: BasicCustomCap> {
    base_addr: u64,
    clamp_top: Option<u128>,
    _t: PhantomData<T>,
}
impl<T: BasicCustomCap> BaseAlign<T> {
    pub const fn new(base_addr: u64, clamp_top: Option<u128>) -> Self {
        Self {
            base_addr,
            clamp_top,
            _t: PhantomData,
        }
    }
}

impl<T: BasicCustomCap> LogScan for BaseAlign<T> {
    type T = (u64, u32);

    const HEADER: &'static str = "intended_base\tintended_len\tbase_align";

    fn apply_f(&self, x: u128) -> Self::T {
        let mut base = self.base_addr;
        let len = x;

        if let Some(clamp_top) = self.clamp_top {
            assert!((len as u128) < clamp_top, "len 0x{:x} clamp_top 0x{:x}", len, clamp_top);
            let mut top = base as u128 + len as u128;
            while top >= clamp_top {
                base = base >> 1;
                top = base as u128 + len as u128;
            }
            if base == 0 {
                base = 1;
            }
        }

        let cap = T::new(base, len);
        (
            base,
            core::cmp::min(T::BASE_WIDTH, cap.base().trailing_zeros()),
        )
    }

    fn accept_result(&mut self, x: u128, result: &Self::T) {
        println!("0x{:016x}\t0x{:016x}\t{}", result.0, x, result.1);
    }
}

pub struct LengthPrecision<T: BasicCustomCap> {
    base_addr: u64,
    clamp_top: Option<u128>,
    _t: PhantomData<T>,
}
impl<T: BasicCustomCap> LengthPrecision<T> {
    pub const fn new(base_addr: u64, clamp_top: Option<u128>) -> Self {
        Self {
            base_addr,
            clamp_top,
            _t: PhantomData,
        }
    }
}

impl<T: BasicCustomCap> LogScan for LengthPrecision<T> {
    type T = (u64, u32);

    const HEADER: &'static str = "intended_base\tintended_len\tlen_align";

    fn apply_f(&self, x: u128) -> Self::T {
        let mut base = self.base_addr;
        let len = x;

        if let Some(clamp_top) = self.clamp_top {
            assert!((len as u128) < clamp_top);

            let mut top = base as u128 + len as u128;
            while top >= clamp_top {
                base = base >> 1;
                top = base as u128 + len as u128;
            }
            if base == 0 {
                base = 1;
            }
        }

        let cap = T::new(base, len);
        (base, cap.len_precision())
    }

    fn accept_result(&mut self, x: u128, result: &Self::T) {
        println!("0x{:016x}\t0x{:016x}\t{}", result.0, x, result.1);
    }
}
