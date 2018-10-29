#ifndef CONFIGDATA_HPP
#define CONFIGDATA_HPP

#include <iostream>

class ConfigData {
private:
    /**
     * @brief ...
     */
    static float deltaT;
    /**
     * @brief the number of time steps between outputs
     */
    static int capitalT;
public:
    static size_t NX;
    static size_t NY;
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
    
    static void initLandscapeSize(size_t NX, size_t NY);

};

#endif
