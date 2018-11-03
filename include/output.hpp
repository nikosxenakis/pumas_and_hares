/**
 * @file output.hpp
 * @brief Provide information about a Tile
 * @ingroup output
 */

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <iostream>
#include "image.hpp"
#include "configData.hpp"

#define OUTPUT_PATH "./output"
#define OUTPUT_FILE "./output/average_density.dat"

using namespace std;

/**
 * @class Output
 * @brief ..
 * @details ..
 */
class Output {
public:
    static void initOutputFile();
    static void print_output(double t);
    static void print_average(double t, float averagePumas, float averageHares);
};

#endif
