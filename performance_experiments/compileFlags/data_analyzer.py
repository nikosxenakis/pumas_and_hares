#!/usr/bin/env python2
# data_analyzer.py
import os
import matplotlib.pyplot as plt


def create_plots(title, x_axis_title, y_axis_title, labels, x_values, y_values, alpha, legent_pos):

    fig, ax = plt.subplots()
    ax.set_xlabel(x_axis_title)
    ax.set_ylabel(y_axis_title)
    ax.set_xticks([1.0,1.5,2.0,2.5])
    colors = ['#22A7F0', '#d3390a', '#35d20a']

    lines = []

    i = 0
    for y_list in y_values:
        lines.append(plt.plot(x_values, y_list, linewidth=2, color=colors[i]))
        i = i + 1

    fig.savefig('./' + str(title) + '.eps', format='eps', dpi=1000)

def analyze_data(data_file):

    i = 0;

    titles = ()
    cflags = ()
    speedup = ()

    for line in data_file:
        data = line.split('\t')

        if i == 0:
            titles = data
        else:
            cflags = cflags + (data[0] ,)
            speedup = speedup + (data[1] ,)
        i = i + 1

    create_plots(
        str("Flags"),
        titles[0],
        str("Speedup"),
        [titles[1]],
        cflags,
        [speedup],
        0.4,
        "lower right"
    )


path = './g6p3.tsv'

if os.path.exists(path):
    f = open(path, 'r')
    analyze_data(f)

