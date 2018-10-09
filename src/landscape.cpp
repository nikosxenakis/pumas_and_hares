#include "../include/landscape.hpp"

Landscape* Landscape::instance = NULL;

Landscape::Landscape(vector< vector<int> > tilesVector) {

	for (auto tilesList : tilesVector) {
		LandscapeTileRow tilesRow;
		for (auto tile : tilesList) {  
			tilesRow.push_back(Tile(tile));
		}
		this->tiles.push_back(tilesRow);
	}

}

void Landscape::init(vector< vector<int> > tilesVector) {
	Landscape::instance = new Landscape(tilesVector);
}

void Landscape::print() {
	for (auto tilesList : Landscape::instance->tiles) {
		for (auto tile : tilesList) {  
			tile.print();
		}
		cout << endl;
	}
	cout << endl;
}

void Landscape::update() {
	for (auto tilesList : Landscape::instance->tiles) {
		for (auto tile : tilesList) {  
			tile.update();
		}
	}
}
