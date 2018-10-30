#include "../include/pixel.hpp"

Pixel::Pixel() {
	this->setRgb(Color::sea,1);
}

int const Pixel::getRed() {
	return this->red;
}

int const Pixel::getBlue() {
	return this->blue;
}

int const Pixel::getGreen() {
	return this->green;
}

void const Pixel::write(ofstream &ppmFile) {
	ppmFile << this->getRed() << " " << this->getGreen() << " " << this->getBlue() << " ";
}

string Pixel::read() {
    stringstream ss;
    ss << this->getRed() << " " << this->getGreen() << " " << this->getBlue() << " ";
    return ss.str();
}

void Pixel::setColour(Color c, double density, double maxPumas, double maxHares) {
	float opacity = 0.0;
    
    if (c == Color::hares) {
        opacity = density/maxHares;
	}
	else if (c == Color::pumas) {
		opacity = density/maxPumas;
	}

	this->setRgb(c, opacity);
}

void Pixel::setRgb(Color c, float opacity) {

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
