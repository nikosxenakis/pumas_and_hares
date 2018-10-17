#include "../include/parser.hpp"
#include "../resources/json.hpp"
#include "../include/helpers.hpp"
#include "../include/hare.hpp"
#include "../include/puma.hpp"

using json = nlohmann::json;

// todo: add parse to config file
void parser::parse(const string& landFileName) {

    string configFileName = "../resources/param.json";
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

    std::ifstream t(configFileName);
    std::stringstream buffer;
    buffer << t.rdbuf();
    string jsonString = buffer.str();

    auto jsonConfig = json::parse(jsonString);

    float H_birth_rate = jsonConfig.at("r");
    float H_predation_rate = jsonConfig.at("a");
    float P_birth_rate = jsonConfig.at("b");
    float P_mortality_rate = jsonConfig.at("m");
    float H_diffusion_rate = jsonConfig.at("k");
    float P_diffusion_rate = jsonConfig.at("l");
    float capital_t = jsonConfig.at("T");
    float delta_t = jsonConfig.at("delta_t");

    // todo
    Helpers::setDeltaT(jsonConfig.at("delta_t"));
    Helpers::setCapitalT(0.01);

    Hare::setBirthRate(0.01);
    Hare::setDiffusionRate(0.01);
    Hare::setPredationRate(0.01);

    Puma::setBirthRate(0.01);
    Puma::setDiffusionRate(0.01);
    Puma::setMortalityRate(0.01);

}

