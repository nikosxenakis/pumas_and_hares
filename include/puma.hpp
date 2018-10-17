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
     * @param P_old
     * @param sum_density_neighbours
     *
     * @return float
     */
    // todo: return typedef Density (in tile.hpp)
    static float calculateNewDensity(float P_old, float H_old, int land_neighbours, float sum_density_neighbours);
};

#endif
