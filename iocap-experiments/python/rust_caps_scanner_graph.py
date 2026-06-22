from dataclasses import dataclass
import math
import tomllib
from typing import Dict, List, Optional, Tuple, TypedDict
import matplotlib.figure
import matplotlib.pyplot as plt
import numpy as np
import argparse
import mplcursors

class Test(TypedDict):
    name: str
    tsv: str

def test_points(test: Test, x: str, y: str) -> List[Tuple[int, int]]:
    tsv = test["tsv"].strip()

    x_cols = None
    y_cols = None
    datas: List[Tuple[int,int]] = []

    def int_parse(val):
        if val.startswith("0x"):
            return int(val, base=16)
        else:
            return int(val, base=0)

    for line in tsv.splitlines():
        line = line.strip()
        if not line:
            continue
        contents = line.split("\t")
        if x_cols is None or y_cols is None:
            try:
                x_cols = contents.index(x)
                y_cols = contents.index(y)
            except ValueError:
                raise RuntimeError(f"Test {test['name']} has line '{line}', columns {contents}, wanted {x} and {y}")
        else:
            data = (
                int_parse(contents[0]),
                int_parse(contents[1]),
                int_parse(contents[2]),
            )
            datas.append(
                (data[x_cols], data[y_cols])
            )

    # new_datas: List[Tuple[int,int]] = []
    # last = None
    # for i, (px, py) in enumerate(datas):
    #     if last is not None and i != len(datas) - 1:
    #         lx, ly = last
    #         if py == ly:
    #             # do not append data, its on a horizontal line
    #             # ACTUALLY THIS IS BAD, YOU CAN ONLY DISCARD POINTS INSIDE A LINE NOT POINTS THAT WOULD BE THE END OF A HORIZONTAL LINE
    #             continue
    #     new_datas.append((px, py))
    #     last = px, py
    # return new_datas

    # Uniquify while retaining order
    return list(dict.fromkeys(datas))


@dataclass
class CapKindInfo:
    intended_max_length_pow2: int = 64
    base_test: Optional[str] = "base_align_unified"
    length_test: Optional[str] = "length_align_unified"

configs = {
    "mmachine": CapKindInfo(intended_max_length_pow2=54),
    "aries": CapKindInfo(intended_max_length_pow2=64),
    "lowfat": CapKindInfo(intended_max_length_pow2=46),
    "cheriv9": CapKindInfo(intended_max_length_pow2=64),
    "rv64y": CapKindInfo(intended_max_length_pow2=64),
    "cheri256": CapKindInfo(intended_max_length_pow2=64),
    "iocap2024_11": CapKindInfo(intended_max_length_pow2=64,
                                base_test="base_align_legacy",
                                length_test="length_precision_legacy_pessimistic"),
    "iocap2024_11_cavs": CapKindInfo(intended_max_length_pow2=64,
                                base_test="base_align_legacy",
                                length_test=None),
    "iocap2024_11_simulated_improved_cavs": CapKindInfo(intended_max_length_pow2=64),
    "iocap_thesisdemo32": CapKindInfo(intended_max_length_pow2=64),
    "iocap_thesisopt": CapKindInfo(intended_max_length_pow2=64),
    "iocap_thesisopt_cav1": CapKindInfo(intended_max_length_pow2=64),
    "iocap_thesisopt_cav12": CapKindInfo(intended_max_length_pow2=64),
    "iocap_thesisopt_cav1_complex": CapKindInfo(intended_max_length_pow2=64),
    "iocap_thesisopt_cav12_complex": CapKindInfo(intended_max_length_pow2=64),
}

display_configs = {
    None: {
        "marker": "o",
    },
    "base": {
        "marker": "x",
        "fillstyle":'none',
        "linestyle": (0, (5, 5)),
    },
    "len": {
        "marker": "o",
        "fillstyle":'none',
        "linestyle": (5, (5, 5)),
    }
}

def plot_on_ax(cap: str, data: Optional[List[Tuple[int, int]]], ax: plt.Axes, color_idx: int, label=None, plot_kind=None, f_x=math.log2, f_y=lambda x: x):
    if not data:
        return
    config = configs[cap]
    x_lim = 1 << config.intended_max_length_pow2

    ax.plot(
        [f_x(x) for (x, y) in data if x <= x_lim],
        [f_y(y) for (x, y) in data if x <= x_lim],

        **display_configs[plot_kind],

        color=f"C{color_idx}",

        # [math.log2(x) for (x, y) in data if x > x_lim],
        # [y for (x, y) in data if x > x_lim],
        # "x--",
        label=label or cap,
    )

def optimal_n_subplots(n: int, max_per_row: int=3) -> Tuple[matplotlib.figure.Figure, np.ndarray]:
    min_n_rows = math.ceil(n / max_per_row)
    n_per_row = math.ceil(n / min_n_rows)

    fig, axes = plt.subplots(min_n_rows, n_per_row)

    if min_n_rows * n_per_row > n:
        flat_axes = axes.flat
        for i in range(n, min_n_rows * n_per_row):
            flat_axes[i].clear()
            flat_axes[i].set_axis_off()

    return fig, axes

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("--mode", default="bl")
    parser.add_argument("results")
    args = parser.parse_args()

    with open(args.results, "rb") as f:
        results: Dict[str, List[Test]] = tomllib.load(f)
    del results["timestamp"]
    del results["generated_by"]
    del results["git_hash"]

    base_data: Dict[str, Optional[List[Tuple[int, int]]]] = {}
    length_data: Dict[str, Optional[List[Tuple[int, int]]]] = {}
    for (cap, tests) in results.items():
        config = configs[cap] or CapKindInfo()
        if config.base_test:
            base_test = next(t for t in tests if t["name"] == config.base_test)
            base_data[cap] = test_points(base_test, x="intended_len", y="base_align")
        else:
            base_data[cap] = None
        if config.length_test:
            length_test = next(t for t in tests if t["name"] == config.length_test)
            length_data[cap] = test_points(length_test, x="intended_len", y="len_align")
        else:
            length_data[cap] = None

    def config_ax(ax, *, title: str):
        def show_annotation(sel):
            xi, yi = sel.target
            sel.annotation.set_text(f'{xi:.3f}\nvalue:{yi:.3f}')

        cursor = mplcursors.cursor(ax.lines) #, highlight=True)
        cursor.connect('add', show_annotation)

        ax.plot([-10, 64+10], [-10, 64+10], "lightgray", zorder=0)

        ax.set_xbound(lower=-10, upper=64+10)
        major_x = list(range(0, 65, 8))
        minor_x = list(range(0, 65, 2))
        ax.set_xticks(
            major_x,
            [f"$2^{{{x}}}$" for x in major_x],
        )
        ax.set_xticks(
            list(x for x in minor_x if x not in major_x),
            minor=True,
        )
        ax.set_ybound(lower=-10, upper=64+10)
        major_y = list(range(0, 65, 8))
        minor_y = list(range(0, 65, 2))
        ax.set_yticks(
            major_y,
            [f"$2^{{{y}}}$" for y in major_y],
        )
        ax.set_yticks(
            list(y for y in minor_y if y not in major_y),
            minor=True,
        )
        ax.xaxis.grid(color='gray', linestyle='dashed')
        ax.yaxis.grid(color='gray', linestyle='dashed')
        # ax.hlines(0, -10, 64+10, 'gray')
        # ax.vlines(0, -10, 64+10, 'gray')
        ax.legend()
        ax.set_title(title)

    if args.mode == "bl":
        # Two figures, each with all caps plotted
        f, (base_ax, length_ax) = plt.subplots(nrows=1, ncols=2)

        for i, cap in enumerate(results.keys()):
            plot_on_ax(cap, base_data[cap], base_ax, color_idx=i)
            plot_on_ax(cap, length_data[cap], length_ax, color_idx=i)

        config_ax(base_ax, title="Base")
        config_ax(length_ax, title="Length")

    elif args.mode.startswith("caps"):
        if args.mode.startswith("caps:"):
            caps = args.mode.removeprefix("caps:").split(",")
        else:
            caps = results.keys()

        # Per-cap figures with base and length together
        n_total_figures = len(caps)
        f, axs = optimal_n_subplots(n_total_figures)
        # print(axs)
        for i, (cap, ax) in enumerate(zip(caps, axs.flat)):
            plot_on_ax(cap, base_data[cap], ax, color_idx=i, label="base", plot_kind="base")
            plot_on_ax(cap, length_data[cap], ax, color_idx=i, label="length", plot_kind="len")
            config_ax(ax, title=cap)
    elif args.mode == "split":
        n_total_figures = len(results) * 2
        f, axs = optimal_n_subplots(n_total_figures)
        axs = axs.flat
        # print(axs)
        for (i, cap) in enumerate(results.keys()):
            plot_on_ax(cap, base_data[cap], axs[i * 2], color_idx=i, label="base")
            config_ax(axs[i * 2], title=f"{cap} Base")
            plot_on_ax(cap, length_data[cap], axs[i * 2 + 1], color_idx=i, label="length")
            config_ax(axs[i * 2 + 1], title=f"{cap} Length")
    elif args.mode.startswith("compare:"):
        caps = args.mode.removeprefix("compare:").split(",")
        f, ax = optimal_n_subplots(1)

        for i, cap in enumerate(caps):
            plot_on_ax(cap, base_data[cap], ax, color_idx=i, label=f"{cap} base", plot_kind="base")
            plot_on_ax(cap, length_data[cap], ax, color_idx=i, label=f"{cap} length", plot_kind="len")
        config_ax(ax, title="Compare " + " vs. ".join(caps))
    elif args.mode.startswith("compareduct:"):
        caps = args.mode.removeprefix("compareduct:").split(",")
        f, ax = optimal_n_subplots(1)

        for i, cap in enumerate(caps):
            t = next(t for t in results[cap] if t["name"] == "reduction")
            td = test_points(t, x="initial_len", y="smallest_len")
            plot_on_ax(cap, td, ax, color_idx=i, label=f"{cap} reduction", f_y=lambda x: math.log2(x) if x > 0 else 0)
        config_ax(ax, title="Compare Reduction " + " vs. ".join(caps))
    elif args.mode == "iocap2024_11:reduct":
        f, ax = optimal_n_subplots(1)

        # cap = "iocap2024_11"
        # plot_on_ax(cap, base_data[cap], ax, color_idx=0, label=f"{cap} base precision", plot_kind="base")
        # plot_on_ax(cap, length_data[cap], ax, color_idx=0, label=f"{cap} length precision", plot_kind="len")

        cap = "iocap2024_11_cavs"
        t = next(t for t in results[cap] if t["name"] == "cav1_reduction")
        td = test_points(t, x="initial_len", y="smallest_len")
        plot_on_ax(cap, td, ax, color_idx=1, label=f"cav1 reduction", f_y=math.log2)
        t = next(t for t in results[cap] if t["name"] == "cav12_reduction")
        td = test_points(t, x="initial_len", y="smallest_len")
        # cav1+2 can result in 0-size
        plot_on_ax(cap, td, ax, color_idx=2, label=f"cav1+2 reduction", f_y=lambda x: math.log2(x) if x > 0 else 0)

        config_ax(ax, title="IOCap2024_11 Reduction Potential")
    elif args.mode == "iocap2024_11:precis":
        f, ax = optimal_n_subplots(1)

        cap = "iocap2024_11"
        plot_on_ax(cap, base_data[cap], ax, color_idx=0, label=f"{cap} base", plot_kind="base")
        plot_on_ax(cap, length_data[cap], ax, color_idx=0, label=f"{cap} length", plot_kind="len")

        cap = "iocap2024_11_cavs"
        t = next(t for t in results[cap] if t["name"] == "base_align_legacy")
        td = test_points(t, x="intended_len", y="base_align")
        plot_on_ax(cap, td, ax, color_idx=2, label=f"cav1+2 precision")
        
        config_ax(ax, title="IOCap2024_11 Precision Potential")
    elif args.mode == "iocap_thesisopt:reduct":
        f, ax = optimal_n_subplots(1)

        # cap = "iocap2024_11"
        # plot_on_ax(cap, base_data[cap], ax, color_idx=0, label=f"{cap} base precision", plot_kind="base")
        # plot_on_ax(cap, length_data[cap], ax, color_idx=0, label=f"{cap} length precision", plot_kind="len")

        cap = "iocap_thesisopt_cav1"
        t = next(t for t in results[cap] if t["name"] == "reduction")
        td = test_points(t, x="initial_len", y="smallest_len")
        plot_on_ax(cap, td, ax, color_idx=1, label=f"cav1 reduction", f_y=math.log2)

        cap = "iocap_thesisopt_cav12"
        t = next(t for t in results[cap] if t["name"] == "reduction")
        td = test_points(t, x="initial_len", y="smallest_len")
        # cav1+2 can result in 0-size
        plot_on_ax(cap, td, ax, color_idx=2, label=f"cav1+2 reduction", f_y=lambda x: math.log2(x) if x > 0 else 0)

        config_ax(ax, title="IOCap Thesis-Opt Reduction Potential")
    else:
        raise RuntimeError(f"Not implemented {args.mode}")

    plt.show()