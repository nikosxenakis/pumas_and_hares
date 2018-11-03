/* landscape_test.cpp
 *
 * Tests landscape class and its functions
 *
 */

#include <iostream>
#include <fstream>
#include "../lib/catch.hpp"
#include "../include/landscape.hpp"
#include "../include/helpers.hpp"
#include "../include/tile.hpp"

using namespace std;



TEST_CASE( "Landscape Test", "[Landscape is generated and functions used]" ){

    GIVEN("A landscape file of size 3x3"){

       string land_file = ("./test/resources/small3x3.dat");
      
       WHEN(" the Landscape is initilised" ){ 
          Helpers::init(land_file);

          int max_index = Landscape::getRows() -1; // This works because this particular land
                                                // file is a square

          THEN(" the landscape is an island"){
               // Check edges
               REQUIRE( Landscape::getTile(0,0)->isLand() == 0 );
               REQUIRE( Landscape::getTile(max_index,0)->isLand() == 0);
               REQUIRE( Landscape::getTile(0,max_index)->isLand() == 0);
               REQUIRE( Landscape::getTile(max_index,max_index)->isLand() == 0);
    
               // Check centre
               REQUIRE( Landscape::getTile(2,2)->isLand() );
          }
          
     //     THEN(" the density of its neighbours is 0 "){
     //          REQUIRE( Landscape::getSumDensityNeighbours(Puma::getName(), 1,1) == Approx(0.0) );
     //          REQUIRE( Landscape::getSumDensityNeighbours(Hare::getName(), 1,1) == Approx(0.0) );
     //     }
          THEN(" It is initialised with a halo"){
               REQUIRE( Landscape::getRows() == 5 );
               REQUIRE( Landscape::getCols() == 5 );

          }
          THEN(" We can set max pumas and hares "){
              REQUIRE( Landscape::getMaxPumas() == Approx(1.0) );
              REQUIRE( Landscape::getMaxHares() == Approx(1.0) );
   
          }
          THEN(" We can calculate the average puma and hare density "){
              REQUIRE( Landscape::getAverageHares() == Approx(1.0/9.0) );
              REQUIRE( Landscape::getAveragePumas() == Approx(1.0/9.0) );
          }
       }
    }
}
