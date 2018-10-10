#include "../include/puma.hpp"
#include <string>

using namespace std;

// todo: interface for parameters / array
float Puma::calculateNewDensity(float P_old, float H_old) {
    int dt = 1;
    int row = 1;
    int col = 1;

    float sum_density_neighbours = Landscape::getSumDensityNeighbours(Puma::name, row, col);
    int land_neighbours = Landscape::getNumberOfLandNeighbours(row, col);

    return P_old
            + dt * (b * H_old * P_old
            - m * P_old + l * (sum_density_neighbours - land_neighbours * P_old));
}

string Puma::name = "Puma";
float Puma::b = 0.9;
float Puma::m = 0.8;
float Puma::l = 0.7;