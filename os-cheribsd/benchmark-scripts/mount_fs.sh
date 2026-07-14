#!/bin/sh

mkdir ./mounted_results/

if [ -c "/dev/vtbd-iocap1" ]; then
    mount /dev/vtbd-iocap0p2 ./mounted_results/
elif [ -c "/dev/vtbd1" ]; then
    mount /dev/vtbd0p2 ./mounted_results/
fi
