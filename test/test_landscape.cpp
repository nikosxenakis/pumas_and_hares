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

    GIVEN("A landscape vector of size 10x10"){

       ifstream landFile;
       landFile.open("../resources/small10x10.dat");
       vector< vector<int> > tilesVector;

       if (landFile.is_open()) {
           tilesVector = Helpers::initTilesVector(landFile);
       }
       else {
           cout << "ERROR OPENING LANDSCAPE FILE" << endl;
           exit(1);
       }
      
       WHEN(" the Landscape is initilised" ){ 
          Landscape::init(tilesVector);

          int max_index =  tilesVector.size()-1;

          THEN(" the landscape is an island"){
               REQUIRE( Landscape::getNumberOfLandNeighbours(0,0) == 0);
               REQUIRE( Landscape::getNumberOfLandNeighbours(max_index,0) == 0);
               REQUIRE( Landscape::getNumberOfLandNeighbours(0,max_index) == 0);
               REQUIRE( Landscape::getNumberOfLandNeighbours(max_index,max_index) == 0);
          }
          
       }
    }
}
