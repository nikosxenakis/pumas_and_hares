#include "../include/tile.hpp"

Tile::Tile(TileData* tileData) {
    this->clear();
    this->land = tileData->land;
    if(this->isLand()) {
        this->pumas = tileData->pumas;
        this->hares = tileData->hares;
    }
}

Tile::~Tile() {
	this->clear();
}

void Tile::clear() {
    this->hares = 0;
    this->pumas = 0;
    this->newHares = 0;
    this->newPumas = 0;
}

void const Tile::print() {
    cout << this->land << ", P" << this->pumas << ", H" << std::fixed << setprecision(1) << this->hares <<  "\t";
}

void Tile::calculate(int tile_neighbours, float hare_neighbour_sum, float puma_neighbour_sum) {
    this->newHares = Hare::calculateNewDensity(this->hares, this->pumas, tile_neighbours, hare_neighbour_sum);
    this->newPumas = Puma::calculateNewDensity(this->pumas, this->hares, tile_neighbours, puma_neighbour_sum);
}

void Tile::update() {
    this->hares = (this->newHares >= 0 ? this->newHares : 0);
    this->pumas = (this->newPumas >= 0 ? this->newPumas : 0);
}

bool const Tile::isLand() {
    return this->land;
}

Density const Tile::getHares() {
    return this->hares;
}

Density const Tile::getPumas() {
    return this->pumas;
}
