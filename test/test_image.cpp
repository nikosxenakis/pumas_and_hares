#include <string>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

#include "../include/helpers.hpp"
#include "../include/landscape.hpp"
#include "../include/image.hpp"
#include "catch.hpp"

using namespace std;

TEST_CASE( "Image test", "[Testing image functions]"){

    const char* outFolder = "./test/out";

    GIVEN( "A 3x3 land file" ){

        string land_file = ("./resources/small3x3.dat");
        Helpers::init(land_file);

        WHEN( "We write the image file"){
            
            Image::init(ConfigData::NX-2,ConfigData::NY-2);
            Image::setGrid();
            mkdir(outFolder, 0777);
            Image::write(outFolder, 0);

            THEN( "The image is the expected size"){
                
                string line;
                ifstream input("./test/out/Density_000.ppm");
                getline(input, line);
                REQUIRE(line == "P3");
                getline(input, line);
                REQUIRE(line == "30 30");
                input.close();
            }
        }
    }

}

TEST_CASE( "Clean up Image Test", "[cleaning]"){

    int rmSuccess = system("rm -rf /home/jim/Documents/masters/prog_skills/pumas_and_hares/test/out/");
    REQUIRE( 0 == rmSuccess);
            
}
