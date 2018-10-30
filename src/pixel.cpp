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

	int max_color = 254;
	int others_color = int(opacity*(1-max_color) + max_color);

	switch(c) {
		case sea: {
			this->red = 64;
			this->green = 164;
			this->blue = 223;
			break;
		}
		case pumas: {
			this->red = max_color;
			this->green = others_color;
			this->blue = others_color;
			break;
		}
		case hares: {
			this->red = others_color;
			this->green = max_color;
			this->blue = others_color;
			break;
		}
	}
}
