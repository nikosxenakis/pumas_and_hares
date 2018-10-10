#include "../include/hare.hpp"
#include <string>

using namespace std;

string Hare::getName() {
    return name;
}

// todo: interface for parameters / array
float Hare::calculateNewDensity(float H_old, float P_old) {
    int dt = 1;
    int row = 1;
    int col = 1;

    float sum_density_neighbours = Landscape::getSumDensityNeighbours(Hare::name, row, col);
    int land_neighbours = Landscape::getNumberOfLandNeighbours(row, col);

    return H_old
            + dt * (Hare::r * H_old
            - Hare::a * H_old * P_old + Hare::k * (sum_density_neighbours - land_neighbours * H_old));
}

string Hare::name = "Hare";
float Hare::r = 0.9;
float Hare::a = 0.8;
float Hare::k = 0.7;