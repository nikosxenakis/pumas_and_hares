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
    ~Tile();
    void const print();
    void update();
    Density const getNeighbours();
    bool const isLand();
    Density const getOldHares();
    Density const getOldPumas();
};

#endif
