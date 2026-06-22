use rust_caps::capability::v2024::Cap2024;
use rust_caps::capability::v2024_11;
use rust_caps::capability::v2024_11::cavs::Caveats;
use rust_caps::capability::AddrRange;
use rust_caps::capability::CapPerms;
use rust_caps::crypto::NullSig;

use crate::caps::BasicCustomCap;
use crate::caps::iocap_general::Cav1IOCap2024_11;
use crate::caps::iocap_general::Cav12IOCap2024_11;
use crate::caps::iocap_general::InitialIOCap2024_11;
use crate::scans::LogScan;

use dbg_hex::dbg_hex;

pub struct InitialRegion_BaseAlign_Scan;
impl LogScan for InitialRegion_BaseAlign_Scan {
    type T = (u64, u32);

    const HEADER: &'static str = "intended_base\tintended_len\tbase_align";

    fn apply_f(&self, x: u128) -> Self::T {
        const BASE_ADDR: u64 = (1u64 << 54) - 1;
        let length = x;
        let (_, addr_range) = v2024_11::EncodedInitialRange::pack_base_and_length(
            &AddrRange::base_len(BASE_ADDR, length as u128),
        )
        .inspect_err(|e| panic!("failed err {e:?} with base 0x{BASE_ADDR:x} and len 0x{length:x}"))
        .unwrap();

        let reimplemented = InitialIOCap2024_11::new(BASE_ADDR, length);
        assert_eq!((addr_range.base(), addr_range.len()), (reimplemented.base(), reimplemented.len()));

        (BASE_ADDR, addr_range.base().trailing_zeros())
    }

    fn accept_result(&mut self, x: u128, result: &Self::T) {
        println!("0x{:016x}\t0x{:016x}\t{}", result.0, x, result.1);
    }
}

pub struct InitialRegion_LengthPrecision_Scan(pub u64);
impl LogScan for InitialRegion_LengthPrecision_Scan {
    type T = (u64, u32);

    const HEADER: &'static str = "intended_base\tintended_len\tlen_align";

    fn apply_f(&self, x: u128) -> Self::T {
        let base = self.0;
        let length = x;
        let (encoded, addr_range) = v2024_11::EncodedInitialRange::pack_base_and_length(
            &AddrRange::base_len(base, length as u128),
        )
        .unwrap();

        let reimplemented = InitialIOCap2024_11::new(base, length);
        assert_eq!((addr_range.base(), addr_range.len()), (reimplemented.base(), reimplemented.len()));

        (
            base,
            (encoded.partial_decode().elem_width_log2_minus_10.val() as u32) + 10,
        )
    }

    fn accept_result(&mut self, x: u128, result: &Self::T) {
        println!("0x{:016x}\t0x{:016x}\t{}", result.0, x, result.1);
    }
}

pub struct Cavs12_BaseAlign_Scan;
impl LogScan for Cavs12_BaseAlign_Scan {
    type T = (u64, u32);

    const HEADER: &'static str = "intended_base\tintended_len\tbase_align";

    fn apply_f(&self, x: u128) -> Self::T {
        // 38 low bits set, any downwards alignment can be counted via the bottom bits
        // don't need that anymore but setting it to zero causes weird filling artifacts.
        // note: caveats innefective once you get past (15+14) count bits. that means the log_max_count which you are trying to reduce from is higher above the block size than cav1+cav2 reduction.
        // should watch out for this: extremely large regions expressed without needing the initial region precision can still be reduced with some precision, but extremely large regions that are expressed using that precision can't be made more precise with caveats.
        // TODO DOUBLE CHECK THAT FUCKING EXPLANATION I'M SO TIRED
        const BASE_ADDR: u64 = (1u64 << 54) - 1;
        let base = BASE_ADDR;
        let len = x;
        let target = AddrRange::base_len(base, len);
        // dbg_hex!(target);
        let mut cap = v2024_11::Cap2024_11::<NullSig>::new_inexact(
            0,
            0,
            base,
            len as u128,
            CapPerms::ReadWrite,
        )
        .unwrap();
        assert!(
            cap.addr_range.encompasses(&target),
            "{:x} not encompassing {:x}",
            cap.addr_range,
            target
        );
        let reimplemented = InitialIOCap2024_11::new(base, len);
        reimplemented.check_bits();
        assert_eq!((cap.addr_range.base(), cap.addr_range.len()), (reimplemented.base(), reimplemented.len()));

        cap = cap.refine_using_cav1_towards(None, target).unwrap();
        assert!(
            cap.addr_range.encompasses(&target),
            "{:x} not encompassing {:x}",
            cap.addr_range,
            target
        );
        let reimplemented = Cav1IOCap2024_11::create_for(reimplemented, base, len);
        reimplemented.check_bits();
        assert_eq!((cap.addr_range.base(), cap.addr_range.len()), (reimplemented.base(), reimplemented.len()));

        cap = cap.refine_using_cav2_towards(None, target).unwrap();
        assert!(
            cap.addr_range.encompasses(&target),
            "{:x} not encompassing {:x}",
            cap.addr_range,
            target
        );
        let reimplemented = Cav12IOCap2024_11::create_for(reimplemented, base, len);
        reimplemented.check_bits();
        assert_eq!((cap.addr_range.base(), cap.addr_range.len()), (reimplemented.base(), reimplemented.len()), "target {}\ncap {:?}\nreimplemented {:?}", target, cap, reimplemented);

        let addr_range = cap.addr_range;

        if let Caveats::Two {
            index,
            index_size_div,

            range_x,
            range_y_minus_one,
        } = cap.cap_data.caveats
        {
            (
                BASE_ADDR,
                (cap.cap_data.initial.elem_width_log2_minus_10.val() as u32
                    + cap.cap_data.initial.log_max_count.val() as u32)
                    .saturating_sub(index_size_div.val() as u32 + 14),
            )
        } else {
            panic!("Not all caveats applied");
        }
    }

    fn accept_result(&mut self, x: u128, result: &Self::T) {
        println!("0x{:016x}\t0x{:016x}\t{}", result.0, x, result.1);
    }
}

pub struct Cavs_Reduction_Scan {
    pub base: u64,
    pub cav2: bool,
}
impl LogScan for Cavs_Reduction_Scan {
    type T = (u64, u64);

    const HEADER: &'static str = "intended_base\tinitial_len\tsmallest_len";

    fn apply_f(&self, x: u128) -> Self::T {
        let base = self.base;
        let len = x;
        let mut cap = v2024_11::Cap2024_11::<NullSig>::new_inexact(
            0,
            0,
            base,
            len as u128,
            CapPerms::ReadWrite,
        )
        .unwrap();
        let reimplemented = InitialIOCap2024_11::new(base, len);
        assert_eq!((cap.addr_range.base(), cap.addr_range.len()), (reimplemented.base(), reimplemented.len()));

        cap = cap.with_cav1_size_div(None, 0, 15).unwrap();
        let reimplemented = Cav1IOCap2024_11 {
            initial_region: reimplemented,
            size_div: 15,
            idx: 0,
        };
        assert_eq!((cap.addr_range.base(), cap.addr_range.len()), (reimplemented.base(), reimplemented.len()));
        
        if self.cav2 {
            cap = cap.with_cav2(None, 0, 1).unwrap();

            let reimplemented = Cav12IOCap2024_11 {
                prior_region: reimplemented,
                x: 0,
                y: 0,
            };
            assert_eq!((cap.addr_range.base(), cap.addr_range.len()), (reimplemented.base(), reimplemented.len()));
        }
        (base, cap.addr_range.len() as u64)
    }

    fn accept_result(&mut self, x: u128, result: &Self::T) {
        println!("0x{:016x}\t0x{:016x}\t0x{:016x}", result.0, x, result.1);
    }
}
