#ifndef PLAYER_H //define player class
#define PLAYER_H

#include "GameMechs.h" //include statements
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public: //public members

        enum Dir {UP, DOWN, LEFT, RIGHT, STOP}; //directions for player

        Player(GameMechs* thisGMRef, Food* foodRef); //construction
        ~Player(); //delete heap memebers

        objPosArrayList* getPlayerPos() const; // Upgrade this in iteration 3.       
        void updatePlayerDir(); //update variable
        void movePlayer(); //moveplayer

        bool checkSelfCollision(); //check self collision

    private: //private members

        objPosArrayList* playerPosList; //player array list
        enum Dir myDir; //direction variable

        GameMechs* mainGameMechsRef; //references to other classes
        Food* mainFoodRef;
};

#endif