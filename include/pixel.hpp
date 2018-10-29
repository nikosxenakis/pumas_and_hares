#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "landscape.hpp"

enum Color { sea, pumas, hares };

using namespace std;

class pixel {

	private:
		int red;
		int green;
		int blue;
		void set_rgb(Color c, float opacity);
	public:
		pixel();
		void set_colour(Color c, double density, double maxPumas, double maxHares);
		int const get_green();
		int const get_red();
		int const get_blue();
        void const write(ofstream &file);
        string read();
};

#endif
