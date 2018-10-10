#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <vector>

using namespace std;

class Helpers{

    public:
       static void simulationLoop();
       static vector< vector<int>> initTilesVector(ifstream &landFile);

};

#endif
