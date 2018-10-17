#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <iostream>
#include <fstream>

enum Color { sea, pumas, hares };

using namespace std;

class pixel {

	private:
		int red;
		int green;
		int blue;
	public:
		void set_colour(string type, double density);
		void set_rgb(Color c, float opacity);
		int const get_green();
		int const get_red();
		int const get_blue();
		pixel();
		void write(ofstream &file);
};

#endif
