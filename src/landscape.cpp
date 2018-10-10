#include "../include/landscape.hpp"
#include <cassert>

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

int Landscape::getNumberOfLandNeighbours(int row, int col) {
    // todo: get Number of neighbouring squares that are land ("dry")
    // todo: by looking into parsed input => vector tiles
    int i = 4;
    return i;
}

Density Landscape::getSumDensityNeighbours(std::string animal, int row, int col) {
    vector<Tile*> tilesVector;
    LandscapeTileVector tiles = Landscape::instance->tiles;
    Density sum = 0;

    if(row < 0 || row > tiles.size() || col < 0 || col > tiles[row].size()) {
        cout << "wrong input in getNeighbours" << endl;
        return 0;
    }

    if(row - 1 >= 0) {
        tilesVector.push_back(tiles[row-1][col]);
    }
    if(row + 1 < tiles.size()) {
        tilesVector.push_back(tiles[row+1][col]);
    }
    if(col - 1 >= 0) {
        tilesVector.push_back(tiles[row][col-1]);
    }
    if(col + 1 < tiles[row].size()) {
        tilesVector.push_back(tiles[row][col+1]);
    }

    for(auto tile: tilesVector) {
        if(animal == "Pumas")
            sum += tile->getOldPumas();
        else if(animal == "Hares")
            sum += tile->getOldHares();
        else
            cout << "error in getNeighbours";
    }
    
    return sum;
}
