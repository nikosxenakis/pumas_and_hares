#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "include/puma.hpp"
#include "include/landscape.hpp"
#include "include/landscapeParser.hpp"

//write the parameters in a json configuration file

class TestClass {

public:
	static void simulationLoop() {

		int dt = 251;
    	
    	Landscape::print();

		for (int t = 0; t <= 500; t+=dt) {
			Landscape::update();
            Landscape::print();
		}
		
	}

	static vector< vector<int> > initTilesVector() {
	    vector< vector<int> > tilesVector;

		for (int i = 0; i < 10; ++i)
		{
			vector<int> tilesLine;
			for (int j = 0; j < 10; ++j)
			{
				tilesLine.push_back((i*j)%2);
			}
			tilesVector.push_back(tilesLine);
		}

	    return tilesVector;
	}

};

int main() {
    //Puma* puma = new Puma();
    //LandscapeParser::parseFile(".resources/small.dat");
    time_t t = time(NULL);
    srand (t);
    
    vector< vector<int> > tilesVector = TestClass::initTilesVector();

    Landscape::init(tilesVector);
    
    TestClass::simulationLoop();

//    (Landscape::getTile(0, 0))->print();
    return 0;
}
