#ifndef FOOD_H
#define FOOD_H
#include "objPos.h"
#include "objPosArrayList.h"

class Food
{
    private:
        objPos food;  
        objPosArrayList* foodBucket;  //Food item array list 

    public: 
        Food(); //COnstructor
        ~Food(); //Destructor

        void generateFood(objPosArrayList* blockOff); //Generate random food method
        objPosArrayList* getFoodPos() const; //Get foodPos method 

};

#endif