#include "../include/inputTile.hpp"

InputTile::InputTile(int land, float pumas, float hares) {
    this->land = land;
    this-> pumas = pumas;
    this->hares = hares;
}

InputTile::InputTile(int land) {
    this->land = land;
    this->pumas = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/5));
    this->hares = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/5));
}
