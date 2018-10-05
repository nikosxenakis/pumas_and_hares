#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>

using namespace std;

class Grid {

	private :
		bool water;
		double hDensity;
		double pDensity;

	public :
		Grid(bool water);
		void print();
};

#endif
