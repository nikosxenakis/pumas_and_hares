#include "include/landscape.hpp"
#include "include/helpers.hpp"
#include "include/parser.hpp"

//#define RESOURCES_PATH "./resources"
#define RESOURCES_PATH "/Users/xenis656/Desktop/PS/pumas_and_hares/pumas_and_hares/resources" //Just for Nikos Xcode

//write the parameters in a json configuration file

int main() {

    Helpers::initRandomGenerator();

    parser::parse(string(RESOURCES_PATH) + "/small10x10.dat");

    Helpers::simulationLoop();
    
    Landscape::destroy();
    
    return 0;
}
