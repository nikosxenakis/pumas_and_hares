#include "../include/landscape.hpp"
#include <cassert>

Landscape* Landscape::instance = NULL;

Landscape::Landscape(vector< vector<int> > tilesVector) {

    int i = 0, j = 0;

    this->rows = tilesVector.size();
    this->cols = tilesVector[0].size();
    
    this->tiles = new Tile**[this->rows];
    
	for (auto tilesList : tilesVector) {
        this->tiles[i] = new Tile*[this->cols];
        j = 0;
		for (auto tile : tilesList) {
            this->tiles[i][j] = new Tile(tile);
            ++j;
		}
        ++i;
	}

}

void Landscape::init(vector< vector<int> > tilesVector) {
    Landscape::instance = new Landscape(tilesVector);
}

void Landscape::destroy() {
    delete (Landscape::instance);
}

Landscape::~Landscape() {

    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            delete this->tiles[i][j];
        }
        delete this->tiles[i];
    }
    delete this->tiles;
    
    this->rows = 0;
    this->cols = 0;
}

void Landscape::update() {

    for (int i = 0; i < Landscape::instance->rows; ++i) {
        for (int j = 0; j < Landscape::instance->cols; ++j) {
            Landscape::instance->tiles[i][j]->update();
        }
    }
}

void Landscape::print() {
    
    for (int i = 0; i < Landscape::instance->rows; ++i) {
        for (int j = 0; j < Landscape::instance->cols; ++j) {
            Tile* tile = Landscape::instance->tiles[i][j];
            tile->print();
        }
        cout << endl;
    }

    cout << endl;
}

Tile* Landscape::getTile(size_t row, size_t col) {
    return Landscape::instance->tiles[row][col];
}

vector<Tile*> Landscape::getNeighbours(int row, int col) {
    vector<Tile*> tilesVector;
    Tile*** tiles = Landscape::instance->tiles;
    size_t rows = Landscape::instance->rows;
    size_t cols = Landscape::instance->cols;
    
    // TODO: throw exception
//    if(row < 0 || row > rows || col < 0 || col > cols) {
//        cout << "wrong input in getNeighbours" << endl;
//        return 0;
//    }
    
    if(row - 1 >= 0) {
        tilesVector.push_back(tiles[row-1][col]);
    }
    if(row + 1 < rows) {
        tilesVector.push_back(tiles[row+1][col]);
    }
    if(col - 1 >= 0) {
        tilesVector.push_back(tiles[row][col-1]);
    }
    if(col + 1 < cols) {
        tilesVector.push_back(tiles[row][col+1]);
    }
    return tilesVector;
}

int Landscape::getNumberOfLandNeighbours(int row, int col) {
    // todo: get Number of neighbouring squares that are land ("dry")
    // todo: by looking into parsed input => vector tiles
    vector<Tile*> tilesVector = Landscape::getNeighbours(row, col);

    int i = 0;

    for(auto tile: tilesVector) {
        if(tile->isLand())
            ++i;
    }
    
    return i;
}

Density Landscape::getSumDensityNeighbours(std::string animal, int row, int col) {

    vector<Tile*> tilesVector = Landscape::getNeighbours(row, col);
    Density sum = 0;

    for(auto tile: tilesVector) {
        if(animal == Puma::getName())
            sum += tile->getOldPumas();
        else if(animal == Hare::getName())
            sum += tile->getOldHares();
        else
            cout << "error in getNeighbours";
    }

    return sum;
}
