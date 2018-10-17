#ifndef TILE_HPP
#define TILE_HPP

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "hare.hpp"
#include "puma.hpp"

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
     */
    Tile(bool land);
    Tile(bool land, Density hares, Density pumas);
    ~Tile();
    void const print();
    void calculate(int tile_neighbours, float hare_neighbour_sume, float puma_neighbour_sume);
    void update();
    Density const getNeighbours();
    bool const isLand();
    Density const getOldHares();
    Density const getOldPumas();
    Density const getDensity(string animal);
};

#endif
