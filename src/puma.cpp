#include "../include/puma.hpp"
#include <string>

using namespace std;


float Puma::getMortalityRate() {
    return mortality_rate;
}

void Puma::setMortalityRate(float mrate) {
    mortality_rate = mrate;
}


// todo: interface for parameters / array
float Puma::calculateNewDensity(float P_old, float H_old) {
    int dt = 1;
    int row = 1;
    int col = 1;

    float sum_density_neighbours = Landscape::getSumDensityNeighbours(this->getName(), row, col);
    int land_neighbours = Landscape::getNumberOfLandNeighbours(row, col);

    return P_old
            + dt * (Puma::birth_rate * H_old * P_old
            - Puma::mortality_rate * P_old + Puma::diffusion_rate * (sum_density_neighbours - land_neighbours * P_old));
}

float Puma::mortality_rate = 2;
