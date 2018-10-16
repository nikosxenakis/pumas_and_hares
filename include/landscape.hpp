#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <iostream>
#include <vector>
#include "tile.hpp"
#include "hare.hpp"
#include "puma.hpp"

using namespace std;

//typedef vector<Tile*> LandscapeTileRow;
//typedef vector<LandscapeTileRow> LandscapeTileVector;

class Landscape {
    
	private :
		static Landscape* instance;
		Landscape(vector< vector<int> > tilesVector);
        ~Landscape();
        Tile*** tiles;
        int rows;
        int cols;
//        LandscapeTileVector tiles;

	public :
		static void init(vector< vector<int> > tilesVector);
        static void destroy();
		static void update();
		static void print();
        static Tile* getTile(int row, int col);
		static int getNumberOfLandNeighbours(int row, int col);
        static Density getSumDensityNeighbours(std::string animal, int row, int col);
};

#endif
