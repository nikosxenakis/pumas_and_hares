#include "../include/output.hpp"

void Output::print_output(double t) {
	Image::setGrid();
	Image::write(OUTPUT_PATH, t);
}
