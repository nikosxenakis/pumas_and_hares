#include "../include/pixel.hpp"


pixel::pixel() {

	this->red = 0;
	this->green = 0;
	this->blue = 255;
}

int pixel::get_red() {

	return this->red;
}

int pixel::get_blue() {

	return this->blue;
}

int pixel::get_green() {

	return this->green;
}

void pixel::write(ofstream &ppmFile) {

	ppmFile << this->get_red() << " " << this->get_green() << " " << this->get_blue() << " ";

}

void pixel::set_colour(string type, double density) {

	int MAX = 5;
	int colourScale;

	colourScale = (density * 255) / MAX;

	if (type == "Hare") {
		this->red = 255 - colourScale;
		this->green = 255;
		this->blue = 255 - colourScale;
	}
	else if (type == "Puma") {
		this->red = 255;
		this->green = 255 - colourScale;
		this->blue = 255 - colourScale;
	}
}
