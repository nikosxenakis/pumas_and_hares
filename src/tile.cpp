#include "../include/tile.hpp"

Tile::Tile(bool land, int row, int col) {
	this->land = land;
    this->row = row;
    this->col = col;
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

void Tile::update() {
    
//    int land_neighbours = Landscape::getNumberOfLandNeighbours(row, col);
//
//    float hare_sum = Landscape::getSumDensityNeighbours(Hare::getName(), this->row, this->col);
//    float puma_sum = Landscape::getSumDensityNeighbours(Puma::getName(), this->row, this->col);
    int land_neighbours = 2;
    float hare_sum = 1.3;
    float puma_sum = 1.2;
    
    this->newHares = Hare::calculateNewDensity(this->oldHares, this->oldPumas, land_neighbours, hare_sum);
    this->newPumas = Puma::calculateNewDensity(this->oldPumas, this->oldHares, land_neighbours, puma_sum);
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
