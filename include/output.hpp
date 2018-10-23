#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <iostream>
#include <vector>
#include "image.hpp"
#include "pixel.hpp"
#define OUTPUT_PATH "./output"
//#define OUTPUT_PATH "/Users/xenis656/Desktop/PS/pumas_and_hares/pumas_and_hares/output" //Just for Nikos Xcode

using namespace std;

class Output {
public:
    static void print_output(double t);
    static void print_average(double t);
};

#endif
