#ifndef GRID_HPP
#define GRID_HPP

#include <stdlib.h>
#include <iostream>

typedef float Density;

using namespace std;
/**
 * @class Tile
 * @brief Provide information about a Tile
 * @details ..
 */

class Tile {

private :
    /**
     * @description a boolean variable which indicates if this tile contains land or not
     */
    bool land;
    Density oldHares;
    Density oldPumas;
    Density newHares;
    Density newPumas;

public :
    /**
     * @description Creates a new object Tile initializing the land value
     * @param land is a boolean variable which indicates if this tile contains land or not
     * @return None
     */
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
