#!/bin/sh
BASE_FOLDER=../../;

cd $BASE_FOLDER;

config_file=./resources/configurations/param.json;
data_file=./performance_experiments/diversity/data.tsv;

declare -a input_files=(
	'./resources/input_files/land_generator50x50.dat'
  './resources/input_files/small4x3.dat'
);

# make clean;
# make ./bin/pumas_and_hares;

echo "Land ratio\tRunning Time\tMemory Usage" > $data_file;

input_files_no=${#input_files[@]}

for (( i=0; i<${input_files_no}; i++ ));
do
	echo ${input_files[$i]};
	./bin/pumas_and_hares ${input_files[$i]} $config_file >> $data_file;
done

cd performance_experiments/diversity;

# python data_analyzer.py
