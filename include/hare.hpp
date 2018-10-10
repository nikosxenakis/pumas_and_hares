#ifndef HARE_HPP
#define HARE_HPP

#endif

class HARE {
private:
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
    HARE();
    /**
     * @description Calculate new Hare density
     * @param H_old
     * @param sum_density_neighbours
     *
     * @return float
     */
    // todo: return typedef Density (in tile.hpp)
    float calculateNewDensity(float H_old, float sum_density_neighbours);
};
