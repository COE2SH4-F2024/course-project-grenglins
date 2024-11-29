#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

    playerPos.pos->x = 5; //initialize player position and character
    playerPos.pos->y = 5;
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
    
    char input = mainGameMechsRef -> getInput();

    switch(input){
        case 'w':
                if (myDir == LEFT || myDir == RIGHT){
                    myDir = UP;
                }
    
                break;

            case 's':
                if (myDir == LEFT || myDir == RIGHT){
                    myDir = DOWN;
                }
 
                break;

            case 'a':
                if (myDir == UP || myDir == DOWN){
                    myDir = LEFT;
                }
                break;
            
            case 'd':
                if (myDir == UP || myDir == DOWN){
                    myDir = RIGHT;
                }
                break;

            default:
                break;
    }       
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added