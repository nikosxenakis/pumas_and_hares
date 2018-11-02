#ifndef HELPERS_HPP
#define HELPERS_HPP

#include "landscape.hpp"
#include "parser.hpp"
#include "configData.hpp"
#include "output.hpp"

class Helpers {
private:
    static void initRandomGenerator();
    static void printProgress(float percentage);
public:
    static void init(string file);

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
