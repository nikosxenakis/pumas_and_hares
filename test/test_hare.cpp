/* landscape_test.cpp
 *
 * Tests landscape class and its functions
 *
 */

#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "../include/hare.hpp"

using namespace std;

TEST_CASE( "Hare Test", "[Testing hare getters and setters]" ){

    GIVEN("The hare class, with initialised variables"){ 
        
        float a = 3.0;
        Hare::setBirthRate(a);
        Hare::setPredationRate(a);
        
        THEN( "Getters should work" ){
            REQUIRE( Hare::getBirthRate() == 3.0 );
            REQUIRE( Hare::getPredationRate() == 3.0);
        }
    }           

}
