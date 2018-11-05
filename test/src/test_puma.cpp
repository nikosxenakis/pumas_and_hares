/* @file landscape_test.cpp
 *
 * @brief Tests landscape class and its functions
 * @ingroup test
 */
#include "../test_declarations.hpp"

#include <iostream>
#include <fstream>

#include STR(HEADERS_PATH/puma.hpp)
#include STR(HEADERS_PATH/configData.hpp)

using namespace std;

TEST_CASE( "Puma Test", "[Testing puma getters and setters]" ){

    GIVEN("The static class Puma") {

        WHEN("initilize the variables") {
            Puma::setBirthRate(3.0);
            Puma::setMortalityRate(3.0);
            Puma::setDiffusionRate(3.0);

            THEN("setters throw exceptions") {
              REQUIRE( Puma::getBirthRate() == 3.0 );
              REQUIRE( Puma::getMortalityRate() == 3.0);
              REQUIRE( Puma::getDiffusionRate() == 3.0);
            }
        }

        WHEN("trying to initilize with wrong values") {

            THEN("setters throw exceptions") {
              REQUIRE_THROWS(Puma::setBirthRate(-3.0));
              REQUIRE_THROWS(Puma::setMortalityRate(-3.0));
              REQUIRE_THROWS(Puma::setDiffusionRate(-3.0));
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

      WHEN("the ConfigData and Hare class parameters are set") {
          ConfigData::setDeltaT(1.0);
          Puma::setBirthRate(1.0);
          Puma::setMortalityRate(1.0);
          Puma::setDiffusionRate(1.0);

          THEN("calculateNewDensity() returns") {
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
