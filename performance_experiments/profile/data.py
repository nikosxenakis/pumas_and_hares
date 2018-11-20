#!/usr/bin/python

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# fix to use fig.savefig()
plt.switch_backend('agg')

###
# exec time
###
df = pd.read_excel("gprof_profile_table.xlsx", sheet_name="exec_time")

time_list = df["time"].tolist()
name_list = df["name"].tolist()

y_pos = np.arange(len(name_list))

fig = plt.figure(1)
plt.bar(y_pos, time_list, align='center', alpha=0.5)
plt.xticks(y_pos, name_list)
plt.ylabel('% time')

#fig.autofmt_xdate()
plt.setp(plt.xticks()[1], rotation=30, ha='right')
# ha is the same as horizontalalignment

fig.subplots_adjust(bottom=0.26)
plt.savefig("execution_time.eps", format="eps")

####
# memory snapshots
####
df2 = pd.read_excel("gprof_profile_table.xlsx", sheet_name="memory_snapshots")

timei = df2["time(i)"].tolist()
totalb = df2["total(B)"].tolist()
usefulheapb = df2["useful-heap(B)"].tolist()
extraheapb = df2["extra-heap(B)"].tolist()
# stacksb = df2["stacks(B)"].tolist()

plt.figure(2)
plt.plot(np.array(timei), np.array(totalb), label="total memory consumption", marker=">", color="green")
plt.plot(np.array(timei), np.array(usefulheapb), label="number of useful heap bytes", marker="o", color="blue")
plt.plot(np.array(timei), np.array(extraheapb), label="number of extra heap bytes", marker="x", color="red")
plt.legend(loc="best")
plt.xlabel("Instructions executed in millions")
plt.ylabel("Kilobyte (kB)")
# adjust padding so that both xlabel and ylabel are displayed
#plt.subplots_adjust(left=.1)
ax = plt.axes() # get current axes
# ticks only at data points
#ax.set_xticks(timei)
#plt.setp(plt.xticks()[1], rotation=30, ha='right')
plt.savefig("memory_overhead.eps", format="eps")