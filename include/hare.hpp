#ifndef HARE_HPP
#define HARE_HPP
#include <string>
#include "parser.hpp"

using namespace std;

class Hare {
private:
    static string name;
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
     * @description Calculate new hare density
     * @param float P_old previous number of pumas
     * @param float H_old previous number of hares
     * @param int land_neighbours number of adjacent tiles of type land
     * @param float sum_density_neighbours sum of adjacent hare densities
     *
     * @return float
     */
    static float calculateNewDensity(float H_old, float P_old, int land_neighbours, float sum_density_neighbours);
};

#endif
