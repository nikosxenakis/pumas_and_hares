#include "../include/helpers.hpp"

void Helpers::init(string file) {
    Helpers::initRandomGenerator();

    string const configFileName = string(RESOURCES_PATH) + "/param.json";
    Parser::parseConfig(configFileName);
    Parser::parseInput(file);
    Output::initOutputFile();
}

void Helpers::close() {
    Landscape::destroy();
}

void Helpers::simulationLoop() {

    for (int t = 0; t <= MAX_STEP; t++) {
        if(t % ConfigData::getCapitalT() == 0) {
//            Landscape::print();
            Output::print_output(t);
            Output::print_average(t, Landscape::getAveragePumas(), Landscape::getAverageHares());
        }
        Landscape::calculate();
        Landscape::update();
    }
}

void Helpers::initRandomGenerator() {
    time_t t = time(NULL);
    srand ((unsigned int)t);
}
