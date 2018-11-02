#!/usr/bin/env python2
# data_analyzer.py

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

    time = ()
    pumas = ()
    hares = ()

    for line in data_file:
        data = line.split('\t')
                
        time = time + (float("%.3f" % float(data[0])),)
        pumas = pumas + (float("%.3f" % float(data[1])),)
        hares = hares + (float("%.3f" % float(data[2])),)

    create_plots(
        "average_density",
        "Time",
        "Average Density",
        ["pumas", "hares"],
        time,
        [pumas, hares],
        0.4,
        "upper right"
    )


f = open('./output/average_density.dat', 'r')

analyze_data(f)
