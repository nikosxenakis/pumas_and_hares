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
    static float r;
    /**
     * @description predation rate at which pumas eat hares
     */
    static float a;
    /**
     * @description diffusion rates for hares
     */
    static float k;

public:
    Hare();
    static string getName();
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