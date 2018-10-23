#include "../include/helpers.hpp"
#define MAX_STEP 500

void Helpers::init(string file) {
    Helpers::initRandomGenerator();
    if(!file.empty()) {
        parser::parse(file);
    }
    else {
        parser::parse(string(RESOURCES_PATH) + "/small10x10.dat");
    }
    Output::initOutputFile();
}

void Helpers::close() {
    Landscape::destroy();
}

void Helpers::simulationLoop() {

    for (int t = 0; t <= MAX_STEP; t++) {
        Landscape::calculate();
        Landscape::update();
        if(t % getCapitalT() == 0) {
            Landscape::print();
            Output::print_output(t);
            Output::print_average(t, Landscape::getAveragePumas(), Landscape::getAverageHares());
        }
    }
    
    InputTile it = Landscape::getRegion(0, 0, 10, 10);
    cout << it.land;
}

void Helpers::initRandomGenerator() {
    time_t t = time(NULL);
    srand ((unsigned int)t);
}

void Helpers::setCapitalT(int capitalT) {
    Helpers::capitalT = capitalT;
}

int Helpers::getCapitalT() {
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
int Helpers::capitalT = 200;
