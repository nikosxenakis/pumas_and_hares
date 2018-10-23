#include "include/helpers.hpp"
#include <string>
#include <time.h>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

using namespace std;

int main(int argc, char* argv[]) {
    
    auto start = Clock::now();

    // If no file specified from the command line, open small10x10 by default
    if(argc == 1){
        Helpers::init(string(RESOURCES_PATH) + "/small10x10.dat");
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
    
    auto end = Clock::now();
    std::cout << "Running time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds" << std::endl;
    return 0;
}
