/**
 * @file configData.hpp
 * @brief Information about input data (time, time steps, grid size, etc)
 * @ingroup pumas_and_hares
 */

#ifndef CONFIGDATA_HPP
#define CONFIGDATA_HPP

#include <iostream>
#include <vector>
#include "tileData.hpp"

#define MAX_STEP 500

using namespace std;

/**
 * @class ConfigData
 * @details A class holding all config parameters associated with the simulation loop, the time and map dimensions
 */
class ConfigData {
private:
    /**
     * @brief the discrete time to run the simulation for
     */
    static float deltaT;
    /**
     * @brief the number of time steps between outputs
     */
    static int capitalT;
public:
    /**
     * @brief grid size X dimension
     */
    static size_t NX;
    /**
     * @brief grid size Y dimension
     */
    static size_t NY;
    static vector< vector<TileData*> > tilesVector;

    /**
     * @brief set deltaT
     */
    static void setDeltaT(float deltaT) throw(invalid_argument);
    /**
     * @return float deltaT
     */
    static float getDeltaT();
    /**
     * @brief setCapitalT
     */
    static void setCapitalT(int capitalT) throw(invalid_argument);
    /**
     * @return int capitalT
     */
    static int getCapitalT();
    
    static void initLandscapeData(vector< vector<TileData*> > tilesVector, size_t NX, size_t NY);

};

#endif
