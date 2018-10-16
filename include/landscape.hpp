#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <iostream>
#include <vector>
#include "tile.hpp"

using namespace std;

typedef Tile*** TilesArray;

class Landscape {
    
private :
    static Landscape* instance;
    Landscape(vector< vector<int> > tilesVector);
    ~Landscape();
    static Tile** getNeighbours(int row, int col);
    TilesArray tiles;
    int rows;
    int cols;

public :
    static void init(vector< vector<int> > tilesVector);
    static void destroy();
    static void update();
    static void print();
    static Tile* getTile(int row, int col);
    static int getNumberOfLandNeighbours(int row, int col);
    static Density getSumDensityNeighbours(string animal, int row, int col);
};

#endif
