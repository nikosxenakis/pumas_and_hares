#!/bin/sh
BASE_FOLDER=../../;

cd $BASE_FOLDER;

config_file=./resources/configurations/param.json;
data_file=./performance_experiments/diversity/data.tsv;

declare -a input_files=(
	'./resources/input_files/diversity_0.05.dat'
	'./resources/input_files/diversity_0.10.dat'
	'./resources/input_files/diversity_0.25.dat'
	'./resources/input_files/diversity_0.50.dat'
	'./resources/input_files/diversity_0.75.dat'
	'./resources/input_files/diversity_1.00.dat'
);

declare -a ratio=(
	'0.05'
	'0.10'
	'0.25'
	'0.50'
	'0.75'
	'1.00'
);

make clean;
make ./bin/pumas_and_hares;

echo "Land ratio\tRunning Time\tMemory Usage" > $data_file;

input_files_no=${#input_files[@]}

for (( i=0; i<${input_files_no}; i++ ));
do
	echo ${input_files[$i]};
	# echo -e "${ratio[$i]}\t" > $data_file;
	./bin/pumas_and_hares ${input_files[$i]} $config_file >> $data_file;
done

cd performance_experiments/diversity;

# python data_analyzer.py
