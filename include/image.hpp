#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

#include "pixel.hpp"
#include "log.hpp"
#include "tile.hpp"
#include "landscape.hpp"

using namespace std;

typedef pixel** ImagePixelVector;

class Image {
    
	private :
		static Image* instance;
		Image(int NX, int NY);
		ImagePixelVector pixels;
        static int imageSizeX;
        static int imageSizeY;
        static int landSizeY;
        static int landSizeX;
        static int tileAveSize;
        static const int maxPixels = 1000;
        static const int tilePixels = 10;
        static const int maxLandSize = maxPixels / tilePixels;
        static bool largeImage;


	public :
		static void init(int NX, int NY);
		static void setGrid();
        static ostringstream packData();
		static void write(string filepath, double t);
        static int getTileSize();
        static int getImageSizeX();
        static int getImageSizeY();
        static int getLandSizeX();
        static int getLandSizeY();
        static int getTileAveSize();
        static bool isLargeImage();
        static void setImageSize(int NX, int NY);
};

#endif
