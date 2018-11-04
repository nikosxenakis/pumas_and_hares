# make run ./resources/input_files/islands.dat;
# make run ./resources/input_files/islands.dat ./resources/configurations/param.json;
# display ./output/average_density.eps;
# display -sample 200 -delay 1 ./output/Density_*.ppm;

for input_file in ./resources/input_files/*.dat
do
  for config_file in ./resources/configurations/*.json
  do
  	echo "make run ${input_file} ${config_file}" >> ./scripts/log.txt;
    make run $input_file $config_file >> ./scripts/log.txt;
	# display ./output/average_density.eps;
	# display -sample 200 -delay 1 ./output/Density_*.ppm;
  done
done
