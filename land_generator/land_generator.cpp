#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#define RESOURCES_PATH "./resources/"

#define LANDPERCENTAGE 0.6

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
    int weight;
    bool land;
    LandFile() {
        this->weight = 1;
        this->land = 0;
    }
};

class Position {
public:
    int row;
    int col;
    Position() {
        this->row = rand() % ROWS;
        this->col = rand() % COLS;
    }
    Position(int i, int j) {
        this->row = i;
        this->col = j;
    }
};

vector< vector<LandFile*> > createLandVector() {
    vector< vector<LandFile*> > landFileVector;

    for (int i = 0; i < ROWS; ++i) {
        vector<LandFile*> landFileVectorRow;
        for (int j = 0; j < COLS; ++j) {
            landFileVectorRow.push_back(new LandFile());
        }
        landFileVector.push_back(landFileVectorRow);
    }
    return landFileVector;
}

int fillNeighbour(vector< vector<LandFile*> > landFileVector, int row, int col) {
    if(row >= 0 && row < landFileVector.size() && col > 0 && col < landFileVector[row].size() && landFileVector[row][col]->land == 0) {
        landFileVector[row][col]-> land = 1;
        return 1;
    }
    return 0;
}

void increaseNeighbourWeight(vector< vector<LandFile*> > landFileVector, int row, int col) {
    landFileVector[row][col]->weight += INC_WEIGHT;

    if(landFileVector[row][col]->weight > MAX_WEIGHT)
        landFileVector[row][col]->weight = MAX_WEIGHT;
}

void reduceNeighbourWeight(vector< vector<LandFile*> > landFileVector, int row, int col) {
    landFileVector[row][col]->weight -= DEC_WEIGHT;

    if(landFileVector[row][col]->weight < 1)
        landFileVector[row][col]->weight = 1;
}

void adjustNeighboursWeight(vector< vector<LandFile*> > landFileVector, int row, int col) {

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            
            if(!landFileVector[row][col]->land) {
                int macro_area = i > row - MACRO_RANGE && i < row + MACRO_RANGE && j > col - MACRO_RANGE && j < col + MACRO_RANGE;
                if(macro_area)
                    increaseNeighbourWeight(landFileVector, i, j);
                else
                    reduceNeighbourWeight(landFileVector, i, j);
            }

        }
    }
}

int fillNeighbours(vector< vector<LandFile*> > landFileVector, Position* pos) {

    static int must_adjust = ADJUST_FREQUENCY;

    int sum = 0;
    int row = pos->row;
    int col = pos->col;

    for (int i = -MICRO_RANGE; i < MICRO_RANGE; ++i) {
        if(i<=0)
            for (int j = -i - MICRO_RANGE; j < i + MICRO_RANGE; ++j) {
                sum += fillNeighbour(landFileVector, row+i, col+j);
            }
       if(i>0)
            for (int j = i - MICRO_RANGE; j < - i + MICRO_RANGE; ++j) {
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
    int row = 0;
    int col = 0;
    int pos;
    vector<int> positionVector;

    for(auto landFileVectorRow : landFileVector) {
        col = 0;
        for(auto landFileElement : landFileVectorRow) {
            if(!landFileElement->land) {
                pos = row*ROWS+col;
                for (int i = 0; i < landFileElement->weight; ++i) {
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

    int i=0;
    static int perc = 0;
    static int first_time = 1;

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

void createLandFile(vector< vector<LandFile*> > landFileVector, ofstream &landFile) {
    landFile << landFileVector.size() << " " << landFileVector[0].size() << " " << endl;

    for(auto landFileVectorRow : landFileVector) {
        for(auto landFileElement : landFileVectorRow) {
            landFile << landFileElement->land << " ";
        }
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
    landFile.open (string(RESOURCES_PATH) + "new.dat");

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
