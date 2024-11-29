#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "GameMechs.h"

using namespace std;
 
#define DELAY_CONST 100000


GameMechs *myGM;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs();
    //myPlayer = new Player(myGM);


    


}

void GetInput(void)
{
   char input = myGM->getInput();
   //action 
    if(input == ' ')
    {
        myGM->setExitTrue();
    }

   //debug
   if(myGM->getInput() == 'z')
    {
        myGM->incrementScore();
    }
    else if (myGM->getInput() == 'x')
    {
        myGM->setLoseFlag();
        myGM->setExitTrue();

    }
   myGM->clearInput();
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    for(int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for(int j = 0; j < myGM->getBoardSizeY(); j++)
        {
            if(i == 0 || i == (myGM->getBoardSizeY() - 1) || j == 0 || j == (myGM->getBoardSizeY() - 1))
            {
                MacUILib_printf("#");
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
       MacUILib_printf("\n");

    }

    //Debugging 
    MacUILib_printf("The score is: %d", myGM->getScore());
    MacUILib_printf("\n");
    if(myGM->getLoseFlagStatus() == true)
    {
        MacUILib_printf("You lose, L bozo");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    


    delete myGM;
    
    MacUILib_uninit();
}
