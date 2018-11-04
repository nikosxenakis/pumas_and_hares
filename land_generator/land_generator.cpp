#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#define RESOURCES_PATH "./resources/"

#define LANDPERCENTAGE 0.8

#define ROWS 50
#define COLS 50

#define MICRO_RANGE 2
// #define MICRO_RANGE (ROWS*COLS)/100
#define MACRO_RANGE 20
// #define MACRO_RANGE (ROWS*COLS)/320

#define MAX_WEIGHT 10

#define INC_WEIGHT 5
#define DEC_WEIGHT 5

#define ADJUST_FREQUENCY 7

using namespace std;

class LandFile {
public:
    unsigned int weight;
    bool land;
    LandFile() {
        this->weight = 1;
        this->land = 0;
    }
};

class Position {
public:
    unsigned int row;
    unsigned int col;
    Position() {
        this->row = rand() % ROWS;
        this->col = rand() % COLS;
    }
    Position(unsigned int i, unsigned int j) {
        this->row = i;
        this->col = j;
    }
};

vector< vector<LandFile*> > createLandVector() {
    vector< vector<LandFile*> > landFileVector;

    for (unsigned int i = 0; i < ROWS; ++i) {
        vector<LandFile*> landFileVectorRow;
        for (unsigned int j = 0; j < COLS; ++j) {
            landFileVectorRow.push_back(new LandFile());
        }
        landFileVector.push_back(landFileVectorRow);
    }
    return landFileVector;
}

unsigned int fillNeighbour(vector< vector<LandFile*> > landFileVector, unsigned int row, unsigned int col) {
    if(row >= 0 && row < landFileVector.size() && col > 0 && col < landFileVector[row].size() && landFileVector[row][col]->land == 0) {
        landFileVector[row][col]-> land = 1;
        return 1;
    }
    return 0;
}

void increaseNeighbourWeight(vector< vector<LandFile*> > landFileVector, unsigned int row, unsigned int col) {
    landFileVector[row][col]->weight += INC_WEIGHT;

    if(landFileVector[row][col]->weight > MAX_WEIGHT)
        landFileVector[row][col]->weight = MAX_WEIGHT;
}

void reduceNeighbourWeight(vector< vector<LandFile*> > landFileVector, unsigned int row, unsigned int col) {
    landFileVector[row][col]->weight -= DEC_WEIGHT;

    if(landFileVector[row][col]->weight < 1)
        landFileVector[row][col]->weight = 1;
}

void adjustNeighboursWeight(vector< vector<LandFile*> > landFileVector, unsigned int row, unsigned int col) {

    for (unsigned int i = 0; i < ROWS; ++i) {
        for (unsigned int j = 0; j < COLS; ++j) {
            
            if(!landFileVector[row][col]->land) {
                unsigned int macro_area = i > row - MACRO_RANGE && i < row + MACRO_RANGE && j > col - MACRO_RANGE && j < col + MACRO_RANGE;
                if(macro_area)
                    increaseNeighbourWeight(landFileVector, i, j);
                else
                    reduceNeighbourWeight(landFileVector, i, j);
            }

        }
    }
}

unsigned int fillNeighbours(vector< vector<LandFile*> > landFileVector, Position* pos) {

    static unsigned int must_adjust = ADJUST_FREQUENCY;

    unsigned int sum = 0;
    unsigned int row = pos->row;
    unsigned int col = pos->col;

    for (unsigned int i = -MICRO_RANGE; i < MICRO_RANGE; ++i) {
        if(i<=0)
            for (unsigned int j = -i - MICRO_RANGE; j < i + MICRO_RANGE; ++j) {
                sum += fillNeighbour(landFileVector, row+i, col+j);
            }
       if(i>0)
            for (unsigned int j = i - MICRO_RANGE; j < - i + MICRO_RANGE; ++j) {
                sum += fillNeighbour(landFileVector, row+i, col+j);
            }
    }

    if(must_adjust == ADJUST_FREQUENCY) {
        adjustNeighboursWeight(landFileVector, row, col);
        must_adjust = 0;
    }
    must_adjust++;

    return sum;
}

Position* getNextPosition(vector< vector<LandFile*> > landFileVector) {
    unsigned int row = 0;
    unsigned int col = 0;
    unsigned int pos;
    vector<unsigned int> positionVector;

    for(auto landFileVectorRow : landFileVector) {
        col = 0;
        for(auto landFileElement : landFileVectorRow) {
            if(!landFileElement->land) {
                pos = row*ROWS+col;
                for (unsigned int i = 0; i < landFileElement->weight; ++i) {
                    positionVector.push_back(pos);
                }
            }
            col++;
        }
        row++;
    }

    pos = rand() % positionVector.size();

    return new Position(pos/ROWS,pos%ROWS);
}

void distributeLand(vector< vector<LandFile*> > landFileVector) {

    unsigned int i=0;
    static int perc = 0;
    static unsigned int first_time = 1;

    while(i < LANDPERCENTAGE*ROWS*COLS) {
        if(perc > 90)
            break;

        if(first_time) {
            landFileVector[ROWS/2][COLS/2]->weight = MAX_WEIGHT;
            i += fillNeighbours(landFileVector, new Position(ROWS/2,COLS/2));
            first_time = 0;
        }
        else
            i += fillNeighbours(landFileVector, getNextPosition(landFileVector));

        int new_perc = int(100*(i/(LANDPERCENTAGE*ROWS*COLS)));
        if(new_perc <= 100 && new_perc!=perc) {
            perc = new_perc;
            cout << perc << "\% done" << endl;           
        }
    }
}

float getPumas(unsigned int i, unsigned int j, unsigned int width, unsigned int height) {
    if(j<width/2 && i<height/2) {
        return 5;
    }
    return 1;
}

float getHares(unsigned int i, unsigned int j, unsigned int width, unsigned int height) {
    if(j>width/2 && i>height/2) {
        return 5;
    }
    return 1;
}

void createLandFile(vector< vector<LandFile*> > landFileVector, ofstream &landFile) {
    unsigned int width = landFileVector.size();
    unsigned int height = landFileVector[0].size();
    unsigned int i=0,j=0;
    float pumas=1;
    float hares=5;

    landFile << width << " " << height << endl;

    for(auto landFileVectorRow : landFileVector) {
        j=0;
        for(auto landFileElement : landFileVectorRow) {
            if(j!=0)
                landFile << " ";

            landFile << landFileElement->land;

            if(landFileElement->land) {
                pumas = getPumas(i,j,width,height);
                hares = getHares(i,j,width,height);
                landFile << "," << pumas << "," << hares;
            }

            j++;
        }
        i++;
        landFile << endl;
    }
}

void land_generator(ofstream &landFile) {
    vector< vector<LandFile*> > landFileVector = createLandVector();
    distributeLand(landFileVector);
    createLandFile(landFileVector, landFile);
}

int main() {

    ofstream landFile;
    landFile.open (string(RESOURCES_PATH) + "new_50x50.dat");

    time_t t = time(NULL);
    srand (t);

    if (landFile.is_open()) {
        land_generator(landFile);
        landFile.close();
    }
    else {
        cout << "File is not open" << endl;
        exit(1);
    }

    return 0;
}
