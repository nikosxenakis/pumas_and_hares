#include "../include/hare.hpp"

using namespace std;

string Hare::getName() {
    return name;
}

float Hare::getBirthRate() {
    return birth_rate;
}

void Hare::setBirthRate(float birth_rate) {
    if(birth_rate <= 0) {
        cout << "r configuration must be greater than 0" << endl;
        exit(1);
    }
    Hare::birth_rate = birth_rate;
}

float Hare::getPredationRate() {
    return predation_rate;
}

void Hare::setPredationRate(float predation_rate) {
    if(predation_rate <= 0) {
        cout << "a configuration must be greater than 0" << endl;
        exit(1);
    }
    Hare::predation_rate = predation_rate;
}

float Hare::getDiffusionRate() {
    return diffusion_rate;
}

void Hare::setDiffusionRate(float diffusion_rate) {
    if(diffusion_rate <= 0) {
        cout << "k configuration must be greater than 0" << endl;
        exit(1);
    }
    Hare::diffusion_rate = diffusion_rate;
}

float Hare::calculateNewDensity(float H_old, float P_old, int land_neighbours, float sum_density_neighbours) {
    float dt = ConfigData::getDeltaT();

    return H_old
            + dt * (birth_rate * H_old
            - predation_rate * H_old * P_old
            + diffusion_rate * (sum_density_neighbours - (float) land_neighbours * H_old));
}

string Hare::name = "Hare";
// default values as in case study
float Hare::birth_rate = 0.08;
float Hare::predation_rate = 0.04;
float Hare::diffusion_rate = 0.2;
