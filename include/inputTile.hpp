#ifndef inputTile_h
#define inputTile_h

#include <iomanip>

class InputTile {
public:
    int land;
    float pumas;
    float hares;

    InputTile(int land, float pumas, float hares);
    InputTile(int land);
};

#endif
