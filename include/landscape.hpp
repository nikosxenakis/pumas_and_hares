#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <iostream>
#include <vector>
#include <assert.h>
#include "tile.hpp"

#define MAX_NEIGHBOURS 4

using namespace std;

typedef Tile*** TilesArray;

class Landscape {
    
private :
    static Landscape* instance;
    Landscape(vector< vector<TileData*> > tilesVector, size_t rows, size_t cols);
    ~Landscape();
    static void getNeighbours(Tile** tilesVector, int row, int col);
    static void getNeighboursInfo(Tile** tilesVector, TileData* tileData, int row, int col);
    TilesArray tiles;
    size_t rows;
    size_t cols;
public :
    static void init(vector< vector<TileData*> > tilesVector, size_t rows, size_t cols) ;
    static void destroy();
    static void calculate();
    static void update();
    static void print();
    static size_t const getRows();
    static size_t const getCols();
    static Tile* getTile(size_t row, size_t col);
    static Density const getMaxPumas();
    static Density const getMaxHares();
    static Density const getAveragePumas();
    static Density const getAverageHares();
    static TileData* const getRegion(size_t row, size_t col, size_t m, size_t n);
};

#endif
