#include "../include/parser.hpp"

void Parser::split(const string& str, vector<string> &cont, char delim) {
    stringstream ss(str);
    string token;
    cont.clear();
    while (getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

void Parser::errorCheck(vector<string> vTile) {
    if (stoi(vTile[0])!= 0 && stoi(vTile[0])!= 1) {
        cout << "Land input must be 0 or 1" << endl;
        // todo: shouldnt do "exit()" in function
        exit(1);
    }
    if (stod(vTile[1])<0 || stod(vTile[2]) <0) {
        cout << "Density input must be positive" << endl;
        exit(1);
    }

}

void Parser::parseInput(const string& landFileName) {

   ifstream landFile;
   landFile.open(landFileName);
   size_t NY, NX;
   string inputLine;
   vector <string> vInputLine;
   vector <string> vInputTile;

   vector< vector<TileData*> > tilesVector;
   
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

       TileData* haloTile = new TileData(0, 0.0, 0.0);
       
       vector<TileData*> zerosFirstLine (NX + 2);
       for (size_t i = 0; i < zerosFirstLine.size(); ++i) {
           zerosFirstLine[i] = haloTile;
       }
       tilesVector.push_back(zerosFirstLine);
       
      landFile.ignore();
      for (size_t i = 0; i < NY; ++i) {

         vector<TileData*> tilesLine;
         tilesLine.push_back(haloTile);

         getline(landFile, inputLine);
         split(inputLine, vInputLine, ' ');
         
         if (vInputLine.size()!=NX) {
            cout << "Error x elements not equal to Landscape size" << endl;
            exit(1);
         }
         
         for (size_t j=0; j<NX; j++) {
                split(vInputLine[j], vInputTile, ',');
                if (vInputTile.size()==3) {
                    tilesLine.push_back(new TileData(stoi(vInputTile[0]), stod(vInputTile[1]), stod(vInputTile[2])));
                }
                else if (vInputTile.size()==1) {
                    tilesLine.push_back(new TileData(stoi(vInputTile[0])));
                }
                else {
                    cout << "Incorrect defintion of input square in input.dat" << endl;
                }
          }
          tilesLine.push_back(haloTile);
          tilesVector.push_back(tilesLine);
      }

       vector<TileData*> zerosLastLine (NX + 2);
       for (size_t i = 0; i < zerosLastLine.size(); ++i) {
           zerosLastLine[i] = haloTile;
       }
       tilesVector.push_back(zerosLastLine);
       
       ConfigData::initLandscapeSize(NX+2, NY+2);
       Landscape::init(tilesVector, NY+2, NX+2);

       //free tilesVector
       for (size_t i=1; i<tilesVector.size()-1; ++i) {
           for (size_t j=1; j<tilesVector[i].size()-1; ++j) {
               delete tilesVector[i][j];
           }
       }
       delete tilesVector[0][0]; //removes all of the halo tiles references
       
   }
   else {
     cout << "Unable to open file: "<< landFileName << endl;
     cout << "landFile in folder /resources not open" << endl;
     exit(1);
   }
}

void Parser::parseConfig(const string& configFileName) {

    try{
        std::ifstream configFile(configFileName);
        std::stringstream buffer;

        configFile.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
        buffer << configFile.rdbuf();
        string jsonString = buffer.str();

        try {
            auto jsonConfig = json::parse(jsonString);
            std::vector<string> found;

            for (auto i = jsonConfig.begin(); i != jsonConfig.end(); ++i)
            {
                // check if json key i.key() is in required_params
                bool key_is_req = std::find(std::begin(required_params), std::end(required_params), i.key()) != std::end(required_params);
                if (key_is_req) {
                    // if found add json key to vector<string> found
                    found.push_back(i.key());
                }

                // compare floating point number (to something close) to zero
                if (fabsf( (float) i.value()) < 0.0000005) {
                    throw std::invalid_argument("Parameters must be greater or equal to 0");
                }
            }

            // check if values in vector<string> found are unique
            auto it = std::unique( found.begin(), found.end() );
            bool found_is_unique = (it == found.end() );

            if (found.size() != 8 && found_is_unique) {
                throw std::invalid_argument("You need to define all of the following parameter keys: delta_t, T, r, k, a, b, l, m");
            }

            ConfigData::setDeltaT(jsonConfig.at("delta_t"));
            ConfigData::setCapitalT(jsonConfig.at("T"));

            Hare::setBirthRate(jsonConfig.at("r"));
            Hare::setDiffusionRate(jsonConfig.at("k"));
            Hare::setPredationRate(jsonConfig.at("a"));

            Puma::setBirthRate(jsonConfig.at("b"));
            Puma::setDiffusionRate(jsonConfig.at("l"));
            Puma::setMortalityRate(jsonConfig.at("m"));
        }
        catch (json::parse_error& e) {
            std::cout << "There is a syntax error in /resources/param.json. Message: " << e.what() << '\n'
                      << "exception id: " << e.id << '\n'
                      << "byte position of error: " << e.byte << std::endl;
            exit(1);
        }
    }
    catch(std::exception const& e){
        cout << "There was an error reading from configFile /resources/param.json: " << e.what() << endl;
        exit(1);
    }

}

string Parser::required_params[8] = { "delta_t", "T", "r", "k", "a", "b", "l", "m" };

void Parser::print_average(double t, float averagePumas, float averageHares) {
    std::ofstream ofs;
    ofs.open (OUTPUT_FILE, std::ofstream::out | std::ofstream::app);

    ofs << "time = " << t << std::fixed << setprecision(1) << "\tpumas = " << averagePumas << "\thares = " << averageHares << endl;
    ofs.close();
}
