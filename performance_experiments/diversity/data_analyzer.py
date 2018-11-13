#!/usr/bin/env python2
# data_analyzer.py
import os
import matplotlib.pyplot as plt


def create_plots(title, x_axis_title, y_axis_title, labels, x_values, y_values, alpha, legent_pos):

    fig, ax = plt.subplots()
    ax.set_xlabel(x_axis_title)
    ax.set_ylabel(y_axis_title)

    colors = ['#35d20a', '#d3390a']

    lines = []

    i = 0
    for y_list in y_values:
        lines.append(plt.plot(x_values, y_list, label=labels[i], linewidth=2, color=colors[i]))
        i = i + 1

    plt.legend(loc=legent_pos)

    fig.savefig('./' + str(title) + '.eps', format='eps', dpi=1000)

def analyze_data(data_file):

    i = 0;

    titles = ()
    ratio = ()
    time = ()
    memory = ()

    for line in data_file:
        data = line.split('\t')

        if i == 0:
            titles = data
        else:
            ratio = ratio + ( float("%.2f" % float(data[0]) ) ,)
            time = time + ( float("%.2f" % float(data[1]) ) ,)
            memory = memory + ( float("%.2f" % float(data[2]) ) ,)
        i = i + 1

    create_plots(
        str("time"),
        titles[0],
        str("time"),
        [titles[1]],
        ratio,
        [time],
        0.4,
        "lower right"
    )

    create_plots(
        str("memory"),
        titles[0],
        str("memory"),
        [titles[1]],
        ratio,
        [memory],
        0.4,
        "lower right"
    )

path = './data.tsv'

if os.path.exists(path):
    f = open(path, 'r')
    analyze_data(f)

