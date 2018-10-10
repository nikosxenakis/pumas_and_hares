#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/landscape.hpp"

unsigned int Factorial( unsigned int number){
    return number <= 1 ? number : Factorial(number - 1)*number;
}



TEST_CASE( "factorials are computed", "[factorial]" ){

    vector<vector <int>> tV;
    
    Landscape::init(tV);
    Landscape::print();

    


    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
}
