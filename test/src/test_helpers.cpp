/* @file test_helpers.cpp
 *
 * @brief Tests helpers class and its functions
 *
 * @ingroup Test
 */
#include "../test_declarations.hpp"

#include STR(HEADERS_PATH/helpers.hpp)

TEST_CASE( "SimulationLoop Test", "[Testing Helpers::simulationLoop()]" ){

    GIVEN( "configFile and landFile inputs" ){

        WHEN( "configFile and landFile are valid" ) {
            string inputFile = STR(INPUT_FILES_PATH/small3x3.dat);
            string config_file = STR(CONFIG_PATH/param.json);

            THEN( "Helpers gets initialised and simulation runs properly" ) {
                REQUIRE_NOTHROW(Helpers::init(inputFile, config_file));
                Helpers::simulationLoop();
                Helpers::close();
            }
        }

        WHEN( "inputFile is invalid" ) {
            string inputFile = STR(INPUT_FILES_PATH/cols_less_1.dat);
            string config_file = STR(CONFIG_PATH/param.json);

            THEN( "Helper initialization throws exception" ) {
                REQUIRE_THROWS(Helpers::init(inputFile, config_file));
            }
        }

        WHEN( "configFile is invalid" ) {
            string inputFile = STR(INPUT_FILES_PATH/small3x3.dat);
            string config_file = STR(CONFIG_PATH/invalid_param.json);

            THEN( "Helper initialization throws exception" ) {
                REQUIRE_THROWS(Helpers::init(inputFile, config_file));
            }
        }
    }
}
