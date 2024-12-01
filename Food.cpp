#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"


Food::Food()
{
    food.setObjPos(-10,-10,'o');
}

Food:: ~Food()
{

}
 
void Food::generateFood(objPos blockOff)
{
    bool isValid;
    GameMechs gameMechs;

   do {
        isValid = true;

        int xCoord = rand() % gameMechs.getBoardSizeX();
        int yCoord = rand() % gameMechs.getBoardSizeY();

        food.setObjPos(xCoord, yCoord, 'o'); // Update the food's position

        if (food.isPosEqual(&blockOff)) {
            isValid = false;
        }
    } while (!isValid);
    
}

objPos Food::getFoodPos() const
{
    return food;
}
