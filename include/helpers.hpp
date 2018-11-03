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
    static void initRandomGenerator();
    static void printProgress(float percentage);
public:
    static void init(string file)  throw(runtime_error);

    /**
     * @brief ...
     */
    static void simulationLoop();

    /**
     * @brief ...
     */
    static void close();
};

#endif
