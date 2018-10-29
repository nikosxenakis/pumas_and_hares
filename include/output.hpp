#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <iostream>
#include "image.hpp"
#define OUTPUT_PATH "./output"
#define OUTPUT_FILE "./output/average_density.txt"
//#define OUTPUT_PATH "/Users/xenis656/Desktop/PS/pumas_and_hares/pumas_and_hares/output" //Just for Nikos Xcode
//#define OUTPUT_FILE "/Users/xenis656/Desktop/PS/pumas_and_hares/pumas_and_hares/output/average_density.txt" //Just for Nikos Xcode

using namespace std;

class Output {
public:
    static void initOutputFile();
    static void print_output(double t);
    static void print_average(double t, float averagePumas, float averageHares);
};

#endif
