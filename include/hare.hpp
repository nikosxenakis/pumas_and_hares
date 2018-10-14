#ifndef HARE_HPP
#define HARE_HPP
#include "../include/landscape.hpp"
#include "../include/animal.hpp"
#include <string>

using namespace std;

class Hare: public Animal{
private:
    /**
     * @description density of hares (preys)
     */
    float H;
    /**
     * @description birth rate of hares
     */
    /**
     * @description predation rate at which pumas eat hares
     */
    static float predation_rate;

public:
    Hare();
    static float getPredationRate();
    static void setPredationRate(float predation_rate);
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
