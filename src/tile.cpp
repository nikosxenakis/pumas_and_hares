#include "../include/tile.hpp"

Tile::Tile(bool land) {
	this->land = land;
	this->oldHares = rand() % 5;
	this->oldPumas = rand() % 5;
	this->newHares = 0;
	this->newPumas = 0;
}

Tile::~Tile() {
//    this->land = 0;
//    this->oldHares = 0;
//    this->oldPumas = 0;
//    this->newHares = 0;
//    this->newPumas = 0;
}

void const Tile::print() {
    cout << this->land << "H" << this->oldHares << "P" << this->oldPumas << " ";
}

void Tile::update(int tile_neighbours, float hare_neighbour_sume, float puma_neighbour_sume) {
    this->newHares = Hare::calculateNewDensity(this->oldHares, this->oldPumas, tile_neighbours, hare_neighbour_sume);
    this->newPumas = Puma::calculateNewDensity(this->oldPumas, this->oldHares, tile_neighbours, puma_neighbour_sume);
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

Density const Tile::getDensity(string animal) {
    return this->oldHares;
    if(animal == Puma::getName())
        return getOldPumas();
    else if(animal == Hare::getName())
        return getOldHares();
}
