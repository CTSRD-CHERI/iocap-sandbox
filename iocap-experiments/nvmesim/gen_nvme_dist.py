import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("t_avg", type=int)
    parser.add_argument("t_max", type=int)
    parser.add_argument("theta", type=int)
    parser.add_argument("--split", type=float, default=0.95)
    parser.add_argument("--t_max_pos", type=float, default=1)
    args = parser.parse_args()

    # t1, t2, t_max model
    # at 0, split, t_max_pos
    # sum = total area under curve
    # t_100 = t_max + (100 - t_max_pos) * (t_max - t2) / (t_max_pos - split)
    # = (split * (t1 + t2) / 2) + ((t_max_pos - split) * (t2 + t_max) / 2) + ((100 - t_max_pos) * (t_100 + t_max) / 2)
    # = (split * (t1 + t2) / 2) + ((t_max_pos - split) * (t2 + t_max) / 2) + ((100 - t_max_pos) * (((100 - t_max_pos) * (t_max - t2) / (t_max_pos - split)) + t_max) / 2)
    # = 100t_avg
    #
    # place t_avg at the 50th percentile
    # t1 = t_avg - (50/split) * theta
    # t2 = t_avg + ((split - 50)/split) * theta = t_avg + (1 - (50/split)) * theta
    # t1 + t2 = t_avg + ((split - 100)/split) * theta = t_avg + (1 - (100/split)) * theta
    #
    # 100t_avg =
    #   (split * (t_avg + (1 - (100/split)) * theta) / 2)
    #       = theta * (split * (1 - (100/split)) / 2) + t_avg * (split / 2)
    #   + ((t_max_pos - split) * (t_avg + (1 - (50/split)) * theta + t_max) / 2)
    #       = theta * (1 - (50/split)) * ((t_max_pos - split) / 2) + (t_avg + t_max) * ((t_max_pos - split) / 2)
    #   + ((100 - t_max_pos) * (((100 - t_max_pos) * (t_max - t_avg + (1 - (50/split)) * theta) / (t_max_pos - split)) + t_max) / 2)
    #       = ((100 - t_max_pos) / 2) * (
    #           (100 - t_max_pos) * (
    #               t_max - t_avg + (1 - (50/split)) * theta
    #           ) / (t_max_pos - split)
    #             ) + t_max)
    #           =
    #       = (theta * (1 - (50/split)) * (100 - t_max_pos)* ((100 - t_max_pos) / 2) / (t_max_pos - split))

    t_avg = args.t_avg
    t_max = args.t_max
    split = args.split
    t_max_pos = args.t_max_pos

    assert split > 0.5

    # my ver (wrong)
    a = split / 2
    b = (t_max_pos - split) / 2
    c = ((1 - t_max_pos) ** 2) / (2 * (t_max_pos - split))
    # 100 * t_avg = theta * (a + b - c) + t1 * (split + b - c) + t_top * (b + c + 2)
    # t1 = t_avg + 50 * theta/split
    # 100 * t_avg = theta * (a + b - c) + t_avg * (split + b - c) + theta * (split + b - c) * (50 / split) + t_top * (b + c + 2)
    #             = theta * (a + b - c + (split + b - c) * (50 / split)) + t_avg * (split + b - c) + t_top * (b + c + 2)
    # theta = (100 * t_avg - (split + b - c) * t_avg - t_top * (b + c + 2))/(a + b - c + (split + b - c) * (50 / split))
    theta = -(
        1 * t_avg - (split + b - c) * t_avg - t_max * (b + c + 1)  #
    ) / (  #
        a + b - c - (split + b - c) * (0.5 / split)  #
    )

    # claude ver (correct)
    theta = (  #
        t_avg - t_max * (1 - split) ** 2 / (2 * (t_max_pos - split))  #
    ) / (  #
        1 - (split / 2) - (1 - split) ** 2 / (2 * (t_max_pos - split))
    )

    t1 = t_avg - (0.5 / split) * theta
    t2 = t1 + theta
    t100 = (1 - t_max_pos) * (t_max - t2) / (t_max_pos - split) + t_max

    # but this is forced to be linear!
    # instead!
    # redefine: fix theta, figure out where to put t1 and t2 to reach desired mean.
    theta = args.theta

    # assumes t_max_pos == 1
    t1 = (  #
        t_avg - split * theta / 2 - (1 - split) * (t_max + theta) / 2
    ) / (  #
        split + (1 - split) / 2  #
    )
    # t_max_pos > split
    d = (1 - split) * (1 - t_max_pos) / (2 * (t_max - split))
    e = split + (1 - split) / 2
    t1 = (
        (  #
            t_avg
            - split * theta / 2
            - (1 - split) * (t_max + theta) / 2
            - d * (t_max - theta)
        )
        / (  #
            e  #
        )
    ) / (1 - d / e)
    t2 = t1 + theta
    t100 = (1 - t_max_pos) * (t_max - t2) / (t_max_pos - split) + t_max

    print(theta)
    print(split + b - c)
    print(c)

    comp_mean = (
        split * (t1 + t2) / 2
        + (t_max_pos - split) * (t_max + t2) / 2
        + (1 - t_max_pos) * (t100 + t_max) / 2
    )
    print(comp_mean)

    for x, y in [
        (0, t1),
        (split, t2),
        (t_max_pos, t_max),
        (1, t100),
    ]:
        print(f"{int(x * 100):3d}\t{y:.1f}")

    # now generate 100-entry histogram (or is it a PDF?)
    histogram = []
    for i in range(101):
        if i <= int(split * 100):
            val = t1 + (t2 - t1) * (i * 0.01 / split)
        elif i <= int(t_max_pos * 100):
            val = t2 + (t_max - t2) * ((i * 0.01 - split) / (t_max_pos - split))
        else:
            val = t_max + (t100 - t_max) * ((i * 0.01 - t_max_pos) / (1 - t_max_pos))
        histogram.append(val)
    print([int(h) for h in histogram])
