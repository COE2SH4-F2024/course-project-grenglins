#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;

        objPos food;

    public:
        GameMechs(); //Defualt Constructor 
        GameMechs(int boardX, int boardY); //COnstructor 
        ~GameMechs(); // Destructor 
        
        bool getExitFlagStatus() const; //Getter Method
        void setExitTrue(); //Setter method
        bool getLoseFlagStatus() const; //Getter Method
        void setLoseFlag(); //Setter method

        char getInput() const; //Getter Method
        void setInput(char this_input); //Setter method
        void clearInput(); //Clear input method 

        int getBoardSizeX() const; //Getter Method
        int getBoardSizeY() const;//Getter Method
        
        int getScore() const; //Getter Method
        void incrementScore(); //Increment score method
        
        void collectAsyncInput();//Collecting input method 
};

#endif