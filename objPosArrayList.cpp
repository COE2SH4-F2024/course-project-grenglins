#include "objPosArrayList.h"
#include "objPos.h"
#include <stdexcept>

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList() //default constructor
{
    aList = new objPos[200]();
    listSize = 0;
    arrayCapacity = 200;
}

objPosArrayList::objPosArrayList(const objPosArrayList& other) //copy constructor
{
    listSize = other.listSize;
    arrayCapacity = other.arrayCapacity;
    aList = new objPos[arrayCapacity];
    for (int i = 0; i < listSize; ++i) {
        aList[i] = other.aList[i];
    }
}

objPosArrayList& objPosArrayList::operator=(const objPosArrayList& other) //copy assignment
{
    if (this != &other) {
        delete[] aList;

        listSize = other.listSize;
        arrayCapacity = other.arrayCapacity;
        aList = new objPos[arrayCapacity];
        for (int i = 0; i < listSize; ++i) {
            aList[i] = other.aList[i];
        }
    }
    return *this;
}

objPosArrayList::~objPosArrayList() //clean up
{
    delete[] aList;
}

int objPosArrayList::getSize() const //return number of elements in list
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos) //insert objPos at start of list
{
    if(listSize >= arrayCapacity) return;
    
    for(int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i - 1];
    }
    
    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos) //insert objPos at end of list
{
    if(listSize >= arrayCapacity) 
    {
        throw std::out_of_range("Index out of bounds");
    }

    aList[listSize++] = thisPos;
}

void objPosArrayList::removeHead() //remove first element from list
{
    if (listSize <= 0){
        throw std::out_of_range("Index out of bounds");
    }

    for(int i = 0; i < listSize - 1; i++) {
        aList[i] = aList[i + 1];
    }
    
    listSize--;
}

void objPosArrayList::removeTail() //remove last element from list
{
    if(listSize > 0)
        listSize--;
}

objPos objPosArrayList::getHeadElement() const //return first element in list
{
    if (listSize <= 0){
        throw std::out_of_range("Index out of bounds");
    }
    return aList[0];
}

objPos objPosArrayList::getTailElement() const //return last element in list
{
    if (listSize <= 0){
        throw std::out_of_range("Index out of bounds");
    }
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const //return element at index
{
    if(index < 0) {
        index = 0;  
    }
    else if (index >= arrayCapacity) {
        index = listSize - 1;
    }

    return aList[index];
}

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
