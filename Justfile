# Requires the following:
# - cmake version>=3.10 in PATH, for building CheriBSD and tinyemu-virtio
#   - can be installed through system package manager `sudo apt-get install cmake`
# - libstdc++ for freertos TODO UNSURE IF THIS IS NECESSARY ANYMORE
#   - I installed this with `sudo apt-get install libstdc++-12-dev`
# - libelf for tinyemu-virtio
#   - can be installed through system package manager `sudo apt-get install libelf-dev`
# - python3.6+ for cheribuild
# - python library elftools, for `elfmanip` which converts ELF files to hex files that CHERI Toooba can run
# - python library pyyaml, for bluespec generation of CHERI tag controller files
#   - these are both automatically installed in a virtual environment
# - bluespec, for building hardware+simulations
#   - including the BLUESPECDIR env variable pointing at `$(dirname $(which bsc))/../lib`
# - fusermount3, through the fuse3 library
#   - The runtime library should be available on new Ubuntu distributions by default
#   - Dev headers are also necessary, available through `sudo apt-get install libfuse3-dev`
#   - note this is fuse3 NOT fuse - the `fuse` package can break ubuntu systems
# - fusefat, available through `sudo apt-get install fusefat`, for generating the virtio disk image for FreeRTOS to read
# - Haskell with `cabal` for `vipbundle` for full elaboration (DE10 `make clean` also requires it)
# - `build_de10_bitfiles` requires the `dtc` device tree compiler program
#   - can be installed through system package manager `sudo apt-get install device-tree-compiler`
# - GMP and MPFR for building native Cheri-aware gdb
#   - can be installed through system package manager `sudo apt-get install libgmp-dev libmpfr-dev`
# - dosfstools for mkfs.vfat
#   - `sudo apt-get install dosfstools`
#   - on some systems this is not on the PATH - try `ln -s /usr/sbin/mkfs.vfat ~/.local/bin/` to symlink it to your PATH.

# The python3 virtual environment path, initialized with install_venv
PYTHON3_VENV := justfile_directory() / ".venv"

# The path for non-cheribuild build files
BUILD_DIR := "./build"
# The location of the hex file to generate from FREERTOS_ELF_FILE, which is then loaded into the Toooba memory map
TOOOBA_FREERTOS_HEX := BUILD_DIR / "tooba_freertos.hex"
# The location of the userspace filesystem directory containing fmem_{read,write}able virtual devices
FUSE_DIR := "/tmp/fuse"
# The directory for storing output files
OUTPUT_DIR := "./output"
# Empty disk img used for scratch stuff (?)
EMPTY_DISK_IMG := BUILD_DIR / "empty_disk.img"
FREERTOS_DISK_IMG := BUILD_DIR / "freertos_fs.img"
# The location of the generated directory holding fpga-relevant contents to upload to a server
FPGA_DIR := "./fpga/current"

# --------------
#    FreeRTOS
# --------------
# The CHERIBUILD output folders for freertos. Use separate environments for building simulation and FPGA outputs
FREERTOS_CHERIBUILD_SRC_ROOT    := "./os-freertos/working"
FREERTOS_CHERIBUILD_SIM_BUILD   := FREERTOS_CHERIBUILD_SRC_ROOT / "build_sim"
FREERTOS_CHERIBUILD_SIM_OUTPUT  := FREERTOS_CHERIBUILD_SRC_ROOT / "output_sim"
FREERTOS_CHERIBUILD_QEMU_BUILD  := FREERTOS_CHERIBUILD_SRC_ROOT / "build_qemu"
FREERTOS_CHERIBUILD_QEMU_OUTPUT := FREERTOS_CHERIBUILD_SRC_ROOT / "output_qemu"
FREERTOS_CHERIBUILD_FPGA_BUILD  := FREERTOS_CHERIBUILD_SRC_ROOT / "build_sim"
FREERTOS_CHERIBUILD_FPGA_OUTPUT := FREERTOS_CHERIBUILD_SRC_ROOT / "output_fpga"
# The target we compile FreeRTOS for
FREERTOS_ELF_TARGET := "baremetal-riscv64-purecap"
# FREERTOS_ELF_TARGET := "baremetal-riscv64"
# The FreeRTOS demo we compile
FREERTOS_ELF_DEMO   := "servers"
# The path of the compiled FreeRTOS ELF file
FREERTOS_SIM_ELF_FILE  :=  FREERTOS_CHERIBUILD_SIM_OUTPUT / "sdk/baremetal" / FREERTOS_ELF_TARGET / "riscv64-unknown-elf/FreeRTOS/Demo/bin/RISC-V-Generic_main_" + FREERTOS_ELF_DEMO + ".elf"
FREERTOS_SIM_BUILDHASH := FREERTOS_CHERIBUILD_SIM_OUTPUT / "freertos.buildhash"
FREERTOS_QEMU_ELF_FILE := FREERTOS_CHERIBUILD_QEMU_OUTPUT / "sdk/baremetal" / FREERTOS_ELF_TARGET / "riscv64-unknown-elf/FreeRTOS/Demo/bin/RISC-V-Generic_main_" + FREERTOS_ELF_DEMO + ".elf"
FREERTOS_QEMU_BUILDHASH := FREERTOS_CHERIBUILD_QEMU_OUTPUT / "freertos.buildhash"
FREERTOS_FPGA_ELF_FILE := FREERTOS_CHERIBUILD_FPGA_OUTPUT / "sdk/baremetal" / FREERTOS_ELF_TARGET / "riscv64-unknown-elf/FreeRTOS/Demo/bin/RISC-V-Generic_main_" + FREERTOS_ELF_DEMO + ".elf"
FREERTOS_FPGA_BUILDHASH := FREERTOS_CHERIBUILD_FPGA_OUTPUT / "freertos.buildhash"

# --------------
#    CheriBSD
# --------------
# The platform target we use for CheriBSD
CHERIBSD_TARGET := "riscv64-purecap"
# CHERIBSD_TARGET := "riscv64"
CHERIBSD_CHERIBUILD_SRC_ROOT := "./os-cheribsd/working"
CHERIBSD_FPGA_PURECAP_ELF_FILE := CHERIBSD_CHERIBUILD_SRC_ROOT / "output/kernel-riscv64-purecap.CHERI-PURECAP-GFE"
CHERIBSD_FPGA_HYBRID_ELF_FILE := CHERIBSD_CHERIBUILD_SRC_ROOT / "output/kernel-riscv64-purecap.CHERI-GFE"
CHERIBSD_FPGA_DISK_IMG := CHERIBSD_CHERIBUILD_SRC_ROOT / "output/cheribsd-minimal-riscv64-purecap.img"
CHERIBSD_FPGA_BUILDHASH := CHERIBSD_CHERIBUILD_SRC_ROOT / "output/cheribsd.buildhash"

# --------------
#    SoC Repos
# --------------
DE10PRO_CHERI_BGAS := "./soc/common/de10pro-cheri-bgas"
TINYEMU_VIRTIO := "./soc/common/tinyemu-virtio"
FMEM_UART := "./soc/sim/fmem-uart"
ELFMANIP := "./soc/sim/elfmanip"

default:
    @just --list

describe_git dir:
    #!/bin/bash
    cd {{dir}}
    NOW=$(date +"%Y-%m-%d %H:%M")
    GITREV=$(git rev-parse HEAD)
    GITDIRTY=$(git diff --quiet || echo "_dirty")
    printf "time %s git %s%s\n" "$NOW" "$GITREV" "$GITDIRTY"
    echo $(git log -n 1 --pretty=format:'%s')

# Create the Python virtual environment used by various commands
install_venv:
    uv sync


# Build freertos
# Use a implicit_mem_0 flag to remove long-winded unnecessary .bss zeroing code.
# Use de10toooba option to set up the memory map correctly, including putting the ELF contents at 0xc000_0000.
# The de10toooba option is only available in my branch of cheribuild 'sws35' at the moment.
# use-virtio-blk is required to actually try to talk to the virtio
rebuild_freertos_sim:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-freertos/cheribuild/cheribuild.py freertos-{{FREERTOS_ELF_TARGET}} \
        --skip-update \
        --freertos/platform de10toooba \
        --freertos/prog main_{{FREERTOS_ELF_DEMO}} \
        --freertos/implicit_mem_0 \
        --freertos/use_virtio_blk \
        --freertos/use_virtio_iocaps \
        --freertos/source-directory "./os-freertos/freertos/" \
        -d \
        --source-root {{FREERTOS_CHERIBUILD_SRC_ROOT}} \
        --output-root {{FREERTOS_CHERIBUILD_SIM_OUTPUT}} \
        --build-root {{FREERTOS_CHERIBUILD_SIM_BUILD}}
    python3 {{ELFMANIP}}/elfmanip.py -vvv {{FREERTOS_SIM_ELF_FILE}} info --list-sections
    python3 {{ELFMANIP}}/elfmanip.py -vvv -o {{TOOOBA_FREERTOS_HEX}} -s 0xc0000000 -i 0x40000000 {{FREERTOS_SIM_ELF_FILE}} to-hex
    just describe_git "./os-freertos/freertos" > {{FREERTOS_SIM_BUILDHASH}}

# No --freertos/implicit_mem_0, this will run on FPGA.
# Use different build/output roots so this doesn't interfere with sim builds
rebuild_freertos_fpga:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-freertos/cheribuild/cheribuild.py freertos-{{FREERTOS_ELF_TARGET}} \
        --skip-update \
        --freertos/platform de10toooba \
        --freertos/prog main_{{FREERTOS_ELF_DEMO}} \
        --freertos/use_virtio_blk \
        --freertos/use_virtio_iocaps \
        --freertos/source-directory "./os-freertos/freertos/" \
        -d \
        --source-root {{FREERTOS_CHERIBUILD_SRC_ROOT}} \
        --output-root {{FREERTOS_CHERIBUILD_FPGA_OUTPUT}} \
        --build-root {{FREERTOS_CHERIBUILD_FPGA_BUILD}}
    just describe_git "./os-freertos/freertos" > {{FREERTOS_FPGA_BUILDHASH}}

# Use a implicit_mem_0 flag to remove long-winded unnecessary .bss zeroing code.
# Use de10toooba option to set up the memory map correctly, including putting the ELF contents at 0xc000_0000.
# The de10toooba option is only available in my branch of cheribuild 'sws35' at the moment.
# use-virtio-blk is required to actually try to talk to the virtio
rebuild_freertos_qemu:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-freertos/cheribuild/cheribuild.py freertos-{{FREERTOS_ELF_TARGET}} \
        --skip-update \
        --freertos/platform qemu_virt \
        --freertos/prog main_{{FREERTOS_ELF_DEMO}} \
        --freertos/use_virtio_blk \
        --freertos/use_virtio_iocaps \
        --freertos/source-directory "./os-freertos/freertos/" \
        -d \
        --source-root {{FREERTOS_CHERIBUILD_SRC_ROOT}} \
        --output-root {{FREERTOS_CHERIBUILD_QEMU_OUTPUT}} \
        --build-root {{FREERTOS_CHERIBUILD_QEMU_BUILD}}
    just describe_git "./os-freertos/freertos" > {{FREERTOS_QEMU_BUILDHASH}}

# Only build the de10 with 1 core - FreeRTOS is not designed to work with two
build_de10_bluesim:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    cd {{DE10PRO_CHERI_BGAS}}
    BSC_OPTIONS="-parallel-sim-link 24" \
        RVFI=true \
        CORE_NUM=1 \
        OUTPUT_DIR_POSTFIX=_sim \
        make bluesim -j24

rebuild_de10_bluesim:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    cd {{DE10PRO_CHERI_BGAS}}
    touch bluespec/CHERI_BGAS_Top_Sim.bsv
    BSC_OPTIONS="-parallel-sim-link 24" \
        RVFI=true \
        CORE_NUM=1 \
        OUTPUT_DIR_POSTFIX=_sim \
        make bluesim -j24

build_de10_bitfiles:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    cd {{DE10PRO_CHERI_BGAS}}
    BSC_OPTIONS="-parallel-sim-link 12" \
        RVFI=false \
        CORE_NUM=2 \
        OUTPUT_DIR_POSTFIX=_fpga \
        make synthesize -j12 && make gen-rbf

clean_de10_bsv:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    cd {{DE10PRO_CHERI_BGAS}}
    BSC_OPTIONS="-parallel-sim-link 24" \
        OUTPUT_DIR_POSTFIX=_sim \
        make clean
    BSC_OPTIONS="-parallel-sim-link 24" \
        OUTPUT_DIR_POSTFIX=_fpga \
        make clean

build_de10_fuse_fifos:
    #!/bin/bash
    cd {{DE10PRO_CHERI_BGAS}}/bluespec/sim-utils/cheri-bgas-fuse-devfs
    make

build_tinyemu:
    #!/bin/bash
    cd {{TINYEMU_VIRTIO}}; cmake -S . -B ./build/; cd ./build/; make

# Rebuild tinyemu, including regenerating the build environment through CMake
rebuild_tinyemu:
    #!/bin/bash
    cd {{TINYEMU_VIRTIO}}; cmake -S . -B ./build/; cd ./build/; make clean && make

build_fmem_uart:
    (cd {{FMEM_UART}} && make)

build_empty_disk_img:
    #!/bin/bash
    mkdir -p {{BUILD_DIR}}
    # Create the 64MiB disk image, make it empty for CheriBSD to poke
    dd if=/dev/zero of={{EMPTY_DISK_IMG}} bs=4K count=16K

    # Create a 4MiB disk image for FreeRTOS
    dd if=/dev/zero of={{FREERTOS_DISK_IMG}} bs=4K count=1024
    # Put a fat filesystem on it
    # This may be fat12/16/32 depending on the number of sectors - FreeRTOS can handle this
    # --mbr=y means create a MBR partition table, which FreeRTOS+FAT can read.
    # There is no documentation on the fact that FreeRTOSs parition structures match MBR, but they do.
    mkfs.vfat --mbr=y {{FREERTOS_DISK_IMG}}
    # FreeRTOS overwrites the disk image

prep_diskimg_extras_cheribsd:
    mkdir -p {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/extra-files/root/bench
    rm -rf {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/extra-files/root/bench/*
    mkdir -p {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/extra-files-minimal/root/bench
    rm -rf {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/extra-files-minimal/root/bench/*
    cp os-cheribsd/cheri-fio/fio {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/extra-files/root/bench/
    cp os-cheribsd/cheri-fio/fio {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/extra-files-minimal/root/bench/
    cp qasmuna_scripts/cheribsd_benchmarks/* {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/extra-files/root/bench/
    cp qasmuna_scripts/cheribsd_benchmarks/* {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/extra-files-minimal/root/bench/

# more recent LLVMs break the version of CheriBSD I'm built on.
pin_cheribsd_versions: (_pin_cheribsd_checkout_ver "llvm-project" "https://github.com/CTSRD-CHERI/llvm-project" "578ea4f7ef67d589f0ca7d10ec9e383333567421") (_pin_cheribsd_checkout_ver "gdb" "https://github.com/CTSRD-CHERI/gdb" "7c05fb82db7ddd8e009548b8e853657c3512029f")

_pin_cheribsd_checkout_ver name url commit:
    mkdir -p {{CHERIBSD_CHERIBUILD_SRC_ROOT}}
    # https://stackoverflow.com/a/43136160
    test -d {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/{{name}} || { \
        mkdir {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/{{name}} && \
        cd {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/{{name}} && \
        git init && \
        git remote add origin {{url}} ; }

    cd {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/{{name}}/ && \
        test "{{commit}}" = "$(git show --pretty=format:'%H' --no-patch)" || { \
        git fetch --depth 1 origin {{commit}} && \
        git checkout {{commit}}; }


build_cheribsd_diskimg: prep_diskimg_extras_cheribsd build_empty_disk_img
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-cheribsd/cheribuild/cheribuild.py disk-image-minimal-{{CHERIBSD_TARGET}} \
        --config-file "./os-cheribsd/cheribuild.json"

build_cheribsd_qemu:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-cheribsd/cheribuild/cheribuild.py cheribsd-{{CHERIBSD_TARGET}} \
        --cheribsd/build-bench-kernels \
        -d \
        --config-file "./os-cheribsd/cheribuild.json"

build_hybrid_sdk_cheribsd:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-cheribsd/cheribuild/cheribuild.py cheribsd-sdk-riscv64-hybrid \
        --enable-hybrid-targets \
        -d \
        --config-file "./os-cheribsd/cheribuild.json"

rebuild_cheribsd_qemu:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-cheribsd/cheribuild/cheribuild.py cheribsd-{{CHERIBSD_TARGET}} \
        --cheribsd/build-bench-kernels \
        --cheribsd/clean \
        -d \
        --config-file "./os-cheribsd/cheribuild.json"

build_cheribsd_fpga:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-cheribsd/cheribuild/cheribuild.py \
        cheribsd-{{CHERIBSD_TARGET}} \
        disk-image-mfs-root-{{CHERIBSD_TARGET}} \
        cheribsd-mfs-root-kernel-{{CHERIBSD_TARGET}} \
        --cheribsd-mfs-root-kernel/build-fpga-kernels \
        --cheribsd/build-bench-kernels \
        --config-file "./os-cheribsd/cheribuild.json"
    just describe_git "./os-cheribsd/cheribsd" > {{CHERIBSD_FPGA_BUILDHASH}}

# I don't know which BBL we need, do both
build_qemu:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-cheribsd/cheribuild/cheribuild.py qemu bbl-baremetal-{{CHERIBSD_TARGET}} bbl-gfe-baremetal-{{CHERIBSD_TARGET}} \
        -d \
        --config-file "./os-cheribsd/cheribuild.json"

build_cheribsd_fpga_device_trees:
    #!/bin/bash
    cd DE10Pro-softcore-devicetree
    # we want to compile these DTBs into risc-v flavor ELFs.
    # the default ld on your system may not have risc-v flavor available,
    # so use the ones from CheriBSD
    export LD=../os-cheribsd/working/output/sdk/bin/ld.lld
    make devicetree.dtb
    make devicetree.dual.dtb
    make devicetree.wrapped.elf
    make devicetree.dual.wrapped.elf

dump-qemu-cheribsd-dtb:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-cheribsd/cheribuild/cheribuild.py \
        run-minimal-{{CHERIBSD_TARGET}} \
        --cheribsd/build-bench-kernels \
        --run-minimal/extra-options "-global virtio-mmio.force-legacy=false -machine dumpdtb={{OUTPUT_DIR}}/cheribsd.dtb" \
        --config-file "./os-cheribsd/cheribuild.json"
    dtc {{OUTPUT_DIR}}/cheribsd.dtb | tee {{OUTPUT_DIR}}/devtree_cheribsd.txt

# TODO enable -d here?
# debug.rman_debug=1
# -machine dumpdtb={{OUTPUT_DIR}}/qemu.dtb
run-qemu-cheribsd:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-cheribsd/cheribuild/cheribuild.py \
        run-minimal-{{CHERIBSD_TARGET}} \
        --cheribsd/build-bench-kernels \
        --run-minimal/extra-options "-global virtio-mmio.force-legacy=false -drive if=none,file={{EMPTY_DISK_IMG}},id=benchdrv,format=raw -device virtio-blk-device,drive=benchdrv,iocap_queue=true" \
        --config-file "./os-cheribsd/cheribuild.json"

run-qemu-cheribsd-load state:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-cheribsd/cheribuild/cheribuild.py \
        run-minimal-{{CHERIBSD_TARGET}} \
        --cheribsd/build-bench-kernels \
        --run-minimal/extra-options "-global virtio-mmio.force-legacy=false -drive if=none,file={{EMPTY_DISK_IMG}},id=benchdrv,format=raw -device virtio-blk-device,drive=benchdrv,iocap_queue=true -loadvm {{state}}" \
        --config-file "./os-cheribsd/cheribuild.json"

# requires  libgmp-dev libmpfr-dev
build_gdb:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-cheribsd/cheribuild/cheribuild.py gdb \
        --config-file "./os-cheribsd/cheribuild.json"

dbg-qemu-cheribsd:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-cheribsd/cheribuild/cheribuild.py \
        run-minimal-{{CHERIBSD_TARGET}} \
        --cheribsd/build-bench-kernels \
        --run-minimal/extra-options "-global virtio-mmio.force-legacy=false -drive if=none,file={{EMPTY_DISK_IMG}},id=benchdrv,format=raw -device virtio-blk-device,drive=benchdrv,iocap_queue=true" \
        --qemu-gdb-break-on-cheri-trap \
        --wait-for-debugger \
        --config-file "./os-cheribsd/cheribuild.json"

run-qemu-cheribsd-noiocap:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./os-cheribsd/cheribuild/cheribuild.py \
        run-minimal-{{CHERIBSD_TARGET}} \
        --cheribsd/build-bench-kernels \
        --run-minimal/extra-options "  -drive if=none,file={{EMPTY_DISK_IMG}},id=benchdrv,format=raw -device virtio-blk-device,drive=benchdrv,iocap_queue=false" \
        --config-file "./os-cheribsd/cheribuild.json"

# TODO the riscv64-purecap here may be out of date w.r.t. FREERTOS_ELF_TARGET
# freertos expects the net device at 0x10008000, net at 0x10007000
# qemu assigns them top-down, so do the net device first.
# force-legacy=false to make devices enable F_VERSION_1
#
# Visit http://localhost:2222/freertos.html to get an IOCaps server page!
run-qemu-freertos: build_empty_disk_img
    {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/output/sdk/bin/qemu-system-riscv64cheri \
        -M virt -m 2048 -nographic \
        -bios none \
        -kernel {{FREERTOS_QEMU_ELF_FILE}} \
        -global virtio-mmio.force-legacy=false \
        -device virtio-net-device,netdev=net0,iocap_queue=true \
        -netdev user,id=net0,hostfwd=tcp::2222-:80 \
        -drive if=none,file={{FREERTOS_DISK_IMG}},id=drv,format=raw \
        -device virtio-blk-device,drive=drv,iocap_queue=true \
        -d guest_errors \
        -D {{OUTPUT_DIR}}/qemu.log

dump-qemu-freertos-dtb:
    {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/output/sdk/bin/qemu-system-riscv64cheri \
        -M virt -m 2048 -nographic \
        -bios none \
        -kernel {{FREERTOS_QEMU_ELF_FILE}} \
        -global virtio-mmio.force-legacy=false \
        -device virtio-net-device,netdev=net0,iocap_queue=true \
        -netdev user,id=net0,hostfwd=tcp::2222-:80 \
        -drive if=none,file={{FREERTOS_DISK_IMG}},id=drv,format=raw \
        -device virtio-blk-device,drive=drv,iocap_queue=true \
        -d guest_errors \
        -D {{OUTPUT_DIR}}/qemu.log \
        -machine dumpdtb={{OUTPUT_DIR}}/freertos.dtb
    dtc {{OUTPUT_DIR}}/freertos.dtb | tee {{OUTPUT_DIR}}/devtree_freertos.txt

valgrind-qemu-freertos: build_empty_disk_img
    valgrind --smc-check=all -- {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/output/sdk/bin/qemu-system-riscv64cheri \
        -M virt -m 2048 -nographic \
        -bios none \
        -kernel {{FREERTOS_QEMU_ELF_FILE}} \
        -global virtio-mmio.force-legacy=false \
        -device virtio-net-device,netdev=net0,iocap_queue=true \
        -netdev user,id=net0,hostfwd=tcp::2222-:80 \
        -drive if=none,file={{FREERTOS_DISK_IMG}},id=drv,format=raw \
        -device virtio-blk-device,drive=drv,iocap_queue=true \
        -d guest_errors \
        -D {{OUTPUT_DIR}}/qemu.log

run-qemu-freertos-noiocap: build_empty_disk_img
    {{CHERIBSD_CHERIBUILD_SRC_ROOT}}/output/sdk/bin/qemu-system-riscv64cheri \
        -M virt -m 2048 -nographic \
        -bios none \
        -kernel {{FREERTOS_QEMU_ELF_FILE}} \
        -global virtio-mmio.force-legacy=false \
        -device virtio-net-device,netdev=net0,iocap_queue=false \
        -netdev user,id=net0,hostfwd=tcp::2222-:80 \
        -drive if=none,file={{FREERTOS_DISK_IMG}},id=drv,format=raw \
        -device virtio-blk-device,drive=drv,iocap_queue=false \
        -d guest_errors \
        -D {{OUTPUT_DIR}}/qemu.log

select_de10_latest_local:
    #!/bin/bash
    DE10BITFILE_OUTPUT=$(find {{DE10PRO_CHERI_BGAS}} -type d -name "output_files_fpga_*" -exec stat -c '%Y %n' {} \; | sort -n | cut -d' ' -f2- | tail -n1)
    cp $DE10BITFILE_OUTPUT/*.core.rbf {{FPGA_DIR}}/fpga.core.rbf
    cp $DE10BITFILE_OUTPUT/*.hps.rbf {{FPGA_DIR}}/fpga.hps.rbf
    echo "$DE10BITFILE_OUTPUT" > {{FPGA_DIR}}/fpga.de10.buildhash
    echo "Copied from $DE10BITFILE_OUTPUT"

select_de10_other path:
    cp {{path}}/*.core.rbf {{FPGA_DIR}}/fpga.core.rbf
    cp {{path}}/*.hps.rbf {{FPGA_DIR}}/fpga.hps.rbf
    echo "{{path}}" > {{FPGA_DIR}}/fpga.de10.buildhash

generate_fpga_dir:
    #!/bin/bash

    if [ -s {{FPGA_DIR}}/arm/freertos.buildhash ] && cmp "{{FPGA_DIR}}/arm/freertos.buildhash" "{{FREERTOS_FPGA_BUILDHASH}}" &>/dev/null; then
        # files are identical
        echo "Using same FreeRTOS build as before"
    fi

    if [ -s {{FPGA_DIR}}/arm/cheribsd.buildhash ]; then
        if cmp "{{FPGA_DIR}}/arm/cheribsd.buildhash" "{{CHERIBSD_FPGA_BUILDHASH}}" &>/dev/null; then
            # files are identical
            echo "Using same CheriBSD build as before"
        else
            echo "Replacing CheriBSD" $(cat {{FPGA_DIR}}/arm/cheribsd.buildhash)
        fi
    fi

    mkdir -p {{FPGA_DIR}}
    mkdir -p {{FPGA_DIR}}/arm
    rm -rf {{FPGA_DIR}}/arm
    mkdir -p {{FPGA_DIR}}/arm

    if [ ! -f "{{FPGA_DIR}}/fpga.core.rbf" ] || [ ! -f "{{FPGA_DIR}}/fpga.hps.rbf" ] || [ ! -f "{{FPGA_DIR}}/fpga.de10.buildhash" ]; then
        echo "no core/buildhash file for FPGA, quitting early"
        exit 1
    fi

    cp {{FREERTOS_FPGA_ELF_FILE}} {{FPGA_DIR}}/arm/freertos.elf
    cp {{FREERTOS_FPGA_BUILDHASH}} {{FPGA_DIR}}/arm
    cp {{CHERIBSD_FPGA_PURECAP_ELF_FILE}} {{FPGA_DIR}}/arm/cheribsd.purecap.elf
    cp {{CHERIBSD_FPGA_HYBRID_ELF_FILE}} {{FPGA_DIR}}/arm/cheribsd.hybrid.elf
    rsync -Phav --update {{CHERIBSD_FPGA_DISK_IMG}} {{FPGA_DIR}}/arm/cheribsd.fs
    # cp qasmuna_scripts/kernel-purecap-1002 {{FPGA_DIR}}/arm/franz-kernel-purecap-1002.elf
    cp {{CHERIBSD_FPGA_BUILDHASH}} {{FPGA_DIR}}/arm
    cp DE10Pro-softcore-devicetree/*.elf {{FPGA_DIR}}/arm
    cp -r {{TINYEMU_VIRTIO}} {{FPGA_DIR}}/arm/
    rm -rf {{FPGA_DIR}}/arm/tinyemu-virtio/build
    cp {{EMPTY_DISK_IMG}} {{FPGA_DIR}}/arm/virtio.fs
    cp {{FREERTOS_DISK_IMG}} {{FPGA_DIR}}/arm/freertos.fs
    cp -r ./qasmuna_scripts/* {{FPGA_DIR}}/arm
    cp -r ./fmem {{FPGA_DIR}}/arm/

    echo "===== FreeRTOS =====" >{{FPGA_DIR}}/Manifest
    awk 1 "{{FREERTOS_FPGA_BUILDHASH}}" >>{{FPGA_DIR}}/Manifest
    echo "md5" "$(md5sum {{FREERTOS_FPGA_ELF_FILE}})" >>{{FPGA_DIR}}/Manifest
    echo "===== CheriBSD =====" >>{{FPGA_DIR}}/Manifest
    awk 1 "{{CHERIBSD_FPGA_BUILDHASH}}" >>{{FPGA_DIR}}/Manifest
    echo "md5" "$(md5sum {{CHERIBSD_FPGA_PURECAP_ELF_FILE}})" >>{{FPGA_DIR}}/Manifest
    echo "md5" "$(md5sum {{CHERIBSD_FPGA_HYBRID_ELF_FILE}})" >>{{FPGA_DIR}}/Manifest
    # echo "len" "$(stat --printf='%s' {{CHERIBSD_FPGA_DISK_IMG}}) {{CHERIBSD_FPGA_DISK_IMG}}" >>{{FPGA_DIR}}/Manifest
    echo "===== DE10Pro  =====" >>{{FPGA_DIR}}/Manifest
    awk 1 {{FPGA_DIR}}/fpga.de10.buildhash >>{{FPGA_DIR}}/Manifest
    echo "md5" "$(md5sum {{FPGA_DIR}}/fpga.core.rbf)" >>{{FPGA_DIR}}/Manifest
    echo "md5" "$(md5sum {{FPGA_DIR}}/fpga.hps.rbf)" >>{{FPGA_DIR}}/Manifest
    echo "===== tinyemu  =====" >>{{FPGA_DIR}}/Manifest
    echo "$(just describe_git tinyemu-virtio)" >>{{FPGA_DIR}}/Manifest
    cat {{FPGA_DIR}}/Manifest

# do diskimg first so that it gets carried into the embedded too
prepare_fpga_cheribsd: build_cheribsd_diskimg build_empty_disk_img build_cheribsd_fpga generate_fpga_dir
prepare_fpga_freertos: rebuild_freertos_fpga build_empty_disk_img generate_fpga_dir

diff_cheribsd_drivers:
    #!/bin/bash
    set -e
    cd os-cheribsd/cheribsd/
    declare -a iocap_files=("sys/dev/virtio/virtio_ring_iocap.h" "sys/dev/virtio/virtqueue_iocap.h" "sys/dev/virtio/virtqueue_iocap.c" "sys/dev/virtio/block/virtio_blk_iocap.c")
    for f in "${iocap_files[@]}"
    do
        other=$(sed s/_iocap// <(echo "$f"))
        printf "\n\ncomparing %s %s\n\n" "$f" "$other"
        diff -U10 -bEB "$other" <(sed s/virtq_iocap/virtqueue/g "$f" | sed s/VIRTQ_IOCAP/VIRTQUEUE/g | sed s/VQ_IOCAP_RING/VQ_RING/g | sed s/_iocap_/_/g | sed s/_IOCAP_/_/g | sed s/_iocap//g) || true
    done
    exit 0

diffcount_cheribsd_drivers:
    #!/bin/bash
    set -e
    cd os-cheribsd/cheribsd/
    declare -a iocap_files=("sys/dev/virtio/virtio_ring_iocap.h" "sys/dev/virtio/virtqueue_iocap.h" "sys/dev/virtio/virtqueue_iocap.c" "sys/dev/virtio/block/virtio_blk_iocap.c")
    printf "iocap\tlines-iocap\toriginal\tlines\tdiff\tdiff-nosed\n"
    for f in "${iocap_files[@]}"
    do
        other=$(sed s/_iocap// <(echo "$f"))
        #n_diff=$(diff -y --suppress-common-lines -bEB "$other" <(sed s/virtq_iocap/virtqueue/g "$f" | sed s/VIRTQ_IOCAP/VIRTQUEUE/g | sed s/VQ_IOCAP_RING/VQ_RING/g | sed s/_iocap_/_/g | sed s/_IOCAP_/_/g | sed s/_iocap//g) | wc -l)
        # https://serverfault.com/a/68717
        n_diff=$(comm -1 -3 <(sort <"$other") <(sed s/virtq_iocap/virtqueue/g "$f" | sed s/VIRTQ_IOCAP/VIRTQUEUE/g | sed s/VQ_IOCAP_RING/VQ_RING/g | sed s/_iocap_/_/g | sed s/_IOCAP_/_/g | sed s/_iocap//g | sort) | wc -l)
        n_diff_plain=$(diff -y --suppress-common-lines -bEB "$other" "$f" | wc -l)

        printf "%s\t%d\t%s\t%d\t%d\t%d\n" "$f" $(wc -l <"$f") "$other" $(wc -l <"$other") "$n_diff" "$n_diff_plain"
    done
    exit 0

diff_cheribsd_existing:
    #!/bin/bash
    set -e
    cd os-cheribsd/cheribsd/
    # https://stackoverflow.com/a/32931403
    mapfile -t all_changed_files < <(git diff --name-only sws35-iocaps-main)

    git diff sws35-iocaps-main "${all_changed_files[@]}"
    exit 0

diffcount_cheribsd_existing:
    #!/bin/bash
    set -e
    cd os-cheribsd/cheribsd/
    mapfile -t all_changed_files < <(git diff --name-only sws35-iocaps-main)

    printf "file\tloc_now\tdiff_plus\tdiff_minus\n"
    # awk -v OFS='\t' '{ $1=$1; print }' <(git diff --numstat sws35-iocaps-main "${all_changed_files[@]}")
    # git diff --numstat sws35-iocaps-main "${all_changed_files[@]}" | tr ' ' '\t'
    # git diff --numstat sws35-iocaps-main "${all_changed_files[@]}"

    for f in "${all_changed_files[@]}"
    do
        loc=$(wc -l <"$f")
        n_diff=$(git diff --numstat sws35-iocaps-main "$f" | cut -f 1,2)

        printf "%s\t%d\t%s\n" "$f" "$loc" "$n_diff"
    done
    exit 0

diff_cheribsd:
    just diff_cheribsd_drivers >./os-cheribsd/iocap-drivers.diff
    just diff_cheribsd_existing >./os-cheribsd/existing.diff
    just diffcount_cheribsd_drivers >./os-cheribsd/iocap-drivers-summary.tsv
    just diffcount_cheribsd_existing >./os-cheribsd/existing-summary.tsv

run-de10-sim-freertos: build_de10_bluesim build_de10_fuse_fifos build_tinyemu build_fmem_uart build_empty_disk_img
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    test -f {{TOOOBA_FREERTOS_HEX}} || { echo "Please build FreeRTOS for Toooba; $ just rebuild_freertos_sim" ; exit 1 ; }

    PROC_FIFOS=0
    PROC_TINYEMU=0
    PROC_UART=0

    # Kill processes in a specific order
    # - if Toooba dies before fmem-uart, then fmem-uart might try to do an fmem_{read,write} IOCTL
    #   when nothing is ready to respond, causing cheri_bgas_fuse_devfs to hang.
    # - same for tinyemu-virtio
    function cleanup {
        echo "Received signal, cleaning up"
        trap 'echo Ignoring signals during cleanup' SIGINT SIGTERM
        # fmem-uart, which may be issuing requests to fuse-devfs
        if [ $PROC_UART -ne 0 ]; then
            kill -s SIGTERM $PROC_UART
        fi
        # tinyemu-virtio, which may be attached to fuse-devfs
        if [ $PROC_TINYEMU -ne 0 ]; then
            kill -s SIGTERM $PROC_TINYEMU
        fi
        sleep 1
        # cheri-bgas-fuse-devfs
        if [ $PROC_FIFOS -ne 0 ]; then
            kill -s SIGKILL $PROC_FIFOS
            # Force unmount the fuse directory, which otherwise will point to a now-killed userspace process
            fusermount3 -u {{FUSE_DIR}}
        fi
        sleep 1
        # kill the rest
        pkill -P $$
        # exit
        exit
    }
    # Call the cleanup function on exit
    trap 'cleanup' SIGINT SIGTERM

    mkdir -p {{FUSE_DIR}}
    mkdir -p {{OUTPUT_DIR}}

    # Run the CHERI BGAS simulator running Cheri-FreeRTOS.
    # While running, it creates a folder './simports/' with a bunch of Unix FIFOs inside.
    # If I understand this correctly:
    # - the contents of the hex file are placed at ddr4_0_uncached_addr_range.base = 0x8000_0000 ({{DE10PRO_CHERI_BGAS}}/bluespec/SoC_Map.bsv)
    #   - when running in purecap, the program needs to be run in cached (and therefore tagged) memory, which currently starts at 0xc000_0000 ({{DE10PRO_CHERI_BGAS}}/bluespec/SoC_Map.bsv)
    #   - but the simulation DDR memory is small and wraps around every 1GiB, so placing the data at 0x8000_0000 automatically creates it at 0xc000_0000, in cached memory.
    # - there should theoretically be a hardcoded boot ROM at boot_rom_addr_base=0x7000_0000 ({{DE10PRO_CHERI_BGAS}}/bluespec/SoC_Map.bsv)
    #   which is intended to jump to 0x8000_0000 (or 0xc000_0000)
    # - Toooba tries to start at pc_reset_value=0x7000_0000 ({{DE10PRO_CHERI_BGAS}}/bluespec/SoC_Map.bsv) to load this boot ROM
    # - but right now we do not have a boot rom!
    # - Hence use this env variable (set via getEnvInt -> C getenv_as_64hex -> C strtoll) to force Toooba to start at 0xc000_0000 in tagged, cached memory where the ELF HEX is placed.
    CHERI_BGAS_PC_RESET_VALUE=0xc0000000 \
        CHERI_BGAS_DDRB_HEX_INIT={{TOOOBA_FREERTOS_HEX}} \
        {{DE10PRO_CHERI_BGAS}}/build_sim/simdir/sim_CHERI_BGAS | grep -e "RVFI" -e "read_req" -e "write_req" -e "virtDev" -e "IOCap" >{{OUTPUT_DIR}}/tooba_freertos_sim.txt &
        # {{DE10PRO_CHERI_BGAS}}/build_sim/simdir/sim_CHERI_BGAS >{{OUTPUT_DIR}}/tooba_freertos_sim.txt 2>&1 &
    echo "Running CHERI-Toooba simulation"

    # Sleep to make sure ./simports/ are exposed
    sleep 0.5

    # Run the fuse driver we just built to expose the Unix FIFOs in './simports/' as file descriptors in '/tmp/fuse/virtual_device'
    # -d = run in debug mode
    # -s = run single-threaded, which prevents e.g. UART accesses and tinyemu accesses to the same AXI channels from overlapping
    {{DE10PRO_CHERI_BGAS}}/bluespec/sim-utils/cheri-bgas-fuse-devfs/cheri-bgas-fuse-devfs ./simports -d -s {{FUSE_DIR}} >{{OUTPUT_DIR}}/cheri_bgas_fuse_devfs.txt 2>&1 &
    PROC_FIFOS=$!
    echo "Running CHERI-Toooba FIFOs ${PROC_FIFOS}"

    # Sleep to make sure the FUSE devices are exposed
    sleep 0.5

    # Run the uart retriever to pull data off the UART and into stdout (in this case, a redirected file)
    {{FMEM_UART}}/obj/fmem-uart {{FUSE_DIR}}/uart0 0x0 >{{OUTPUT_DIR}}/tooba_uart0.txt &
    PROC_UART=$!
    echo "Running UART processor ${PROC_UART}"

    # Run the tinyemu server, which accesses the CHERI Tooobas physical memory through the virtual device files through 'fmem'.
    # 'fmem' uses file descriptors and a custom IOCTL to access physical memory, allowing different implementations to swap in their own
    # implementation of physical memory - in our case, the cheri-bgas-fuse-devfs intercepts the custom IOCTL and turns them into AXI
    # requests sent over the Unix FIFOs into the CHERI Toooba simulation.
    # These exports are based on magic strings inside `cheri-bgas-fuse-devfs/H2F_LW.h` and `cheri-bgas-fuse-devfs/H2F.h`
    RISCV_VIRTUAL_DEVICE_FMEM_DEV={{FUSE_DIR}}/virtual_device \
        RISCV_ADDRESS_SELECTOR_FMEM_DEV={{FUSE_DIR}}/h2f_addr_ctrl \
        RISCV_DMA_FMEM_DEV={{FUSE_DIR}}/dma_window \
        RISCV_INTERRUPT_FMEM_DEV={{FUSE_DIR}}/irqs \
        {{TINYEMU_VIRTIO}}/build/src/fmem_virtio_host --block {{FREERTOS_DISK_IMG}} --debug-log >{{OUTPUT_DIR}}/fmem_virtio_host.txt 2>&1 &
    PROC_TINYEMU=$!
    echo "Running virtio-host connected to FIFOs ${PROC_TINYEMU}"

    wait $(jobs -p); fusermount3 -u {{FUSE_DIR}}

watch-de10-sim:
    watch tail -n 20 {{OUTPUT_DIR}}/tooba_freertos_sim.txt

watch-de10-uart:
    watch tail -n 20 {{OUTPUT_DIR}}/tooba_uart0.txt

disasm-trace:
    #!/bin/bash
    source {{PYTHON3_VENV}}/bin/activate || { echo "Please create the Python venv; $ just install_venv" ; exit 1 ; }
    python3 ./annotate_rvfi.py {{OUTPUT_DIR}}/tooba_freertos_sim.txt {{FREERTOS_CHERIBUILD_SIM_OUTPUT}}/sdk/bin/ {{FREERTOS_SIM_ELF_FILE}} --start-instr=-1000 test_trace.txt

disasm file=FREERTOS_SIM_ELF_FILE:
    {{FREERTOS_CHERIBUILD_SIM_OUTPUT}}/sdk/bin/llvm-objdump --disassemble-all {{file}}

all-gits:
    find . -type d -exec test -e '{}/.git' ';' -print -exec just describe_git {} ';'

# Enter a shell with the os-cheribsd tools active and ready for cross-compilation to CheriBSD
# make sure to just build_hybrid_sdk_cheribsd BEFORE you enter a cross-shell
cross-shell:
	#!/bin/bash
	cd os-cheribsd
	exec bash --init-file <(cat <<-'EOF'
		. ~/.bashrc
		export PS1="\[$(tput setaf 200)\](CROSS)\[$(tput sgr0)\]$PS1"
		export PATH="$(realpath working/output/sdk/bin):$PATH"

		# based on https://community.arm.com/support-forums/f/morello-forum/49763/cheribsd-morello-fvp-pure-capability---how-to-cross-compile-from-source
		export CC="$(realpath working/output/sdk/bin/clang) $(cat working/output/sdk/bin/cheribsd-riscv64-hybrid.cfg | tr '\n' ' ')"
		export PKG_CONFIG_PATH=
		export PKG_CONFIG_LIBDIR=
		export CROSS_COMPILE="$(realpath working/output/sdk)"

		$CC -v
	EOF
	) -i

# Only run this from inside a `$ just cross-shell`
fio-cross-only:
    cd os-cheribsd/cheri-fio && make clean && make
