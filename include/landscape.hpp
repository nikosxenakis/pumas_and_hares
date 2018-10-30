/**
 * @file landscape.hpp
 * @author Group 9
 * @date Oct 2018
 * @brief File containing class Landscape
 * @code{.hpp}
 */
#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <iostream>
#include <vector>
#include <assert.h>
#include "tile.hpp"

#define MAX_NEIGHBOURS 4

using namespace std;

/**
 * @typedef
 * @brief Type TilesArray is a pointer to a 2D Tiles array
 */
typedef Tile*** TilesArray;

/**
 * @class Landscape
 * @brief Provide information about the Landscape
 * @details A class that contains data about the Landscape size and tiles
 */
class Landscape {
    
private :
    static Landscape* instance;   /**< the static variable that contains the instance of the landscape */
    TilesArray tiles;   /**< array of the containing tiles */
    size_t rows;   /**< number of rows in landscape */
    size_t cols;   /**< number of cols in landscape */
    /**
     * @brief Landscape contructor
     */
    Landscape(vector< vector<TileData*> > tilesVector, size_t rows, size_t cols);
    /**
     * @brief Landscape destructor
     */
    ~Landscape();
    /**
     * @brief returns an array with the neighbour tiles
     * 
     * @param tilesVector Array of tiles
     * @param row Target tile row
     * @param col Target tile col
     */
    static void getNeighbours(Tile** tilesVector, size_t row, size_t col);
    /**
     * @brief Returns Information about the neighbour tiles
     * 
     * @param tilesVector Array of tiles
     * @param tileData A structure with information for all the neighbour tiles
     * @param row Target tile row
     * @param col Target tile col
     */
    static void getNeighboursInfo(Tile** tilesVector, TileData* tileData, size_t row, size_t col);
public :
    /**
     * @brief Initializes the static Lanscape
     * 
     * @param tilesVector Array of tiles
     * @param row Target tile row
     * @param col Target tile col
     */
    static void init(vector< vector<TileData*> > tilesVector, size_t rows, size_t cols) ;
    /**
     * @brief Destroys the static information about the Landscape
     */
    static void destroy();
    /**
     * @brief Calculates new densities in the Lanscape
     */
    static void calculate();
    /**
     * @brief Updates new densities in the Lanscape
     */
    static void update();
    /**
     * @brief Prints the lanscape
     */
    static void print();
    /**
     * @return Returns the number of Rows
     */
    static size_t const getRows();
    /**
     * @return Returns the number of Cols
     */
    static size_t const getCols();
    /**
     * @brief Finds the tile in the given row and col
     * 
     * @param row Target tile row
     * @param col Target tile col
     * 
     * @return Returns the tile in the given row and col
     */
    static Tile* getTile(size_t row, size_t col);
    /**
     * @return Returns the max density of Pumas in the landscape
     */
    static Density const getMaxPumas();
    /**
     * @return Returns the max density of Hares in the landscape
     */
    static Density const getMaxHares();
    /**
     * @return Returns the average density of Pumas in the landscape
     */
    static Density const getAveragePumas();
    /**
     * @return Returns the max density of Hares in the landscape
     */
    static Density const getAverageHares();
    /**
     * @brief Find information about a specific region
     * 
     * @param row Target tile row
     * @param col Target tile col
     * @param m Number of rows in the region
     * @param n Number of cols in the region
     * @return Returns information about the requested region
     */
    static TileData* const getRegion(size_t row, size_t col, size_t m, size_t n);
};

#endif
