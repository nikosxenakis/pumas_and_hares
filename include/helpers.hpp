#ifndef HELPERS_HPP
#define HELPERS_HPP

#include "output.hpp"
#include "landscape.hpp"
#include "parser.hpp"
#include "image.hpp"

#define MAX_STEP 500

class Helpers {
private:
    static void initRandomGenerator();

public:
    static void init(string file);

    /**
     * @brief
     * @return void
     */
    static void simulationLoop();

    /**
     * @brief
     * @return void
     */
    static void close();

    /**
     * @brief
     * @return
     */
    static vector< vector<int>> initTilesVector(ifstream &landFile);
};

#endif
