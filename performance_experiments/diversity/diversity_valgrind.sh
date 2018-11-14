#!/bin/sh
BASE_FOLDER=../../;

config_file=../../resources/configurations/param.json;
data_file=./data.tsv;
bin=../../bin/pumas_and_hares;

declare -a input_files=(
	'./input/diversity_0.05.dat'
	'./input/diversity_0.10.dat'
	'./input/diversity_0.25.dat'
	'./input/diversity_0.50.dat'
	'./input/diversity_0.75.dat'
	'./input/diversity_1.00.dat'
);

declare -a ratio=(
	'0.05'
	'0.10'
	'0.25'
	'0.50'
	'0.75'
	'1.00'
);

module load valgrind

make -C ../../ clean; make -C ../../ ./bin/pumas_and_hares;

# echo "Land ratio\tRunning Time (sec)\tMemory Usage" > $data_file;

input_files_no=${#input_files[@]}

for (( i=0; i<${input_files_no}; i++ ));
do
	echo ${input_files[$i]};
	$bin ${input_files[$i]} $config_file;
	valgrind --log-file="valgrind_${ratio[$i]}.txt" $bin ${input_files[$i]} $config_file;
done
