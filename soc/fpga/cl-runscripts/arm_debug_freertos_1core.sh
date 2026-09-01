#!/usr/bin/env sh

# Enable Job Control mode, where all spawned processes run in separate process groups, including backgrounded processes.
# This means any signals this script receives (e.g. SIGINT from Ctrl-C) are passed through to only the foreground process, not any other background processes.
set -m

# Ensure that /usr/local/lib is searched for .so files - this should always be the case anyway but sometimes just... doesn't happen!!!!!
# If this wasn't here there would be spurious failures like 'failed to find libwhatever.so'
ldconfig /usr/local/lib

BASEPATH=/root

# For tinyemu
export RISCV_ADDRESS_SELECTOR_FMEM_DEV=/dev/fmem_sys0_h2f_addr_ctrl

run_jtagvpi_to_fmemdmi()
{
  # This is guaranteed to already exist
  $BASEPATH/jtagvpi_to_fmemdmi/jtagvpi_to_fmemdmi 1>jtag.log 2>&1
}

OPENOCD_CFG=$BASEPATH/sws35-stuff/openocd_1hart.cfg
run_openocd()
{
  # this has more errors with our debug unit
  # $BASEPATH/sws35-stuff/riscv-openocd/src/openocd -f $OPENOCD_CFG
  /usr/local/bin/openocd -f $OPENOCD_CFG
}

VIRTIO_FS=$BASEPATH/sws35-stuff/virtio.fs
run_tinyemu-virtio()
{
  ls -l $VIRTIO_FS
  $BASEPATH/sws35-stuff/tinyemu-virtio/src/fmem_virtio_host --block $VIRTIO_FS --debug-log >$BASEPATH/sws35-stuff/tinyemu.stdout 2>$BASEPATH/sws35-stuff/tinyemu.stderr
}

GDB_PORT=81
KERNEL=$BASEPATH/sws35-stuff/freertos.elf

run_gdb()
{
  $BASEPATH/sws35-stuff/fmem/fmem_load_elf $KERNEL
  # RISCV_ADDRESS_SELECTOR_FMEM_DEV=/dev/fmem_sys0_h2f_addr_ctrl $BASEPATH/sws35-stuff/fmem/fmem_dump 0xc0000000 0xc0000600 w dump.bin
  # Literally actually kill yourself :(((( 0xc0000000 is cached
  #    -ex "load $KERNEL" 

  /usr/local/bin/gdb -ex "target remote :$GDB_PORT" \
      -ex "load $KERNEL" \
      -ex 'set $a0=0' \
      -ex 'set $pc=0xc0000000' \
      -ex 'set os none' \
      -ex "echo RISCV core ready" \
      $KERNEL
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

# echo "Building openocd"
# (
#   cd $BASEPATH/sws35-stuff/openocd && \
#   ./bootstrap && ./configure --enable-jtag_vpi && \
#   make
# )

# echo "Check commit for tinyemu"
# (cd $BASEPATH/tinyemu-virtio && git status)

# echo "Resetting time to ensure pkg install and git clone work"
# service ntpd stop
# ntpd -g -q freebsd.pool.ntp.org
# echo "Recompiling riscv-openocd with gmake"
# pkg install gmake
# (
#   cd $BASEPATH/sws35-stuff/riscv-openocd && \
#   ./bootstrap nosubmodule && ./configure --enable-jtag_vpi && \
#   gmake
# )

# echo "Recompiling jtagvpi in debug mode"
# (
#   # fucking freebsd i swear to god
#   cd $BASEPATH/jtagvpi_to_fmemdmi && gmake mrproper && gmake DEBUG=1 jtagvpi_to_fmemdmi
# )

# # sysrc ntpd_sync_on_start=YES && service ntpd restart
# echo "Recompiling tinyemu-virtio"
# # pkg install cmake
# (cd $BASEPATH && \
# 	rm -rf tinyemu-virtio && \
#     git clone https://github.com/theturboturnip/tinyemu-virtio.git && \
#     cd tinyemu-virtio && \
#     git switch de10 && \
#     cmake -DCMAKE_C_COMPILER=/usr/local/bin/cc -DCMAKE_CXX_COMPILER=/usr/local/bin/c++ -S . -B ./build/ && \
#     cd ./build/ && \
#     make && \
#     cp ./src/fmem_virtio_host ../src/fmem_virtio_host \
# )
# ls -lah -R $BASEPATH/tinyemu-virtio

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
# sleep 32
# echo "RISC-V Boot: loading kernel."
# load_kernel
echo "RISC-V Boot: spawning virtio server."
run_tinyemu-virtio &
sleep 5
echo "RISC-V Boot: spawning gdb."
# cu needs newlines before it starts pulling output from the UART?
printf "\r\n\r\n\r\n" | cu -s 115200 -l /dev/ttyu0 &
echo "Current processes:"
pgrep -l -u root
run_gdb
# sleep 10
# echo "RISC-V Boot: Attaching to terminal."
# # expect -c 'set timeout 2000000' \
# #        -c 'spawn cu -l /dev/ttyu0' \
# #        -c 'send -- "\r"' \
# #        -c 'expect "/bin/sh"' \
# #        -c 'send -- "mount -t msdos /dev/vtbd0 /mnt\r"' \
# #        -c 'send -- "cd /mnt/\r"' \
# #        -c 'send -- "sh runme.sh\r"' \
# #        -c 'expect ""' \
# #        -c 'exit 0'EXPECT >> RISCV >> DONE
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