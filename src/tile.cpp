#include "../include/tile.hpp"

Tile::Tile(bool land) {
	this->land = land;
	this->oldHares = rand() % 5;
	this->oldPumas = rand() % 5;
	this->newHares = 0;
	this->newPumas = 0;
}

void Tile::print() {
    cout << this->land << "H" << this->oldHares << "P" << this->oldPumas << " ";
}

void Tile::update() {
    this->oldHares = this->oldHares + 1;
}