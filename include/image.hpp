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
		Image(size_t NX, size_t NY);
		ImagePixelVector pixels;
        static size_t imageSizeX;
        static size_t imageSizeY;
        static size_t landSizeY;
        static size_t landSizeX;
        static size_t tileAveSize;
        static const int maxPixels;
        static const int tilePixels;
        static const int maxLandSize;
        static bool largeImage;
        static string packData();
        static size_t getTileSize();
        static size_t getImageSizeX();
        static size_t getImageSizeY();
        static size_t getLandSizeX();
        static size_t getLandSizeY();
        static size_t getTileAveSize();
        static bool isLargeImage();
        static void setImageSize(size_t NX, size_t NY);

	public :
		static void init(size_t NX, size_t NY);
		static void setGrid();
        static void write(string filepath, double t);
};

#endif
