/**
 * @file tile.hpp
 * @author Group 9
 * @date Oct 2018
 * @brief File containing class Tile
 * @code{.hpp}
 */
#ifndef TILE_HPP
#define TILE_HPP

#include <stdlib.h>
#include <iostream>
#include "hare.hpp"
#include "puma.hpp"
#include "inputTile.hpp"

/**
 * @typedef
 * @brief Type Density of animals
 */
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
     * @brief a boolean variable which indicates if this tile contains land or not
     */
    bool land;
    Density oldHares;   /**< number of hares */
    Density oldPumas;
    Density newHares;
    Density newPumas;
    void clear();
    public :
    /**
     * @brief Creates a new object Tile initializing the land value
     * @param inputTile is a boolean variable which indicates if this tile contains land or not
     */
    Tile(InputTile* inputTile);
    ~Tile();
    /**
     * @brief prints information for tile
     */
    void const print();
    /**
     * @brief calculates the new densities of pumas and hares
     * @param[in] tile_neighbours number of neighbour tiles with land
     * @param[in] hare_neighbour_sum number of hares in the neighbour tiles
     * @param[in] puma_neighbour_sum number of pumas in the neighbour tiles
     */
    void calculate(int tile_neighbours, float hare_neighbour_sum, float puma_neighbour_sum);
    void update();
    /**
     * @brief checks if the tile is land
     * @return either TRUE if the tile is land or FALSE if it is not
     */
    bool const isLand();
    Density const getOldHares();
    Density const getOldPumas();
};

#endif
