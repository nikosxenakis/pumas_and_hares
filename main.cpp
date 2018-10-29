#include "include/helpers.hpp"
#include "include/log.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    
    Log::startLogTime("main");
    
    // If no file specified from the command line, open small10x10 by default
    if(argc == 1){
//        Helpers::init(string(RESOURCES_PATH) + "/land_generator50x50_densities_in_the_corners.dat");
        Helpers::init(string(RESOURCES_PATH) + "/land_generator2000x2000_densities_in_the_corners.dat");
    } else {
        
        std::string arg = string(argv[1]);
        if(arg == "--help"){
            printf("Usage: ./pumas_and_hares path/to/file.dat\n");
            return 0;
        } else{ 
            Helpers::init(arg);
        }
    }

    Helpers::simulationLoop();
    Helpers::close();

    Log::endLogTime("main");
    return 0;
}
