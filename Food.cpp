#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include "objPosArrayList.h"


Food::Food()
{
    objPos food;
    food.setObjPos(-10,-10,'o');
}

Food:: ~Food()
{

}
 
void Food::generateFood(objPosArrayList* blockOff)
{
    bool isValid;
    GameMechs gameMechs;

   do {
        isValid = true;

        int xCoord = (rand() % (gameMechs.getBoardSizeX() - 2)) + 1;
        int yCoord = (rand() % (gameMechs.getBoardSizeY() - 2)) + 1;

        food.setObjPos(xCoord, yCoord, 'o'); // Update the food's position

        for (int i = 0; i< blockOff -> getSize(); i++){
            objPos currElement = blockOff -> getElement(i);
            if (food.isPosEqual(&currElement)) {
                isValid = false;
            }
        }
    } while (!isValid);
    
}

objPos Food::getFoodPos() const
{
    return food;
}
