# make run ./resources/input_files/islands.dat;
# make run ./resources/input_files/islands.dat ./resources/configurations/param.json;
# display ./output/average_density.eps;
# display -sample 200 -delay 1 ./output/Density_*.ppm;

echo "Warning! this script will take very long time and hammer one of your cores."
echo "This script is running, and will place logs in the scripts/logs directory"

# if log folder already exists, then wipe it
if [ -d ./scripts/logs/ ]; then
    rm -rf ./scripts/logs
fi

mkdir ./scripts/logs
for input_file in ./resources/input_files/*.dat
do
  for config_file in ./resources/configurations/*.json
  do
    # put logs in log folder, tagged with their input and config files
    export input=$(basename $input_file .dat)
    export config=$(basename $config_file .json)
    make run $input_file $config_file > ./scripts/logs/$input$config.log.txt 2> ./scripts/logs/$input$config.err.txt
    echo -n .
	# display ./output/average_density.eps;
	# display -sample 200 -delay 1 ./output/Density_*.ppm;
  done
done
