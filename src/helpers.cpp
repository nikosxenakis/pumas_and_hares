#include "../include/puma.hpp"
#include "../include/landscape.hpp"
#include "../include/helpers.hpp"

void Helpers::simulationLoop() {

    int dt = 251;
     
    Landscape::print();

    for (int t = 0; t <= 500; t+=dt) {
        Landscape::calculate();
        Landscape::update();
        Landscape::print();
        Output::print_output(t);
    }
}

void Helpers::initRandomGenerator() {
    time_t t = time(NULL);
    srand ((unsigned int)t);
}

vector< vector<int> > Helpers::initTilesVector(ifstream &landFile) {
    vector< vector<int> > tilesVector;

     int NY, NX, val;
     landFile >> NX;
     if (0 > NX || NX > 2000) {
         cout << "Number of columns must be between 1 and 2000" << endl;
         exit(1);
     }
     landFile >> NY;
     if (0 > NY || NY > 2000) {
                     cout << "Number of rows must be between 1 and 2000" << endl;
         exit(1);
     }

     for (int i = 0; i < NX; ++i)
     {
         vector<int> tilesLine;
         for (int j = 0; j < NY; ++j)
         {
             landFile >> val;

             if (val != 0 && val != 1) {
                 cout << "tile must be 1 or 0" << endl;
                 exit(1);
             }
             else {
                 tilesLine.push_back(val);
             }
         }
         tilesVector.push_back(tilesLine);
     }

     return tilesVector;
 }

void Helpers::setCapitalT(float capitalT) {
    Helpers::capitalT = capitalT;
}

float Helpers::getCapitalT() {
    return Helpers::capitalT;
}

void Helpers::setDeltaT(float deltaT) {
    Helpers::deltaT = deltaT;
}

float Helpers::getDeltaT() {
    return Helpers::deltaT;
}

// init
float Helpers::deltaT = 0.4;
float Helpers::capitalT = 0.0;