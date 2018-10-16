#include "../include/animal.hpp"
#include <string>

using namespace std;

string Animal::getName() {
    return name;
}

float Animal::getBirthRate() {
    return birth_rate;
}

void Animal::setBirthRate(float birth_rate) {
    Animal::birth_rate = birth_rate;
}

float Animal::getDiffusionRate() {
    return diffusion_rate;
}

void Animal::setDiffusionRate(float diffusion_rate) {
    Animal::diffusion_rate = diffusion_rate;
}
float Animal::birth_rate = 0.01;
float Animal::diffusion_rate = 0.03;
