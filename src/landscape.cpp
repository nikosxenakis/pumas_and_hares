#include "../include/landscape.hpp"

Landscape* Landscape::instance = NULL;

Landscape::Landscape(vector< vector<TileData*> > tilesVector, size_t rows, size_t cols):
rows(rows), cols(cols) {
    
    this->tiles = new Tile**[this->rows];
    
    for (size_t i = 0; i < this->rows; ++i) {
        this->tiles[i] = new Tile*[this->cols];
        for (size_t j = 0; j < this->cols; ++j) {
            this->tiles[i][j] = new Tile(tilesVector[i][j]);
        }
    }
}

void Landscape::init(vector< vector<TileData*> > tilesVector, size_t rows, size_t cols)  {
    Landscape::instance = new Landscape(tilesVector, rows, cols);
}

void Landscape::destroy() {
    delete (Landscape::instance);
}

Landscape::~Landscape() {

    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
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
    TileData* tileData = new TileData(0, 0, 0);
    Tile* tilesVector[4];

    for (size_t i = 1; i < Landscape::instance->rows-1; ++i) {
        for (size_t j = 1; j < Landscape::instance->cols-1; ++j) {
            tile = Landscape::instance->tiles[i][j];
            tileData->clear();

            if(tile->isLand()) {
                getNeighboursInfo(tilesVector, tileData, i, j);
                tile->calculate(tileData->land, tileData->hares, tileData->pumas);
            }
        }
    }
    
    delete tileData;
}

void Landscape::update() {
    Landscape* landscape = Landscape::instance;
    Tile* tile = nullptr;
    for (size_t i = 1; i < landscape->rows-1; ++i) {
        for (size_t j = 1; j < landscape->cols-1; ++j) {
            tile = landscape->tiles[i][j];
            if(tile->isLand()) {
                tile->update();
            }
        }
    }
}

void Landscape::print() {
    
    for (size_t i = 0; i < Landscape::instance->rows; ++i) {
        for (size_t j = 0; j < Landscape::instance->cols; ++j) {
            Tile* tile = Landscape::instance->tiles[i][j];
            tile->print();
        }
        cout << endl;
    }

    cout << endl;
}

Tile* Landscape::getTile(size_t row, size_t col) {
    Landscape* landscape = Landscape::instance;
    assert(row >= 0 && row < landscape->getRows() && col >= 0 && col < landscape->getCols());
    return Landscape::instance->tiles[row][col];
}

void Landscape::getNeighbours(Tile** tilesVector, size_t row, size_t col) {
    Landscape* landscape = Landscape::instance;
    assert(tilesVector && row > 0 && row < landscape->getRows() - 1 && col > 0 && col < landscape->getCols() - 1);
    tilesVector[0] = landscape->getTile(row-1, col);
    tilesVector[1] = landscape->getTile(row+1, col);
    tilesVector[2] = landscape->getTile(row, col-1);
    tilesVector[3] = landscape->getTile(row, col+1);
}

void Landscape::getNeighboursInfo(Tile** tilesVector, TileData* tileData, size_t row, size_t col) {
    Landscape::getNeighbours(tilesVector, row, col);
    for (int i = 0; i < MAX_NEIGHBOURS; ++i) {
        if(tilesVector[i]->isLand()) {
            tileData->land++;
            tileData->pumas += tilesVector[i]->getOldPumas();
            tileData->hares += tilesVector[i]->getOldHares();
        }
    }
}

size_t const Landscape::getRows() {
    return Landscape::instance->rows;
}

size_t const Landscape::getCols() {
    return Landscape::instance->cols;
}

Density const Landscape::getMaxPumas() {
    Landscape* landscape = Landscape::instance;
    Density maxPumas = 0;
    for (size_t i = 1; i < landscape->rows-1; ++i) {
        for (size_t j = 1; j < landscape->cols-1; ++j) {
            Tile* tile = Landscape::getTile(i, j);
            if(tile->isLand()) {
                Density oldPumas = tile->getOldPumas();
                if(maxPumas < oldPumas) maxPumas = oldPumas;
            }
        }
    }
    return maxPumas;
}

Density const Landscape::getMaxHares() {
    Landscape* landscape = Landscape::instance;
    Density maxHares = 0;
    for (size_t i = 1; i < landscape->rows-1; ++i) {
        for (size_t j = 1; j < landscape->cols-1; ++j) {
            Tile* tile = Landscape::getTile(i, j);
            if(tile->isLand()) {
                Density oldHares = tile->getOldHares();
                if(maxHares < oldHares) maxHares = oldHares;
            }
        }
    }
    return maxHares;
}

Density const Landscape::getAveragePumas() {
    TileData* tileData = Landscape::getRegion(0, 0, Landscape::instance->rows, Landscape::instance->cols);
    Density retVal = tileData->pumas;
    delete tileData;
    return retVal;
}

Density const Landscape::getAverageHares() {
    TileData* tileData = Landscape::getRegion(0, 0, Landscape::instance->rows, Landscape::instance->cols);
    Density retVal = tileData->hares;
    delete tileData;
    return retVal;
}

TileData* const Landscape::getRegion(size_t row, size_t col, size_t m, size_t n) {
    Landscape* landscape = Landscape::instance;
    size_t lastRow = (row + m < landscape->rows ? row + m : landscape->rows) ;
    size_t lastCol = (col + n < landscape->cols ? col + n : landscape->cols) ;
    Tile* tile = nullptr;
    float maxTiles = (lastRow-row)*(lastCol-col);
    float landTiles = 0.0;
    float pumas = 0, hares = 0;
    for (size_t i = row; i < lastRow; ++i) {
        for (size_t j = col; j < lastCol; ++j) {
            tile = landscape->tiles[i][j];
            if(tile->isLand()) {
                landTiles+=1.0;
                pumas+=tile->getOldPumas();
                hares+=tile->getOldHares();
            }
        }
    }
    int land = (landTiles/maxTiles > 0.5 ? 1 : 0);
    float aver_pumas = pumas/landTiles;
    float aver_hares = hares/landTiles;
    if(land)
        return new TileData(land, aver_pumas, aver_hares);
    return new TileData(0, 0, 0);
}
