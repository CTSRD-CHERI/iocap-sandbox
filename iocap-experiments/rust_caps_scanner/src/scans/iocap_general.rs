use std::marker::PhantomData;

use crate::{
    caps::{BasicCustomCap, iocap_general::{Cav12IOCap2024_11_Improved, Caveat1, Caveat2, GenericIocapGuaranteedTwoDepthInitialRegion, GenericIocapInitialRegion, IndexCaveatOf, InitialIOCap2024_11, InitialRegion, RangeCaveatOf, SubalignIndexCaveatOf, SubalignTightIndexCaveatOf, WidthClass}},
    scans::{LogScan, basic_cap::{BaseAlign, LengthPrecision}},
};

type BaseThesisDemoIocap =
    GenericIocapInitialRegion<32, 0, 8, { 1 << 3 }, { 1 << 1 }, 1>;
pub type ThesisDemoIocap = GenericIocapGuaranteedTwoDepthInitialRegion<32, 0, 8, { 1 << 3 }, { 1 << 1 }, 1>;


pub fn check_thesis_demo() {
    assert_eq!(
        BaseThesisDemoIocap::WIDTH_CLASSES[0],
        WidthClass {
            w: 0,
            e: 0,
            m_top: 0,
            m_bits: 8,
            b_bits: 32,
            b_align: 0,
            max_encodable_pow2: 8,
            min_used_pow2: 0,
        }
    );
    assert_eq!(BaseThesisDemoIocap::WIDTH_CLASSES[0].min_used_pow2_incl(), true);
    assert_eq!(
        BaseThesisDemoIocap::WIDTH_CLASSES[1],
        WidthClass {
            w: 1,
            e: 0,
            m_top: 1,
            m_bits: 8,
            b_bits: 32,
            b_align: 0,
            min_used_pow2: 8,
            max_encodable_pow2: 9,
        }
    );
    assert_eq!(BaseThesisDemoIocap::WIDTH_CLASSES[1].min_used_pow2_incl(), false);
    assert_eq!(
        BaseThesisDemoIocap::WIDTH_CLASSES[4],
        WidthClass {
            w: 4,
            e: 3,
            m_top: 0,
            m_bits: 11,
            b_bits: 29,
            b_align: 32 - 29,
            min_used_pow2: 11,
            max_encodable_pow2: 14,
        }
    );
    assert_eq!(BaseThesisDemoIocap::WIDTH_CLASSES[4].min_used_pow2_incl(), false);

    assert_eq!(
        BaseThesisDemoIocap::WIDTH_CLASSES[5],
        WidthClass {
            w: 5,
            e: 3,
            m_top: 1,
            m_bits: 11,
            b_bits: 29,
            b_align: 32 - 29,
            min_used_pow2: 14,
            max_encodable_pow2: 15,
        }
    );
    assert_eq!(BaseThesisDemoIocap::WIDTH_CLASSES[5].min_used_pow2_incl(), false);

    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[0].map(|s| s.get()), Some(0));
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[1].map(|s| s.get()), Some(0));
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[8].map(|s| s.get()), Some(0));
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[9].map(|s| s.get()), Some(1));
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[10].map(|s| s.get()), Some(2));
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[11].map(|s| s.get()), Some(3));
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[12].map(|s| s.get()), Some(4));
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[13].map(|s| s.get()), Some(4));
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[14].map(|s| s.get()), Some(4));
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[15].map(|s| s.get()), Some(5));
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[16].map(|s| s.get()), Some(6));
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[17].map(|s| s.get()), Some(7));
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[18], None);
    assert_eq!(BaseThesisDemoIocap::LENGTH_POW2_TO_WIDTH_CLASS[127], None);
}

pub const THESIS_DEMO_BASE_ADDR: u64 = (1u64 << 32) - 1;
pub const THESIS_DEMO_CLAMP_TOP: Option<u128> = Some((THESIS_DEMO_BASE_ADDR as u128 & ((!0) << 3)) + (1u128 << 17)); 
pub const THESIS_DEMO_BASE_ALIGN: BaseAlign<ThesisDemoIocap> =
    BaseAlign::<ThesisDemoIocap>::new(THESIS_DEMO_BASE_ADDR, THESIS_DEMO_CLAMP_TOP);
pub const THESIS_DEMO_LENGTH_PRECISION: LengthPrecision<ThesisDemoIocap> = LengthPrecision::<ThesisDemoIocap>::new(THESIS_DEMO_BASE_ADDR, THESIS_DEMO_CLAMP_TOP);

pub type ThesisOptIocap =
    GenericIocapGuaranteedTwoDepthInitialRegion<64, 12, 8, { 1 << 3 }, { 1 << 2 }, 8>;

pub const THESIS_OPT_BASE_ADDR: u64 = !0;
pub const THESIS_OPT_CLAMP_TOP: Option<u128> = None; // Some((1u128 << 64) - 1); //Some((THESIS_DEMO_BASE_ADDR as u128 & ((!0) << 36)) + (1u128 << 64)); 
pub const THESIS_OPT_BASE_ALIGN: BaseAlign<ThesisOptIocap> =
    BaseAlign::<ThesisOptIocap>::new(THESIS_OPT_BASE_ADDR, THESIS_OPT_CLAMP_TOP);
pub const THESIS_OPT_LENGTH_PRECISION: LengthPrecision<ThesisOptIocap> = LengthPrecision::<ThesisOptIocap>::new(THESIS_OPT_BASE_ADDR, THESIS_OPT_CLAMP_TOP);

pub type ThesisOptCav1Iocap = IndexCaveatOf<ThesisOptIocap, 4, true>;
pub type ThesisOptCav2Iocap = RangeCaveatOf<ThesisOptCav1Iocap, 12, true>;

pub const THESIS_OPT_CAV1_BASE_ALIGN: BaseAlign<ThesisOptCav1Iocap> =
    BaseAlign::<ThesisOptCav1Iocap>::new(THESIS_OPT_BASE_ADDR, THESIS_OPT_CLAMP_TOP);
pub const THESIS_OPT_CAV1_LENGTH_PRECISION: LengthPrecision<ThesisOptCav1Iocap> = LengthPrecision::<ThesisOptCav1Iocap>::new(THESIS_OPT_BASE_ADDR, THESIS_OPT_CLAMP_TOP);
pub const THESIS_OPT_CAV1_REDUCTION: Cavs_Reduction_Scan<ThesisOptCav2Iocap> = Cavs_Reduction_Scan::<ThesisOptCav2Iocap> {
    base: THESIS_OPT_BASE_ADDR,
    cav2: false,
    _p: PhantomData,
};

pub const THESIS_OPT_CAV12_BASE_ALIGN: BaseAlign<ThesisOptCav2Iocap> =
    BaseAlign::<ThesisOptCav2Iocap>::new(THESIS_OPT_BASE_ADDR, THESIS_OPT_CLAMP_TOP);
pub const THESIS_OPT_CAV12_LENGTH_PRECISION: LengthPrecision<ThesisOptCav2Iocap> = LengthPrecision::<ThesisOptCav2Iocap>::new(THESIS_OPT_BASE_ADDR, THESIS_OPT_CLAMP_TOP);
pub const THESIS_OPT_CAV12_REDUCTION: Cavs_Reduction_Scan<ThesisOptCav2Iocap> = Cavs_Reduction_Scan::<ThesisOptCav2Iocap> {
    base: THESIS_OPT_BASE_ADDR,
    cav2: true,
    _p: PhantomData,
};

pub type ThesisOptComplexCav1Iocap = SubalignTightIndexCaveatOf<ThesisOptIocap, 4>;
pub type ThesisOptComplexCav2Iocap = RangeCaveatOf<ThesisOptComplexCav1Iocap, 12, true>;

pub const THESIS_OPT_COMPLEX_CAV1_BASE_ALIGN: BaseAlign<ThesisOptComplexCav1Iocap> =
    BaseAlign::<ThesisOptComplexCav1Iocap>::new(THESIS_OPT_BASE_ADDR, THESIS_OPT_CLAMP_TOP);
pub const THESIS_OPT_COMPLEX_CAV1_LENGTH_PRECISION: LengthPrecision<ThesisOptComplexCav1Iocap> = LengthPrecision::<ThesisOptComplexCav1Iocap>::new(THESIS_OPT_BASE_ADDR, THESIS_OPT_CLAMP_TOP);
pub const THESIS_OPT_COMPLEX_CAV1_REDUCTION: Cavs_Reduction_Scan<ThesisOptComplexCav2Iocap> = Cavs_Reduction_Scan::<ThesisOptComplexCav2Iocap> {
    base: THESIS_OPT_BASE_ADDR,
    cav2: false,
    _p: PhantomData,
};

pub const THESIS_OPT_COMPLEX_CAV12_BASE_ALIGN: BaseAlign<ThesisOptComplexCav2Iocap> =
    BaseAlign::<ThesisOptComplexCav2Iocap>::new(THESIS_OPT_BASE_ADDR, THESIS_OPT_CLAMP_TOP);
pub const THESIS_OPT_COMPLEX_CAV12_LENGTH_PRECISION: LengthPrecision<ThesisOptComplexCav2Iocap> = LengthPrecision::<ThesisOptComplexCav2Iocap>::new(THESIS_OPT_BASE_ADDR, THESIS_OPT_CLAMP_TOP);
pub const THESIS_OPT_COMPLEX_CAV12_REDUCTION: Cavs_Reduction_Scan<ThesisOptComplexCav2Iocap> = Cavs_Reduction_Scan::<ThesisOptComplexCav2Iocap> {
    base: THESIS_OPT_BASE_ADDR,
    cav2: true,
    _p: PhantomData,
};

// See scan.rs
// TODO These are borked?
const IOCAP2024_11_BASE_ADDR: u64 = (1u64 << 54) - 1; //((1u64 << 54) - 1) & !((1u64 << 63) - 1);
pub const IOCAP2024_11_IMPRVCAV12_BASE_ALIGN: BaseAlign<Cav12IOCap2024_11_Improved> =
    BaseAlign::<Cav12IOCap2024_11_Improved>::new(IOCAP2024_11_BASE_ADDR, THESIS_OPT_CLAMP_TOP);
pub const IOCAP2024_11_IMPRVCAV12_LENGTH_PRECISION: LengthPrecision<Cav12IOCap2024_11_Improved> = LengthPrecision::<Cav12IOCap2024_11_Improved>::new(IOCAP2024_11_BASE_ADDR, THESIS_OPT_CLAMP_TOP);
pub const IOCAP2024_11_IMPRVCAV12_REDUCTION: Cavs_Reduction_Scan<Cav12IOCap2024_11_Improved> = Cavs_Reduction_Scan::<Cav12IOCap2024_11_Improved> {
    base: IOCAP2024_11_BASE_ADDR,
    cav2: true,
    _p: PhantomData,
};


pub struct Cavs_Reduction_Scan<TCav2: Caveat2> {
    pub base: u64,
    pub cav2: bool,
    _p: PhantomData<TCav2>,
}
impl<
    TCav2: Caveat2,
> LogScan for Cavs_Reduction_Scan<TCav2> {
    type T = (u64, u128);

    const HEADER: &'static str = "intended_base\tinitial_len\tsmallest_len";

    fn apply_f(&self, x: u128) -> Self::T {
        let base = self.base;
        let len = x;

        let initial_region = <TCav2::PriorRegion as Caveat1>::InitialRegion::new(base, len);
        let index_cav: TCav2::PriorRegion = TCav2::PriorRegion::smallest_reduction_of(initial_region);
        
        if self.cav2 {
            let range_cav = TCav2::smallest_reduction_of(index_cav);
            (base, range_cav.len())
        } else {
            (base, index_cav.len())
        }
    }

    fn accept_result(&mut self, x: u128, result: &Self::T) {
        println!("0x{:016x}\t0x{:016x}\t0x{:016x}", result.0, x, result.1);
    }
}

#[test]
pub fn thesis_opt_cav1_512b_representable() {
    let base = THESIS_OPT_BASE_ADDR;
    for len in 1..=512 {
        let cap_cav1 = ThesisOptCav1Iocap::new(base, len);
        assert!(
            cap_cav1.exponent_c1() <= 9,
            "cap {:?}\ninitial b 0x{:x} l 0x{:x}\ncav1    b 0x{:x} l 0x{:x}\nexponent {}",
            cap_cav1,
            cap_cav1.initial_region.base(),
            cap_cav1.initial_region.len(),
            cap_cav1.base(),
            cap_cav1.len(),
            cap_cav1.exponent_c1(),
        );
    }
}
