#ifndef GRID_HPP
#define GRID_HPP

#include <stdlib.h>
#include <iostream>

typedef float Density;

using namespace std;

class Tile {

	private :
		bool land;
		Density oldHares;
		Density oldPumas;
		Density newHares;
		Density newPumas;

	public :
		Tile(bool land);
		void print();
		void update();
		Density getNeighbours();
};

#endif
