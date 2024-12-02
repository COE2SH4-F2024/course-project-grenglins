#include <iostream> //include io

#include "MacUILib.h" //include libraries
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std; //saving namespace
 
#define DELAY_CONST 100000 //initialize delay constant

Player *myPlayer; //initialize variables
GameMechs *myGM;
Food *myFood;


void Initialize(void); //declare functions
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void) //main
{
    srand(time(NULL)); //time variation line

    Initialize(); //call initialize

    while(myGM->getExitFlagStatus() == false)   //if not exit flag
    {
        GetInput(); //run functions
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp(); //call clean up

}


void Initialize(void) //initialize
{
    MacUILib_init(); 
    MacUILib_clearScreen(); //clear screen

    myGM = new GameMechs(); //initialize variables
    myFood = new Food();
    myPlayer = new Player(myGM, myFood);

    myFood->generateFood(myPlayer -> getPlayerPos()); //generate food items

}

void GetInput(void)
{
   myGM->collectAsyncInput(); //read in
}

void RunLogic(void)
{
    myPlayer -> updatePlayerDir(); //update direction
    myPlayer -> movePlayer(); //move direction
    
    myGM->clearInput(); //clear input
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   //clear screen

    objPosArrayList* foodPos = myFood->getFoodPos(); //get food and player pos
    objPosArrayList* playerPos = myPlayer -> getPlayerPos();
    
    int playerSize = playerPos->getSize(); //get size of player and food arrays
    int foodSize = foodPos ->getSize();
    
    int boardX = myGM->getBoardSizeX(); //collect board size
    int boardY = myGM->getBoardSizeY();

    bool printed = false; //set boolean for printed to false

    for(int i = 0; i < boardY; i++) //iterate through board
    {
        for(int j = 0; j < boardX; j++)
        {
            printed = false; //set printed to false

           for (int k = 0; k<playerSize; k++){ //iterate through player list

                objPos thisSeg = playerPos -> getElement(k);

                if (((thisSeg.pos -> x) == j) && ((thisSeg.pos -> y) == i)){ //if there is a player at pos
                    MacUILib_printf("%c", thisSeg.symbol); //print
                    printed = true; //set bool to true
                    break;
                }

            }

            for (int k = 0; k< foodSize; k++){ //iterate through food list

                objPos thisSeg = foodPos -> getElement(k);

                if (((thisSeg.pos -> x) == j) && ((thisSeg.pos -> y) == i)){ //if there is a food at pos
                    MacUILib_printf("%c", thisSeg.symbol); //print food
                    printed = true; //set bool to true
                }

            }

            if (!printed){ //if nothing has been printed

                if(i == 0 || i == (boardY - 1) || j == 0 || j == (boardX - 1)) //if edge of board
                {
                    MacUILib_printf("#"); //print border character
                }

                else
                {
                    MacUILib_printf(" "); //print whitespace
                }

            }

        }
       MacUILib_printf("\n");

    }

    MacUILib_printf("The score is: %d", myGM->getScore()); //print score
    MacUILib_printf("\n");
    
    if(myGM->getLoseFlagStatus() == true && myGM -> getExitFlagStatus() == true) //if player lost
    {
        MacUILib_printf("You lose, L bozo"); //lose message
    }

    else if (myGM -> getExitFlagStatus() == true) //if player exited game
    {
        MacUILib_printf("You exited the game, bozo"); //exit message
    
    }

}

void LoopDelay(void) 
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();    

    delete myGM; //delete heap members
    delete myPlayer;
    delete myFood;

    MacUILib_uninit();
}
