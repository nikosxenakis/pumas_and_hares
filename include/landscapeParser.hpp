#ifndef LANDSCAPE_PARSER_HPP
#define LANDSCAPE_PARSER_HPP

#include <iostream>
#include <fstream>
#include <system_error>

using namespace std;

class LandscapeParser {
   public:
      static void parseFile(string fileName){
         ifstream inFile(fileName);
         string strOneLine;

         try {
            inFile.open(fileName);
            cout << fileName << endl;

            while (inFile){
               getline(inFile, strOneLine);
               cout << strOneLine << endl;
            }
            inFile.close();
         } catch (std::system_error& e) {
            std::cerr << e.code().message() << std::endl;
         }

      }

   private:
      LandscapeParser() {}
};


#endif

