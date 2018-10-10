#include "../include/hare.hpp"

HARE::HARE(){
	float H = 0.1;
}

// todo: interface for parameters / array
float HARE::calculateNewDensity(float H_old, float sum_density_neighbours) {
    int dt = 1;
    // todo: instead use Landscape::getNumberOfLandNeighbours(int row, int col)
    float sum_density_neighbours = 1.0;
    // todo: instead use Landscape::getSumDensityNeighbours(std::string animal, int row, int col)
    int land_neighbours = 4;

    return H_old
        + dt * (this->getR() * H_old
        - this->getA() * H_old * P_old + k * (sum_density_neighbours - land_neighbours * H_old));
}