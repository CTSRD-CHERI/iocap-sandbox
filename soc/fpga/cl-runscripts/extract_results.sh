#!/bin/sh

mkdir -p results mounted_results
d=$(mdconfig -a -t vnode -f cheribsd.fs) || { echo 'failed to md'; exit 1; }
mount -t ufs "/dev/${d}p2" mounted_results || { echo 'failed to mount'; exit 1; }
cp mounted_results/root/bench/*.txt results/
umount mounted_results
sync
