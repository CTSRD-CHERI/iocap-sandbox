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

TODO

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
# Run the caps scanner experiment, generating results.toml.
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

The graphs from Chapter 5 can all be replicated (albeit without the same formatting, as the code to generate the final graphs is embedded in the thesis text itself **TODO link to that repository**) with these commands.

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

The M-Machine format.

```
aries.base_align_unified
aries.length_align_unified
```

The Aries format.


```
lowfat.base_align_unified
lowfat.length_align_unified
```

The Low-Fat format.

```
iocap_thesisdemo32.base_align_unified
iocap_thesisdemo32.length_align_unified
```

A demo format for my generic IOCap implementation using the 32-0-8-3-1-1 format described in section 5.3.1.

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

## Chapter 5/6/7 - IOCap Implementation Libraries & Testing

TODO

The different implementations are found in `iocap-experiments`:

- 

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
