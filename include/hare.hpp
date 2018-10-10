#ifndef HARE_HPP
#define HARE_HPP
#include "../include/landscape.hpp"
#include <string>

using namespace std;

class Hare {
private:
    static string name;
    /**
     * @description density of hares (preys)
     */
    float H;
    /**
     * @description birth rate of hares
     */
    static float birth_rate;
    /**
     * @description predation rate at which pumas eat hares
     */
    static float predation_rate;
    /**
     * @description diffusion rates for hares
     */
    static float diffusion_rate;

public:
    Hare();
    static string getName();
    static float getBirthRate();
    static void setBirthRate(float birth_rate);
    static float getPredationRate();
    static void setPredationRate(float predation_rate);
    static float getDiffusionRate();
    static void setDiffusionRate(float diffusion_rate);
    /**
     * @description Calculate new Hare density
     * @param H_old
     * @param sum_density_neighbours
     *
     * @return float
     */
    // todo: return typedef Density (in tile.hpp)
    float calculateNewDensity(float H_old, float P_old);
};

#endif