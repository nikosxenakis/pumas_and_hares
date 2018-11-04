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

#ifndef STR
#define XSTR(x) #x
#define STR(x) XSTR(x)
#endif

#define OUTPUT_PATH STR(./output)
#define OUTPUT_FILE STR(./output/average_density.dat)
//#define OUTPUT_PATH "/Users/xenis656/Desktop/PS/pumas_and_hares/pumas_and_hares/output" //Just for Nikos Xcode
//#define OUTPUT_FILE "/Users/xenis656/Desktop/PS/pumas_and_hares/pumas_and_hares/output/average_density.dat" //Just for Nikos Xcode

using namespace std;

/**
 * @class Output
 * @brief contains necessary output functions
 * @details initialising the output file, printing output and average
 */
class Output {
public:
    /**
     * @brief initialisies output file
     */
    static void initOutputFile();
    /**
     * @brief prints the output
     * @param t
     */
    static void print_output(double t);
    /**
     * @brief prints the output
     * @param t
     * @param averageHares
     * @param averagePumas
     */
    static void print_average(double t, float averagePumas, float averageHares);
};

#endif
