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

using namespace std;



TEST_CASE( "Landscape Test", "[Landscape is generated and functions used]" ){

    GIVEN("A landscape file of size 3x3"){

       string land_file = ("../resources/small3x3.dat");
      
       WHEN(" the Landscape is initilised" ){ 
          Helpers::init(land_file);

          int max_index = Landscape::getRows(); // This works because this particular land
                                                // file is a square

          THEN(" the landscape is an island"){
               REQUIRE( Landscape::getNumberOfLandNeighbours(0,0) == 0);
               REQUIRE( Landscape::getNumberOfLandNeighbours(max_index,0) == 0);
               REQUIRE( Landscape::getNumberOfLandNeighbours(0,max_index) == 0);
               REQUIRE( Landscape::getNumberOfLandNeighbours(max_index,max_index) == 0);
          }
          
          THEN(" the Density of it's neighbours is 0 "){
               REQUIRE( Landscape::getSumDensityNeighbours(Puma::getName(), 1,1) == Approx(0.0) );
               REQUIRE( Landscape::getSumDensityNeighbours(Hare::getName(), 1,1) == Approx(0.0) );
          }
       }
    }
}
