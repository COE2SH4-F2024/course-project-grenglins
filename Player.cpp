#include "Player.h" //include libraries
#include <iostream>
#include "MacUILib.h"
#include "GameMechs.h"
#include "Food.h"

Player::Player(GameMechs* thisGMRef, Food* foodRef) //default constructor
{
    mainGameMechsRef = thisGMRef; //game mechanics variable
    mainFoodRef = foodRef; //food array variable
    
    myDir = UP; //set myDir to up
    playerPosList = new objPosArrayList(); //array to hold snake

    objPos headPos(((mainGameMechsRef -> getBoardSizeX()) / 2), ((mainGameMechsRef -> getBoardSizeY()) / 2), '@'); //initialize head position
    playerPosList -> insertHead(headPos); //add head position to array

}


Player::~Player() //delete heap members
{
    delete playerPosList; //delete player positions
}

objPosArrayList* Player::getPlayerPos() const //return player array
{
    return playerPosList;
}

void Player::updatePlayerDir() //update myDir variable (player direction)
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

void Player::movePlayer() //move player function
{
    // PPA3 Finite State Machine logic

    int xSize = mainGameMechsRef -> getBoardSizeX(); //store board dimensions
    int ySize = mainGameMechsRef -> getBoardSizeY(); 

    bool collisionFood = false; //set collision with food to false

    objPos tempHead = playerPosList -> getHeadElement(); //temporarily store snake head

    switch (myDir) //move direction
    {
        case UP: //if going up
            if (tempHead.pos->y == 1){  //if at edge of board
                tempHead.pos->y = ySize - 2; //go to bottom of board
            }
            else {
                tempHead.pos->y -= 1; //otherwise decrement position by 1
            }
            
            break;

        case DOWN: //if going down
            if (tempHead.pos->y == ySize - 2){ //if at edge of board
                tempHead.pos->y = 1; //go to top of board
            }
            else {
                tempHead.pos->y += 1; //increase position by 1
            }
            
            break;

        case LEFT: //if going left
            if (tempHead.pos->x == 1){ //if at edge of board
                tempHead.pos->x = xSize - 2; //go to left side of board
            }
            else {
                tempHead.pos->x -= 1; //otherwise decrement position by 1
            }
            
            break;

        case RIGHT: //if going right
            if (tempHead.pos->x == xSize - 2){ //if at edge of board
                tempHead.pos->x = 1; //go to right side of board
            }
            else {
                tempHead.pos->x += 1; //otherwise increment position by 1
            }
    
            break;

        default: //default case
                break;
    }


   playerPosList -> insertHead(tempHead); //temporary head position

   if (checkSelfCollision() == true){ //if snake collided with itself
        mainGameMechsRef -> setLoseFlag(); //set lose flag to true
        mainGameMechsRef -> setExitTrue(); //exit flag true
   }

   objPosArrayList* food = mainFoodRef -> getFoodPos(); //temporary food position

   for (int i= 0; i< food ->getSize(); i++){ //iterate through all items in food array

        objPos tempFood = food -> getElement(i); //get current food element

       if (tempHead.isPosEqual(&tempFood)){ //if there was a collision

            collisionFood = true; //set collision with food to true

            if (food ->getElement(i).getSymbol() == '*'){ //if collided with special food

                for (int x = 0; x < 4; x++){ 
                    mainGameMechsRef -> incrementScore(); //increment score by 5
                }
                
            }

            else{
                mainGameMechsRef -> incrementScore(); //if normal food increment score by 1
            }

        }
   }


    if (collisionFood){ 
        mainFoodRef -> generateFood(playerPosList); //if collided with food generate new food positions
    }

    else if (!collisionFood){
        playerPosList -> removeTail(); //if no collision remove tail
    }

}

// More methods to be added


bool Player::checkSelfCollision() { //self collision function

    for (int i=1; i< playerPosList->getSize() ; i++){ //iterate through position in snake array

        if (((playerPosList -> getHeadElement().pos->x) == (playerPosList -> getElement(i).pos->x)) && ((playerPosList -> getHeadElement().pos->y) == (playerPosList -> getElement(i).pos->y))){
            return true; //if head element is equal to other position in array return true
        }

    }

    return false; //if head element was not equal to another position in array return false
}