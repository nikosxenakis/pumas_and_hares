#ifndef tileData_h
#define tileData_h

#include <iomanip>

class TileData {
public:
    int land;
    float pumas;
    float hares;

    TileData(int land, float pumas, float hares);
    TileData(int land);
};

#endif
