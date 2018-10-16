#include "../include/hare.hpp"
#include <string>

using namespace std;

string Hare::getName() {
    return name;
}

float Hare::getBirthRate() {
    return birth_rate;
}

void Hare::setBirthRate(float birth_rate) {
    Hare::birth_rate = birth_rate;
}

float Hare::getPredationRate() {
    return predation_rate;
}

void Hare::setPredationRate(float predation_rate) {
    Hare::predation_rate = predation_rate;
}

float Hare::getDiffusionRate() {
    return diffusion_rate;
}

void Hare::setDiffusionRate(float diffusion_rate) {
    Hare::diffusion_rate = diffusion_rate;
}

// todo: interface for parameters / array
float Hare::calculateNewDensity(float H_old, float P_old) {
    int dt = 1;
    int row = 1;
    int col = 1;

    float sum_density_neighbours = Landscape::getSumDensityNeighbours(Hare::name, row, col);
    int land_neighbours = Landscape::getNumberOfLandNeighbours(row, col);

    return H_old
            + dt * (birth_rate * H_old
            - predation_rate * H_old * P_old
            + diffusion_rate * (sum_density_neighbours - land_neighbours * H_old));
}

string Hare::name = "Hare";
float Hare::birth_rate = 0.01;
float Hare::predation_rate = 0.02;
float Hare::diffusion_rate = 0.03;
