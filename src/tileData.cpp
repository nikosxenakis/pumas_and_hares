#include "../include/tileData.hpp"

TileData::TileData(int land, float pumas, float hares) {
    this->land = land;
    this-> pumas = pumas;
    this->hares = hares;
}

TileData::TileData(int land) {
    this->clear();
    this->land = land;
    if(this->land) {
        this->pumas = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/5));
        this->hares = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/5));
    }
}

void TileData::clear() {
    this->land = 0;
    this->pumas = 0;
    this->hares = 0;
}
