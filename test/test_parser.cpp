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

TEST_CASE( "ParseConfig Test", "[Testing parseConfig()]" ){

    GIVEN( "There are correct config parameters defined in a json file" ){

        string configFileName = "./test/test_param.json";
        Parser::parseConfig(configFileName);

        THEN( "Parser sets the correct config parameters to ConfigData, Hare and Puma" ){

            REQUIRE(Hare::getBirthRate() == Approx(0.08));
            REQUIRE(Hare::getDiffusionRate() == Approx(0.2));
            REQUIRE(Hare::getPredationRate() == Approx(0.04));

            REQUIRE(Puma::getBirthRate() == Approx(0.02));
            REQUIRE(Puma::getDiffusionRate() == Approx(0.2));
            REQUIRE(Puma::getMortalityRate() == Approx(0.06));

            REQUIRE(ConfigData::getCapitalT() == 20);
            REQUIRE(ConfigData::getDeltaT() == Approx(0.4));

        }
    }

    GIVEN( "A non-existing file handle" ){
        string non_sense_configFileName = string(RESOURCES_PATH) + "/non_sense.json";

        THEN( "Parser::parseConfig() throws an exception" ){
            REQUIRE_THROWS( Parser::parseConfig(non_sense_configFileName) );
        }
    }

    GIVEN( "Non-valid json string in .json file" ) {
        string invalid_json_configFileName = "invalid_param.json";

        THEN( "Parser::parseConfig() throws an exception") {
            REQUIRE_THROWS( Parser::parseConfig(invalid_json_configFileName) );
        }
    }
}

TEST_CASE( "ParseInput Test", "[Testing ParseInput]" ){
    GIVEN( "There is a valid input file that is sucessfully read" ) {
        WHEN( "Dimensions are not greater than 2000") {
            THEN( "Tile is populated" ) {

            }
        }
    }

    GIVEN( "A Vector") {
        WHEN( "Vector value is smaller than 0" ) {
            THEN( "Return error" ) {

            }
        }

        WHEN( "Vector value is bigger than 1" ) {
            THEN( "Return error" ) {

            }
        }

        WHEN( "Vector value is 0" ) {
            THEN( "Return no error" ) {

            }
        }

        WHEN( "Vector value is 1" ) {
            THEN( "Return no error" ) {

            }
        }
    }
}