#include "Player.h"
#include <iostream>
#include "MacUILib.h"
#include "GameMechs.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = UP;

    // more actions to be included

    playerPos.pos->x = (mainGameMechsRef -> getBoardSizeX()) / 2; //initialize player position and character
    playerPos.pos->y = (mainGameMechsRef -> getBoardSizeY()) / 2;
    playerPos.symbol = '@';
}


Player::~Player()
{
    // delete any heap members here
    
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
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

    switch (myDir) //move direction
    {
        case UP:
            if (playerPos.pos->y == 1){
                playerPos.pos->y = ySize - 1;
            }
            else {
                playerPos.pos->y -= 1;
            }
            
            break;

        case DOWN:
            if (playerPos.pos->y == ySize - 1){
                playerPos.pos->y = 1;
            }
            else {
                playerPos.pos->y += 1;
            }
            
            break;

        case LEFT:
            if (playerPos.pos->x == 1){
                playerPos.pos->x = xSize - 1;
            }
            else {
                playerPos.pos->x -= 1;
            }
            
            break;

        case RIGHT:
            if (playerPos.pos->x == xSize - 1){
                playerPos.pos->x = 1;
            }
            else {
                playerPos.pos->x += 1;
            }
            
            break;
    }
}

// More methods to be added


void Player:: printDir (){
    cout << myDir << "\n";
}