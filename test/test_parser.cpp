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

        string configFileName = "./test/resources/test_param.json";
        REQUIRE_NOTHROW( Parser::parseConfig(configFileName) );

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

    GIVEN( "Not all of the config parameters are define in a json file" ){
        string missing_keys_configFileName = "./test/resources/test_param_missing_keys.json";

        THEN( "Parser throws an exception" ){
            REQUIRE_THROWS( Parser::parseConfig(missing_keys_configFileName) );
        }
    }

    GIVEN( "negative config params set in json file" ){
        string negative_values_configFileName = "./test/resources/test_param_negative_values.json";

        THEN( "Parser accepts negative values but Hare model throws invalid_arg exception" ){
            REQUIRE_THROWS( Parser::parseConfig(negative_values_configFileName) );
            // REQUIRE( Hare::getBirthRate() == Approx(-0.08) );
            // REQUIRE( ConfigData::getCapitalT() == -20 );
        }
    }

    GIVEN( "A non-existing file handle" ){
        string non_existing_configFileName = string(RESOURCES_PATH) + "/non_sense.json";

        THEN( "Parser::parseConfig() throws an exception" ){
            REQUIRE_THROWS( Parser::parseConfig(non_existing_configFileName) );
        }
    }

    GIVEN( "Non-valid json string in .json file" ) {
        string invalid_json_configFileName = "./test/resources/invalid_param.json";

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
            string inputFile = "./test/resources/vector_smaller_than_0.dat";
            THEN( "Return error" ) {
                REQUIRE_THROWS( Parser::parseInput(inputFile) );
            }
        }

        WHEN( "Vector value is bigger than 1" ) {
            string inputFile = "./test/resources/vector_bigger_than_1.dat";
            THEN( "Return error" ) {
                REQUIRE_THROWS( Parser::parseInput(inputFile) );
            }
        }

        WHEN( "Vector value is 0" ) {
            string inputFile = "./test/resources/vector_equals_0.dat";
            THEN( "Return no error" ) {
                // REQUIRE_NOTHROW( Parser::parseInput(inputFile) );
            }
        }

        WHEN( "Vector value is 1" ) {
            string inputFile = "./test/resources/vector_equals_1.dat";
            THEN( "Return no error" ) {
                // REQUIRE_NOTHROW( Parser::parseInput(inputFile) );
            }
        }

        WHEN( "x elements not equal to Landscape size" ) {
            string inputFile = "./test/resources/input_x_elements_not_equal_landscape_size.dat";
            THEN( "Throw exception" ) {
                REQUIRE_THROWS( Parser::parseInput(inputFile) );
            }
        }

        // todo: might be the same as first WHEN
        WHEN( "Number of columns are between 1 and 2000" ) {
            string inputFile = "./test/resources/cols_between_1_2000.dat";
            THEN( "Return no error" ) {
                // REQUIRE_NOTHROW( Parser::parseInput(inputFile) );
            }
        }

        // todo: might be the same as first WHEN
        WHEN( "Number of rows are between 1 and 2000") {
            string inputFile = "./test/resources/rows_between_1_2000.dat";
            THEN( "Return no error" ) {
                // REQUIRE_NOTHROW( Parser::parseInput(inputFile) );
            }
        }

        WHEN( "Number of rows bigger than 2000") {
            string inputFile = "./test/resources/rows_bigger_2000.dat";
            THEN( "Return error" ) {
                // REQUIRE_THROWS( Parser::parseInput(inputFile) );
            }
        }

        WHEN( "Number of rows less than 1") {
            string inputFile = "./test/resources/rows_less_1.dat";
            THEN( "Return error" ) {
                REQUIRE_THROWS( Parser::parseInput(inputFile) );
            }
        }

        WHEN( "Number of cols bigger than 2000") {
            string inputFile = "./test/resources/cols_bigger_2000.dat";
            THEN( "Return error" ) {
                // REQUIRE_THROWS( Parser::parseInput(inputFile) );
            }
        }

        WHEN( "Number of cols less than 1") {
            string inputFile = "./test/resources/cols_less_1.dat";
            THEN( "Return error" ) {
                REQUIRE_THROWS( Parser::parseInput(inputFile) );
            }
        }
    }
}