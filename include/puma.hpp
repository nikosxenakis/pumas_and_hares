#ifndef PUMA_HPP
#define PUMA_HPP

#include <string>
#include "configData.hpp"

using namespace std;

/**
 * @class Puma
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
    Puma();
    static string getName();

    static float getBirthRate();
    static void setBirthRate(float birth_rate);

    static float getMortalityRate();
    static void setMortalityRate(float mortality_rate);

    static float getDiffusionRate();
    static void setDiffusionRate(float diffusion_rate);

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
