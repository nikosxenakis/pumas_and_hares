#include "../include/helpers.hpp"

void Helpers::init() {
    Helpers::initRandomGenerator();
    parser::parse(string(RESOURCES_PATH) + "/small10x10.dat");
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
