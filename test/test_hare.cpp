/* landscape_test.cpp
 *
 * Tests landscape class and its functions
 *
 */

#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "../include/hare.hpp"

using namespace std;

TEST_CASE( "Hare Test", "[Testing the hares]" ){
   float a = 3.0;
   Hare::setBirthRate(a);
   float b = Hare::getBirthRate();

   REQUIRE(b == a);
}
