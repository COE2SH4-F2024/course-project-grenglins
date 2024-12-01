
#include "objPos.h"

class Food
{
    private:
        objPos food;

    public: 
        Food();
        ~Food();

        void generateFood(objPos blockOff);
        objPos getFoodPos() const;

};