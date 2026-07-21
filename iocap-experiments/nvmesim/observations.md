# In-order

We can see from in-order-q32 that you get discrete 'shelves'.
We can see from in-order-q08 and in-order-q1024 that these are independent of the queue depth, they depend on q_iops only.
IOPS = 100_000 => inbetween time = 1E-5 = 10k ns
completion latency = 30k ns
consider scenario: queue is full. you are the first element under your lease. you open (completion pending at t=30k). the next element is filled in after 10k ns, it will complete at 10k + 30k = 40k. your overexposure is 10k if it stops there. their overexposure is 0k. the third element is filled in at t=20k, completes at t=50k. your overexposure is 20k if it stops there. the second element's overexposure is 10k. the third is 0k.
the fourth element is filled in at 30k, completes at 60k. (1st = 30k, 2nd=20k, 3rd=10k, 4th=0k).
the fifth element is filled in at 40k, completes at 70k. (1st = 40k, 2nd=30k, 3rd=20k, 4th=10k, 5th=0k).
the sixth element is filled in at 50k, completes at 80k. (1st = 50k, 2nd=40k, 3rd=30k, 4th=20k, 5th=10k, 6th=0k).
the seventh element is filled in at 60k, completes at 90k. (1st = 60k, 2nd=50k, 3rd=40k, 4th=30k, 5th=20k, 6th=10k, 7th=0k).

consider four-elements, completed at 60k. delay = 30k, 20k, 10k, 0k. repeat. expect four steps, but don't get. why?
becuase it was broken! fixed. was trying to enqueue too fast.

out_order_unsaturated variants do not have the queue blocking problem. haas has queue blocking problem but only reaches max iops when queue > 4 (surely queue not fully occupied at that point?)

for haas:
maximum queue blocking delay = number_of_steps/per_q_iops = (q_len - 2)/(per_q_iops)
  = 14 / 20k = roughly 0.75ms = 750us = 750_000ns
per_q_iops = 20k => 50_000ns thruput
t_max = 400_000ns
delta_t_max = 225_000ns
over_max = maximum queue blocking delay + delta_t_max (right now assume l_ops = 2)
= 750_000ns + 225_000ns = 975_000ns, too long. 

haas_q{16,32} max overexposure matches, for l_ops=2 274300 for l_ops=4 376727
standard calc expects (l_ops-1)*l + delta_t_max: 50k + 225k... which is correct lol

ok! so one would expect that exactly bandwidth-delay-product 8 (20k * 400us) would be enough.
Is that true?
yes - for haas, q08 (actual parallel q elements = 7) is just over the expected, then q09 is exact.

the out_order baselines were 1*thruput extra - that was down to a round-robin bug

computed Haas histogram from `uv run gen_nvme_dist.py 175000 400000 20000 --split 0.9 --t_max_pos 0.99`
i.e. with 20us spread up until the 90th percentile

computed out-of-order histogram from `uv run gen_nvme_dist.py 50000 100000 20000 --split 0.9 --t_max_pos 1`
which makes latencies more realistic but around 10x lower than they were before!!! 
8x-d the iops to compensate.
800k iops seems realistic for e.g. 2021 samsung 980 pro https://download.semiconductor.samsung.com/resources/data-sheet/Samsung-NVMe-SSD-980-PRO-Data-Sheet_Rev.2.1_230509_10129505081019.pdf
