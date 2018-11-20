#!/usr/bin/python

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# fix to use fig.savefig()
plt.switch_backend('agg')

df = pd.read_excel("gprof_profile_table.xlsx", sheet_name="input")

time_list = df["time"].tolist()
name_list = df["name"].tolist()

y_pos = np.arange(len(name_list))

fig = plt.figure()
plt.bar(y_pos, time_list, align='center', alpha=0.5)
plt.xticks(y_pos, name_list)
plt.ylabel('% time')

#fig.autofmt_xdate()
plt.setp(plt.xticks()[1], rotation=30, ha='right')
# ha is the same as horizontalalignment

fig.subplots_adjust(bottom=0.26)
plt.savefig("execution_time.eps", format="eps")