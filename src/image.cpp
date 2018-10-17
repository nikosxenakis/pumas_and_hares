#include "../include/image.hpp"

Image* Image::instance = NULL;

int Image::tilePixels;
int Image::imageSizeX;
int Image::imageSizeY;
int Image::landSizeX;
int Image::landSizeY;

// create new image
//
Image::Image(int NX, int NY) {

    int SizeX, SizeY;
    
    this->setImageSize(NX, NY);

	SizeX = this->getImageSizeX();
	SizeY = this->getImageSizeY();

    pixels = new pixel* [SizeX];
    for (int i=0; i < SizeX; i++) {
        pixels[i] = new pixel[SizeY];
    }

}

// need deconstructor

void Image::init(int NX, int NY) {
	Image::instance = new Image(NX, NY);
}

void Image::setImageSize(int NX, int NY) {

    landSizeX = NX;
    landSizeY = NY;

    if (NX > NY) {
        tilePixels = maxPixels / NX;
        imageSizeX = tilePixels * NX;
        imageSizeY = (NY * tilePixels * NX) / NX;
    }
    else {
        tilePixels = maxPixels / NY;
        imageSizeY = tilePixels * NY;
        imageSizeX = (NX * tilePixels * NY) / NY;
    }
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


void Image::setGrid() {

    int origin_i;
    int origin_j;
	int NY, NX;

    NY = Image::getLandSizeX();
	NX = Image::getLandSizeY();

    cout << NX << " " << NY << endl;

    // skips over halo cells
    for (int i=1; i<NY+1; i++) {
        for (int j=1; j< NX+1; j++) {

            Tile* tile = Landscape::getTile(i, j);

            if (tile->isLand()==0) {
                continue;
            }
            else {
                origin_i = Image::getTileSize() * (i-1);
                origin_j = Image::getTileSize() * (j-1);

                for (int it = origin_i; it < origin_i + Image::getTileSize(); it++) {
                    for (int jt = origin_j; jt < origin_j + Image::getTileSize(); jt++) {

                        if (it-origin_i < Image::getTileSize() - (jt - origin_j)) {
                            Image::instance->pixels[it][jt].set_colour("Puma", tile->getOldPumas());
                        }
                        else {
                            Image::instance->pixels[it][jt].set_colour("Hare", tile->getOldHares());
                        }
                    }
                }
            }
        }
    }
}

void Image::write(double t) {

    ostringstream FileName;
    ofstream ppmOut;
    FileName << "./output/" << "Density_" << setw(3) << setfill('0') << t << ".ppm"; 
    ppmOut.open(FileName.str());
    int ySize;
    int xSize;
    xSize = Image::getImageSizeX();
    ySize = Image::getImageSizeY();

    ppmOut << "P3\n" << xSize << " " << ySize << "\n255\n";

    for (int i=0; i<ySize; i++) {
      for (int j=0; j<xSize; j++) {
          Image::instance->pixels[i][j].write(ppmOut);
          if (((ySize * i)+j+1) % 4==0) {
              ppmOut << endl;
          }
      }
   }
    ppmOut.close();
}


