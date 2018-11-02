#include <iostream>
#include <fstream>
#include <sstream>      // std::stringstream
#include <string>
#include <vector>

#define RESOURCES_PATH "./resources/"

using namespace std;

void land_enchancer(ifstream &input, ofstream &output) {
    string l;
    std::stringstream myline;

    //write the size
    output << "2000 2000\n";
    getline (input,l);
    while ( getline (input,l) )
    {

        myline.flush();
        myline.clear();
        myline.str("");

        istringstream split(l);

        vector<string> tokens;
        for (string each; getline(split, each, ' '); tokens.push_back(each));

        for(int i = 0; i < 50; ++i) {
            if(i!=0)
                myline << " ";
            for (int j = 0; j < 40; ++j)
            {
                if(j!=0)
                    myline << " ";
                myline << tokens[i];
            }
        }

        for (int i = 0; i < 40; ++i)
        {
            output << myline.str();
            output << "\n";
        }
    }

}

int main(int argc, char** argv) {

    ofstream output;
    output.open (string(RESOURCES_PATH) + "new_2000x2000.dat");
    ifstream input (string(RESOURCES_PATH) + "new_50x50.dat");

    if (input.is_open() && output.is_open()) {
        land_enchancer(input, output);
        input.close();
        output.close();
    }
    else {
        cout << "File is not open" << endl;
        exit(1);
    }

    return 0;
}
