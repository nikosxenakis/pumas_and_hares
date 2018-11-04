/* @file landscape_test.cpp
 *
 * @brief Tests landscape class and its functions
 *
 */
#include "../test_declarations.hpp"

#include <iostream>
#include <fstream>

#include STR(HEADERS_PATH/puma.hpp)
#include STR(HEADERS_PATH/landscape.hpp)
#include STR(HEADERS_PATH/configData.hpp)
#include STR(HEADERS_PATH/helpers.hpp)

using namespace std;

TEST_CASE( "Puma Test", "[Testing puma getters and setters]" ){

    GIVEN("The puma class, with initialised variables") {

        WHEN("trying to set positive float to birth_rate and mortality_rate") {

            float a = 3.0;
            Puma::setBirthRate(a);
            Puma::setMortalityRate(a);
            Puma::setDiffusionRate(a);

            THEN("Getters should work") {
                REQUIRE(Puma::getBirthRate() == 3.0);
                REQUIRE(Puma::getMortalityRate() == 3.0);
                REQUIRE(Puma::getDiffusionRate() == 3.0);
            }
        }

        WHEN("trying to set negative float to birth_rate and mortality_rate") {

            float b = -3.0;
            THEN("setters throw exceptions") {
                REQUIRE_THROWS(Puma::setBirthRate(b));
                REQUIRE_THROWS(Puma::setMortalityRate(b));
                REQUIRE_THROWS(Puma::setDiffusionRate(b));
            }
        }
    }

}

TEST_CASE( "Calculating new Puma Density", "[Testing Puma::CalculateNewDensity()]" ){

    GIVEN("P_old = 1.0, H_old = 1.0, land_neighbours = 1, sum_density_neighbours = 1.0") {

        float P_old = 1.0;
        float H_old = 1.0;
        int land_neighbours = 1;
        float sum_density_neighbours = 1.0;

        float br = 1.0;
        float mr = 1.0;
        float dr = 1.0;

        string land_file = STR(INPUT_FILES_PATH/small3x3.dat);
        string config_file = STR(CONFIG_PATH/param.json);

        WHEN("the Landscape is initilised and Puma Params are set") {
            Helpers::init(land_file, config_file);
            ConfigData::setDeltaT(1.0);

            Puma::setBirthRate(br);
            Puma::setMortalityRate(mr);
            Puma::setDiffusionRate(dr);

            THEN("calculateNewDensity() returns correct result") {

                /**
                 * return P_old
                    + dt * (Puma::birth_rate * H_old * P_old
                    - Puma::mortality_rate * P_old
                    + Puma::diffusion_rate * (sum_density_neighbours - (float) land_neighbours * P_old));
                 */

                REQUIRE(Puma::calculateNewDensity(P_old, H_old, land_neighbours, sum_density_neighbours) == 1.0);
            }
        }
    }
}


