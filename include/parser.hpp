#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <sstream>
#include <istream>
#include <fstream>
#include <vector>
#include <string>
#include "hare.hpp"
#include "puma.hpp"
#include "tileData.hpp"
#include "configData.hpp"
#include "landscape.hpp"
#include "../resources/json.hpp"

#define OUTPUT_PATH "./output"
#define OUTPUT_FILE "./output/average_density.txt"
//#define OUTPUT_PATH "/Users/xenis656/Desktop/PS/pumas_and_hares/pumas_and_hares/output" //Just for Nikos Xcode
//#define OUTPUT_FILE "/Users/xenis656/Desktop/PS/pumas_and_hares/pumas_and_hares/output/average_density.txt" //Just for Nikos Xcode
#define RESOURCES_PATH "./resources"
//#define RESOURCES_PATH "/Users/xenis656/Desktop/PS/pumas_and_hares/pumas_and_hares/resources" //Just for Nikos Xcode

using json = nlohmann::json;

using namespace std;

class Parser {

	private:
        static void split(const string& line, vector <string> &vline, char delim);
        static void errorCheck(vector <string> vtile);

	public:

		/**
       	 * @brief read dat file, parse landscape
      	 * @param landFile ...
      	 */
		static void parseInput(const string& landFile);

		/**
      	 * @brief read json file, parse json and set parsed parameters to Helpers, Hare and Puma
     	 * @param configFile ...
     	 */
		static void parseConfig(const string& configFile);
// 		static void parse(const string& landFileName);
        static string required_params[8];
};

#endif
