#include "../include/landscape.hpp"

Landscape* Landscape::instance = NULL;

Landscape::Landscape(vector< vector<InputTile*> > tilesVector, int rows, int cols):
rows(rows), cols(cols), maxPumas(0), maxHares(0) {
    
    int totalPumas = 0;
    int totalHares = 0;
    Density sumPumas = 0;
    Density sumHares = 0;
    Tile* tile = nullptr;

    this->tiles = new Tile**[this->rows];
    
    for (int i = 0; i < this->rows; ++i) {
        this->tiles[i] = new Tile*[this->cols];
        for (int j = 0; j < this->cols; ++j) {
            this->tiles[i][j] = new Tile(tilesVector[i][j]);
            tile = this->tiles[i][j];
            Density pumas = tile->getOldPumas();
            Density hares = tile->getOldHares();
            if(this->maxPumas < pumas) this->maxPumas = pumas;
            if(this->maxHares < hares) this->maxHares = hares;
            if(tile->isLand()) {
                sumPumas += pumas;
                totalPumas ++;
                sumHares += hares;
                totalHares ++;
            }
        }
    }
    this->averagePumas = sumPumas / totalPumas;
    this->averageHares = sumHares / totalHares;
}

void Landscape::init(vector< vector<InputTile*> > tilesVector, int rows, int cols)  {
    Landscape::instance = new Landscape(tilesVector, rows, cols);
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
    int totalPumas = 0;
    int totalHares = 0;
    Density sumPumas = 0;
    Density sumHares = 0;

    Landscape* landscape = Landscape::instance;
    Tile* tile = nullptr;
    for (int i = 0; i < landscape->rows; ++i) {
        for (int j = 0; j < landscape->cols; ++j) {
            tile = landscape->tiles[i][j];
            if(tile->isLand())  tile->update();
            Density pumas = tile->getOldPumas();
            Density hares = tile->getOldHares();
            if(getMaxPumas() < pumas) setMaxPumas(pumas);
            if(getMaxHares() < hares) setMaxHares(hares);
            if(tile->isLand()) {
                sumPumas += pumas;
                totalPumas ++;
                sumHares += hares;
                totalHares ++;
            }
        }
    }
    landscape->averagePumas = sumPumas / totalPumas;
    landscape->averageHares = sumHares / totalHares;
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

Density const Landscape::getMaxPumas() {
    return Landscape::instance->maxPumas;
}

Density const Landscape::getMaxHares() {
    return Landscape::instance->maxHares;
}

void Landscape::setMaxPumas(Density pumas) {
    Landscape::instance->maxPumas = pumas;
}

void Landscape::setMaxHares(Density hares) {
    Landscape::instance->maxHares = hares;
}

Density const Landscape::getAveragePumas() {
    return Landscape::instance->averagePumas;
}

Density const Landscape::getAverageHares() {
    return Landscape::instance->averageHares;
}
