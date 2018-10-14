#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
// inlude json 
#include "hare.hpp"
#include "puma.hpp"
#include "landscape.hpp"

using namespace std;

class parser {

	private:

    		static void parseInput(const string& landFile);
		static void parseConfig(const string& configFile);
	public:
		static void parse(const string& landFileName);

};


#endif