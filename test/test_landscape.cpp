/* landscape_test.cpp
 *
 * Tests landscape class and its functions
 *
 */

#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "../include/landscape.hpp"
#include "../include/helpers.hpp"
#include "../include/tile.hpp"

using namespace std;



TEST_CASE( "Landscape Test", "[Landscape is generated and functions used]" ){

    GIVEN("A landscape file of size 3x3"){

       string land_file = ("./resources/small3x3.dat");
      
       WHEN(" the Landscape is initilised" ){ 
          Helpers::init(land_file);

          int max_index = Landscape::getRows(); // This works because this particular land
                                                // file is a square

          THEN(" the landscape is an island"){
               // Check edges
               REQUIRE( Landscape::getNumberOfLandNeighbours(0,0) == 0);
               REQUIRE( Landscape::getNumberOfLandNeighbours(max_index,0) == 0);
               REQUIRE( Landscape::getNumberOfLandNeighbours(0,max_index) == 0);
               REQUIRE( Landscape::getNumberOfLandNeighbours(max_index,max_index) == 0);

               // Check centre
               REQUIRE( Landscape::getNumberOfLandNeighbours(2,2) == 4 );
          }
          
          THEN(" the density of its neighbours is 0 "){
               REQUIRE( Landscape::getSumDensityNeighbours(Puma::getName(), 1,1) == Approx(0.0) );
               REQUIRE( Landscape::getSumDensityNeighbours(Hare::getName(), 1,1) == Approx(0.0) );
          }
          THEN(" It is initialised with a halo"){
               REQUIRE( Landscape::getRows() == 5 );
               REQUIRE( Landscape::getCols() == 5 );

          }
          THEN(" We can set max pumas and hares "){
              Landscape::setMaxHares(5.0);
              Landscape::setMaxPumas(6.0);

              REQUIRE( Landscape::getMaxPumas() == Approx(6.0) );
              REQUIRE( Landscape::getMaxHares() == Approx(5.0) );

          }
       }
    }
}
