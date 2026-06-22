use crate::{
    caps::lowfat::LowFatCap,
    scans::basic_cap::{self, BaseAlign, LengthPrecision},
};

pub const LOWFAT_BASE_ALIGN: BaseAlign<LowFatCap> =
    basic_cap::BaseAlign::<LowFatCap>::new((1u64 << 46) - 1, None); // Some((1u128 << 65) - 1));
pub const LOWFAT_LENGTH_PRECISION: LengthPrecision<LowFatCap> =
    basic_cap::LengthPrecision::<LowFatCap>::new((1u64 << 46) - 1, None); // Some((1u128 << 65) - 1));
