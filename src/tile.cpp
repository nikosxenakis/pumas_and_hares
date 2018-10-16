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

void Tile::update() {
    this->oldHares = this->oldHares + 1;
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
