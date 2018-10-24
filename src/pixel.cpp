#include "../include/pixel.hpp"

pixel::pixel() {
	this->set_rgb(Color::sea,1);
}

int const pixel::get_red() {
	return this->red;
}

int const pixel::get_blue() {
	return this->blue;
}

int const pixel::get_green() {
	return this->green;
}

void const pixel::write(ofstream &ppmFile) {
	ppmFile << this->get_red() << " " << this->get_green() << " " << this->get_blue() << " ";
}

string pixel::read() {
    std::stringstream ss;
    ss << to_string(this->get_red()) << " " << to_string(this->get_green()) << " " << to_string(this->get_blue()) << " ";
    return ss.str();
}

void pixel::set_colour(Color c, double density) {
	float opacity = 0.0;

	if (c == Color::hares) {
		opacity = density/Landscape::getMaxHares();
	}
	else if (c == Color::pumas) {
		opacity = density/Landscape::getMaxPumas();
	}

	this->set_rgb(c, opacity);
}

void pixel::set_rgb(Color c, float opacity) {

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
