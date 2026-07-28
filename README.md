# IOCap Sandbox

This repository (WIP) contains all of the relevant programs, hardware designs, experiments, and results used in the creation of Samuel W. Stark's PhD thesis.
Please contact [samuel.stark@cl.cam.ac.uk](mailto:samuel.stark@cl.cam.ac.uk) if you have any questions.
Note: all references to figures and chapters are up-to-date as of the initial submission, I don't expect them to change significantly post-corrections but they might.

## Checking out

This repository contains many submodules, which hold most of the relevant code.
If checking out all content, I recommend using `--depth=1` to avoid downloading redundant data, especially from CheriBSD which is a large repository.

```bash
$ git submodule update --init --recursive --depth=1
```

TODO theturboturnip/cheribsd and theturboturnip/tinyemu-virtio should be migrated over to CTSRD-CHERI. The others may be less consequential?


## Dependencies

This repository uses some external tools that should be installed directly.

- Bash shell (I assume you already have this.)
- The Rust programming language <https://rust-lang.org/tools/install/>.
- The Bluespec hardware design language <https://github.com/B-Lang-org/bsc/releases/tag/2023.07> (version 2023.07 preferred, later ones might break).
- The Just command runner <https://github.com/casey/just>.
- The UV Python package manager <https://docs.astral.sh/uv/> to orchestrate and run the tests and experiments.
- The Haskell programming language <https://www.haskell.org/ghcup/>, when building the DE10Pro-cheri-bgas SoC.

Other dependencies can be installed via your system package manager - see the `Justfile` for some more details on why each one is needed.

```bash
# Basic CHERIBuild dependencies
$ apt install autoconf automake libtool pkg-config clang bison cmake mercurial ninja-build samba flex texinfo time libglib2.0-dev libpixman-1-dev libarchive-dev libarchive-tools libbz2-dev libattr1-dev libcap-ng-dev libexpat1-dev libgmp-dev bc tzdata
# Others... see Justfile
$ apt install libelf-dev
$ apt install libfuse3-dev
$ apt install fusefat dosfstools
$ apt install device-tree-compiler
$ apt install libgmp-dev libmpfr-dev
# OpenSSL used by the Rust IOCap implementations
$ apt install libssl-dev
```

Once these tools are installed, you should be able to run various experiments.

```bash
# Prerequisite for all experiments
$ just install_venv             # Set up Python using UV
```

# Experiments

TODO write a bit about this, explain the original results for the thesis are in results/thesis, explain that they can be replicated and compared.

## Chapter 4 - NVMe Simulations

The Chapter 4 evaluation uses [an NVMe queue simulation in `iocap-experiments/nvmesim`](./iocap-experiments/nvmesim`) to model the behaviour of lease allocation under in-order and out-of-order op completion.
These simulations are configured using TOML files, where each file describes a different simulation context.
Each context consists of a latency histogram for read operations (write operations are included in the config but are not modelled, because modeling them separately would be equivalent to modelling reads with a different histogram), the IOPS number, the number of ops per queue, the number of queues, and a set of IOCap $L_\text{ops}$ values to model.
The simulation then runs, generating new ops at a rate equal to IOPS, and sampling the histogram to determine how long they take to complete.
A separate `IOCapLeaseContext` for every $L_\text{ops}$ value for each queue (and one per $L_\text{ops}$ value for all queues combined) run in parallel, measuring the number of leases that would need to be open concurrently to handle the ops, and how long those leases are open for.
The outputs are stored in `iocap-experiments/nvmesim/nvme_queue_results`.

You can rerun the experiments with a single command:

```bash
# Run all of them
$ just iocap-experiments/nvmesim/run-all
```

These will take a little while, roughly 10min on my PC, as the simulation is single-threaded and written in Python.
Not all the simulations run are actually used in the thesis, and that subset can be run manually (approx 4mins):

```bash
# Run just the simulations for the thesis
$ just iocap-experiments/nvmesim/run-thesis
```

The thesis uses data from the following simulations:

> ```just
> run-thesis:
>     # Figure 4.3, Table 4.2
>     just run in_order_q08 1
>     just run in_order_q32 2
>
>     # Figure 4.6, Table 4.3
>     just run out_order_q32_nq1 4
>     just run out_order_q128_nq1_unsaturated 14
>
>     # Figure 4.8, Table 4.4, Figure 4.10
>     just run out_order_q16_nq8_unsaturated 15
>
>     # Figure 4.11, 4.12, Table 4.5, 4.6
>     just run out_order_haas_q09 13
>     just run out_order_haas_q10 16
> ```

The graphs in the thesis are generated at document build time using the relevant output TOML files, so there isn't a convenient way to replicate them here.
This includes the latency distribution graphs (Figs 4.6a, 4.11) which are generated from the `"exposed_to_completed"` latency entries of a specific queue from the relevant results TOML.
These have been manually checked to match the input histograms specified in the configs, which are generated using the `gen_nvme_dist.py` script:

```bash
# The out-of-order latency in Fig 4.6a:
# - average 50us
# - max out at t_max=100us
# - with a 20us-wide steep line before the "split point"
# - where the split point is the 90th percentile
# - and t_max is the 100th percentile
$ uv run ./iocap-experiments/nvmesim/gen_nvme_dist.py  50000 100000 20000 --split 0.9 --t_max_pos 1
# The out-of-order latency in Fig 4.11
# - average 175us
# - max out at t_p99 = 400us
# - with a 20us-wide steep line before the split point (i.e. assuming the 400us is a far outlier)
# - where the split point is the 90th percentile
# - and t_p99 is the 99th percentile
$ uv run ./iocap-experiments/nvmesim/gen_nvme_dist.py 175000 400000 20000 --split 0.9 --t_max_pos 0.99
```

## Chapter 5 - Capability Format Simulations

The capability precision and reduction diagrams in the Evaluation section of Chapter 5 (Figs. 5.13-5.20) are generated based on results from the ["rust_caps_scanner" program](./iocap-experiments/rust_caps_scanner).
This program simulates many capability formats on top of the tested IOCap formats, and the results were used to manually double check other tables and assertions about those other formats in the text.
Each format is scanned multiple times for different properties.
Each scan is based on a monotonic function `f(x) -> y` (e.g. `f(x)` could encode a capability with a fixed base address of length `x` and return the precision of the length encoding).
`x` is incremented by a `step`, which doubles until `f(x)` changes, at which point the gap between the last known `x` and `x + step` is binary-searched for the transition point.
This allows the whole space between 1 and $2^{64}$ to be searched very quickly, as there are few transition points - in these diagrams, `f(x)` typically ranges between 0 and 64.
The full scanning logic can be found in [`scans.rs`](./iocap-experiments/rust_caps_scanner/src/scans.rs).
The output is saved in [`./iocap-experiments/rust_caps_scanner/results/format_results.toml`](./iocap-experiments/rust_caps_scanner/results/format_results.toml).

```bash
# Run the caps scanner experiment, generating format_results.toml.
$ just iocap-experiments/run-cap-scan
```

A basic visualisation of these results can be generated with matplotlib:

```bash
# Plot a base-precision and length-precision graph, each comparing all formats
$ just iocap-experiments/show-cap-scan
$ just iocap-experiments/show-cap-scan bl

# Plots a single combined base+length graph for each format
$ just iocap-experiments/show-cap-scan caps
# Pass arguments to limit to specific formats
$ just iocap-experiments/show-cap-scan caps:cheriv9,iocap_thesisopt_cav12_complex

# Plot separate base and length graphs for each format
$ just iocap-experiments/show-cap-scan split:cheriv9,iocap_thesisopt_cav12_complex

# Plot a separate graph of reduction potential for each format
$ just iocap-experiments/show-cap-scan reduct:iocap_thesisopt_cav1_complex,iocap_thesisopt_cav12_complex

# Plot a comparison of the given formats' base and length precision
$ just iocap-experiments/show-cap-scan compare:cheriv9,iocap_thesisopt_cav12
# Plot a comparison of the given formats' reduction
$ just iocap-experiments/show-cap-scan compareduct:iocap_thesisopt_cav1_complex,iocap_thesisopt_cav12_complex
```

The graphs from Chapter 5 can all be replicated with these commands.

```bash
# (Fig 5.13)
$ just iocap-experiments/show-cap-scan caps:iocap_thesisopt
# (Fig 5.14)
$ just iocap-experiments/show-cap-scan caps:iocap2024_11
# (Fig 5.15)
$ just iocap-experiments/show-cap-scan iocap_thesisopt:reduct
# (Fig 5.16)
$ just iocap-experiments/show-cap-scan iocap2024_11:reduct
# (Fig 5.17)
$ just iocap-experiments/show-cap-scan compare:iocap_thesisopt,iocap_thesisopt_cav1,iocap_thesisopt_cav12
# (Fig 5.18)
$ just iocap-experiments/show-cap-scan compare:cheriv9,iocap_thesisopt_cav12
# (Fig 5.19)
$ just iocap-experiments/show-cap-scan compareduct:iocap_thesisopt_cav1_complex,iocap_thesisopt_cav12_complex
# (Fig 5.20)
$ just iocap-experiments/show-cap-scan compare:cheriv9,iocap_thesisopt_cav1_complex,iocap_thesisopt_cav12_complex
```

They will not have the same formatting as in the thesis, but they originate from the same data.
The thesis itself is written in [turnip_text](https://github.com/theturboturnip/turnip_text), a document description language of my own design, which uses embedded Python snippets to parse [format_results.toml](./iocap-experiments/rust_caps_scanner/results/format_results.toml) and generate bespoke matplotlib plots.

### Scans

Here is an exhaustive list of the scans.

```
cheriv9.base_align_legacy
cheriv9.length_align_legacy
cheriv9.base_align_unified
cheriv9.length_align_unified
```

CHERI ISAv9 scans, both "legacy" (with a bespoke scanning function for the format) and "unified" (using a generic scanning function over a capability trait), which return the same results.
Implemented using the canonical [cheri-compressed-cap](https://github.com/CTSRD-CHERI/cheri-compressed-cap) C library, specifically [my fork](https://github.com/theturboturnip/cheri-compressed-cap) with Rust bindings.
**TODO get the Rust bindings upstreamed**

```
rv64y.base_align_legacy
rv64y.length_align_legacy
rv64y.base_align_unified
rv64y.length_align_unified
```

Scans for the RISC-V RV64Y format, both "legacy" (with a bespoke scanning function for the format) and "unified" (using a generic scanning function over a capability trait), which return the same results.
Identical to CHERI ISAv9, though the internal implementation is slightly different (I believe the subnormal or "internal exponent" flag is inverted, for example).
Implemented using the canonical [cheri-compressed-cap](https://github.com/CTSRD-CHERI/cheri-compressed-cap) C library, specifically [my fork](https://github.com/theturboturnip/cheri-compressed-cap) with Rust bindings.
**TODO get the Rust bindings upstreamed**

```
cheri256.base_align_legacy
cheri256.length_align_legacy
cheri256.base_align_unified
cheri256.length_align_unified
```

Scans for the CHERI-256 format, both "legacy" (with a bespoke scanning function for the format) and "unified" (using a generic scanning function over a capability trait), which return the same results.
Full precision throughout, as expected from the larger format.
Implemented using the canonical [cheri-compressed-cap](https://github.com/CTSRD-CHERI/cheri-compressed-cap) C library, specifically [my fork](https://github.com/theturboturnip/cheri-compressed-cap) with Rust bindings.
**TODO get the Rust bindings upstreamed**

```
iocap2024_11.base_align_legacy
iocap2024_11.length_precision_legacy_pessimistic
iocap2024_11.length_precision_legacy_optimistic
iocap2024_11.length_precision_legacy_semioptimistic
iocap2024_11_cavs.base_align_legacy
iocap2024_11_cavs.cav1_reduction
iocap2024_11_cavs.cav12_reduction
iocap2024_11_simulated_improved_cavs.base_align_unified
iocap2024_11_simulated_improved_cavs.length_align_unified
iocap2024_11_simulated_improved_cavs.reduction
```

The IOCap-VirtIO format, including the initial region `iocap2024_11`, index caveat `iocap2024_11_cavs.cav1_reduction`, range caveat `iocap2024_11_cavs.cav12_reduction`, and a variant that allows the range caveat to use a nonzero `x` in the null case `iocap2024_11_simulated_improved_cavs`.

`length_precision_legacy_{pessimistic,optimistic,semioptimistic}` are the same test using more-aligned or less-aligned base addresses - for the thesis, extremely poorly aligned base addresses are always used. 

```
mmachine.base_align_unified
mmachine.length_align_unified
```

The M-Machine format, which I implemented manually in Rust.

```
aries.base_align_unified
aries.length_align_unified
```

The Aries format, which I implemented manually in Rust.


```
lowfat.base_align_unified
lowfat.length_align_unified
```

The Low-Fat format, which I implemented manually in Rust.

```
iocap_thesisdemo32.base_align_unified
iocap_thesisdemo32.length_align_unified
```

A generic IOCap initial-region implementation, configured to use the 32-0-8-3-1-1 format described in section 5.3.1.

```
iocap_thesisopt.base_align_unified
iocap_thesisopt.length_align_unified
iocap_thesisopt_cav1.base_align_unified
iocap_thesisopt_cav1.length_align_unified
iocap_thesisopt_cav1.reduction
iocap_thesisopt_cav12.base_align_unified
iocap_thesisopt_cav12.length_align_unified
iocap_thesisopt_cav12.reduction
iocap_thesisopt_cav1_complex.base_align_unified
iocap_thesisopt_cav1_complex.length_align_unified
iocap_thesisopt_cav1_complex.reduction
iocap_thesisopt_cav12_complex.base_align_unified
iocap_thesisopt_cav12_complex.length_align_unified
iocap_thesisopt_cav12_complex.reduction
```

The "optimal" format used in the thesis, with the initial region `iocap_thesisopt`, both initial caveats `iocap_thesisopt_cav1` & `iocap_thesisopt_cav12`, and variants with the improved index caveat `iocap_thesisopt_cav1_complex` & `iocap_thesisopt_cav12_complex`.

## Chapter 5/6/7 - IOCap Software Implementations

- `iocap-experiments/rust_caps`: The initial Rust implementation.
  - Includes three versions: v1, a rough first attempt which encodes three caveats; v2024_02, which mostly matches the format presented in Chapter 5, but doesn't support the 'null case' for caveats; and v2024_11, which supports 'null' caveats.
  - v2024_11 only supports null caveats where 'index' = 0 or 'x' = 0 (see sections 5.3.3 & 5.3.4), and it does *not* support the improved index caveat (section 5.5.4).
  - The library can link against OpenSSL or use a handrolled AES implementation (which I would not recommend in practice, and was mostly developed to familiarize myself with AES concepts).
  - The library includes functions to generate random IOCaps.
    - Valid IOCaps and 'edge case' IOCaps can be generated, where the different 'edge cases' are enumerated in `rust_caps/src/capability/v2024_{02,11}/rand.rs`.
  - `iocap-experiments/rust_caps_c` packages this crate into a `.a` static library and `.h` C header file. A vendored version of this library is used to generate random IOCaps for hardware testbenches.
- `iocap-experiments/rust_caps_scanner` includes implementations of the M-Machine, Aries, and Low-Fat capabilties alongside a paramaterizable IOCap in `rust_caps_scanner/src/caps`.
  - This includes a parameterized initial resource e.g. for the "optimal" 64-12-8-3-2-8 format:
    ```rust
    pub type ThesisOptIocap =
    GenericIocapGuaranteedTwoDepthInitialRegion<64, 12, 8, { 1 << 3 }, { 1 << 2 }, 8>;
    ```
  - and caveat implementations e.g. for the improved (15-4 index) and (12-12 range) caveats presented in section 5.5.4:
    ```rust
    pub type ThesisOptComplexCav1Iocap = SubalignTightIndexCaveatOf<ThesisOptIocap, 4>;
    pub type ThesisOptComplexCav2Iocap = RangeCaveatOf<ThesisOptComplexCav1Iocap, 12, true>;
    ```
  - See `iocap-experiments/rust_caps_scanner/src/scans/iocap_general.rs` for more examples.
- `iocap-experiments/python_caps` contains three cycle-level Python decoders, which were used to design the hardware versions.
  - `cap2024_02_decoder_test.py` for v2024_02
  - `cap2024_11_decoder_test.py` for an older version of v2024_11
  - `cap2024_11_2026_04_decoder_test.py` for the "optimal" format described in the thesis. The differences from v2024_11 are marked with `# 2026_04` comments. It allows null caveats only when 'index' = 0 or 'x' = 0, and it does *not* support the improved index caveat (section 5.5.4).
- `iocap-experiments/libccap` contains pure C implementations of an encoder and decoder for the v2024_11 format described in the thesis. It allows null caveats only when 'index' = 0 or 'x' = 0, and it does *not* support the improved index caveat (section 5.5.4).
  - This implementation is used for the `tinyemu` peripheral emulator, the CheriFreeRTOS drivers, and the CheriBSD drivers.

### Testing the Software

The `rust_caps` crate is the golden model, from which all test vectors are generated.
The `rust_caps_testgen` crate generates `:`-separated CSV files for different permuatations of valid and edge-case IOCaps using `rust_caps`.
Examples of these files can be found in the `iocap-experiments/tests_cap{2024_02,2024_11,2024_11_2026_04}` folders, and the latter can be regenerated:

```bash
# Generate iocap-experiments/tests_cap_2024_11_2026_04, which includes edge cases for null range caveats. 
$ just iocap-experiments/gen-2026-tests
```

The Python implementation can be tested against the 2024_11_2026_04 test vectors, which also tests that the 2024_11 impl *fails* under those vectors:

```bash
$ just iocap-experiments/validate-python-2026
```

which should give the following output:

```
<a Python RuntimeError trace>
Cap2024_11 basic failed, as expected
Cap2024_11 2026_04 didn't fail!
Cap2024_11 2026_04 didn't fail!
```

`libccap` can also be tested against the 2024_11_2026_04 test vectors.
This command also tests it against the plain 2024_11 vectors, as the 2026_04 variant is strictly more permissive.

```bash
$ just iocap-experiments/validate-libccap-2026
```

which will produce a set of non-fatal errors related to the improved index caveat (section 5.5.4), but will not fail.

```
570 Non-fatal: reencoding line 572 with ccap2024_11_init_virtio_cavs_exact() produced an error CCapResult_Encode_UnrepresentableBaseRange, ignoring because this is likely due to index caveat being bad (thesis $5.5.4)
Non-fatal: reencoding line 572 with ccap2024_11_init_cavs_exact() produced an error CCapResult_Encode_UnrepresentableBaseRange, ignoring because this is likely due to index caveat being bad (thesis $5.5.4)
```

This is because the tests are built around decoding the IOCap, then attempting to re-encode it from the decoded range.
Certain edge cases rely on specific values of the non-improved index caveat which the encoding algorithm will not arrive at normally.
For example, instead of starting from a very large initial region, then using the improved index caveat to select a reduced cav-1 range entirely inside that, the re-encode will start from a tight initial region and be forced to use a null cav-1 which doesn't reduce.
Using the improved index caveat from section 5.5.4 and allowing null index caveats where 'index' != 0 would make the encoder more flexible.

## Chapter 6 - Run FreeRTOS on DE10 SoC in Simulation

This is not fast enough to be truly useful, but is a fine litmus test to make sure none of your hardware is irretrievably broken.

```bash
# Build CheriFreeRTOS for simulation.
# The FreeRTOS build system is prone to race conditions, so if it fails with
# e.g. "unable to find library -lfreertos_tcpip" just try again a few times.
$ just rebuild_freertos_sim
$ just build_de10_bluesim       # Build a Bluespec simulation of the DE10 SoC
$ just run-de10-sim-freertos    # Run the Bluespec simulation using the FreeRTOS ELF binary
```

Leave this running and open another terminal window.
You can watch the output from the UART with another command.

```bash
# (in another window)
$ just watch-de10-sim           # watch the RVFI log of instructions executed by the DE10 SoC
# or
$ just watch-de10-uart          # watch the UART log of prints from CheriFreeRTOS
```

Once you are finished, hit Ctrl-C to interrupt - the simulation will take ~1 second to cleanly shut down.

## Chapter 6 - Run CheriFreeRTOS on QEMU

```bash
# Build CheriFreeRTOS for QEMU, will also build a compatible version of CHERI-LLVM so will take a while.
# The FreeRTOS build system is prone to race conditions, so if it fails with
# e.g. "unable to find library -lfreertos_tcpip" just try again a few times.
$ just rebuild_freertos_qemu
# Make sure we check out the exact correct revision of CHERI-LLVM for the BBL bootloader.
$ just pin_cheribsd_versions
# Build QEMU and the BBL bootloaders. Note that the qemu source is inside os-cheribsd/qemu,
# because the bootloaders are built using a different CHERI-LLVM used for CheriBSD,
# so this will build CHERI-LLVM a second time.
# A faster way to go about this would be to build a separate copy of the bootloaders
# using the FreeRTOS CHERI-LLVM, but I haven't tested this.
$ just build_qemu

$ just run-qemu-freertos           # Run CheriFreeRTOS inside a QEMU that has IOCap-enabled VirtIO devices
# or
$ just run-qemu-freertos-noiocap   # Run CheriFreeRTOS inside a QEMU that has VirtIO devices *without IOCap support*.
```

You will see a set of log lines "virtioblk_tranfer failed! type=X, status = 255", this is unrelated to IOCaps - I believe it's part of the disk test suite that runs before the server.

While it's running, visit <http://localhost:2222/freertos.html> to get a webpage served from IOCaps!

Exit QEMU with Ctrl+A - X.

## Chapter 6 - Run CheriBSD on QEMU

First, build CheriBSD and QEMU.

```bash
# Make sure we check out the exact correct revision of CHERI-LLVM for CheriBSD and the BBL bootloader.
$ just pin_cheribsd_versions
# Build CheriBSD, which will also build the CheriBSD-specific revision of CHERI-LLVM if needed.
$ just build_cheribsd_qemu
# Build QEMU, which uses standard host Clang, and the BBL bootloaders, which will use the CheriBSD-CHERI-LLVM built previously.
$ just build_qemu
```

This is sufficient to boot into IOCap-powered BSD.
Next, build the benchmarking tool.

```bash
# Build a cross-compiler to a CheriBSD-compatible hybrid ABI, where compiled programs use raw pointers instead of capabilities
# but can opt into capabilities if desired.
$ just build_hybrid_sdk_cheribsd 
# Cross-compile the fio benchmark tool using the hybrid ABI.
# I used the hybrid ABI to avoid having to diagnose/fix pointer problems in fio.
$ just build_fio_cross_compile
# Build the disk image for CheriBSD, which contains cheri-fio and benchmarking scripts
$ just build_cheribsd_diskimg
```

Building the disk image will ask you some questions about SSH keys to include in the image.
These don't matter, at least in my run flows, as other methods are used to interact with the session.

Once that has finished, CheriBSD can be run with the disk image attached.

```bash
$ just run-qemu-cheribsd           # Run CheriBSD inside a QEMU that has IOCap-enabled VirtIO devices
# or
$ just run-qemu-cheribsd-noiocap   # Run CheriBSD inside a QEMU that has VirtIO devices *without IOCap support*.
```

You should see a few `<VirtIO Block Adapter (IOCap)>`s roll by in the boot log.
Once you see the following, the system will be fully booted.

> ```
> Logging in as root...
> 2026-07-14T15:12:31.702978+00:00 - login 82 - - login on console as root
> #
> ```
>
> Inside, you can make a results directory in the ramdisk, and then run `./bench/bench.sh` (note: different from the plain `bench` command) to run some fio benchmarks.
>
> ```
> # mkdir -p ./results/
> # ./bench/bench.sh ./results/
> ```
>
> Exit QEMU by running `poweroff` - using the Ctrl+A - X method may corrupt the disk image.
>
> ```
> # poweroff
>
> Shutdown NOW!
> poweroff: [pid 109]
> #
> *** FINAL System shutdown message from root@ ***
>
> System going down IMMEDIATELY
> ```

## Chapter 6 - Generate CheriBSD Diff

TODO

## Chapter 7 - IOCap Hardware UVM Testing/Benchmarking

TODO

## Chapter 7 - IOCap Hardware Synthesis Benchmarks

TODO

## Chapter 7 - Full-System Build

TODO
