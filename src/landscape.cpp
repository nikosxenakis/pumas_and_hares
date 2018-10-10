#include "../include/landscape.hpp"

Landscape* Landscape::instance = NULL;

Landscape::Landscape(vector< vector<int> > tilesVector) {

	for (auto tilesList : tilesVector) {
		LandscapeTileRow tilesRow;
		for (auto tile : tilesList) {  
			tilesRow.push_back(new Tile(tile));
		}
		this->tiles.push_back(tilesRow);
	}

}

void Landscape::init(vector< vector<int> > tilesVector) {
	Landscape::instance = new Landscape(tilesVector);
}

void Landscape::update() {
    for (auto tilesList : Landscape::instance->tiles) {
        for (auto tile : tilesList) {
            tile->update();
        }
    }
}

void Landscape::print() {
	for (auto tilesList : Landscape::instance->tiles) {
		for (auto tile : tilesList) {  
			tile->print();
		}
		cout << endl;
	}
	cout << endl;
}

//Tile* Landscape::getTile(int row, int column)() {
//    
//    return Landscape::instance->tiles;
//}
