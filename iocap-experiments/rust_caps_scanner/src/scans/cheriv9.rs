use rust_cheri_compressed_cap::{caps::cheriv9::cc128, CcxCap, CompressedCapability};
type Cap = cc128::Cc128;

use crate::{
    caps::BasicCustomCap,
    scans::{
        basic_cap::{self, BaseAlign, LengthPrecision},
        LogScan,
    },
};

impl BasicCustomCap for CcxCap<Cap> {
    const BASE_WIDTH: u32 = 64;

    fn check_bits(&self) {}

    fn new_unchecked(base: u64, len: u128) -> Self {
        let mut cap = Cap::make_max_perms_cap(0, base, 1u128 << 64);
        cap.set_otype(Cap::OTYPE_UNSEALED);
        cap.set_bounds_unchecked(len as u128);
        assert!(cap.tag());
        cap
    }

    fn base(&self) -> u64 {
        self.base()
    }

    fn len(&self) -> u128 {
        self.length()
    }

    fn len_precision(&self) -> u32 {
        let bits = self.extract_bounds_bits();
        if bits.ie {
            assert_eq!(bits.b & 0b111, 0);
            assert_eq!(bits.t & 0b111, 0);
            bits.e as u32 + 3
        } else {
            bits.e as u32
        }
    }
}

pub const CHERIV9_BASE_ALIGN: BaseAlign<CcxCap<Cap>> =
    basic_cap::BaseAlign::<CcxCap<Cap>>::new(!0, Some(1u128 << 64));
pub const CHERIV9_LENGTH_PRECISION: LengthPrecision<CcxCap<Cap>> =
    basic_cap::LengthPrecision::<CcxCap<Cap>>::new(!0, Some(1u128 << 64));

pub struct BaseAlign_Scan;
impl LogScan for BaseAlign_Scan {
    type T = (u64, u32);

    const HEADER: &'static str = "intended_base\tintended_len\tbase_align";

    fn apply_f(&self, x: u128) -> Self::T {
        // 63 low bits set, any downwards alignment can be counted via the bottom bits
        const BASE_ADDR: u64 = !0;
        let mut base = BASE_ADDR;
        let length = x;
        // TODO this whole setup is a little odd and breaks the base precision metric near the start?
        // or actually, no! think about it.
        // The CHERI model requires moving from the almighty capability, which is 0-(1 << 64).
        // You can't exceed the almighty bounds, so once your target length exceeds (1 << 64) - (min align)
        // you are effectively forced into the almighty capability again.
        let mut top = base as u128 + length as u128;
        while top >= (1u128 << 64) {
            base = base >> 1;
            top = base as u128 + length as u128;
        }
        if base == 0 {
            base = 1;
        }
        let mut cap = Cap::make_max_perms_cap(0, base, 1u128 << 64);
        // dbg_hex!(cap.base(), cap.length());
        cap.set_otype(Cap::OTYPE_UNSEALED);
        // dbg_hex!(cap);
        let exact = cap.set_bounds_unchecked(length as u128);
        // dbg_hex!(cap);
        assert!(cap.tag());
        // dbg_hex!(exact, cap.tag(), cap.base(), cap.length());
        (base, cap.base().trailing_zeros())
    }

    fn accept_result(&mut self, x: u128, result: &Self::T) {
        println!("0x{:016x}\t0x{:016x}\t{}", result.0, x, result.1);
    }
}

pub struct LengthPrecision_Scan(pub u64);
impl LogScan for LengthPrecision_Scan {
    type T = (u64, u8);

    const HEADER: &'static str = "intended_base\tintended_len\tlen_align";

    fn apply_f(&self, x: u128) -> Self::T {
        let mut base = self.0;
        let length = x;
        // TODO this whole setup is a little odd and breaks the base precision metric near the start?
        // or actually, no! think about it.
        // The CHERI model requires moving from the almighty capability, which is 0-(1 << 64).
        // You can't exceed the almighty bounds, so once your target length exceeds (1 << 64) - (min align)
        // you are effectively forced into the almighty capability again.
        let mut top = base as u128 + length as u128;
        while top >= (1u128 << 64) {
            base = base >> 1;
            top = base as u128 + length as u128;
        }
        if base == 0 {
            base = 1;
        }
        let mut cap = Cap::make_max_perms_cap(0, base, 1u128 << 64);
        // dbg_hex!(cap.base(), cap.length());
        cap.set_otype(Cap::OTYPE_UNSEALED);
        // dbg_hex!(cap);
        let exact = cap.set_bounds_unchecked(length as u128);
        assert!(cap.tag());
        (
            cap.base(),
            cap.extract_bounds_bits().e, // todo!("Find way to track length precision from scan")
        )
    }

    fn accept_result(&mut self, x: u128, result: &Self::T) {
        println!("0x{:016x}\t0x{:016x}\t{}", result.0, x, result.1);
    }
}
