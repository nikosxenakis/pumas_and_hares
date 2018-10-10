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

	    vector< vector<int> > tilesVector;

		{
			vector<int> tilesLine;
			{
<<<<<<< HEAD
				tilesLine.push_back((i*j)%2);
=======
>>>>>>> 1de39b49e0082516be268b7d56c1bc6ac93597d4
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
    

    Landscape::init(tilesVector);
    
    TestClass::simulationLoop();

//    (Landscape::getTile(0, 0))->print();
    return 0;
}
