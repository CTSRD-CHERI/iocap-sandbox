#!/usr/bin/env sh

# Ensure that /usr/local/lib is searched for .so files - this should always be the case anyway but sometimes just... doesn't happen!!!!!
# If this wasn't here there would be spurious failures like 'failed to find libwhatever.so'
ldconfig /usr/local/lib

BASEPATH=/root

# For tinyemu and fmem utils
export RISCV_ADDRESS_SELECTOR_FMEM_DEV=/dev/fmem_sys0_h2f_addr_ctrl

run_jtagvpi_to_fmemdmi()
{
  # This is guaranteed to already exist
  $BASEPATH/jtagvpi_to_fmemdmi/jtagvpi_to_fmemdmi
}

OPENOCD_CFG=$BASEPATH/sws35-stuff/openocd_2hart.cfg
run_openocd()
{
  /usr/local/bin/openocd -f $OPENOCD_CFG
}

# KERNEL=$BASEPATH/riscv-freebsd-boot/kernel-cheri
KERNEL=$BASEPATH/sws35-stuff/cheribsd.purecap.elf
# KERNEL=$BASEPATH/sws35-stuff/cheribsd.hybrid.elf
# KERNEL=$BASEPATH/sws35-stuff/franz-kernel-purecap-1002.elf
load_kernel()
{
  $BASEPATH/sws35-stuff/fmem/fmem_load_elf $KERNEL
}

# VIRTIO_FS=$BASEPATH/riscv-freebsd-boot/virtio.fs
VIRTIO_BLANK_FS=$BASEPATH/sws35-stuff/virtio.fs
VIRTIO_FS=$BASEPATH/sws35-stuff/cheribsd.fs
run_tinyemu-virtio()
{
  ls -l $VIRTIO_FS
  $BASEPATH/sws35-stuff/tinyemu-virtio/src/fmem_virtio_host -I --block $VIRTIO_FS --block $VIRTIO_BLANK_FS 1>/dev/null 2>/dev/null
  #--debug-log >$BASEPATH/sws35-stuff/tinyemu.stdout 2>$BASEPATH/sws35-stuff/tinyemu.stderr
}

GDB_PORT=81
# BBL=$BASEPATH/riscv-freebsd-boot/bbl-dual-cheri
# DEVICETREE=$BASEPATH/riscv-freebsd-boot/devicetree.virtio.dual.wrapped.elf
BBL=$BASEPATH/riscv-freebsd-boot/bbl-dual-cheri
# only upload a device tree with 1 core - this is taken from Franz's script
DEVICETREE=$BASEPATH/sws35-stuff/devicetree.wrapped.elf

# -ex 'thread 2'
# -ex "load $BBL"
# -ex 'set $a0=0'
# -ex 'set $a1=0x80000000'

run_gdb()
{
  echo "NOTE: WE ARE RUNNING GDB AND NOT TURNING ON THE SECOND CORE/THREAD. OPENOCD IS LOOKING AT IT THOUGH"
  /usr/local/bin/gdb -ex "target remote :$GDB_PORT" \
      -ex "thread 1" \
      -ex "load $DEVICETREE" \
      -ex "load $BBL" \
      -ex 'set $a0=0' \
      -ex 'set $a1=0x80000000' \
      -ex 'thread 1' \
      -ex "echo RISCV cores ready" \
      -ex "c" \
      $BBL
}

echo "Building tinyemu"
(
  cd $BASEPATH/sws35-stuff/tinyemu-virtio && \
  cmake -DCMAKE_C_COMPILER=/usr/local/bin/cc -DCMAKE_CXX_COMPILER=/usr/local/bin/c++ -S . -B ./build/ && \
  cd ./build/ && \
  make && \
  cp ./src/fmem_virtio_host ../src/fmem_virtio_host
)

echo "Building sws35 fmem"
(
  cd $BASEPATH/sws35-stuff/fmem && make clean && make
)


echo "RISC-V Boot: beginning riscv boot"
killall -9 jtagvpi_to_fmemdmi
killall -9 openocd
killall -9 gdb
killall -9 fmem_virtio_host
killall -9 cu
echo "RISC-V Boot: Done cleaning old processes; spawning jtag to fmem bridge."
run_jtagvpi_to_fmemdmi > /dev/null &
sleep 2
echo "RISC-V Boot: spawning openocd."
run_openocd &
sleep 2
echo "RISC-V Boot: loading kernel."
load_kernel
echo "RISC-V Boot: spawning virtio server."
run_tinyemu-virtio >/dev/null 2>/dev/null &
sleep 5
echo "RISC-V Boot: spawning gdb."
run_gdb &
sleep 10
echo "ABOUT TO TURN ON CU. PRESS ENTER TWICE TO MAKE IT START POLLING THE UART."
echo "IF INSIDE AN SSH SESSION USE \\n~~. TO EXIT CU."
cu -l /dev/ttyu0

# run_gdb &
# sleep 10
# echo "RISC-V Boot: Attaching to terminal."
# # expect -c 'set timeout 2000000' \
# #        -c 'spawn cu -l /dev/ttyu0' \
# #        -c 'send -- "\r"' \
# #        -c 'expect "/bin/sh"' \
# #        -c 'send -- "mount -t msdos /dev/vtbd0 /mnt\r"' \
# #        -c 'send -- "cd /mnt/\r"' \
# #        -c 'send -- "sh runme.sh\r"' \
# #        -c 'expect "EXPECT >> RISCV >> DONE"' \
# #        -c 'exit 0'
# # TODO load some runme.sh script as above
# expect -c 'set timeout 2000000' \
#        -c 'spawn cu -l /dev/ttyu0' \
#        -c 'send -- "\r"' \
#        -c 'expect "/bin/sh"' \
#        -c 'send -- "sleep 240"' \
#        -c 'expect "EXPECT >> RISCV >> DONE"' \
#        -c 'exit 0'
# sleep 20 # Allow RISC-V to complete shutdown
# echo "EXPECT >> HPS >> DONE"
# echo "HPS Shutting Down."
# shutdown -h now
