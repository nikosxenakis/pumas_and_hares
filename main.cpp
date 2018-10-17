#include "include/helpers.hpp"
#include <string>
#include <time.h>
#include <chrono>

int main(int argc, char* argv[]) {
    
    using namespace std;
   
    float start = chrono::duration_cast< chrono::milliseconds >(
        chrono::system_clock::now().time_since_epoch()
    ).count();

    // If no file specified from the command line, open small10x10 by default
    if(argc == 1){
        Helpers::init();
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
    
    float end = chrono::duration_cast< chrono::milliseconds >(
        chrono::system_clock::now().time_since_epoch()
    ).count();

    printf("Program finished. Ellapsed time (ms): %f\n", (end -start));

    return 0;
}
