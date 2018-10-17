#ifndef PARSER_HPP
#define PARSER_HPP
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
// inlude json 
#include "hare.hpp"
#include "puma.hpp"
#include "landscape.hpp"
#include "pixel.hpp"
#include "image.hpp"
#include "inputTile.hpp"

using namespace std;

class parser {

	private:
        static void split(const string& line, vector <string> &vline, char delim);
        static void errorCheck(vector <string> vtile);
    	static void parseInput(const string& landFile);
		static void parseConfig(const string& configFile);
	public:
		static void parse(const string& landFileName);

};


#endif
