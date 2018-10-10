#include "../include/puma.hpp"

Puma::Puma(){
	this->x = 1;
}

// todo: interface for parameters / array
float PUMA::calculateNewDensity(float P_old, float sum_density_neighbours) {
    int dt = 1;
    // todo: instead use Landscape::getNumberOfLandNeighbours(int row, int col)
    float sum_density_neighbours = 1.0;
    // todo: instead use Landscape::getSumDensityNeighbours(std::string animal, int row, int col)
    int land_neighbours = 4;

    return P_old
           + dt * (this->getB() * H_old * P_old
                   - this->getM() * P_old + this->getL() * (sum_density_neighbours - land_neighbours * P_old));
}