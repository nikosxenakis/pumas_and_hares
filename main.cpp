#include "include/helpers.hpp"

int main() {

    Helpers::init();

    Helpers::simulationLoop();
    
    Helpers::close();
    
    return 0;
}
