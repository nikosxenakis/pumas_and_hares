#include "../include/landscape.hpp"

Landscape* Landscape::instance = NULL;

Landscape::Landscape(vector< vector<int> > tilesVector) {

	for (auto &tilesList : tilesVector) {
		LandscapeTileRow tilesRow;
		this->tiles.push_back(tilesRow);
		for (auto &tile : tilesList) {  
			tilesRow.push_back(new Tile(tile));
		}
	}

}

void Landscape::init(vector< vector<int> > tilesVector) {
	Landscape::instance = new Landscape(tilesVector);
}

void Landscape::print() {
	for(LandscapeTileVector::iterator it = Landscape::instance->tiles.begin(); it != Landscape::instance->tiles.end(); ++it) {
		for(LandscapeTileRow::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			(*it2).print();
		}
		cout << endl;
	}
}

void Landscape::update() {}