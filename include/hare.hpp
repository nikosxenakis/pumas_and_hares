#ifndef HARE_HPP
#define HARE_HPP

#include <string>
#include "configData.hpp"

using namespace std;

/**
 * @class Hare
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
    Hare();
    static string getName();

    static float getBirthRate();
    static void setBirthRate(float birth_rate);

    static float getPredationRate();
    static void setPredationRate(float predation_rate)
    ;
    static float getDiffusionRate();
    static void setDiffusionRate(float diffusion_rate);

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
