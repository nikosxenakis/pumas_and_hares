#include "../include/image.hpp"

Image* Image::instance = NULL;

size_t Image::tileAveSize;
size_t Image::imageSizeX;
size_t Image::imageSizeY;
size_t Image::landSizeX;
size_t Image::landSizeY;
bool Image::largeImage;
const int Image::maxPixels = 1000;
const int Image::tilePixels = 10;
const int Image::maxLandSize = maxPixels / tilePixels;

// create new image
//
Image::Image(size_t NX, size_t NY) {

    size_t SizeX, SizeY;
    
    this->setImageSize(NX, NY);

	SizeX = this->getImageSizeX();
	SizeY = this->getImageSizeY();

    pixels = new Pixel* [SizeY];
    for (size_t i=0; i < SizeY; i++) {
        pixels[i] = new Pixel[SizeX];
    }

}


void Image::init(size_t NX, size_t NY) {
	Image::instance = new Image(NX, NY);
}

void Image::setImageSize(size_t NX, size_t NY) {

    landSizeX = NX;
    landSizeY = NY;

    // regular image
    if (NX <= maxLandSize || NY <= maxLandSize) {

        largeImage = false;

        if (NX > NY) {
            imageSizeX = tilePixels * NX;
            imageSizeY = (NY * tilePixels * NX) / NX;
         }
        else {
            imageSizeY = tilePixels * NY;
            imageSizeX = (NX * tilePixels * NY) / NY;
        }
    }

    // large image with averaging
    else {
        largeImage = true;
        if (NX > NY) {
            imageSizeX = maxPixels;
            imageSizeY = (maxPixels * NY) / NX;
            tileAveSize = NX / maxLandSize;
        }
        else {
            imageSizeY = maxPixels;
            imageSizeX = (maxPixels * NX) / NY;
            tileAveSize = NY / maxLandSize;

        }
    cout << "averaging tile size: " << tileAveSize << " x " << tileAveSize << endl;
    }


    cout << "land size: " << landSizeX << " x " << landSizeY << endl;
    cout << "image size(pixels): " << imageSizeX << " x " << imageSizeY << endl;
    cout << "tile size: " << tilePixels << " x " << tilePixels << endl;


}

size_t Image::getTileSize() {
    return Image::tilePixels;
}

size_t Image::getImageSizeX() {
    return Image::imageSizeX;
}

size_t Image::getImageSizeY() {
    return Image::imageSizeY;
}

size_t Image::getLandSizeX() {
    return Image::landSizeX;
}
size_t Image::getLandSizeY() {
    return Image::landSizeY;
}

size_t Image::getTileAveSize() {
    return Image::tileAveSize;
}       
bool Image::isLargeImage() {
    return Image::largeImage;
} 

void Image::setGrid() {
    size_t origin_i;
    size_t origin_j;
    size_t NY, NX;
    bool landVal;
    float pumaVal, hareVal;
    size_t aveSize = Image::getTileAveSize();
    float maxPumas = Landscape::getMaxPumas();
    float maxHares = Landscape::getMaxHares();


    // correct bounds for image loop with rescaling    
    NY = Image::getImageSizeY() / Image::getTileSize();
    NX = Image::getImageSizeX() / Image::getTileSize();

    

    // skips over halo cells
    for (size_t i=1; i<NY+1; i++) {
        for (size_t j=1; j< NX+1; j++) {

            // small image prints as is
            if (Image::isLargeImage()==false) {
                Tile* tile = Landscape::getTile(i, j);
                landVal = tile->isLand();
                pumaVal = tile->getPumas();
                hareVal = tile->getHares();
            }
            // large image does averaging
            else {
                TileData* tile = Landscape::getRegion(((i-1) * aveSize) + aveSize/2, ((j-1) * aveSize) + aveSize/2, aveSize, aveSize);
                landVal = tile->land;
                pumaVal = tile->pumas;
                hareVal = tile->hares;
                delete tile;
            }
            // skip over water cells
            if (landVal==0) {
                continue;
            }
            else {
                // corner for image tile
                origin_i = Image::getTileSize() * (i-1);
                origin_j = Image::getTileSize() * (j-1);
                
                for (size_t it = origin_i; it < origin_i + Image::getTileSize(); it++) {
                    for (size_t jt = origin_j; jt < origin_j + Image::getTileSize(); jt++) {

                        if (it-origin_i < Image::getTileSize() - (jt - origin_j)) {
                            Image::instance->pixels[it][jt].setColour(Colour::pumas, pumaVal, maxPumas, maxHares);
                        }
                        else {
                            Image::instance->pixels[it][jt].setColour(Colour::hares, hareVal, maxPumas, maxHares);
                        }
                    }
                }
            }
        }
    }
}

string Image::packData() {
    stringstream ppmOut(stringstream::out|stringstream::binary);
    size_t ySize = Image::getImageSizeY();
    size_t xSize = Image::getImageSizeX();

    ppmOut << "P3\n" << xSize << " " << ySize << "\n255\n";
    for (size_t i=0; i<ySize; i++) {
        for (size_t j=0; j<xSize; j++) {
            ppmOut << Image::instance->pixels[i][j].read();
            if (((ySize * i)+j+1) % 4==0) {
                ppmOut << endl;
            }
        }
    }
    return ppmOut.str();
}

void Image::write(string filepath, double t) {
    ostringstream fileName;
    fileName << filepath << "/Density_" << setw(3) << setfill('0') << t << ".ppm";
  
    string ppmOut = Image::packData();
    
    ofstream datFile;
    datFile.open(fileName.str(), ios::binary);
    datFile.write(ppmOut.c_str(), ppmOut.length());
    datFile.close();
}
