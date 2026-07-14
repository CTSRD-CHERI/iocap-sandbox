# IOCap Sandbox

This repository (WIP) contains all of the relevant programs, hardware designs, experiments, and results used in the creation of Samuel W. Stark's PhD thesis.
Please contact [samuel.stark@cl.cam.ac.uk](mailto:samuel.stark@cl.cam.ac.uk) if you have any questions.

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

TODO

## Chapter 5/6/7 - IOCap Implementation Libraries & Testing

TODO

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

```
Logging in as root...
2026-07-14T15:12:31.702978+00:00 - login 82 - - login on console as root
#
```

Inside, you can make a results directory in the ramdisk, and then run `./bench/bench.sh` (note: different from the plain `bench` command) to run some fio benchmarks.

```
# mkdir -p ./results/
# ./bench/bench.sh ./results/
```

Exit QEMU by running `poweroff` - using the Ctrl+A - X method may corrupt the disk image.

```
# poweroff

Shutdown NOW!
poweroff: [pid 109]
#
*** FINAL System shutdown message from root@ ***

System going down IMMEDIATELY
```

## Chapter 6 - Generate CheriBSD Diff

TODO

## Chapter 7 - IOCap Hardware UVM Testing/Benchmarking

TODO

## Chapter 7 - IOCap Hardware Synthesis Benchmarks

TODO

## Chapter 7 - Full-System Build

TODO
