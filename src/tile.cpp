#include "../include/tile.hpp"

Tile::Tile(InputTile* inputTile) {
    this->clear();
    this->land = inputTile->land;
    if(this->isLand()) {
        this->oldPumas = inputTile->pumas;
        this->oldHares = inputTile->hares;
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
    cout << this->land << ", H" << std::fixed << setprecision(1) << this->oldHares << ", P" << this->oldPumas << "\t";
}

void Tile::calculate(int tile_neighbours, float hare_neighbour_sum, float puma_neighbour_sum) {
    this->newHares = Hare::calculateNewDensity(this->oldHares, this->oldPumas, tile_neighbours, hare_neighbour_sum);
    this->newPumas = Puma::calculateNewDensity(this->oldPumas, this->oldHares, tile_neighbours, puma_neighbour_sum);
}

void Tile::update() {
    this->oldHares = this->newHares >= 0 ? this->newHares : 0;
    this->oldPumas = this->newPumas >= 0 ? this->newPumas : 0;
    this->newHares = 0;
    this->newPumas = 0;
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
