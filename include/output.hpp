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
     * @param t time
     */
    static void print_output(double t);
    /**
     * @brief prints the output
     * @param t time
     * @param averageHares average number of hares
     * @param averagePumas avarage number of pumas
     */
    static void print_average(double t, float averagePumas, float averageHares);
};

#endif
