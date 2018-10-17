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

TEST_CASE( "Puma Test", "[Testing getBirthRate]" ){
   float a = 3.0;
   Puma::setBirthRate(a);
   float b = Puma::getBirthRate();

   REQUIRE(b == a);
}


