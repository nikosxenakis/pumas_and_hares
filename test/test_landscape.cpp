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

unsigned int Factorial( unsigned int number){
    return number <= 1 ? number : Factorial(number - 1)*number;
}



TEST_CASE( "Landscape Test", "[Landscape is generated and functions used]" ){

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
    

    Landscape::init(tilesVector);
    
    SECTION("Landscape generation"){
        SECTION("check that land is generated as an island"){
            REQUIRE( Landscape::getSumDensityNeighbours("Puma", 0,0) == 1);
            REQUIRE( Landscape::getNumberOfLandNeighbours(0,0) == 1);
        }
            REQUIRE( Factorial(4) == 2);
    }
}
