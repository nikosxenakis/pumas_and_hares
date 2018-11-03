/**
 * @file parser.hpp
 * @brief Parses the input files
 * @ingroup input
 */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <sstream>
#include <fstream>
#include <vector>
#include "hare.hpp"
#include "puma.hpp"
#include "tileData.hpp"
#include "configData.hpp"
#include "../lib/json.hpp"

#define RESOURCES_PATH "./resources"

using json = nlohmann::json;

using namespace std;

class Parser {

	private:
        static void split(const string& line, vector <string> &vline, char delim);
        static void errorCheck(vector <string> vtile);

	public:

		/**
       	 * @brief read dat file, parse landscape
      	 * @param handle for landFile containing the landscape definition for water, land and/or Puma and Hare densities
      	 */
		static void parseInput(const string& landFile);

        static void freeTilesVector();

		/**
      	 * @brief read json file, parse json and set parsed parameters to Helpers, Hare and Puma
     	 * @param handle for configFile containing Puma, Hare, Time parameters (birth rates, deltaT, etc)
     	 */
		static void parseConfig(const string& configFile);
        static string required_params[8];
};

#endif
