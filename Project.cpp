#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;
//sussy wussy 
#define DELAY_CONST 100000

Player *myPlayer;

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    myPlayer = new Player(nullptr);

    exitFlag = false;

}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    //implement copy assignment operator to make this work
    //ok buddy
    objPos playerPos = myPlayer -> getPlayerPos();
    MacUILib_printf("Player[x,y] = [%d,%d], %c\n", 
    playerPos.pos->x, playerPos.pos->y, playerPos.symbol);

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(i == 0 || i == 9 || j == 0 || j == 19 )
            {
                MacUILib_printf("#");
            }
            else if ((i == playerPos.pos->x) && (j == playerPos.pos->y)){
                MacUILib_printf("%c", playerPos.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
       MacUILib_printf("\n");

    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    delete myPlayer;

    MacUILib_uninit();
}
