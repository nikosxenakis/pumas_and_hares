#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <vector>
#include <time.h>
#include "output.hpp"

using namespace std;

class Helpers{
    private:
        static float capitalT;
        static float deltaT;
    public:
       static void simulationLoop();
       static void initRandomGenerator();
       static vector< vector<int>> initTilesVector(ifstream &landFile);
        static void setCapitalT(float capitalT);
        static float getCapitalT();
        static void setDeltaT(float deltaT);
        static float getDeltaT();
};

#endif
