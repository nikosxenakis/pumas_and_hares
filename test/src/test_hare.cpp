/* hare_test.cpp
 *
 * Tests hare class and its functions
 *
 */
#include "../test_declarations.hpp"

#include STR(HEADERS_PATH/hare.hpp)
#include STR(HEADERS_PATH/landscape.hpp)
#include STR(HEADERS_PATH/configData.hpp)
#include STR(HEADERS_PATH/helpers.hpp)

using namespace std;

TEST_CASE( "Hare Test", "[Testing hare getters and setters]" ){

    GIVEN("The hare class, with initialised variables"){ 
        
        float a = 3.0;
        Hare::setBirthRate(a);
        Hare::setPredationRate(a);
        
        THEN( "Getters should work" ){
            REQUIRE( Hare::getBirthRate() == 3.0 );
            REQUIRE( Hare::getPredationRate() == 3.0);
        }
    }           

}

TEST_CASE( "Calculating new Hare Density", "[Testing Hare::CalculateNewDensity()]" ){

    GIVEN("P_old = 1.0, H_old = 1.0, land_neighbours = 1, sum_density_neighbours = 1.0") {

        float P_old = 1.0;
        float H_old = 1.0;
        int land_neighbours = 1;
        float sum_density_neighbours = 1.0;

        float br = 1.0;
        float pr = 1.0;
        float dr = 1.0;

        string land_file = STR(RESOURCES_PATH/small3x3.dat);

        WHEN("the Landscape is initilised and Hare Params are set") {
            Helpers::init(land_file);
            ConfigData::setDeltaT(1.0);

            Hare::setBirthRate(br);
            Hare::setPredationRate(pr);
            Hare::setDiffusionRate(dr);

            THEN("calculateNewDensity() returns") {
                /**
                 * return H_old
                    + dt * (birth_rate * H_old
                    - predation_rate * H_old * P_old
                    + diffusion_rate * (sum_density_neighbours - (float) land_neighbours * H_old));

                    1 + 1 * (1 * 1 - 1 * 1 * 1 + 1 * (1 - 1*1) == 1
                 */
                REQUIRE(Hare::calculateNewDensity(P_old, H_old, land_neighbours, sum_density_neighbours) == 1.0);
            }
        }

        // todo
        // test different results for calculateNewDensity
        // test negative parameters
        // test too large parameters

        // we already validate input config params in Parser
        // either reject negative values in Parser or not at all (but not here in Puma/Hare::calculateNewDensity())
    }
}
