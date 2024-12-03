//Include libraries 
#include "GameMechs.h"
#include "MacUILib.h"

//Default cunstructor 
GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 30;
    boardSizeY = 15;
}

//Constructor that takes intvalues to set board size 
GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY; 
}

//Destructor 
GameMechs::~GameMechs()
{
    //Nothign on heap   
}

//Getter methoud that returns boolean value of exitFlag
bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

//Getter methoud that returns boolean value of loseFlag
bool GameMechs::getLoseFlagStatus() const
{
 return loseFlag;
}
    
//Input collection
void GameMechs:: collectAsyncInput()
{
    if(MacUILib_hasChar()) //Check to see if there is new input 
    {
        input = MacUILib_getChar(); //if yes, set input to the char 
    }
    
    if(input == ' ') //If exit key 
    {
        exitFlag = true; //Set exitFlag to true, to exit game
    }
}


//Getter method that returns input 
char GameMechs::getInput() const
{
    return input;
}

//Getter method that returns score 
int GameMechs::getScore() const
{
 return score; 
}

//Method that increments score by 1 
void GameMechs::incrementScore()
{
    score ++;

}

//Getter method that returns boardSizeX
int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

//Getter method that returns boardSizeY
int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

//Setter method to set exitFlag to true 
void GameMechs::setExitTrue()
{
    exitFlag = true; 
}

//Setter method to set loseFlag to true 
void GameMechs::setLoseFlag()
{
    loseFlag = true; 
}

//Setter method to set the input to this_input 
void GameMechs::setInput(char this_input)
{
    input = this_input;
}


//Method to clear current input
void GameMechs::clearInput()
{
    input = 0; 
}

