#include "../include/puma.hpp"

using namespace std;

string Puma::getName() {
    return Puma::name;
}

float Puma::getBirthRate() {
    return Puma::birth_rate;
}

void Puma::setBirthRate(float birth_rate) throw(invalid_argument) {
    if(birth_rate <= 0)
        throw invalid_argument("b configuration must be greater than 0");
    Puma::birth_rate = birth_rate;
}

float Puma::getMortalityRate() {
    return Puma::mortality_rate;
}

void Puma::setMortalityRate(float mortality_rate) throw(invalid_argument) {
    if(mortality_rate <= 0)
        throw invalid_argument("m configuration must be greater than 0");
    Puma::mortality_rate = mortality_rate;
}

float Puma::getDiffusionRate() {
    return Puma::diffusion_rate;
}

void Puma::setDiffusionRate(float diffusion_rate) throw(invalid_argument) {
    if(diffusion_rate <= 0)
        throw invalid_argument("l configuration must be greater than 0");
    Puma::diffusion_rate = diffusion_rate;
}

// todo: interface for parameters / array
float Puma::calculateNewDensity(float P_old, float H_old, int land_neighbours, float sum_density_neighbours) {
    float dt = ConfigData::getDeltaT();

    return P_old
            + dt * (Puma::birth_rate * H_old * P_old
            - Puma::mortality_rate * P_old
            + Puma::diffusion_rate * (sum_density_neighbours - (float) land_neighbours * P_old));
}

// init
string Puma::name = "Puma";
// default values as in case study
float Puma::birth_rate = 0.02;
float Puma::mortality_rate = 0.06;
float Puma::diffusion_rate = 0.2;
