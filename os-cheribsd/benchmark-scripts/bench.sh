#!/bin/sh

benchdir=$(dirname $0)
disk_name=""

if [ -z $disk_name ]; then
    if [ -c "/dev/vtbd-iocap1" ]; then
        disk_name="vtbd-iocap1"
    elif [ -c "/dev/vtbd1" ]; then
        disk_name="vtbd1"
    else
        echo "No disk"
        exit 1
    fi
fi

outputdir="$1"
if [ -z "$outputdir" ] ; then
    echo "specify output dir"
    exit 1
elif [ ! -d "$outputdir" ] ; then
    echo "output dir '$outputdir' doesn't exist"
    exit 1
fi

# Print commands
set -x

# : "Confirm disk exists via geometry" "In the mininal ver, geom doesn't exist"
# geom disk list "$disk_name" || { echo "No such disk"; exit 1; }

: "Confirm disk exists via dev"
test -c "/dev/$disk_name" || { echo "No such device"; exit 1; }

: "Confirm iocap is functional"
sysctl dev.iocap_keymngr

: "Enable encryption"
sysctl dev.iocap_keymngr.0.disable_encrypt=0

# I get spurious write failures 'panic: virtq_iocap_nused: vtblk_iocap1 request - used more than available', even when running with large queue,
# so as a stopgap disable the tee. I capture results by capturing the tmux buffer anyhow.

suffix="${disk_name}_nj1_enc"
"$benchdir/fio" "--filename=/dev/$disk_name" --numjobs 1 --rw=randread "$benchdir/fio_jobs.ini" # | tee "$outputdir/results_randrw_10000_${suffix}.txt"
sysctl dev.iocap_keymngr

"$benchdir/fio" "--filename=/dev/$disk_name" --numjobs 1 --rw=randrw "$benchdir/fio_jobs.ini" # | tee "$outputdir/results_randrw_5050_${suffix}.txt"
sysctl dev.iocap_keymngr

# suffix="${disk_name}_nj2_enc"
# "$benchdir/fio" "--filename=/dev/$disk_name" --numjobs 2 --rw=randread "$benchdir/fio_jobs.ini" | tee "$outputdir/results_randrw_10000_${suffix}.txt"
# sysctl dev.iocap_keymngr

# "$benchdir/fio" "--filename=/dev/$disk_name" --numjobs 2 --rw=randrw "$benchdir/fio_jobs.ini" | tee "$outputdir/results_randrw_5050_${suffix}.txt"
# sysctl dev.iocap_keymngr

# "$benchdir/fio" "--filename=/dev/$disk_name" --rw=randrw --rwmixread=70 "$benchdir/fio_jobs.ini" | tee "$outputdir/results_randrw_7030_$diskname.txt"
# sysctl dev.iocap_keymngr

# "$benchdir/fio" "--filename=/dev/$disk_name" --rw=randrw --rwmixread=30 "$benchdir/fio_jobs.ini" | tee "$outputdir/results_randrw_3070_$diskname.txt"
# sysctl dev.iocap_keymngr

case $disk_name in
    *iocap* )
        : iocap found, continue
        ;;
    * )
        : no iocaps
        exit 0
        ;;
esac

: "Disable encryption"
sysctl dev.iocap_keymngr.0.disable_encrypt=1
sysctl dev.iocap_keymngr

suffix="${disk_name}_nj1_unenc"
"$benchdir/fio" "--filename=/dev/$disk_name" --numjobs 1 --rw=randread "$benchdir/fio_jobs.ini" # | tee "$outputdir/results_randrw_10000_${suffix}.txt"
sysctl dev.iocap_keymngr

"$benchdir/fio" "--filename=/dev/$disk_name" --numjobs 1 --rw=randrw "$benchdir/fio_jobs.ini" # | tee "$outputdir/results_randrw_5050_${suffix}.txt"
sysctl dev.iocap_keymngr

# suffix="${disk_name}_nj2_unenc"
# "$benchdir/fio" "--filename=/dev/$disk_name" --numjobs 2 --rw=randread "$benchdir/fio_jobs.ini" | tee "$outputdir/results_randrw_10000_${suffix}.txt"
# sysctl dev.iocap_keymngr

# "$benchdir/fio" "--filename=/dev/$disk_name" --numjobs 2 --rw=randrw "$benchdir/fio_jobs.ini" | tee "$outputdir/results_randrw_5050_${suffix}.txt"
# sysctl dev.iocap_keymngr

# "$benchdir/fio" "--filename=/dev/$disk_name" --rw=randrw --rwmixread=70 "$benchdir/fio_jobs.ini" | tee "$outputdir/results_randrw_7030_$diskname.txt"
# sysctl dev.iocap_keymngr

# "$benchdir/fio" "--filename=/dev/$disk_name" --rw=randrw --rwmixread=30 "$benchdir/fio_jobs.ini" | tee "$outputdir/results_randrw_3070_$diskname.txt"
# sysctl dev.iocap_keymngr
