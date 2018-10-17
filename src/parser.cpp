#include "../include/parser.hpp"


// todo: add parse to config file
void parser::parse(const string& landFileName) {


//parseConfig(configFileName);
   parseInput(landFileName);

}

void parser::split(const string& str, vector<string> &cont, char delim) {
    stringstream ss(str);
    string token;
    cont.clear();
    while (getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

void parser::errorCheck(vector<string> vTile) {
    if (stoi(vTile[0])!= 0 && stoi(vTile[0])!= 1) {
        cout << "Land input must be 0 or 1" << endl;
        exit(1);
    }
    if (stod(vTile[1])<0 || stod(vTile[2]) <0) {
        cout << "Density input must be positive" << endl;
        exit(1);
    }

}

void parser::parseInput(const string& landFileName) {

   ifstream landFile;
   landFile.open(landFileName);
   int NY, NX;

   string inputLine;
   vector <string> vInputLine;
   vector <string> vInputTile;

   vector< vector<InputTile*> > tilesVector;
   
   InputTile* halo = new InputTile(0, 0.0, 0.0);
   InputTile* LandTile;

   if (landFile.is_open()) {
      landFile >> NX;
      if (0 > NX || NX > 2000) {
          cout << "Number of columns must be between 1 and 2000" << endl;
          exit(1);
      }
      landFile >> NY;
      if (0 > NY || NY > 2000) {
         cout << "Number of rows must be between 1 and 2000" << endl;
         exit(1);
      }


      vector<InputTile*> zerosLine (NX + 2);
      fill (zerosLine.begin(), zerosLine.end(), halo);
      tilesVector.push_back(zerosLine);
      landFile.ignore();
      for (int i = 0; i < NY; ++i) {

         vector<InputTile*> tilesLine;
         tilesLine.push_back(halo);

         getline(landFile, inputLine);
         split(inputLine, vInputLine, ' ');
         
         if (vInputLine.size()!=NX) {
            cout << "Error x elements not equal to Landscape size" << endl;
            exit(1);
         }
         
         for (int j=0; j<NX; j++) {
                split(vInputLine[j], vInputTile, ',');
                cout << vInputTile.size() << endl;
                if (vInputTile.size()==3) {
                    LandTile = new InputTile(stoi(vInputTile[0]), stod(vInputTile[1]), stod(vInputTile[2]));
                }
                else if (vInputTile.size()==1) {
                    LandTile = new InputTile(stoi(vInputTile[0]));
                }
                else {
                    cout << "Incorrect defintion of input square in input.dat" << endl;
                }
                tilesLine.push_back(LandTile);
          }
          tilesLine.push_back(halo);
          tilesVector.push_back(tilesLine);
      }
      tilesVector.push_back(zerosLine);
      Landscape::init(tilesVector, NX+2, NY+2);

      // initalise image for ppm
      Image::init(NX, NY);
   }
   else {
     cout << "file not open" << endl;
     exit(1);
   }

}


void parser::parseConfig(const string& configFileName) {

//    ifstream configFile;
//    configFile.open(configFileName);
//    json jConfig;
   // read json file
   // pass values to set.hares and set.pumas

}

