#ifndef OBJPOS_H
#define OBJPOS_H

//Define the struct Pos
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;        
        char symbol;

        objPos();//Default Constructor 
        objPos(int xPos, int yPos, char sym);//Constructor 

        ~objPos(); //Destructor

        objPos(const objPos &other); //Copy constructor 

        objPos& operator = (const objPos &other); //Copy Assignment operator 
        
        //Setter Methods 
        void setObjPos(objPos o);    
        void setObjPos(int xPos, int yPos, char sym);  

        //Getter Methods 
        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        //Other methods
        bool isPosEqual(const objPos* refPos) const; 
};

#endif