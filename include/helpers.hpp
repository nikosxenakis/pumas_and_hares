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
    static int capitalT;
    static float deltaT;
    static void initRandomGenerator();

public:
    static void init();
    static void init(string file);
    static void simulationLoop();
    static void close();
    static vector< vector<int>> initTilesVector(ifstream &landFile);
    static void setCapitalT(int capitalT);
    static int getCapitalT();
    static void setDeltaT(float deltaT);
    static float getDeltaT();
};

#endif
