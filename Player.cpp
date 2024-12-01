#include "Player.h"
#include <iostream>
#include "MacUILib.h"
#include "GameMechs.h"
#include "Food.h"

Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    mainFoodRef = foodRef;
    
    myDir = UP;
    playerPosList = new objPosArrayList();

    // more actions to be included

    objPos headPos(((mainGameMechsRef -> getBoardSizeX()) / 2), ((mainGameMechsRef -> getBoardSizeY()) / 2), '@');
    playerPosList -> insertHead(headPos);

    //playerPos.pos->x = (mainGameMechsRef -> getBoardSizeX()) / 2; //initialize player position and character
    //playerPos.pos->y = (mainGameMechsRef -> getBoardSizeY()) / 2;
    //playerPos.symbol = '@';
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
    
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  
    
    char input = mainGameMechsRef -> getInput(); //store user input

    switch(input){ //switch statement to change direction
        case 'w':
                if (myDir == LEFT || myDir == RIGHT){ //move up
                    myDir = UP;
                    //printf("move up\n");
                }
                break;

            case 's':
                if (myDir == LEFT || myDir == RIGHT){ //move down
                    myDir = DOWN;
                    //printf("move down\n");
                }
                break;

            case 'a':
                if (myDir == UP || myDir == DOWN){ //move left
                    myDir = LEFT;
                    //printf("move L\n");
                }
                break;
            
            case 'd':
                if (myDir == UP || myDir == DOWN){ //move right
                    myDir = RIGHT;
                    //printf("move R\n");
                }
                break;

            default: //default case
                break;
    }       
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    int xSize = mainGameMechsRef -> getBoardSizeX(); //store board dimensions
    int ySize = mainGameMechsRef -> getBoardSizeY(); 
    bool collisionFood = false;

    /*
    create a temp objPos to calc the new head pos
    hint - propbably should get the head element of the playerPosList
    */

    objPos tempHead = playerPosList -> getHeadElement();

    switch (myDir) //move direction
    {
        /*
        calc the new head pos using the temp objPos
        */
        case UP:
            if (tempHead.pos->y == 1){
                tempHead.pos->y = ySize - 2;
            }
            else {
                tempHead.pos->y -= 1;
            }
            
            break;

        case DOWN:
            if (tempHead.pos->y == ySize - 2){
                tempHead.pos->y = 1;
            }
            else {
                tempHead.pos->y += 1;
            }
            
            break;

        case LEFT:
            if (tempHead.pos->x == 1){
                tempHead.pos->x = xSize - 2;
            }
            else {
                tempHead.pos->x -= 1;
            }
            
            break;

        case RIGHT:
            if (tempHead.pos->x == xSize - 2){
                tempHead.pos->x = 1;
            }
            else {
                tempHead.pos->x += 1;
            }
            
            break;
    }

    /*
    insert temp objPos to head of the list

    later - check if the new temp objPos overlaps the food pos (get it from game mech class)

    use isposequal method from obj class

    if overlap, food consumed, DO NOT REMOVE SNAKE TAIL
    and take the respective actions to increase the score

    if no overlap, remove tail, complete movement
    */

   playerPosList -> insertHead(tempHead); //temporary head position

   if (checkSelfCollision() == true){
        mainGameMechsRef -> setLoseFlag();
        mainGameMechsRef -> setExitTrue();
   }

   objPosArrayList* food = mainFoodRef -> getFoodPos(); //temporary food position

   for (int i= 0; i< food ->getSize(); i++){

        objPos tempFood = food -> getElement(i);
        MacUILib_printf("Food[x,y] = [%d,%d], %c\n",tempFood.pos->x, tempFood.pos->y, tempFood.symbol);

       if (tempHead.isPosEqual(&tempFood)){ //if collision don't remove tail
            collisionFood = true;
            if (food ->getElement(i).getSymbol() == '*'){
                mainGameMechsRef -> incrementScore();
                mainGameMechsRef -> incrementScore();
                mainGameMechsRef -> incrementScore();
                mainGameMechsRef -> incrementScore();
                
            }

            else{
                mainGameMechsRef -> incrementScore();
            }
        }
   }


    if (collisionFood){
        mainFoodRef -> generateFood(playerPosList);
    }
    else if (!collisionFood){
        playerPosList -> removeTail(); //if no collision remove tail
    }

}

// More methods to be added

bool checkFoodConsumption (){

}

void increasePlayerLength(){

}

bool Player::checkSelfCollision() {
    for (int i=1; i< playerPosList->getSize() ; i++){
        if (((playerPosList -> getHeadElement().pos->x) == (playerPosList -> getElement(i).pos->x)) && ((playerPosList -> getHeadElement().pos->y) == (playerPosList -> getElement(i).pos->y))){
            return true;
        }
    }
    return false;
}