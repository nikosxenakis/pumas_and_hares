/* parser_test.cpp
 *
 * Tests parser class and its functions
 *
 */

#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "../include/helpers.hpp"
#include "../include/configData.hpp"

using namespace std;

TEST_CASE( "ParseInput Test", "[Testing ParseInput]" ){

    GIVEN( "There are correct config parameters defined in a json file" ){

        string configFileName = string(RESOURCES_PATH) + "/param.json";

        THEN( "Parser sets the correct config parameters to ConfigData, Hare and Puma" ){

            REQUIRE(Hare::getBirthRate() == 1.0);
            REQUIRE(Hare::getDiffusionRate() == 1.0);
            REQUIRE(Hare::getPredationRate() == 1.0);

            REQUIRE(Puma::getBirthRate() == 1.0);
            REQUIRE(Puma::getDiffusionRate() == 1.0);
            REQUIRE(Puma::getMortalityRate() == 1.0);

            REQUIRE(ConfigData::getCapitalT() == 1.0);
            REQUIRE(ConfigData::getDeltaT() == 1.0);
            REQUIRE(Hare::getMortalityRate() == 1.0);

        }
    }
}

// todo: refactor Parser to modularise reading config file, parsing json, setting configData etc

TEST_CASE( "Read json file", "[Reading json file]" ){
    GIVEN( "A file handle" ){
        THEN( "The file can be read" ){

        }
    }

    GIVEN( "A json string" ) {
        WHEN( "The json can be parsed" ){
            THEN( "There are all necessary parameter keys in json") {

            }
        }

    }
}