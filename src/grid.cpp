#include "../include/grid.hpp"

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param water [description]
 */
Grid::Grid(bool water) {
	this->water = water;

	this->hDensity = rand() % 5;
	this->pDensity = rand() % 5;
}

void Grid::print() {
	if(this->water)
		cout << "0" << "H" << this->hDensity << "P" << this->pDensity << " ";
	else
		cout << "1" << "H" << this->hDensity << "P" << this->pDensity << " ";
}