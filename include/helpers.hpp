#ifndef HELPERS_HPP
#define HELPERS_HPP

#include "output.hpp"
#include "landscape.hpp"
#include "helpers.hpp"
#include "parser.hpp"
#include "puma.hpp"
#define RESOURCES_PATH "./resources"
//#define RESOURCES_PATH "/Users/xenis656/Desktop/PS/pumas_and_hares/pumas_and_hares/resources" //Just for Nikos Xcode

class Helpers {
private:
    /**
     * @brief the number of time steps between outputs
     */
    static int capitalT;

    /**
     * @brief
     */
    static float deltaT;

    /**
     * @brief
     * @return void
     */
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

    /**
     * @brief setCapitalT
     * @return void
     */
    static void setCapitalT(int capitalT);

    /**
     * @return int capitalT
     */
    static int getCapitalT();

    /**
     * @brief set deltaT
     * @return void
     */
    static void setDeltaT(float deltaT);

    /**
     * @return float deltaT
     */
    static float getDeltaT();
};

#endif
