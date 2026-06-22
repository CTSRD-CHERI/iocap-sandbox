use crate::{
    caps::aries::AriesCap,
    scans::basic_cap::{self, BaseAlign, LengthPrecision},
};

pub const ARIES_BASE_ALIGN: BaseAlign<AriesCap> = basic_cap::BaseAlign::<AriesCap>::new(!0, None);
pub const ARIES_LENGTH_PRECISION: LengthPrecision<AriesCap> =
    basic_cap::LengthPrecision::<AriesCap>::new(!0, None);
