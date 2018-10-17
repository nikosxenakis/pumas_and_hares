#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <vector>
#include <time.h>
#include "output.hpp"

using namespace std;

class Helpers{

    public:
       static void simulationLoop();
       static void initRandomGenerator();
       static vector< vector<int>> initTilesVector(ifstream &landFile);

};

#endif
