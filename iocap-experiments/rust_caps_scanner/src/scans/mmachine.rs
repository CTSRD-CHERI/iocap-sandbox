use crate::{
    caps::mmachine::MMachineCap,
    scans::basic_cap::{self, BaseAlign, LengthPrecision},
};

pub const MMACHINE_BASE_ALIGN: BaseAlign<MMachineCap> =
    basic_cap::BaseAlign::<MMachineCap>::new((1u64 << 54) - 1, Some(1u128 << 54));
pub const MMACHINE_LENGTH_PRECISION: LengthPrecision<MMachineCap> =
    basic_cap::LengthPrecision::<MMachineCap>::new((1u64 << 54) - 1, Some(1u128 << 54));
