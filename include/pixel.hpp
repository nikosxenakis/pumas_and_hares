/**
 * @file pixel.hpp
 * @brief Provide information about Pixel
 * @ingroup pumas_and_hares
 */

#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <fstream>
#include <sstream>

enum Colour { sea, pumas, hares };

using namespace std;

/**
 * @class Pixel
 * @brief Setting the pixels for the overall output image
 * @details A class for setting the color of a pixel as given in r,g,b format
 */
class Pixel {

	private:
		int red; /**< value of red */
		int green; /**< value of green */
		int blue; /**< value of blue */

        /**
         * @brief sets the rgb color of a pixel
         * @param[in] c type of the color (pumas, hares, or sea)
         * @param[in] opacity color opacity corresponding to density
         */
		void setRgb(Colour c, float opacity);
	public:

        /**
         * @brief creates a new pixel with sea color
         */
		Pixel();

        /** 
         * @brief determines the opacity based on the max values and calls set_rgb
         * @param[in] c type for the color
         * @param[in] density density of either pumas or hares for given tile
         * @param[in] maxPumas maximum density of pumas from the whole grid
         * @param[in] maxHares maximum density of hares from the whole grid
         */
		void setColour(Colour c, double density, double maxPumas, double maxHares);

        /**
         * @return returns the value of the g rgb value
         */
		int const getGreen();

        /**
         * @return returns the value of the r rgb value
         */
        int const getRed();

        /**
         * @return returns the value of the b rgb value
         */
		int const getBlue();

        /** 
         * @brief writes rgb value to a file
         * @param[in] file ppm file object
         */
        void const write(ofstream &file);
        /**
         * @brief reads rgb string stream
         */
        string read();
};

#endif
