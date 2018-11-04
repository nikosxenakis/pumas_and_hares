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

/**
 * @class Helpers
 * @brief setting up simulation
 * @details necessary inits, printing and actual simulation wrappers
 */
class Helpers {
private:
    /**
     * @brief uses random integer generation
     */
    static void initRandomGenerator();

    /**
     * @brief Prints a visualised progress to command line
     * @param percentage simulation progress in percentage
     */
    static void printProgress(float percentage);
public:
    /**
     * @brief initialising Helpers
     * @param file handle
     */
    static void init(string file, string configFile)  throw(runtime_error);

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
