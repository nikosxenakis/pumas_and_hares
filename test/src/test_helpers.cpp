/* helpers_test.cpp
 *
 * Tests helpers class and its functions
 *
 */
#include "../test_declarations.hpp"

#include STR(HEADERS_PATH/configData.hpp)
#include STR(HEADERS_PATH/helpers.hpp)
#include STR(HEADERS_PATH/parser.hpp)

using namespace std;

TEST_CASE( "SimulationLoop Test", "[Testing Helpers::simulationLoop()]" ){

    GIVEN( "configFile and landFile inputs" ){
        string file = STR(INPUT_FILES_PATH/small3x3.dat);
        string config_file = STR(CONFIG_PATH/param.json);

        WHEN( "configFile and landFile can be parsed and Parser does not throw error" ) {
            REQUIRE_NOTHROW(Parser::parseConfig(config_file));
            REQUIRE_NOTHROW(Parser::parseInput(file));

            THEN( "Helpers gets initialised" ) {
                REQUIRE_NOTHROW(Helpers::init(file, config_file));
            }
        }
    }
}