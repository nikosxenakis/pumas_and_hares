/**
 * @file hare.hpp
 * @brief Information about the hare model
 * @ingroup pumas_and_hares
 * @ingroup data_structures
 */

#ifndef HARE_HPP
#define HARE_HPP

#include <string>
#include "configData.hpp"

using namespace std;

/**
 * @class Hare
 * @brief Hare model with parameters
 * @details A class holding all config parameters associated with Hare and its density calculation
 */
class Hare {
private:
    static string name;
    /**
     * @brief birth rate of hares
     */
    static float birth_rate;

    /**
     * @brief predation rate at which pumas eat hares
     */
    static float predation_rate;

    /**
     * @brief diffusion rates for hares
     */
    static float diffusion_rate;
public:
    /**
     * @brief Hare constructor
     */
    Hare();
    /**
     * @brief gets the name attribute of class Hare
     * @return name
     */
    static string getName();

    /**
     * @brief gets the birth rate
     * @return birth rate
     */
    static float getBirthRate();

    /**
     * @brief sets the birth rate
     * @param birth_rate birth_rate
     */
    static void setBirthRate(float birth_rate) throw(invalid_argument);

    /**
     * @brief gets the predation rate
     * @return predation rate
     */
    static float getPredationRate();

    /**
     * @brief sets the predation rate
     * @param predation_rate predation_rate
     */
    static void setPredationRate(float predation_rate) throw(invalid_argument);

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
     * @brief Calculate new hare density
     * @param[in] P_old previous number of pumas
     * @param[in] H_old previous number of hares
     * @param[in] land_neighbours number of adjacent tiles of type land
     * @param[in] sum_density_neighbours sum of adjacent hare densities
     *
     * @return newly calculated Hare Density
     */
    static float calculateNewDensity(float H_old, float P_old, int land_neighbours, float sum_density_neighbours);
};

#endif
