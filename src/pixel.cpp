#include "../include/pixel.hpp"

Pixel::Pixel() {
	this->set_rgb(Color::sea,1);
}

int const Pixel::get_red() {
	return this->red;
}

int const Pixel::get_blue() {
	return this->blue;
}

int const Pixel::get_green() {
	return this->green;
}

void const Pixel::write(ofstream &ppmFile) {
	ppmFile << this->get_red() << " " << this->get_green() << " " << this->get_blue() << " ";
}

string Pixel::read() {
    stringstream ss;
    ss << this->get_red() << " " << this->get_green() << " " << this->get_blue() << " ";
    return ss.str();
}

void Pixel::set_colour(Color c, double density, double maxPumas, double maxHares) {
	float opacity = 0.0;
    
    if (c == Color::hares) {
        opacity = density/maxHares;
	}
	else if (c == Color::pumas) {
		opacity = density/maxPumas;
	}

	this->set_rgb(c, opacity);
}

void Pixel::set_rgb(Color c, float opacity) {

	int max_colour = 254;
	int others_colour = int(opacity*(1-max_colour) + max_colour);

	switch(c) {
		case sea: {
			this->red = 64;
			this->green = 164;
			this->blue = 223;
			break;
		}
		case pumas: {
			this->red = max_colour;
			this->green = others_colour;
			this->blue = others_colour;
			break;
		}
		case hares: {
			this->red = others_colour;
			this->green = max_colour;
			this->blue = others_colour;
			break;
		}
	}
}
