/* @file test_hare.cpp
 *
 * @brief Tests hare class and its functions
 * @ingroup test
 *
 */
#include "../test_declarations.hpp"

#include STR(HEADERS_PATH/hare.hpp)
#include STR(HEADERS_PATH/configData.hpp)

TEST_CASE( "Hare Test", "[Testing hare getters and setters]" ){

    GIVEN("The static Hare class"){

        WHEN("initilize the variables") {
            Hare::setBirthRate(3.0);
            Hare::setPredationRate(3.0);
            Hare::setDiffusionRate(3.0);

            THEN("setters throw exceptions") {
              REQUIRE( Hare::getBirthRate() == 3.0 );
              REQUIRE( Hare::getPredationRate() == 3.0);
              REQUIRE( Hare::getDiffusionRate() == 3.0);
            }
        }

        WHEN("trying to initilize with wrong values") {

            THEN("setters throw exceptions") {
              REQUIRE_THROWS(Hare::setBirthRate(-3.0));
              REQUIRE_THROWS(Hare::setPredationRate(-3.0));
              REQUIRE_THROWS(Hare::setDiffusionRate(-3.0));
            }
        }
    }

}

TEST_CASE( "Calculating new Hare Density", "[Testing Hare::CalculateNewDensity()]" ){

    GIVEN("H_old = 1.0, P_old = 1.0, land_neighbours = 1, sum_density_neighbours = 1.0") {

        float H_old = 1.0;
        float P_old = 1.0;
        int land_neighbours = 1;
        float sum_density_neighbours = 1.0;

        WHEN("the ConfigData and Hare class parameters are set") {
            ConfigData::setDeltaT(1.0);
            Hare::setBirthRate(1.0);
            Hare::setPredationRate(1.0);
            Hare::setDiffusionRate(1.0);

            THEN("calculateNewDensity() returns") {
                /**
                 * return H_old
                    + dt * (birth_rate * H_old
                    - predation_rate * H_old * P_old
                    + diffusion_rate * (sum_density_neighbours - (float) land_neighbours * H_old));

                    1 + 1 * (1 * 1 - 1 * 1 * 1 + 1 * (1 - 1*1) == 1
                 */
                REQUIRE(Hare::calculateNewDensity(H_old, P_old, land_neighbours, sum_density_neighbours) == 1.0);
            }
        }
    }
}
