#include "../include/tile.hpp"

Tile::Tile(TileData* tileData) {
    this->clear();
    this->land = tileData->land;
    if(this->isLand()) {
        this->oldPumas = tileData->pumas;
        this->oldHares = tileData->hares;
    }
}

Tile::~Tile() {
	this->clear();
}

void Tile::clear() {
    this->oldHares = 0;
    this->oldPumas = 0;
    this->newHares = 0;
    this->newPumas = 0;
}

void const Tile::print() {
    cout << this->land << ", P" << this->oldPumas << ", H" << std::fixed << setprecision(1) << this->oldHares <<  "\t";
}

void Tile::calculate(int tile_neighbours, float hare_neighbour_sum, float puma_neighbour_sum) {
    this->newHares = Hare::calculateNewDensity(this->oldHares, this->oldPumas, tile_neighbours, hare_neighbour_sum);
    this->newPumas = Puma::calculateNewDensity(this->oldPumas, this->oldHares, tile_neighbours, puma_neighbour_sum);
}

void Tile::update() {
    this->oldHares = (this->newHares >= 0 ? this->newHares : 0);
    this->oldPumas = (this->newPumas >= 0 ? this->newPumas : 0);
}

bool const Tile::isLand() {
    return this->land;
}

Density const Tile::getOldHares() {
    return this->oldHares;
}

Density const Tile::getOldPumas() {
    return this->oldPumas;
}
