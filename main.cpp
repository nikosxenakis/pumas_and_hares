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

	static vector< vector<int> > initTilesVector(ifstream landFile) {
	    vector< vector<int> > tilesVector;

		int NY, NX, val;
		landFile >> NX;
		if (0 > NX || NX > 2000) {
			cout << "Number of columns must be between 1 and 2000" << endl;
			exit(1);
		}
		landFile >> NY;
  	 	if (0 > NY || NY > 2000) {
                        cout << "Number of rows must be between 1 and 2000" << endl;
			exit(1);
		}

		for (int i = 0; i < NX; ++i)
		{
			vector<int> tilesLine;
			for (int j = 0; j < NY; ++j)
			{
<<<<<<< HEAD
				tilesLine.push_back((i*j)%2);
=======
				landFile >> val;

				if (val != 0 || val != 1) {
					cout << "tile must be 1 or 0" << endl;
					exit(1);
				}
				else {
					tilesLine.push_back(val);
				}
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
    ifstream landFile;
    landFile.open("./resouces/small.dat");
    
    if (landFile.is_open()) {
        vector< vector<int> > tilesVector = TestClass::initTilesVector(&landFile);
    }
    else {
        cout << "File is not open" << endl;
        exit(1);
    }

    Landscape::init(tilesVector);
    
    TestClass::simulationLoop();

//    (Landscape::getTile(0, 0))->print();
    return 0;
}
