#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;
 
#define DELAY_CONST 100000

Player *myPlayer;

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

    myGM = new GameMechs(); //initialize player
    myPlayer = new Player(myGM);


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
   if(input == 'z')
    {
        myGM->incrementScore();
    }
    else if (input == 'x')
    {
        myGM->setLoseFlag();
        myGM->setExitTrue();

    }

}

void RunLogic(void)
{
    myPlayer -> updatePlayerDir(); //update direction
    myPlayer -> movePlayer(); //move direction
    
    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    //implement copy assignment operator to make this work
    //ok buddy
    objPos playerPos = myPlayer -> getPlayerPos();
    MacUILib_printf("Player[x,y] = [%d,%d], %c\n",playerPos.pos->x, playerPos.pos->y, playerPos.symbol);

    for(int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for(int j = 0; j < myGM->getBoardSizeX(); j++)
        {
            if(i == 0 || i == (myGM->getBoardSizeY() - 1) || j == 0 || j == (myGM->getBoardSizeX() - 1))
            {
                MacUILib_printf("#");
            }
            else if ((i == playerPos.pos->y) && (j == playerPos.pos->x)){
                MacUILib_printf("%c", playerPos.symbol);
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
    myPlayer -> printDir();
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
    
    delete myPlayer;

    MacUILib_uninit();
}
