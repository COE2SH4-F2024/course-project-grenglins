#ifndef FOOD_H
#define FOOD_H
#include "objPos.h"
#include "objPosArrayList.h"

class Food
{
    private:
        objPos food;
        objPosArrayList* foodBucket;

    public: 
        Food();
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        objPosArrayList* getFoodPos() const;

};

#endif