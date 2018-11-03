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
