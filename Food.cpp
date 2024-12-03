//Include libraaries
#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

//Default constructor 
Food::Food()
{
    foodBucket = new objPosArrayList();
}

//Detructor
Food:: ~Food()
{
    delete foodBucket;
}
 
//Function to generate food randomly on board  
void Food::generateFood(objPosArrayList* blockOff)
{
    bool isValid; //Boolean to check if the random values are different from player position
    GameMechs gameMechs; //refrence to GameMechs class 
    objPos food; //objPos to hold the food postion and symbol

    
    //clear the array list before repopulating 
    //three times, since three food items are generated at a time
    foodBucket->removeTail();
    foodBucket->removeTail();
    foodBucket->removeTail();


    //iterate through each item in foodBucket 
    for (int x = 0; x < 3; x++){

        do {
            isValid = true;

            
            //Generate random coordinate 
            int xCoord = (rand() % (gameMechs.getBoardSizeX() - 2)) + 1;
            int yCoord = (rand() % (gameMechs.getBoardSizeY() - 2)) + 1;

            if (x == 2) {
                food.setObjPos(xCoord, yCoord, '*'); // Update the food's position;
            }

            else {
                food.setObjPos(xCoord, yCoord, 'o'); // Update the food's position
            }

            //Iterate through blockOff list to invalidate any duplicate positions
            for (int i = 0; i< blockOff -> getSize(); i++){

                objPos currElement = blockOff -> getElement(i); //Set element i to currElement

                if (food.isPosEqual(&currElement)) {
                    isValid = false; //Continue generating random coordinates
                }

            }


            //Iterate through foodBucket to make sure no overlapp between food items
            for (int i = 0; i< foodBucket -> getSize(); i++){

                objPos currFoodElement = foodBucket->getElement(i);//Set element i to currFoodElement

                if (food.isPosEqual(&currFoodElement)) {
                    isValid = false; //Continue generating random coordinates 
                }

            }

        } while (!isValid);

        foodBucket->insertTail(food); //Valid coordinates were found and food can be added to arrayList

    }


}

objPosArrayList* Food::getFoodPos() const
{
    return foodBucket; //return foodBucket objPosArrayList
}
