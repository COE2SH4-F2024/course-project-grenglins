//Include libraries
#include "objPos.h"

//Default constructor
objPos::objPos()
{
    pos = new Pos; //Create new struct
    pos->x = 0; //Set x value to 0 
    pos->y = 0; //Set y value to 0 
    symbol = 0; //Set symbol to NULL character
}

//Constructor 
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos; //Create new struct 
    pos->x = xPos; //Set x value to xPos 
    pos->y = yPos; //Set y value to yPos
    symbol = sym; //Set symbol to sym 
}

//Destructor
objPos :: ~objPos()
{
    delete pos; //Delete pos 
}


//Copy constructor 
objPos::objPos(const objPos &other)
{
    pos = new Pos; //Create new struct 

    pos->x = other.pos->x; //Set x vaule to x value of other 
    pos->y = other.pos->y; //Set y vaule to y value of other
    symbol = other.symbol; //Set symbol to symbol of other

}

//Copy Assignment
objPos &objPos:: operator =(const objPos &other)
{
    //Check to see if both objPos are equal 
    if (this == &other)
    {
        return *this;
    }

    delete pos; //delete pos

    pos = new Pos;//Create new pos struct 
    
    pos->x = other.pos->x;//Set x value to other x value 
    pos->y = other.pos->y;//Set y value to other y value 
    symbol = other.symbol;//Set symbol to other symbol 

    return *this; //return this objPos

}

//Setter method to set the values of this objPos to objPos o 
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}


//Setter method to st value of this objPos to a nex x,y, and symbol value 
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

//Getter method that returns this objPos
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

//Getter that return this objPos symbol
char objPos::getSymbol() const
{
    return symbol;
}

//Boolean that checks whether this objPos is equa to refPos objPos 
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

//Check if this objPos is equal to the refPos objPos, returns symbol of this objPos
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}