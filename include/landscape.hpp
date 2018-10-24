#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <iostream>
#include <vector>
#include "tile.hpp"
#include "inputTile.hpp"
#include "log.hpp"

#define MAX_NEIGHBOURS 4

using namespace std;

typedef Tile*** TilesArray;

class Landscape {
    
private :
    static Landscape* instance;
    Landscape(vector< vector<InputTile*> > tilesVector, int rows, int cols);
    ~Landscape();
    static Tile** getNeighbours(int row, int col);
    static InputTile* getNeighboursInfo(int row, int col);
    TilesArray tiles;
    int rows;
    int cols;
    Density maxPumas;
    Density maxHares;
public :
    static void init(vector< vector<InputTile*> > tilesVector, int rows, int cols) ;
    static void destroy();
    static void calculate();
    static void update();
    static void print();
    static Tile* getTile(int row, int col);
    static int const getRows();
    static int const getCols();
    static Density const getMaxPumas();
    static Density const getMaxHares();
    static void setMaxPumas(Density pumas);
    static void setMaxHares(Density hares);
    static Density const getAveragePumas();
    static Density const getAverageHares();
    static InputTile const getRegion(int row, int col, int m, int n);
};

#endif
