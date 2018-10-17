#include "../include/parser.hpp"


// todo: add parse to config file
void parser::parse(const string& landFileName) {


//parseConfig(configFileName);
   parseInput(landFileName);

}

void parser::parseInput(const string& landFileName) {

   ifstream landFile;
   landFile.open(landFileName);
   int NY, NX, val;
   vector< vector<InputTile*> > tilesVector;
   
   InputTile* halo = new InputTile(0, 0.0, 0.0);

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
      vector<InputTile*> zerosLine (NY + 2);
      fill (zerosLine.begin(), zerosLine.end(), halo);
      tilesVector.push_back(zerosLine);

      for (int i = 0; i < NY; ++i) {

         vector<InputTile*> tilesLine;
         tilesLine.push_back(halo);

         // read in line
         // split by space
         // store as NX strings
         // split by comma
          for (int j=0; j<NY;++j) {

             landFile >> val;

             if (val != 0 && val != 1) {
                 cout << "tile must be 1 or 0" << endl;
                 exit(1);
             }
             else {

                InputTile* LandTile = new InputTile(val);
                tilesLine.push_back(LandTile);
             }
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

