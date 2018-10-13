/* test_tile.cpp
 *
 * Tests landscape class and its functions
 *
 */

#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "../include/tile.hpp"
#include "../include/helpers.hpp"

TEST_CASE( "Tile test", "[testing the tiles]"){
    Tile t = new Tile(1);
    float h1 = t.getOldHares();
    float p1 = t.getOldPumas();
    t.update();
    REQUIRE( h1 == t.getOldHares() );
    REQUIRE( p1 >= t.getOldPumas() );
}
