#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

using namespace std;

class Animal {

   protected:
       string name;
       /**
        * @description birth rate of pumas per one heare eaten
        */
       static float birth_rate;
       /**
        * @description diffusion rates for pumas
        */
       static float diffusion_rate;

   public:
       string getName();
       static float getBirthRate();
       static void setBirthRate(float birth_rate);
       static float getDiffusionRate();
       static void setDiffusionRate(float diffusion_rate);
};
#endif
