# IOCap Sandbox

This repository (WIP) contains all of the relevant programs, hardware designs, experiments, and results used in the creation of Samuel W. Stark's PhD thesis.
Please contact [samuel.stark@cl.cam.ac.uk](mailto:samuel.stark@cl.cam.ac.uk) if you have any questions.

## Checking out

This repository contains many submodules, which hold most of the relevant code.
If checking out all content, I recommend using `--depth=1` to avoid downloading redundant data, especially from CheriBSD which is a large repository.

```
$ git submodule update --init --recursive --depth=1
```

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
$ just rebuild_freertos_sim     # Build CheriFreeRTOS for simulation
$ just build_de10_bluesim       # Build a Bluespec simulation of the DE10 SoC
$ just run-de10-sim-freertos    # Run the Bluespec simulation using the FreeRTOS ELF binary
# once you are finished, hit Ctrl-C to interrupt - the simulation will take ~1 second to cleanly shut down.

# (in another window)
$ just watch-de10-sim           # watch the RVFI log of instructions executed by the DE10 SoC
# or
$ just watch-de10-uart          # watch the UART log of prints from CheriFreeRTOS
```

## Chapter 6 - Run CheriFreeRTOS on QEMU

TODO test this

```bash
$ just rebuild_freertos_qemu       # Build CheriFreeRTOS for QEMU
$ just build_qemu                  # Build QEMU

$ just run-qemu-freertos           # Run CheriFreeRTOS inside a QEMU that has IOCap-enabled VirtIO devices
# or
$ just run-qemu-freertos-noiocap   # Run CheriFreeRTOS inside a QEMU that has VirtIO devices *without IOCap support*.

# While it's running, visit http://localhost:2222/freertos.html to get a webpage served from IOCaps!
```

## Chapter 6 - Run CheriBSD on QEMU

TODO test this

```bash
$ just build_qemu
$ just build_cheribsd_qemu
$ just run-qemu-cheribsd
# or
$ just run-qemu-cheribsd-noiocap

# TODO what should you do once inside?
```

## Chapter 6 - Generate CheriBSD Diff

TODO

## Chapter 7 - IOCap Hardware UVM Testing/Benchmarking

TODO

## Chapter 7 - IOCap Hardware Synthesis Benchmarks

TODO
