#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <vector>
#include <iostream>
#include <string>
#include "grid.hpp"

using namespace std;

typedef vector<Grid> LandscapeGridLine;
typedef vector<LandscapeGridLine> LandscapeGridVector;

class Landscape {
    
	private :
		static Landscape* instance;
		Landscape(int rows, int columns);
		int rows;
		int columns;
		LandscapeGridVector grids;

	public :
		static void Init(int rows, int columns);
		static void Print();
};

#endif
