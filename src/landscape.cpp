#include "../include/landscape.hpp"

Landscape* Landscape::instance = NULL;

// TODO: Landscape::Landscape(vector< vector<YourClass> > tilesVector, int rows, int cols)
Landscape::Landscape(vector< vector<int> > tilesVector) {

    this->rows = tilesVector.size();
    this->cols = tilesVector[0].size();
    
    this->tiles = new Tile**[this->rows];
    
    for (int i = 0; i < this->rows; ++i) {
        this->tiles[i] = new Tile*[this->cols];
        for (int j = 0; j < this->cols; ++j) {
            this->tiles[i][j] = new Tile(tilesVector[i][j]);
        }
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

void Landscape::calculate() {
    Tile* tile = nullptr;
    for (int i = 0; i < Landscape::instance->rows; ++i) {
        for (int j = 0; j < Landscape::instance->cols; ++j) {
            tile = Landscape::instance->tiles[i][j];
            if(tile->isLand()) {
                tile->calculate(
                    getNumberOfLandNeighbours(i, j), 
                    getSumDensityNeighbours(Hare::getName(), i, j), 
                    getSumDensityNeighbours(Puma::getName(), i, j)
                );
            }
        }
    }
}

void Landscape::update() {
    Tile* tile = nullptr;
    for (int i = 0; i < Landscape::instance->rows; ++i) {
        for (int j = 0; j < Landscape::instance->cols; ++j) {
            tile = Landscape::instance->tiles[i][j];
            if(tile->isLand())  tile->update();
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

Tile* Landscape::getTile(int row, int col) {
    int rows = Landscape::instance->rows;
    int cols = Landscape::instance->cols;
    
    if(row > 0 && row < rows && col > 0 && col < cols) {
        return Landscape::instance->tiles[row][col];
    }
    return nullptr;
}

Tile** Landscape::getNeighbours(int row, int col) {
    Tile** tilesVector = new Tile*[4];
    
    tilesVector[0] = getTile(row-1, col);
    tilesVector[1] = getTile(row+1, col);
    tilesVector[2] = getTile(row, col-1);
    tilesVector[3] = getTile(row, col+1);

    return tilesVector;
}

int Landscape::getNumberOfLandNeighbours(int row, int col) {

    int land_neighbours = 0;

    Tile** tilesVector = Landscape::getNeighbours(row, col);
    
    for (int i = 0; i < MAX_NEIGHBOURS; ++i) {
        if(tilesVector[i])
            land_neighbours += tilesVector[i]->isLand();
    }
    delete[] tilesVector;
    return land_neighbours;
}

Density Landscape::getSumDensityNeighbours(string animal, int row, int col) {

    Density sum = 0;

    Tile** tilesVector = Landscape::getNeighbours(row, col);
    
    for (int i = 0; i < MAX_NEIGHBOURS; ++i) {
        if(tilesVector[i])
            sum += tilesVector[i]->getDensity(animal);
    }
    delete[] tilesVector;
    return sum;
}

int const Landscape::getRows() {
    return Landscape::instance->rows;
}

int const Landscape::getCols() {
    return Landscape::instance->cols;
}
