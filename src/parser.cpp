#include "../include/parser.hpp"

// todo: better to take parameter, wrangle values, return corrected (split) vector
void Parser::split(const string& str, vector<string> &strVect, char delim) {
    stringstream ss(str);
    string value;
    strVect.clear();
    while (getline(ss, value, delim)) {
        strVect.push_back(value);
    }
}

// todo: where is it used? throw exceptions instead of cout and exit()
void Parser::errorCheck(vector<string> vTile) {
    if (stoi(vTile[0])!= 0 && stoi(vTile[0])!= 1) {
        cout << "Land input must be 0 or 1" << endl;
        exit(1);
    }
    if (stod(vTile[1])<0 || stod(vTile[2]) <0) {
        cout << "Density input must be positive" << endl;
        exit(1);
    }

}

void Parser::parseInput(const string& landFileName) throw(runtime_error) {

    ifstream landFile;
    landFile.open(landFileName);
    size_t NY, NX;
    string inputLine;
    vector <string> vInputLine;
    vector <string> vInputTile;
    vector< vector<TileData*> > tilesVector;

    if (landFile.is_open()) {
        landFile >> NX;
        if (NX > 2000 || NX < 1) {
            cerr << "Number of columns must be between 1 and 2000 but instead it was " << NX << endl;
            throw runtime_error("Exception parsing the input");
        }
        landFile >> NY;
        if (NY > 2000 || NY < 1) {
            cerr << "Number of rows must be between 1 and 2000 but instead it was " << NY << endl;
            throw runtime_error("Exception parsing the input");
        }

        // halo cell
        TileData* haloTile = new TileData(0, 0.0, 0.0);

        // creating first row or halo cells
        vector<TileData*> zerosFirstLine (NX + 2);
        for (size_t i = 0; i < zerosFirstLine.size(); ++i) {
            zerosFirstLine[i] = haloTile;
        }
        tilesVector.push_back(zerosFirstLine);
       
        landFile.ignore();

        // reading Landscape
        for (size_t i = 0; i < NY; ++i) {
            
            vector<TileData*> tilesLine;
            tilesLine.push_back(haloTile);      // first column halos

            getline(landFile, inputLine);

            // split by space for each square
            split(inputLine, vInputLine, ' ');
         
            if (vInputLine.size()!=NX) {
                cerr << "Error in line " << i << " declared " << NX << " columns but " << vInputLine.size()  <<" was found" << endl;
                throw runtime_error("Exception parsing the input");
            }
         
            for (size_t j=0; j<NX; j++) {

                // split by comma for land, pumas, hares
                split(vInputLine[j], vInputTile, ',');
             
                if (vInputTile.size()==3) {
                    tilesLine.push_back(new TileData(stoi(vInputTile[0]), stod(vInputTile[1]), stod(vInputTile[2])));
                }
                else if (vInputTile.size()==1) {
                    tilesLine.push_back(new TileData(stoi(vInputTile[0])));
                }
                else {
                    cerr << "Invalid input tile in position ( " << i << ", " << j << endl;
                    throw runtime_error("Exception parsing the input");
                }
            }
            tilesLine.push_back(haloTile);      // last column halos
            tilesVector.push_back(tilesLine);
        }

        // add last row as halos
        vector<TileData*> zerosLastLine (NX + 2);
        for (size_t i = 0; i < zerosLastLine.size(); ++i) {
            zerosLastLine[i] = haloTile;
        }
        tilesVector.push_back(zerosLastLine);
       
       ConfigData::initLandscapeData(tilesVector, NX+2, NY+2);
   }
   else {
       cerr << "Invalid land file name: " << landFileName << endl;
       throw runtime_error("Exception in land file");
   }
}

void Parser::freeTilesVector() {
    vector< vector< TileData* > >& tilesVector = ConfigData::tilesVector;

   for (size_t i=1; i<tilesVector.size()-1; ++i) {
       for (size_t j=1; j<tilesVector[i].size()-1; ++j) {
           delete tilesVector[i][j];
       }
   }
   
    delete tilesVector[0][0]; //removes all of the halo tiles references
}

void Parser::parseConfig(const string& configFileName) throw(runtime_error) {

    ifstream configFile(configFileName);
    stringstream buffer;
    json jsonConfig;

        configFile.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
        buffer << configFile.rdbuf();
        string jsonString = buffer.str();

    try {
        jsonConfig = json::parse(jsonString);
    }
    catch (...) {
        cerr << "Exception parsing json: Wrong format" << endl;
        throw runtime_error("Exception in set Configuration data");
    }

    std::vector<string> found;

        for (auto i = jsonConfig.begin(); i != jsonConfig.end(); ++i)
        {
            // check if json key i.key() is in required_params
            bool key_is_req = std::find(std::begin(required_params), std::end(required_params), i.key()) != std::end(required_params);
            if (key_is_req) {
                // if found add json key to vector<string> found
                found.push_back(i.key());
            }
        }

        // check if values in vector<string> found are unique
        auto it = std::unique( found.begin(), found.end() );
        bool found_is_unique = (it == found.end() );

        if (found.size() != 8 && found_is_unique) {
            throw invalid_argument("You need to define all of the following parameter keys: delta_t, T, r, k, a, b, l, m");
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
    catch (const invalid_argument& ia) {
        cerr << "Invalid configuration in param.json: " << ia.what() << endl;
        throw runtime_error("Exception in set Configuration data");
    }
    catch (json::parse_error& e) {
        std::cout << "There is a syntax error in /resources/param.json. Message: " << e.what() << '\n'
                  << "exception id: " << e.id << '\n'
                  << "byte position of error: " << e.byte << std::endl;
        throw runtime_error("Exception thrown during json parsing");
    }
}

string Parser::required_params[8] = { "delta_t", "T", "r", "k", "a", "b", "l", "m" };
