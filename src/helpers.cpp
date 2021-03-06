#include "../include/helpers.hpp"

void Helpers::init(string file, string configFile) throw(runtime_error) {
    // cout<< "Input file: " << file << endl;
    // cout<< "Config file: " << configFile << endl;
    Helpers::initRandomGenerator();

    try {
        Parser::parseConfig(configFile);
        Parser::parseInput(file);
    }
    catch (const runtime_error& re) {
        throw re;
    }

    Landscape::init(ConfigData::tilesVector, ConfigData::NY, ConfigData::NX);
    Parser::freeTilesVector();
    Output::initOutputFile();
}

void Helpers::close() {
    Landscape::destroy();
}

void Helpers::simulationLoop() {

    for (int t = 0; t <= MAX_STEP; t++) {
        if(t % ConfigData::getCapitalT() == 0) {
            Output::print_output(t);
            // Helpers::printProgress(t/float(MAX_STEP));
        }
        Output::print_average(t, Landscape::getAveragePumas(), Landscape::getAverageHares());
        Landscape::calculate();
        Landscape::update();
    }
}

void Helpers::initRandomGenerator() {
    time_t t = time(NULL);
    srand ((unsigned int)t);
}

void Helpers::printProgress(float percentage) {
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf ("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush (stdout);
}
