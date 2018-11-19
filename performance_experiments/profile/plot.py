#!/usr/bin/python3
import re, codecs, os
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt



# first strip out checks and average files
# place values into a dictionary of data frames
# where d[schedule + n_threads] = data frame

df = pd.read_csv('g6p3.tsv',index_col=0, sep='\t')
print(df)

plt.figure()
axes = plt.axes()
axes.set_xlabel("Compile Flags")
axes.set_ylabel("Speedup")
#axes.set_ylim([0,6])
#axes.set_xticks([1.0,1.5,2.0,2.5])
axes.set_xticks([0,1, 2,3,4,5])
p = df.plot(ax=axes, marker='o').get_figure()
p.savefig("g.eps", format='eps')

#print(d_name)
#print(data[d_name].sort_index())
#print("Loop 2")
#print(data["Loop 2"].sort_index())

#for key in data:
#    data[key] = data[key].sort_index()
#    plt.figure()
#    axes = plt.axes()
#    axes.set_xlabel("Chunksize")
#    axes.set_ylabel("Time (seconds)")
#    axes.set_ylim([0,6])
#    axes.set_xticks([1, 4, 8, 16,32,64])
#    axes.set_yticks([0,0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0,4.5,5.0,5.5,6.0])
#    p = data[key].plot(title=key.upper(), ax=axes, marker='o').get_figure()

#    p.savefig(plots+key.replace(" ", ""))
#    print("Plot", key, "generated")
    
                
