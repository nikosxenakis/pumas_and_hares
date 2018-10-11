#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "include/puma.hpp"
#include "include/landscape.hpp"
#include "include/landscapeParser.hpp"
#include "include/helpers.hpp"

#define RESOURCES_PATH "./resources"
//#define RESOURCES_PATH "/Users/xenis656/Desktop/pumas_and_hares/pumas_and_hares/resources" //Just for Nikos Xcode

//write the parameters in a json configuration file


int main() {
    //Puma* puma = new Puma();
    //LandscapeParser::parseFile(".resources/small.dat");
    time_t t = time(NULL);
    srand (t);
    ifstream landFile;

    landFile.open(string(RESOURCES_PATH) + "/small10x10.dat");
    
    vector< vector<int> > tilesVector;
    
    if (landFile.is_open()) {
        tilesVector = Helpers::initTilesVector(landFile);
    }
    else {
        cout << "File is not open" << endl;
        exit(1);
    }

    Landscape::init(tilesVector);
    
    Helpers::simulationLoop();

    cout << (Landscape::getSumDensityNeighbours("Hares", 2, 2)) << endl;
    return 0;
}
