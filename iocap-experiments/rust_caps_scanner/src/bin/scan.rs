use std::collections::HashSet;

use rust_caps_scanner::scans::LogScan;

fn test(category: &str, secondary: &str, f: impl FnOnce()) {
    println!(
        r##"
[[{category}]]
name="{secondary}"
tsv=""""##
    );

    f();

    println!(r##"""""##);
}

/// Number of bytes used to store a complete git commit hash
const HASH_BYTES: usize = 20;

// Based on https://github.com/samcrow/git_rev.rs/blob/master/src/lib.rs#L127
fn get_git_revision() -> String {
    // Run git rev-parse HEAD to get the revision
    let output = std::process::Command::new("git")
        .args(&["rev-parse", "HEAD"])
        .output()
        .expect("git rev-parse failed :(");
    if output.status.success() {
        let stdout = output.stdout;
        let mut stdout = String::from_utf8(stdout).expect("git rev-parse returned non-utf8");
        // Expected stdout length is HASH_BYTES * 2 characters, plus one for the newline
        if stdout.len() < HASH_BYTES * 2 {
            panic!("git returned too short string {stdout}");
        }
        stdout.truncate(HASH_BYTES * 2);
        stdout
    } else {
        panic!("git rev-parse failed, code {:?}", output.status.code());
    }
}

fn main() {
    let args = std::env::args().collect::<Vec<_>>();
    assert!(
        args.len() <= 2,
        "Call with at most one argument: the set of passes to perform"
    );
    let passes = if args.len() == 2 {
        Some(args[1].split(",").map(|s| s.trim()).collect::<HashSet<_>>())
    } else {
        None
    };
    let want_pass = |name: &str| match &passes {
        Some(set) => set.contains(name),
        None => true,
    };

    let now = std::time::SystemTime::now();
    let now: chrono::DateTime<chrono::Utc> = now.into();
    let now = now.to_rfc3339();
    let revision_string = get_git_revision();

    println!(
        r##"timestamp = "{now}"
generated_by = "rust_caps_scanner"
git_hash = "{revision_string}"
    "##
    );

    if want_pass("cheriv9") {
        use rust_caps_scanner::scans::cheriv9;

        test("cheriv9", "base_align_legacy", || {
            let mut x = cheriv9::BaseAlign_Scan;
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        test("cheriv9", "length_align_legacy", || {
            let mut x = cheriv9::LengthPrecision_Scan((1u64 << 31) - 1);
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        test("cheriv9", "base_align_unified", || {
            let mut x = cheriv9::CHERIV9_BASE_ALIGN;
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        test("cheriv9", "length_align_unified", || {
            let mut x = cheriv9::CHERIV9_LENGTH_PRECISION;
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });
    }

    if want_pass("rv64y") {
        use rust_caps_scanner::scans::rv64y;

        test("rv64y", "base_align_legacy", || {
            let mut x = rv64y::BaseAlign_Scan;
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        test("rv64y", "length_align_legacy", || {
            let mut x = rv64y::LengthPrecision_Scan((1u64 << 31) - 1);
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        test("rv64y", "base_align_unified", || {
            let mut x = rv64y::RV64Y_BASE_ALIGN;
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        test("rv64y", "length_align_unified", || {
            let mut x = rv64y::RV64Y_LENGTH_PRECISION;
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });
    }

    if want_pass("cheri256") {
        use rust_caps_scanner::scans::cheri256;

        test("cheri256", "base_align_legacy", || {
            let mut x = cheri256::BaseAlign_Scan;
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        test("cheri256", "length_align_legacy", || {
            let mut x = cheri256::LengthPrecision_Scan((1u64 << 31) - 1);
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        test("cheri256", "base_align_unified", || {
            let mut x = cheri256::CHERI256_BASE_ALIGN;
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        test("cheri256", "length_align_unified", || {
            let mut x = cheri256::CHERI256_LENGTH_PRECISION;
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });
    }

    if want_pass("iocap2024_11") {
        use rust_caps_scanner::scans::iocap2024_11;

        test("iocap2024_11", "base_align_legacy", || {
            let mut x = iocap2024_11::InitialRegion_BaseAlign_Scan;
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        // All low bits set, any downwards alignment can be counted via the bottom bits.
        // Having to round the bases forces shorter lengths to be rounded up higher than they are in the optimistic case.
        const BASE_ADDR: u64 = (1u64 << 54) - 1;
        test(
            "iocap2024_11",
            "length_precision_legacy_pessimistic",
            || {
                let mut x = iocap2024_11::InitialRegion_LengthPrecision_Scan(BASE_ADDR);
                x.scan(1, (1u128 << 64) - (1u128 << 31));
            },
        );

        // In the ideal case the base is perfectly aligned and we focus entirely on aligning the length.
        test("iocap2024_11", "length_precision_legacy_optimistic", || {
            let mut x = iocap2024_11::InitialRegion_LengthPrecision_Scan(0);
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        // The semi-optimistic case demonstrates that the effect of the BASE_ADDR above is isolated only to rounding the base addresses? by removing the requirement to do so,
        // and shows it does not affect even the
        const MAX_BASE_ALIGNMENT_REQ: u64 = (1u64 << 63) - 1;
        test(
            "iocap2024_11",
            "length_precision_legacy_semioptimistic",
            || {
                let mut x = iocap2024_11::InitialRegion_LengthPrecision_Scan(
                    BASE_ADDR & (!MAX_BASE_ALIGNMENT_REQ),
                );
                x.scan(1, (1u128 << 64) - (1u128 << 31));
            },
        );
    }

    if want_pass("iocap2024_11_cavs") {
        use rust_caps_scanner::scans::iocap2024_11;

        test("iocap2024_11_cavs", "base_align_legacy", || {
            let mut x = iocap2024_11::Cavs12_BaseAlign_Scan;
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        const BASE_ADDR: u64 = (1u64 << 54) - 1;
        const MAX_BASE_ALIGNMENT_REQ: u64 = (1u64 << 63) - 1;

        test("iocap2024_11_cavs", "cav1_reduction", || {
            let mut x = iocap2024_11::Cavs_Reduction_Scan {
                base: BASE_ADDR & (!MAX_BASE_ALIGNMENT_REQ),
                cav2: false,
            };
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });

        test("iocap2024_11_cavs", "cav12_reduction", || {
            let mut x = iocap2024_11::Cavs_Reduction_Scan {
                base: BASE_ADDR & (!MAX_BASE_ALIGNMENT_REQ),
                cav2: true,
            };
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });
    }

    if want_pass("iocap2024_11_simulated_improved_cavs") {
        use rust_caps_scanner::scans::iocap_general;

        test(
            "iocap2024_11_simulated_improved_cavs",
            "base_align_unified",
            || {
                let mut x = iocap_general::IOCAP2024_11_IMPRVCAV12_BASE_ALIGN;
                x.scan(1, (1u128 << 64) - (1u128 << 31));
            },
        );

        test(
            "iocap2024_11_simulated_improved_cavs",
            "length_align_unified",
            || {
                let mut x = iocap_general::IOCAP2024_11_IMPRVCAV12_LENGTH_PRECISION;
                x.scan(1, (1u128 << 64) - (1u128 << 31));
            },
        );

        test("iocap2024_11_simulated_improved_cavs", "reduction", || {
            let mut x = iocap_general::IOCAP2024_11_IMPRVCAV12_REDUCTION;
            x.scan(1, (1u128 << 64) - (1u128 << 31));
        });
    }

    if want_pass("mmachine") {
        use rust_caps_scanner::scans::mmachine;

        test("mmachine", "base_align_unified", || {
            let mut x = mmachine::MMACHINE_BASE_ALIGN;
            x.scan(1, (1u128 << 54) - 1);
        });

        test("mmachine", "length_align_unified", || {
            let mut x = mmachine::MMACHINE_LENGTH_PRECISION;
            x.scan(1, (1u128 << 54) - 1);
        });
    }

    if want_pass("aries") {
        use rust_caps_scanner::scans::aries;

        test("aries", "base_align_unified", || {
            let mut x = aries::ARIES_BASE_ALIGN;
            x.scan(1, 1u128 << 64);
        });

        test("aries", "length_align_unified", || {
            let mut x = aries::ARIES_LENGTH_PRECISION;
            x.scan(1, 1u128 << 64);
        });
    }

    if want_pass("lowfat") {
        use rust_caps_scanner::scans::lowfat;

        test("lowfat", "base_align_unified", || {
            let mut x = lowfat::LOWFAT_BASE_ALIGN;
            x.scan(1, 1u128 << 64);
        });

        test("lowfat", "length_align_unified", || {
            let mut x = lowfat::LOWFAT_LENGTH_PRECISION;
            x.scan(1, 1u128 << 64);
        });
    }

    if want_pass("iocap_thesisdemo32") {
        use rust_caps_scanner::scans::iocap_general;

        iocap_general::check_thesis_demo();

        // The iocap thesis demo ver is incomplete: it can only represent up to 2^17 not 2^32.
        // If it could represent up to 2^32 then this would not be a problem.
        // with the rounding included, this means at most it may need to round up by 0b111 = 7.
        // therefore cap length at 2^17 - 7

        test("iocap_thesisdemo32", "base_align_unified", || {
            let mut x = iocap_general::THESIS_DEMO_BASE_ALIGN;
            x.scan(1, (1 << 17) - 0b111);
        });

        test("iocap_thesisdemo32", "length_align_unified", || {
            let mut x = iocap_general::THESIS_DEMO_LENGTH_PRECISION;
            x.scan(1, (1 << 17) - 0b111);
        });
    }

    if want_pass("iocap_thesisopt") {
        use rust_caps_scanner::scans::iocap_general;

        test("iocap_thesisopt", "base_align_unified", || {
            let mut x = iocap_general::THESIS_OPT_BASE_ALIGN;
            x.scan(1, 1u128 << 64);
        });

        test("iocap_thesisopt", "length_align_unified", || {
            let mut x = iocap_general::THESIS_OPT_LENGTH_PRECISION;
            x.scan(1, 1u128 << 64);
        });
    }

    if want_pass("iocap_thesisopt_cav1") {
        use rust_caps_scanner::scans::iocap_general;

        test("iocap_thesisopt_cav1", "base_align_unified", || {
            let mut x = iocap_general::THESIS_OPT_CAV1_BASE_ALIGN;
            x.scan(1, 1u128 << 64);
        });

        test("iocap_thesisopt_cav1", "length_align_unified", || {
            let mut x = iocap_general::THESIS_OPT_CAV1_LENGTH_PRECISION;
            x.scan(1, 1u128 << 64);
        });

        test("iocap_thesisopt_cav1", "reduction", || {
            let mut x = iocap_general::THESIS_OPT_CAV1_REDUCTION;
            x.scan(1, 1u128 << 64);
        });
    }

    if want_pass("iocap_thesisopt_cav12") {
        use rust_caps_scanner::scans::iocap_general;

        test("iocap_thesisopt_cav12", "base_align_unified", || {
            let mut x = iocap_general::THESIS_OPT_CAV12_BASE_ALIGN;
            x.scan(1, 1u128 << 64);
        });

        test("iocap_thesisopt_cav12", "length_align_unified", || {
            let mut x = iocap_general::THESIS_OPT_CAV12_LENGTH_PRECISION;
            x.scan(1, 1u128 << 64);
        });

        test("iocap_thesisopt_cav12", "reduction", || {
            let mut x = iocap_general::THESIS_OPT_CAV12_REDUCTION;
            x.scan(1, 1u128 << 64);
        });
    }

    if want_pass("iocap_thesisopt_cav1_complex") {
        use rust_caps_scanner::scans::iocap_general;

        test("iocap_thesisopt_cav1_complex", "base_align_unified", || {
            let mut x = iocap_general::THESIS_OPT_COMPLEX_CAV1_BASE_ALIGN;
            x.scan(1, 1u128 << 64);
        });

        test(
            "iocap_thesisopt_cav1_complex",
            "length_align_unified",
            || {
                let mut x = iocap_general::THESIS_OPT_COMPLEX_CAV1_LENGTH_PRECISION;
                x.scan(1, 1u128 << 64);
            },
        );

        test("iocap_thesisopt_cav1_complex", "reduction", || {
            let mut x = iocap_general::THESIS_OPT_COMPLEX_CAV1_REDUCTION;
            x.scan(1, 1u128 << 64);
        });
    }

    if want_pass("iocap_thesisopt_cav12_complex") {
        use rust_caps_scanner::scans::iocap_general;

        test(
            "iocap_thesisopt_cav12_complex",
            "base_align_unified",
            || {
                let mut x = iocap_general::THESIS_OPT_COMPLEX_CAV12_BASE_ALIGN;
                x.scan(1, 1u128 << 64);
            },
        );

        test(
            "iocap_thesisopt_cav12_complex",
            "length_align_unified",
            || {
                let mut x = iocap_general::THESIS_OPT_COMPLEX_CAV12_LENGTH_PRECISION;
                x.scan(1, 1u128 << 64);
            },
        );

        test("iocap_thesisopt_cav12_complex", "reduction", || {
            let mut x = iocap_general::THESIS_OPT_COMPLEX_CAV12_REDUCTION;
            x.scan(1, 1u128 << 64);
        });
    }
}
