#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <iostream>
#include <vector>
#include "tile.hpp"

using namespace std;

typedef vector<Tile> LandscapeTileRow;
typedef vector<LandscapeTileRow> LandscapeTileVector;

class Landscape {
    
	private :
		static Landscape* instance;
		Landscape(vector< vector<int> > tilesVector);
		LandscapeTileVector tiles;

	public :
		static void init(vector< vector<int> > tilesVector);
		static void update();
		static void print();
		static Tile getTile(int row, int column);
};

#endif
