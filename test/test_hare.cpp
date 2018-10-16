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
   Hare* h = new Hare;
   float b = h->getBirthRate();

   REQUIRE(b == 0.01);
}
