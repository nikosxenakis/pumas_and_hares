/**
 * @file tile.hpp
 * @brief Provide information about a Tile
 * @ingroup pumas_and_hares
 * @author Nikolaos Xenakis http://github.com/nikosxenakis nikosxenakis94@gmail.com
 */

#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
#include "hare.hpp"
#include "puma.hpp"
#include "tileData.hpp"

/**
 * @typedef
 * @brief Type Density of animals
 */
typedef float Density;

using namespace std;

/**
 * @class Tile
 * @brief Provide information about a Tile
 * @details A class that contains data about the current and new densities of the tile, also whether the tile is land or not
 */
class Tile {

private :
    /**
     * @brief a boolean variable which indicates if this tile contains land or not
     */
    bool land;
    /**
     * @brief number of hares
     */
    Density hares;
    /**
     * @brief number of pumas
     */
    Density pumas;
    /**
     * @brief new number of hares
     */
    Density newHares;
    /**
     * @brief new number of pumas
     */
    Density newPumas;
    
    /**
     * @brief Resets the densities of the tile
     */
    void clear();
public :
    /**
     * @brief Creates a new object Tile initializing the land value
     * @param tileData is a boolean variable which indicates if this tile contains land or not
     */
    Tile(TileData* tileData);
    
    /**
     * @brief Destructs the Tile and free the allocated memory
     */
    ~Tile();

    /**
     * @brief calculates the new densities of pumas and hares
     * @param[in] tile_neighbours number of neighbour tiles with land
     * @param[in] hare_neighbour_sum number of hares in the neighbour tiles
     * @param[in] puma_neighbour_sum number of pumas in the neighbour tiles
     */
    void calculate(int tile_neighbours, float hare_neighbour_sum, float puma_neighbour_sum);
    
    /**
     * @brief updates the old to be the new densities of the animals in the tile
     */
    void update();

    /**
     * @brief checks if the tile is land
     * @return either TRUE if the tile is land or FALSE if it is not
     */
    bool const isLand();

    /**
     * @return returns number of hares
     */
    Density const getHares();

    /**
     * @return returns number of pumas
     */
    Density const getPumas();
};

#endif
