#!/bin/sh
#
# for Valgrind only compile with -g flag! -fg flag is for gprof
# hardcode a landfile e.g. "small10x10.dat" in main.cpp
# as no arguments can be passed to Valgrind
# use optimisation flag -O1 with Valgrind!
# optimsation flags -O2 and above are not supported (give weird errors)
#
# create memory overhead profile with:
# "valgrind --tool=massif ./bin/pumas_and_hares"
# massif creates a file massif.out.<pid> for output
#
# create readable output with:
# "ms_print massif.out.<pid> >> massif_profile.txt"
module load valgrind

#make -C ../../ clean; make -C ../../ ./bin/pumas_and_hares;

valgrind --tool=massif ./bin/pumas_and_hares
