#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"


using namespace std;
 
#define DELAY_CONST 100000

Player *myPlayer;

GameMechs *myGM;

Food *myFood;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{
    srand(time(NULL));

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
    myFood = new Food();
    myPlayer = new Player(myGM, myFood);

    myFood->generateFood(myPlayer -> getPlayerPos());

}

void GetInput(void)
{
   myGM->collectAsyncInput();

   //debug
   char input = myGM->getInput();
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

    objPosArrayList* foodPos = myFood->getFoodPos();
    objPosArrayList* playerPos = myPlayer -> getPlayerPos();
    
    int playerSize = playerPos->getSize();

    //MacUILib_printf("Player[x,y] = [%d,%d], %c\n",playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
    MacUILib_printf("Food[x,y] = [%d,%d], %c\n",foodPos->getHeadElement().pos->x, foodPos->getHeadElement().pos->y, foodPos->getHeadElement().symbol);
    MacUILib_printf("Food[x,y] = [%d,%d], %c\n",foodPos->getTailElement().pos->x, foodPos->getTailElement().pos->y, foodPos->getTailElement().symbol);
    
    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();

    bool printed = false;

    for(int i = 0; i < boardY; i++)
    {
        for(int j = 0; j < boardX; j++)
        {
            printed = false;
            /*
            we now need to iterate through the playerPosArrayList to print
            all segments out
            */
           for (int k = 0; k<playerSize; k++){
                objPos thisSeg = playerPos -> getElement(k);

                if (((thisSeg.pos -> x) == j) && ((thisSeg.pos -> y) == i)){
                    MacUILib_printf("%c", thisSeg.symbol);
                    printed = true;
                }

            }

            if (!printed){
                if(i == 0 || i == (boardY - 1) || j == 0 || j == (boardX - 1))
                {
                    MacUILib_printf("#");
                }
                else if(j == foodPos->getHeadElement().pos->x && i == foodPos->getHeadElement().pos->y)
                {
                    MacUILib_printf("%c", foodPos->getHeadElement().symbol);
                }
                else if(j == foodPos->getTailElement().pos->x && i == foodPos->getTailElement().pos->y)
                {
                    MacUILib_printf("%c", foodPos->getTailElement().symbol);
                }
                else
                {
                    MacUILib_printf(" ");
                }
            }
        }
       MacUILib_printf("\n");

    }

    //Debugging 
    MacUILib_printf("The score is: %d", myGM->getScore());
    MacUILib_printf("\n");
    
    if(myGM->getLoseFlagStatus() == true && myGM -> getExitFlagStatus() == true)
    {
        MacUILib_printf("You lose, L bozo");
    }
    else if (myGM -> getExitFlagStatus() == true)
    {
        MacUILib_printf("You exited the game, bozo");
    
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();    

    delete myGM;
    
    delete myPlayer;

    delete myFood;

    MacUILib_uninit();
}
