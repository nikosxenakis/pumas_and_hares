#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#define RESOURCES_PATH "./resources/"

using namespace std;

float landPercentage = 0.55;
int rows = 50;
int cols = 50;

class Position {
public:
    int row;
    int col;
    Position() {
        this->row = rand() % rows;
        this->col = rand() % cols;
    }
};

class LandFile {
public:
    int weight;
    bool land;
    LandFile() {
        this->weight = 1;
        this->land = 0;
    }
};

vector< vector<LandFile*> > createLandVector() {
    vector< vector<LandFile*> > landFileVector;

    for (int i = 0; i < rows; ++i) {
        vector<LandFile*> landFileVectorRow;
        for (int j = 0; j < cols; ++j) {
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

int fillNeighbours(vector< vector<LandFile*> > landFileVector, Position* pos) {

    int sum = 0;
    int range = 1;
    int row = pos->row;
    int col = pos->col;

    if(row < 0 || row > landFileVector.size() || col < 0 || col > landFileVector[row].size()) {
        cout << "wrong input in fillNeighbours" << endl;
        return 0;
    }

    for (int i = -range; i < range; ++i) {
        if(i<=0)
            for (int j = -i - range; j < i + range; ++j) {
                sum += fillNeighbour(landFileVector, row+i, col+j);
            }
       if(i>0)
            for (int j = i - range; j < - i + range; ++j) {
                sum += fillNeighbour(landFileVector, row+i, col+j);
            }
    }
    
    return sum;
}

void distributeLand(vector< vector<LandFile*> > landFileVector) {

    int i=0;

    while(i < landPercentage*rows*cols) {
        i += fillNeighbours(landFileVector, new Position());
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

int main() {

    ofstream landFile;
    landFile.open (string(RESOURCES_PATH) + "new.dat");

    time_t t = time(NULL);
    srand (t);

    if (landFile.is_open()) {
        vector< vector<LandFile*> > landFileVector = createLandVector();
        distributeLand(landFileVector);
        createLandFile(landFileVector, landFile);
        landFile.close();
    }
    else {
        cout << "File is not open" << endl;
        exit(1);
    }

    return 0;
}
