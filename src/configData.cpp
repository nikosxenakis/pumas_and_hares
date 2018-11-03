#include "../include/configData.hpp"

float ConfigData::deltaT = 0.4;
int ConfigData::capitalT = 200;
vector< vector<TileData*> > ConfigData::tilesVector;
size_t ConfigData::NX = 0;
size_t ConfigData::NY = 0;

void ConfigData::setDeltaT(float deltaT) throw(invalid_argument) {
    if(deltaT <= 0)
        throw invalid_argument("deltaT configuration must be greater than 0");
    ConfigData::deltaT = deltaT;
}

float ConfigData::getDeltaT() {
    return ConfigData::deltaT;
}

void ConfigData::setCapitalT(int capitalT) {
    if(capitalT <= 0 || capitalT > MAX_STEP) {
        throw std::invalid_argument("T configuration must be greater than 0 and less than 500");
    }
    ConfigData::capitalT = capitalT;
}

int ConfigData::getCapitalT() {
    return ConfigData::capitalT;
}

void ConfigData::initLandscapeData(vector< vector<TileData*> > tilesVector, size_t NX, size_t NY) {
    ConfigData::tilesVector = tilesVector;
    ConfigData::NX = NX;
    ConfigData::NY = NY;

}
