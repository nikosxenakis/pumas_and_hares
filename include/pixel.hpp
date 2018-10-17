#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <iostream>
#include <fstream>

using namespace std;

class pixel {

	private:
		int red;
		int green;
		int blue;
	public:
		void set_colour(string type, double density);
		int get_green();
		int get_red();
		int get_blue();
		pixel();
		void write(ofstream &file);
};

#endif
