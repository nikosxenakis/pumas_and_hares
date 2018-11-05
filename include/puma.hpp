/**
 * @file puma.hpp
 * @brief Information about the Puma model
 * @ingroup pumas_and_hares
 * @ingroup data_structures
 */

#ifndef PUMA_HPP
#define PUMA_HPP

#include <string>
#include "configData.hpp"

using namespace std;

/**
 * @class Puma
 * @brief Puma model with parameters
 * @details A class holding all config parameters associated with Puma and its density calculation
 */
class Puma {
private:
    static string name;
    /**
     * @brief birth rate of pumas per one hare eaten
     */
    static float birth_rate;

    /**
     * @brief mortality rate
     */
    static float mortality_rate;

    /**
     * @brief diffusion rates for pumas
     */
    static float diffusion_rate;
public:
    /**
     * @brief Puma constructor
     */
    Puma();

    /**
     * @brief gets the name attribute
     * @return name
     */
    static string getName();

    /**
     * @brief gets the birth rate
     * @return birth_rate
     */
    static float getBirthRate();

    /**
     * @brief sets the birth rate
     * @param birth_rate birth_rate
     */
    static void setBirthRate(float birth_rate) throw(invalid_argument);

    /**
     * @brief gets the mortality rate
     * @return mortality rate
     */
    static float getMortalityRate();

    /**
     * @brief sets the mortlity rate
     * @param mortality_rate mortality_rate
     */
    static void setMortalityRate(float mortality_rate) throw(invalid_argument);

    /**
     * @brief gets diffusion rate
     * @return diffusion rate
     */
    static float getDiffusionRate();

    /**
     * @brief sets diffusion rate
     * @param diffusion_rate diffusion_rate
     */
    static void setDiffusionRate(float diffusion_rate) throw(invalid_argument);

    /**
     * @brief Calculate new Puma density
     * @param[in] P_old previous number of pumas
     * @param[in] H_old previous number of hares
     * @param[in] land_neighbours number of adjacent tiles of type land
     * @param[in] sum_density_neighbours sum of adjacent puma densities
     *
     * @return newly calculated Puma density
     */
    static float calculateNewDensity(float P_old, float H_old, int land_neighbours, float sum_density_neighbours);
};

#endif
