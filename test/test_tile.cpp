/* test_tile.cpp
 *
 * Tests tile class and its functions
 *
 */

#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "../include/tile.hpp"
#include "../include/landscape.hpp"
#include "../include/helpers.hpp"

TEST_CASE( "Tile test", "[testing the tiles]"){
    REQUIRE( 1 == 1 );
    GIVEN("A landscape of size 3x3"){

       string land_file = "../resources/small3x3.dat";
       Helpers::init(land_file);
      
       WHEN(" the Landscape is initilised and one time step occurs" ){ 
           
          Landscape::calculate();
          Landscape::update();


          THEN(" Values of old hares and pumas are as expexted "){

               Tile* t = Landscape::getTile(2,2);
               REQUIRE( t->getOldHares() == Approx(1.016) );
               REQUIRE( t->getOldPumas() == Approx(0.984) );

          }
       }
    }
}
