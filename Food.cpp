#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include "objPosArrayList.h"


Food::Food()
{
    foodBucket = new objPosArrayList();
}

Food:: ~Food()
{
    delete foodBucket;
}
 
void Food::generateFood(objPosArrayList* blockOff)
{
    bool isValid;
    GameMechs gameMechs;
    objPos food;

    foodBucket->removeTail();
    foodBucket->removeTail();
    foodBucket->removeTail();

//    do {
//         isValid = true;

//         int xCoord = (rand() % (gameMechs.getBoardSizeX() - 2)) + 1;
//         int yCoord = (rand() % (gameMechs.getBoardSizeY() - 2)) + 1;

//         food.setObjPos(xCoord, yCoord, 'o'); // Update the food's position

//         for (int i = 0; i< blockOff -> getSize(); i++){
//             objPos currElement = blockOff -> getElement(i);
//             if (food.isPosEqual(&currElement)) {
//                 isValid = false;
//             }
//         }

//     } while (!isValid);

//     foodBucket->insertHead(food);

//     do {
//         isValid = true;

//         int xCoord = (rand() % (gameMechs.getBoardSizeX() - 2)) + 1;
//         int yCoord = (rand() % (gameMechs.getBoardSizeY() - 2)) + 1;

//         food.setObjPos(xCoord, yCoord, '*'); // Update the food's position

//         objPos headElement = foodBucket->getHeadElement();
//         if (food.isPosEqual(&headElement)) {
//             isValid = false;
//         }

//     } while (!isValid);

//     foodBucket->insertTail(food);

    for (int x = 0; x < 3; x++){

        do {
            isValid = true;

            int xCoord = (rand() % (gameMechs.getBoardSizeX() - 2)) + 1;
            int yCoord = (rand() % (gameMechs.getBoardSizeY() - 2)) + 1;

            if (x == 2) {
                food.setObjPos(xCoord, yCoord, '*'); // Update the food's position;
            }

            else {
                food.setObjPos(xCoord, yCoord, 'o'); // Update the food's position
            }

            for (int i = 0; i< blockOff -> getSize(); i++){

                objPos currElement = blockOff -> getElement(i);

                if (food.isPosEqual(&currElement)) {
                    isValid = false;
                }

            }

            for (int i = 0; i< foodBucket -> getSize(); i++){

                objPos currFoodElement = foodBucket->getElement(i);

                if (food.isPosEqual(&currFoodElement)) {
                    isValid = false;
                }

            }

        } while (!isValid);

        foodBucket->insertTail(food);

    }


}

objPosArrayList* Food::getFoodPos() const
{
    return foodBucket;
}
