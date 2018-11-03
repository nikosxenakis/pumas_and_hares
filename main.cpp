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
    
    string inputFile = string(RESOURCES_PATH) + "/islands.dat";
    
    if(argc == 2) {
        inputFile = string(argv[1]);
    }
    else if(argc > 2){
        cerr << "Exception in main: too many arguments" << endl;
        return 0;
    }

    try {
        Helpers::init(inputFile);
    }
    catch (const runtime_error& re) {
        cerr << re.what() << endl;
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
