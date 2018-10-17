#include "include/landscape.hpp"
#include "include/helpers.hpp"
#include "include/parser.hpp"
#include <string>
#include <time.h>
#include <chrono>

#define RESOURCES_PATH "./resources"
//#define RESOURCES_PATH "/Users/xenis656/Desktop/PS/pumas_and_hares/pumas_and_hares/resources" //Just for Nikos Xcode

//write the parameters in a json configuration file

int main(int argc, char* argv[]) {
    
    using namespace std;
   
    float start = chrono::duration_cast< chrono::milliseconds >(
        chrono::system_clock::now().time_since_epoch()
    ).count();

    // If no file specified from the command line, open small10x10 by default
    if(argc == 1){

        Helpers::initRandomGenerator();
        parser::parse(string(RESOURCES_PATH) + "/small10x10.dat");

    } else {
        
        std::string arg = string(argv[1]);
        if(arg == "--help"){
            printf("Usage: ./pumas_and_hares path/to/file.dat\n");
            return 0;
        } else{ 

        Helpers::initRandomGenerator();
        parser::parse(arg);
        }

    }
        Helpers::simulationLoop();
        Landscape::destroy();
    float end = chrono::duration_cast< chrono::milliseconds >(
        chrono::system_clock::now().time_since_epoch()
    ).count();
    printf("Program finished. Ellapsed time (ms): %f\n", (end -start));

    return 0;
}
