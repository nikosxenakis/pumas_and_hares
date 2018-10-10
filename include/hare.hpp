#ifndef HARE_HPP
#define HARE_HPP

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
        static float l;

    public:
        HARE();
        /**
         * @description Calculation new Hare density
         * @param H_old
         * @param H_old_left
         * @param H_old_right
         * @param H_old_top
         * @param H_old_bottom
         *
         * @return float
         */
         // todo: return typedef Density (in tile.hpp)
        float calculateNewDensity(float H_old, float H_old_left, float H_old_right, float H_old_top, float H_old_bottom);
};

#endif