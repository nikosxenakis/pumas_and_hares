#include "catch.hpp"

#include "../include/pixel.hpp"


TEST_CASE( "Pixel Test", "[Testing pixel's getters and setters]" ){

    GIVEN( " A pixel "){
        Pixel p = Pixel();
        
        WHEN( "We set the pixel's value to an edge case "){
            p.setColour(Colour::hares, 3.0, 0, 0);

            THEN( "The pixel returns sane results"){
                REQUIRE(p.getGreen() == 254);
            }

        }
    }

}
