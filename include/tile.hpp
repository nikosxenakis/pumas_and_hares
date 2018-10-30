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
    bool land;   /**< a boolean variable which indicates if this tile contains land or not */
    Density oldHares;   /**< number of hares */
    Density oldPumas;   /**< number of pumas */
    Density newHares;   /**< new number of hares */
    Density newPumas;   /**< new number of pumas */
    
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
    Density const getOldHares();

    /**
     * @return returns number of pumas
     */
    Density const getOldPumas();
};

#endif
