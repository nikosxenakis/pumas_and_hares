#include "../include/image.hpp"

Image* Image::instance = NULL;

int Image::tileAveSize;
int Image::imageSizeX;
int Image::imageSizeY;
int Image::landSizeX;
int Image::landSizeY;
bool Image::largeImage;
const int Image::maxPixels = 1000;
const int Image::tilePixels = 10;
const int Image::maxLandSize = maxPixels / tilePixels;

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

int Image::getTileAveSize() {
    return Image::tileAveSize;
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
    int aveSize = Image::getTileAveSize();
    float maxPumas = Landscape::getMaxPumas();
    float maxHares = Landscape::getMaxHares();

//    NY = Image::getLandSizeY();
//  NX = Image::getLandSizeX();
    NY = Image::getImageSizeY() / Image::getTileSize();
    NX = Image::getImageSizeX() / Image::getTileSize();


//    cout << NX << " " << NY << endl;

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
                origin_i = Image::getTileSize() * (i-1);
                origin_j = Image::getTileSize() * (j-1);
                
                for (int it = origin_i; it < origin_i + Image::getTileSize(); it++) {
                    for (int jt = origin_j; jt < origin_j + Image::getTileSize(); jt++) {

                        if (it-origin_i < Image::getTileSize() - (jt - origin_j)) {
                            Image::instance->pixels[it][jt].set_colour(Color::pumas, pumaVal, maxPumas, maxHares);
                        }
                        else {
                            Image::instance->pixels[it][jt].set_colour(Color::hares, hareVal, maxPumas, maxHares);
                        }
                    }
                }
            }
        }
    }
}

string Image::packData() {
    stringstream ppmOut(stringstream::out|stringstream::binary);
    int ySize = Image::getImageSizeY();
    int xSize = Image::getImageSizeX();

    ppmOut << "P3\n" << xSize << " " << ySize << "\n255\n";
    for (int i=0; i<ySize; i++) {
        for (int j=0; j<xSize; j++) {
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
