#!/usr/bin/env python2
# data_analyzer.py
import os
import matplotlib.pyplot as plt


def create_plots(title, x_axis_title, y_axis_title, labels, x_values, y_values, alpha, legent_pos):

    fig, ax = plt.subplots()
    ax.set_xlabel(x_axis_title)
    ax.set_ylabel(y_axis_title)

    colors = ['#d3390a', '#35d20a']

    lines = []

    i = 0
    for y_list in y_values:
        lines.append(plt.plot(x_values, y_list, label=labels[i], linewidth=2, color=colors[i]))
        i = i + 1

    plt.legend(loc=legent_pos)

    fig.savefig('./output/' + str(title) + '.eps', format='eps', dpi=1000)

def analyze_data(data_file):

    i = 0;

    time = ()
    pumas = ()
    hares = ()

    for line in data_file:
        if i == 0:
            titles = line.split('\t')
        else:
            data = line.split('\t')
            time = time + (float("%.3f" % float(data[0])),)
            pumas = pumas + (float("%.3f" % float(data[1])),)
            hares = hares + (float("%.3f" % float(data[2])),)
        i = i + 1

    create_plots(
        "average_density",
        titles[0],
        "Average Density",
        [titles[1], titles[2]],
        time,
        [pumas, hares],
        0.4,
        "upper right"
    )


path = './output/average_density.dat'

if os.path.exists(path):
    f = open(path, 'r')
    analyze_data(f)
