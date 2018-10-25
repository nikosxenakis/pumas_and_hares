#include "../include/landscape.hpp"

Landscape* Landscape::instance = NULL;

Landscape::Landscape(vector< vector<InputTile*> > tilesVector, int rows, int cols):
rows(rows), cols(cols) {
    
    Tile* tile = nullptr;

    this->tiles = new Tile**[this->rows];
    
    for (int i = 0; i < this->rows; ++i) {
        this->tiles[i] = new Tile*[this->cols];
        for (int j = 0; j < this->cols; ++j) {
            this->tiles[i][j] = new Tile(tilesVector[i][j]);
            tile = this->tiles[i][j];
        }
    }
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
    Log::startLogTime("calculate");
    Tile* tile = nullptr;
    for (int i = 0; i < Landscape::instance->rows; ++i) {
        for (int j = 0; j < Landscape::instance->cols; ++j) {
            tile = Landscape::instance->tiles[i][j];
            if(tile->isLand()) {
                InputTile* inputTile = getNeighboursInfo(i, j);
                tile->calculate(inputTile->land, inputTile->hares, inputTile->pumas);
            }
        }
    }
    Log::endLogTime("calculate");
}

void Landscape::update() {
    Landscape* landscape = Landscape::instance;
    Tile* tile = nullptr;
    for (int i = 0; i < landscape->rows; ++i) {
        for (int j = 0; j < landscape->cols; ++j) {
            tile = landscape->tiles[i][j];
            if(tile->isLand()) {
                tile->update();
            }
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
    
    if(row >= 0 && row < rows && col >= 0 && col < cols) {
        return Landscape::instance->tiles[row][col];
    }
    return nullptr;
}

void Landscape::getNeighbours(Tile** tilesVector, int row, int col) {
    tilesVector[0] = Landscape::getTile(row-1, col);
    tilesVector[1] = Landscape::getTile(row+1, col);
    tilesVector[2] = Landscape::getTile(row, col-1);
    tilesVector[3] = Landscape::getTile(row, col+1);
}

InputTile* Landscape::getNeighboursInfo(int row, int col) {
    InputTile* inputTile = new InputTile(0, 0, 0);
    Tile* tilesVector[4];
    Landscape::getNeighbours(tilesVector, row, col);
    for (int i = 0; i < MAX_NEIGHBOURS; ++i) {
        if(tilesVector[i]) {
            if(tilesVector[i]->isLand()) {
                inputTile->land ++;
                inputTile->pumas += tilesVector[i]->getOldPumas();
                inputTile->hares += tilesVector[i]->getOldHares();
            }
        }
    }
    return inputTile;
}

int const Landscape::getRows() {
    return Landscape::instance->rows;
}

int const Landscape::getCols() {
    return Landscape::instance->cols;
}

Density const Landscape::getMaxPumas() {
    Landscape* landscape = Landscape::instance;
    Density maxPumas = 0;
    for (int i = 0; i < landscape->rows; ++i) {
        for (int j = 0; j < landscape->cols; ++j) {
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
    for (int i = 0; i < landscape->rows; ++i) {
        for (int j = 0; j < landscape->cols; ++j) {
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
    return Landscape::getRegion(0, 0, Landscape::instance->rows, Landscape::instance->cols).pumas;
}

Density const Landscape::getAverageHares() {
    return Landscape::getRegion(0, 0, Landscape::instance->rows, Landscape::instance->cols).hares;
}

InputTile const Landscape::getRegion(int row, int col, int m, int n) {
    Landscape* landscape = Landscape::instance;
    int lastRow = (row + m < landscape->rows ? row + m : landscape->rows) ;
    int lastCol = (col + n < landscape->cols ? col + n : landscape->cols) ;
    Tile* tile = nullptr;
    int maxTiles = m*n;
    int landTiles = 0;
    float pumas = 0, hares = 0;
    for (int i = row; i < lastRow; ++i) {
        for (int j = col; j < lastCol; ++j) {
            tile = landscape->tiles[i][j];
            if(tile->isLand()) {
                landTiles++;
                pumas+=tile->getOldPumas();
                hares+=tile->getOldHares();
            }
        }
    }
    int land = ((float(landTiles) / float(maxTiles)) > 0.5 ? 1 : 0);
    return InputTile(land, float(pumas)/float(landTiles), float(hares)/float(landTiles));
}
