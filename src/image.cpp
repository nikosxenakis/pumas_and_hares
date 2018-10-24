#include "../include/image.hpp"

Image* Image::instance = NULL;

int Image::tileAveSizeX;
int Image::tileAveSizeY;
int Image::imageSizeX;
int Image::imageSizeY;
int Image::landSizeX;
int Image::landSizeY;
bool Image::largeImage;

// create new image
//
Image::Image(int NX, int NY) {

    int SizeX, SizeY;
    
    this->setImageSize(NX, NY);

	SizeX = this->getImageSizeX();
	SizeY = this->getImageSizeY();

    pixels = new pixel* [SizeY];
    for (int i=0; i < SizeY; i++) {
        pixels[i] = new pixel[SizeX];
    }

}

// need deconstructor

void Image::init(int NX, int NY) {
	Image::instance = new Image(NX, NY);
}

void Image::setImageSize(int NX, int NY) {

    landSizeX = NX;
    landSizeY = NY;
/*
    float tmp2 = float(landSizeY)/float(landSizeX);
    float tmp = float(maxPixels/tmp2);
    imageSizeX = int(sqrt(tmp));
    imageSizeY = int(maxPixels/imageSizeX);

    tilePixelsX = int(imageSizeX / NX);
    tilePixelsY = int(imageSizeY / NY);
*/
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
        tileAveSizeX = NX / maxLandSize;
        tileAveSizeY = NY / maxLandSize;
        if (NX > NY) {
            imageSizeX = maxPixels;
            imageSizeY = (maxPixels * NY) / NX;
        }
        else {
            imageSizeY = maxPixels;
            imageSizeX = (maxPixels * NX) / NY;

        }
    cout << "averaging tile size: " << tileAveSizeX << " x " << tileAveSizeY << endl;
    }


    cout << "land size: " << landSizeX << " x " << landSizeY << endl;
    cout << "image size(pixels): " << imageSizeX << " x " << imageSizeY << endl;
    cout << "tile size: " << tilePixels << " x " << tilePixels << endl;


}

int Image::getTileSize() {
    return Image::tilePixels;
}

int Image::getImageSizeX() {

    return Image::imageSizeX;
}

int Image::getImageSizeY() {

    return Image::imageSizeY;
}

int Image::getLandSizeX() {
    return Image::landSizeX;
}
int Image::getLandSizeY() {
    return Image::landSizeY;
}
int Image::getTileAveSizeX() {
    return Image::tileAveSizeX;
}
int Image::getTileAveSizeY() {
    return Image::tileAveSizeY;
}       
bool Image::isLargeImage() {
    return Image::largeImage;
} 

void Image::setGrid() {

    int origin_i;
    int origin_j;
    int NY, NX;
    bool landVal;
    float pumaVal, hareVal;
    int aveX = Image::getTileAveSizeX();
    int aveY = Image::getTileAveSizeY();

//    NY = Image::getLandSizeY();
//  NX = Image::getLandSizeX();
    NY = Image::getImageSizeY() / Image::getTileSize();
    NX = Image::getImageSizeX() / Image::getTileSize();


    cout << NX << " " << NY << endl;

    // skips over halo cells
    for (int i=1; i<NY+1; i++) {
        for (int j=1; j< NX+1; j++) {

            // large image or not
            if (Image::isLargeImage()==false) {
                Tile* tile = Landscape::getTile(i, j);
                landVal = tile->isLand();
                pumaVal = tile->getOldPumas();
                hareVal = tile->getOldHares();
            }
            // does averaging
            else {
                InputTile tile = Landscape::getRegion((i * aveX) + aveX/2, (j * aveY) + aveY/2, aveX, aveY);
                landVal = tile.land;
                pumaVal = tile.pumas;
                hareVal = tile.hares;
            }
            // skip over water cells
            if (landVal==0) {
                continue;
            }
            else {
                origin_i = Image::getTileSize() * (i-1);
                origin_j = Image::getTileSize() * (j-1);

                for (int it = origin_i; it < origin_i + Image::getTileSize(); it++) {
                    for (int jt = origin_j; jt < origin_j + Image::getTileSize(); jt++) {

                        if (it-origin_i < Image::getTileSize() - (jt - origin_j)) {
                            Image::instance->pixels[it][jt].set_colour(Color::pumas, pumaVal);
                        }
                        else {
                            Image::instance->pixels[it][jt].set_colour(Color::hares, hareVal);
                        }
                    }
                }
            }
        }
    }
}

ostringstream Image::packData() {
    ostringstream ppmOut(stringstream::out|stringstream::binary);
    int ySize = Image::getImageSizeY();
    int xSize = Image::getImageSizeX();

    Log::startLogTime("packData");

    ppmOut << "P3\n" << xSize << " " << ySize << "\n255\n";
    for (int i=0; i<ySize; i++) {
        for (int j=0; j<xSize; j++) {
            ppmOut << Image::instance->pixels[i][j].read();
            if (((ySize * i)+j+1) % 4==0) {
                ppmOut << endl;
            }
        }
    }
    Log::endLogTime("packData");
    return ppmOut;
}

void Image::write(string filepath, double t) {
    ostringstream fileName;
    fileName << filepath << "/Density_" << setw(3) << setfill('0') << t << ".ppm";
  
    ostringstream ppmOut = Image::packData();
    
    ofstream datFile;
    datFile.open(fileName.str(), ios::binary);
    datFile.write(ppmOut.str().c_str(), ppmOut.str().length());
    datFile.close();
}
