/**
 * @file helpers.hpp
 * @brief Describes class Helpers
 * @ingroup pumas_and_hares
 */

#ifndef HELPERS_HPP
#define HELPERS_HPP

#include "landscape.hpp"
#include "parser.hpp"
#include "configData.hpp"
#include "output.hpp"

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

#define RESOURCES_PATH "./resources"
//#define RESOURCES_PATH "/Users/xenis656/Desktop/PS/pumas_and_hares/pumas_and_hares/resources" //Just for Nikos Xcode

class Helpers {
private:
    /**
     * @brief ...
     */
    static void initRandomGenerator();

    /**
     * @brief Prints a visualised progress to command line
     *
     * @param simulation progress in percentage
     */
    static void printProgress(float percentage);
public:
    static void init(string file)  throw(runtime_error);

    /**
     * @brief Iterates over time steps and calls all necessary calculations, intialising output, printing to command line
     */
    static void simulationLoop();

    /**
     * @brief Closes the landscape after simulation
     */
    static void close();
};

#endif
