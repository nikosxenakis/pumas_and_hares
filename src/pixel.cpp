#include "../include/pixel.hpp"
#include "../include/landscape.hpp"

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

void pixel::write(ofstream &ppmFile) {
	ppmFile << this->get_red() << " " << this->get_green() << " " << this->get_blue() << " ";
}

void pixel::set_colour(string type, double density) {
	if (type == "Hare") {
		this->set_rgb(Color::hares, density/Landscape::getMaxHares());
	}
	else if (type == "Puma") {
		this->set_rgb(Color::pumas, density/Landscape::getMaxPumas());
	}
}

void pixel::set_rgb(Color c, float opacity) {

	int nutral_color = 254;
	int max_color = int(opacity*(1-nutral_color) + nutral_color);

	switch(c) {
		case sea: {
			this->red = 64;
			this->green = 164;
			this->blue = 223;
			break;
		}
		case pumas: {
			this->red = 254;
			this->green = max_color;
			this->blue = max_color;
			break;
		}
		case hares: {
			this->red = max_color;
			this->green = 254;
			this->blue = max_color;
			break;
		}
	}
}
