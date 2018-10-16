#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <iostream>
#include <vector>
#include "tile.hpp"
#include "hare.hpp"
#include "puma.hpp"

using namespace std;

typedef Tile*** TilesArray;

class Landscape {
    
private :
    static Landscape* instance;
    Landscape(vector< vector<int> > tilesVector);
    ~Landscape();
    static vector<Tile*> getNeighbours(int row, int col) throw (out_of_range);
    TilesArray tiles;
    size_t rows;
    size_t cols;

public :
    static void init(vector< vector<int> > tilesVector);
    static void destroy();
    static void update();
    static void print();
    static Tile* getTile(size_t row, size_t col);
    static int getNumberOfLandNeighbours(int row, int col);
    static Density getSumDensityNeighbours(string animal, int row, int col);
};

#endif
