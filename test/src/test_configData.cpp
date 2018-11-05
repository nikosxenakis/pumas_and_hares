/* @file configdata.cpp
 *
 * @brief Checks getters and setters. Also ensures exceptions are thrown where appropriate
 * @ingroup test
 *
 */
#include "../test_declarations.hpp"

#include STR(HEADERS_PATH/configData.hpp)

TEST_CASE( "ConfigData Test", "[Testing ConfigData getters and setters]" ){

    GIVEN("The ConfigData static class"){

        WHEN("trying to initilize DeltaT and CapitalT") {

          ConfigData::setDeltaT(0.4);
          ConfigData::setCapitalT(30);

            THEN( "Getters should work" ){
                REQUIRE( ConfigData::getDeltaT() == Approx(0.4) );
                REQUIRE( ConfigData::getCapitalT() == 30);
            }
        }

        WHEN("trying to initilize with wrong values DeltaT and CapitalT") {

            THEN( "setters throw exceptions" ){
                REQUIRE_THROWS(ConfigData::setDeltaT(-0.4));
                REQUIRE_THROWS(ConfigData::setCapitalT(-30));
            }
        }

    }

}
