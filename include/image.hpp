/**
 * @file image.hpp
 * @brief Provide information about Image
 * @ingroup pumas_and_hares
 */

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

#include "pixel.hpp"
#include "tile.hpp"
#include "landscape.hpp"

using namespace std;

/**
 * @typedef
 * @brief Type 2D array of pixel for image
 */
typedef Pixel** ImagePixelVector;

/**
 * @class Image
 * @brief A class for creating a ppm image
 * @details Contains all necessary sizing and writing options for image creation
 */
class Image {
    
	private :
		static Image* instance; /**< Image pointer */

        /**
         * @brief constructor for an image
         * @param[in] NX size of x dimension of input file
         * @param[in] NY size of y dimension of input file
         */
		Image(size_t NX, size_t NY);

        /**
         * @brief 2D array pixels
         */
		ImagePixelVector pixels;

        /**
         * @brief Number of pixels in the image in x
         */
        static size_t imageSizeX;

        /**
         * @brief Number of pixels in the image in y
         */
        static size_t imageSizeY;

        /**
         * @brief Size of the input landscape in y
         */
        static size_t landSizeY;

        /**
         * @brief Size of the input landscape in x
         */
        static size_t landSizeX;

        /**
         * @brief Size of the square used (in tiles) for averaging over values
         */
        static size_t tileAveSize;

        /**
         * @brief The maximum number of pixels allowed in either x or y
         */
        static const int maxPixels;

        /**
         * @brief The number of pixels used to represent a tile (same for x and y)
         */
        static const int tilePixels;

        /**
         * @brief The maximum size of landscape before averaging is required for the image
         */
        static const int maxLandSize;

        /**
         * @brief Boolean for whether an landscape is greater than maxLandSize
         */
        static bool largeImage;

        /**
         * @brief stores the data for the ppm file in a string
         * @return the ppm file in string formart
         */
        static string packData();

        /**
         * @brief gets the TileSize
         * @return returns the TileSize
         */
        static size_t getTileSize();

        /**
         * @brief gets the image size in x
         * @return returns the image size in x
         */
        static size_t getImageSizeX();

        /**
         * @brief gets the image size in y
         * @return returns the image size in y
         */
        static size_t getImageSizeY();

        /**
         * @brief gets the landscape size in x
         * @return returns the landscape size in x
         */
        static size_t getLandSizeX();

        /**
         * @brief gets the landscape size in y
         * @return returns the landscape size in y
         */
        static size_t getLandSizeY();

        /**
         * @brief gets the tile size used for averaging
         * @return returns the tile size used for averaging
         */
        static size_t getTileAveSize();

        /**
         * @brief checks if the landscape is greater than the maxLandSize
         * @return either TRUE if the landscape is greater or FALSE if it is not
         */
        static bool isLargeImage();

        /**
         * @brief sets the size of an image (pixels) and decides whether averaging is needed
         * @param[in] NX landscape size in x
         * @param[in] NY landscape size in y
         */
        static void setImageSize(size_t NX, size_t NY);

	public :

        /**
         * @brief initialises pixel array
         * @param[in] NX image size in x
         * @param[in] NY image size in y
         */ 
		static void init(size_t NX, size_t NY);

        /**
         * @brief sets the colors in the image based on the density of hares/pumas on each landscape tile
         */
		static void setGrid();

        /**
         * @brief writes the ppm string to file
         * @param[in] filepath destination of the file
         * @param[in] t timestep
         */
        static void write(string filepath, double t);
};

#endif
