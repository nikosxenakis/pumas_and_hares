/**
 * @file main.cpp
 *
 * @brief ...
 *
 * @defgroup input
 * @defgroup pumas_and_hares
 * @defgroup output
 *
 * @author Nikolaos Xenakis http://github.com/nikosxenakis nikosxenakis94@gmail.com
 * @author ...
 * @author ...
 * @author ...
 *
 */

#include "include/helpers.hpp"
#include "include/log.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    
    string inputFile = string(RESOURCES_PATH) + "/land_generator2000x2000_densities_in_the_corners.dat";
    
    if(argc == 2) {
        string arg = string(argv[1]);
        if(arg == "--help" || arg == "-h") {
            cout << "Usage: ./pumas_and_hares path/to/file.dat\n" << endl;
            return 0;
        } else {
            inputFile = arg;
        }
    }
    else if(argc > 2){
        inputFile.clear();
    }

    if(inputFile.empty()) {
        cerr << "Exception in main: Input File is empty" << endl;
        return 0;
    }

    try {
        Helpers::init(inputFile);
    }
    catch (...) {
        return 0;
    }

    Log::startLogTime("simulation");
    Helpers::simulationLoop();
    Helpers::close();
    cout << endl;
    Log::endLogTime("simulation");
    cout << "The program has finished. All output files have been placed in output folder" << endl;
    
    return 0;
}
