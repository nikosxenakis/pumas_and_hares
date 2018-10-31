/* test_tile.cpp
 *
 * Tests tile class and its functions
 *
 */
#include <iostream>
#include "catch.hpp"
#include "../include/tile.hpp"
#include "../include/landscape.hpp"
#include "../include/helpers.hpp"

TEST_CASE( "Tile test", "[testing the tiles]"){

    GIVEN("A landscape of size 10x10") {

        string land_file = "./resources/small10x10.dat";

        Helpers::init(land_file);
        Tile* t1 = Landscape::getTile(3, 3);
        Tile* t2 = Landscape::getTile(1, 1);
        
        WHEN(" the Landscape is initilised" ) { 
            THEN(" Values of initial land, pumas and hares are as expected ") {
                REQUIRE( t1->isLand() == 1 );
                REQUIRE( t1->getPumas() == Approx(1.0) );
                REQUIRE( t1->getHares() == Approx(2.0) );
                REQUIRE( t2->isLand() == 0 );
                REQUIRE( t2->getPumas() == Approx(0.0) );
                REQUIRE( t2->getHares() == Approx(0.0) );
            }
        }

        WHEN(" the Landscape is initilised and one time step occurs" ) { 
            Landscape::calculate();
            Landscape::update();

            THEN(" Values of old hares and pumas are as expected ") {
                REQUIRE( t1->isLand() == 1 );
                REQUIRE( t1->getPumas() == Approx(1.632) );
                REQUIRE( t1->getHares() == Approx(2.432) );
                REQUIRE( t2->isLand() == 0 );
                REQUIRE( t2->getPumas() == Approx(0.0) );
                REQUIRE( t2->getHares() == Approx(0.0) );
            }
        }

        WHEN(" the Landscape is initilised and the last time step occurs" ) { 
            for (int t = 2; t <= MAX_STEP; t++) {
                Landscape::calculate();
                Landscape::update();
            }

            THEN(" Values of old hares and pumas are as expected ") {
                REQUIRE( t1->isLand() == 1 );
                REQUIRE( t1->getPumas() == Approx(2.47594) );
                REQUIRE( t1->getHares() == Approx(10.03977) );
                REQUIRE( t2->isLand() == 0 );
                REQUIRE( t2->getPumas() == Approx(0.0) );
                REQUIRE( t2->getHares() == Approx(0.0) );
            }
        }
    }
}
