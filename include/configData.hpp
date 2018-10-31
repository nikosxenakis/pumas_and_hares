#ifndef CONFIGDATA_HPP
#define CONFIGDATA_HPP

#include <iostream>
#include <vector>
#include "tileData.hpp"

using namespace std;

/**
 * @class ConfigData
 * @details A class holding all config parameters associated the simulation loop, the time and map dimensions
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
    static size_t NX;
    static size_t NY;
    static vector< vector<TileData*> > tilesVector;

    /**
     * @brief set deltaT
     */
    static void setDeltaT(float deltaT);
    /**
     * @return float deltaT
     */
    static float getDeltaT();
    /**
     * @brief setCapitalT
     */
    static void setCapitalT(int capitalT);
    /**
     * @return int capitalT
     */
    static int getCapitalT();
    
    static void initLandscapeData(vector< vector<TileData*> > tilesVector, size_t NX, size_t NY);

};

#endif
