#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "pixel.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include "tile.hpp"
#include "landscape.hpp"

using namespace std;

typedef pixel** ImagePixelVector;

class Image {
    
	private :
		static Image* instance;
		Image(int NX, int NY);
		ImagePixelVector pixels;
		static int tilePixels;
        static int imageSizeX;
        static int imageSizeY;
        static const int maxPixels = 500;


	public :
		static void init(int NX, int NY);
		static void setGrid();
		static void write(double t);
        static int getTileSize();
        static int getImageSizeX();
        static int getImageSizeY();
        static void setImageSize(int NX, int NY);
};

#endif
