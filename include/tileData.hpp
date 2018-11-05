/**
 * @file tileData.hpp
 * @brief Provide information about tileData
 * @ingroup pumas_and_hares
 * @ingroup data_structures
 */

#ifndef tileData_h
#define tileData_h

#include <iomanip>

/**
 * @class TileData
 * @brief Provide information about TileData
 * @details A class that contains data about the current and new densities of the tile, also whether the tile is land or not
 */
class TileData {
public:
    /**
     * @brief if land or water
     */
    int land;
    /**
     * @brief puma density
     */
    float pumas;
    /**
     * @brief hare density
     */
    float hares;

    /**
     * @brief constructor
     * @param hares hares
     * @param land land
     * @param pumas pumas
     */
    TileData(int land, float pumas, float hares);
    /**
     * @brief constructor
     * @param land land
     */
    TileData(int land);

    /**
     * @brief clearing
     */
    void clear();
};

#endif
