/* test_tile.cpp
 *
 * Tests landscape class and its functions
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
    GIVEN("A landscape vector of size 3x3"){

       ifstream landFile;
       landFile.open("../resources/small3x3.dat");
       vector< vector<int> > tilesVector;

       if (landFile.is_open()) {
           tilesVector = Helpers::initTilesVector(landFile);
       }
       else {
           cout << "ERROR OPENING LANDSCAPE FILE" << endl;
           exit(1);
       }
      
       WHEN(" the Landscape is initilised and one time step occurs" ){ 

          Landscape::init(tilesVector);
          Landscape::update();


          THEN(" Values of old hares and pumas are as expexted "){

               Tile t = Landscape::getTile(1,1);
               REQUIRE( t.getOldHares() == Approx(1.016) );
               REQUIRE( t.getOldPumas() == Approx(0.984) );

          }
       }
    }
}
