/* @file landscape_test.cpp
 *
 * @brief Tests landscape class and its functions
 * @ingroup test
 *
 */
#include "../test_declarations.hpp"

#include <iostream>
#include <fstream>

#include STR(HEADERS_PATH/landscape.hpp)
#include STR(HEADERS_PATH/helpers.hpp)

TEST_CASE( "Landscape Test", "[Landscape is generated and functions used]" ){

    GIVEN("A landscape file of size 3x3"){

       string land_file = STR(INPUT_FILES_PATH/small3x3.dat);
       string config_file = STR(CONFIG_PATH/param.json);

       WHEN(" the Landscape is initilised" ){
          Helpers::init(land_file, config_file);

          int maxRow = Landscape::getRows() -1;
          int maxCol = Landscape::getCols() -1;

          THEN(" the landscape is an island"){
               // Check edges
               REQUIRE(!Landscape::getTile(0,0)->isLand());
               REQUIRE(!Landscape::getTile(maxRow,0)->isLand());
               REQUIRE(!Landscape::getTile(0,maxCol)->isLand());
               REQUIRE(!Landscape::getTile(maxRow,maxCol)->isLand());
               // Check centre
               REQUIRE(Landscape::getTile(2,2)->isLand());
          }

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

          THEN(" The simulation runs correctly through the Helpers"){
              Helpers::simulationLoop();
              Helpers::close();
          }
       }
    }
}
