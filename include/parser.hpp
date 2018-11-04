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

using json = nlohmann::json;

using namespace std;

/**
 * @class Parser
 * @brief Parsing input data
 * @details Parsing input data from a .json config file and reading landscape definition
 */
class Parser {

	private:
        /**
       	 * @brief splits the parsed vector
      	 * @param line input line
         * @param vline input vline
         * @param delim delimeter
      	 */
        static void split(const string& line, vector <string> &vline, char delim);
        /**
         * @brief checks if vector only contains 0 and 1 for water and land
         * @param land land
         */
        static bool validTile(int land);

	public:

		/**
       	 * @brief read dat file, parse landscape
      	 * @param landFile for landFile containing the landscape definition for water, land and/or Puma and Hare densities
      	 */
		static void parseInput(const string& landFile) throw(runtime_error);
        /**
       	 * @brief deleting tiles vector
      	 */
        static void freeTilesVector();

		/**
      	 * @brief read json file, parse json and set parsed parameters to Helpers, Hare and Puma
     	 * @param configFile for configFile containing Puma, Hare, Time parameters (birth rates, deltaT, etc)
     	 */
		static void parseConfig(const string& configFile) throw(runtime_error);
		/**
       	 * @brief array containing all mandatory keys for the json file
      	 */
        static string required_params[8];

};

#endif
