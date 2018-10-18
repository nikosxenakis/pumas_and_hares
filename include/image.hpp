#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "pixel.hpp"
#include <string>
#include <sstream>
#include <cmath>
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
		static int tilePixelsX;
        static int tilePixelsY;
        static int imageSizeX;
        static int imageSizeY;
        static int landSizeY;
        static int landSizeX;
        static const int maxPixels = 300*300;


	public :
		static void init(int NX, int NY);
		static void setGrid();
		static void write(double t);
        static int getTileSizeX();
        static int getTileSizeY();
        static int getImageSizeX();
        static int getImageSizeY();
        static int getLandSizeX();
        static int getLandSizeY();
        static void setImageSize(int NX, int NY);
};

#endif
