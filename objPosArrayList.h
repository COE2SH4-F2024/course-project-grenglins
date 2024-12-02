#ifndef OBJPOS_ARRAYLIST_H //define objPosArrayList class
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200 //set max capacity to 200

#include "objPos.h" //include objPos

class objPosArrayList
{
    private:
        objPos* aList; //initialize variables
        int listSize;
        int arrayCapacity;

    public:
        objPosArrayList(); //constructor
        ~objPosArrayList(); //destructor

        objPosArrayList(const objPosArrayList& other); //copy and copy assignment constructors
        objPosArrayList& operator=(const objPosArrayList& other);

        int getSize() const; //return size

        void insertHead(objPos thisPos); //insert to head or tail
        void insertTail(objPos thisPos);

        void removeHead(); //remove head or tail
        void removeTail();
        
        objPos getHeadElement() const; //get elements
        objPos getTailElement() const;
        objPos getElement(int index) const;
};

#endif