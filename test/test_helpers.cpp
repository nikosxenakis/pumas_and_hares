/* helpers_test.cpp
 *
 * Tests helpers class and its functions
 *
 */

#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "../include/helpers.hpp"
#include "../include/configData.hpp"

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

