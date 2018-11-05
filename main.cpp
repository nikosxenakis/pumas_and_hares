/**
 * @file main.cpp
 *
 * @brief We initialise and call the simulation loop, initialise execution time logging, specify config files and handle exceptions
 *
 * @defgroup input
 * @defgroup pumas_and_hares
 * @defgroup output
 *
 * @author Nikolaos Xenakis | http://github.com/nikosxenakis        | nikosxenakis94@gmail.com
 * @author Holly Judge
 * @author Jim Walker       | https://github.com/andrewpsuedonym    | j.m.walker@live.co.uk
 * @author Mark Klaisoongnoen
 *
 */
#include "include/helpers.hpp"
#include "include/log.hpp"

// Define preprocessor string concatination
#ifndef STR
#define XSTR(x) #x
#define STR(x) XSTR(x)
#endif

#ifndef RESOURCES_PATH
#define RESOURCES_PATH ./resources
#define INPUT_FILES_PATH ./resources/input_files
#define CONFIG_PATH ./resources/configurations
#endif

using namespace std;

int main(int argc, char* argv[]) {
    
    string inputFile = STR(INPUT_FILES_PATH/islands.dat);
    string configFile = STR(CONFIG_PATH/param.json);

    if(argc == 3) {
        inputFile = string(argv[1]);
        configFile = string(argv[2]);
    }
    else if(argc == 2) {
        inputFile = string(argv[1]);
    }
    else if(argc > 3) {
        cerr << "Exception in main: invalid number of arguments" << endl;
        return 0;
    }

    try {
        Helpers::init(inputFile, configFile);
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
    cout << "The program has finished. All output files have been placed in output folder" << endl << endl;
    return 0;
}
