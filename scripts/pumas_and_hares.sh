make run;
# make run ./resources/input_files/islands.dat;
# make run ./resources/input_files/islands.dat ./resources/configurations/param.json;
display ./output/average_density.eps;
display -sample 200 -delay 1 ./output/Density_*.ppm;
