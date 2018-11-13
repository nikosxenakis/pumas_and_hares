#!/bin/sh
# 1. compile your program with GNU profiler flag "-pg"
# 2. write gprof profile output to txt file
gprof ./../bin/pumas_and_hares >> gprof_profile.txt
