#include <iostream>
#include <fstream>
#include <sstream>      // std::stringstream
#include <string>
#include <vector>

#define RESOURCES_PATH "./resources/"

using namespace std;

void land_enchancer(ifstream &input, ofstream &output, int nx, int ny) {
    string l;
    std::stringstream myline;

    //write the size
    output << nx << " " << ny << "\n";
    getline (input,l);
    while ( getline (input,l) )
    {
        int sx = nx/10;
        int sy = ny/10;

        myline.flush();
        myline.clear();
        myline.str("");

        istringstream split(l);

        vector<string> tokens;
        for (string each; getline(split, each, ' '); tokens.push_back(each));

        for(int i = 0; i < 10; ++i) {
            if(i!=0)
                myline << " ";
            for (int j = 0; j < sx; ++j)
            {
                if(j!=0)
                    myline << " ";
                myline << tokens[i];
            }
        }

        for (int i = 0; i < sy; ++i)
        {
            output << myline.str();
            output << "\n";
        }
    }

}

int main(int argc, char** argv) {

    ofstream output;
    ifstream input ("new10x10.dat");
    int nx = 20;
    int ny = 20;
    cout << "Enter nx: ";
    cin >> nx;
    cout << "Enter ny: ";
    cin >> ny;

    string name="new_" + std::to_string(nx) + "x" + std::to_string(ny) + ".dat";
    output.open (name);

    if (input.is_open() && output.is_open()) {
        land_enchancer(input, output, nx, ny);
        input.close();
        output.close();
    }
    else {
        cout << "File is not open" << endl;
        exit(1);
    }

    return 0;
}
