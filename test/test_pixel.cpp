#include "catch.hpp"

#include "../include/pixel.hpp"


TEST_CASE( "Pixel Test", "[Testing pixel's getters and setters]" ){

    GIVEN( " A pixel "){
        Pixel p = Pixel();
        
        THEN( "The pixel is set to blue "){
            REQUIRE(p.getRed() == 64);
            REQUIRE(p.getGreen() == 164);
            REQUIRE(p.getBlue() == 223);
        }

        WHEN( "We set the pixel's value to an edge case "){
            p.setColour(Colour::hares, 3.0, 0, 0);

            THEN( "The pixel returns sane results"){
                REQUIRE(p.getGreen() == 254);
            }

        }
        WHEN( "We set the pixel colour for pumas ") {
            p.setColour(Colour::pumas, 1.0, 2.0, 2.0);

            THEN( "The pixel colour is set correctly"){
                REQUIRE(p.getRed() == 254);
                REQUIRE(p.getGreen() == 127);
                REQUIRE(p.getBlue() == 127);
            }
        }
        WHEN(" We set the pixel colour for hares ") {
            p.setColour(Colour::hares, 1.0, 2.0, 2.0);

            THEN( "The pixel colours is set correctly") {
                REQUIRE(p.getRed() == 127);
                REQUIRE(p.getGreen() == 254);
                REQUIRE(p.getBlue() == 127);
            }
        }
    }

}
