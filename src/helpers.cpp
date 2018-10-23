#include "../include/helpers.hpp"

void Helpers::init() {
    Helpers::initRandomGenerator();
    parser::parse(string(RESOURCES_PATH) + "/small10x10.dat");
}

void Helpers::init(string file) {
    Helpers::initRandomGenerator();
    parser::parse(file);
}

void Helpers::close() {
    Landscape::destroy();
}

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
int Helpers::capitalT = 0;
