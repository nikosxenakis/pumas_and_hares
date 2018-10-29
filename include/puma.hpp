#ifndef PUMA_HPP
#define PUMA_HPP
#include <string>

using namespace std;

class Puma {
private:
    static string name;
    /**
     * @description birth rate of pumas per one heare eaten
     */
    static float birth_rate;

    /**
     * @description mortality rate
     */
    static float mortality_rate;

    /**
     * @description diffusion rates for pumas
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
     * @description Calculate new Puma density
     * @param float P_old previous number of pumas
     * @param float H_old previous number of hares
     * @param int land_neighbours number of adjacent tiles of type land
     * @param float sum_density_neighbours sum of adjacent puma densities
     *
     * @return float
     */
    static float calculateNewDensity(float P_old, float H_old, int land_neighbours, float sum_density_neighbours);
};

#endif
