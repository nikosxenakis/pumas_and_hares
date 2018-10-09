#include "../include/tile.hpp"

Tile::Tile(bool land) {
	this->land = land;
	this->oldHares = rand() % 5;
	this->oldPumas = rand() % 5;
	this->newHares = 0;
	this->newPumas = 0;
}

void Tile::print() {
	if(this->land)
		cout << "1" << "H" << this->oldHares << "P" << this->oldPumas << " ";
	else
		cout << "0" << "H" << this->oldHares << "P" << this->oldPumas << " ";
}
