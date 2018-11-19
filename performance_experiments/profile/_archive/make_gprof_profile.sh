#!/bin/sh
# 1. compile your program with GNU profiler flag "-pg"
# 2. run your newly compiled exectuable - this will create a gmon.out file
# 3. write gprof profile output to txt file
gprof ./../bin/pumas_and_hares >> gprof_profile.txt
