/* test_image.cpp
 *
 * Tests image class and its functions
 *
 */
#include "../test_declarations.hpp"

#include <string>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

#include STR(HEADERS_PATH/landscape.hpp)
#include STR(HEADERS_PATH/image.hpp)
#include STR(HEADERS_PATH/helpers.hpp)


using namespace std;

TEST_CASE( "Image test", "[Testing image functions]"){

    const char* outFolder = "./test/out";

    GIVEN( "A 1x1 land file" ){

        string land_file = STR(INPUT_FILES_PATH/small1x1.dat);
        string config_file = STR(CONFIG_PATH/param.json);
        Helpers::init(land_file, config_file);

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
                REQUIRE(line == "10 10");
                input.close();
            }

            THEN( " The colour prints correctly ") {  
                string line;
                ifstream input("./test/out/Density_000.ppm");
                getline(input, line);
                getline(input, line);
                getline(input, line);
                getline(input, line);
                REQUIRE(line == "254 1 1 254 1 1 254 1 1 254 1 1 ");
                input.close();
            }
        }
    }

}

TEST_CASE( "Clean up Image Test", "[cleaning]"){

    int rmSuccess = system("rm -rf /home/jim/Documents/masters/prog_skills/pumas_and_hares/test/out/");
    REQUIRE( 0 == rmSuccess);
            
}
