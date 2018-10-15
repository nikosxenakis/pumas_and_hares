#ifndef PUMA_HPP
#define PUMA_HPP
#include "../include/landscape.hpp"
#include "../include/animal.hpp"
#include <string>

using namespace std;

class Puma: public Animal {
private:
    /**
     * @description density of pumas (predators)
     */
    float P;
    /**
     * @description mortality rate
     */
    static float mortality_rate;

public:
    static float getMortalityRate();
    static void setMortalityRate(float mortality_rate);
    /**
     * @description Calculate new Puma density
     * @param P_old
     * @param sum_density_neighbours
     *
     * @return float
     */
    // todo: return typedef Density (in tile.hpp)
    float calculateNewDensity(float P_old, float H_old);
};


#endif
