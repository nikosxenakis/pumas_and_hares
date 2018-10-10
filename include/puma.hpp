#ifndef PUMA_HPP
#define PUMA_HPP

class PUMA {
private:
    /**
     * @description density of pumas (predators)
     */
    float P;
    /**
     * @description birth rate of pumas per one heare eaten
     */
    static float b;
    /**
     * @description mortality rate
     */
    static float m;
    /**
     * @description diffusion rates for pumas
     */
    static float l;

public:
    PUMA();
    /**
     * @description Calculate new Puma density
     * @param P_old
     * @param sum_density_neighbours
     *
     * @return float
     */
    // todo: return typedef Density (in tile.hpp)
    float calculateNewDensity(float P_old, float sum_density_neighbours);
};

#endif
