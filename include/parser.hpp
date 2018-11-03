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

class Parser {

	private:
        static void split(const string& line, vector <string> &vline, char delim);
        static void errorCheck(vector <string> vtile);

	public:

		/**
       	 * @brief read dat file, parse landscape
      	 * @param landFile ...
      	 */
		static void parseInput(const string& landFile) throw(runtime_error);

        static void freeTilesVector();

		/**
      	 * @brief read json file, parse json and set parsed parameters to Helpers, Hare and Puma
     	 * @param configFile ...
     	 */
		static void parseConfig(const string& configFile) throw(runtime_error);

        static string required_params[8];
};

#endif
