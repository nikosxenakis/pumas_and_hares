#include "../include/output.hpp"

void Output::initOutputFile() {
    std::remove(OUTPUT_FILE);
    Image::init(ConfigData::NX-2, ConfigData::NY-2);
}

void Output::print_output(double t) {
	Image::setGrid();
	Image::write(OUTPUT_PATH, t);
}

void Output::print_average(double t, float averagePumas, float averageHares) {
    std::ofstream ofs;
    ofs.open (OUTPUT_FILE, std::ofstream::out | std::ofstream::app);
    
    ofs << "time = " << t << std::fixed << setprecision(3) << "\tpumas = " << averagePumas << "\thares = " << averageHares << endl;
    ofs.close();
}
