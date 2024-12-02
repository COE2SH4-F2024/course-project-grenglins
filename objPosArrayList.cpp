#include "objPosArrayList.h" //include statements
#include "objPos.h"
#include <stdexcept>


objPosArrayList::objPosArrayList() //default constructor
{
    aList = new objPos[ARRAY_MAX_CAP](); //initialize 200 spaces in array
    listSize = 0; //set size to 0
    arrayCapacity = ARRAY_MAX_CAP; //set capacity to 200
}

objPosArrayList::objPosArrayList(const objPosArrayList& other) //copy constructor
{
    listSize = other.listSize; //copy size and capacity
    arrayCapacity = other.arrayCapacity;

    aList = new objPos[arrayCapacity]; //create new list

    for (int i = 0; i < listSize; ++i) { //initialize values to copy other list
        aList[i] = other.aList[i];
    }
}

objPosArrayList& objPosArrayList::operator=(const objPosArrayList& other) //copy assignment
{
    if (this != &other) { //if not the same

        delete[] aList; //delete list

        listSize = other.listSize; //initialize new list
        arrayCapacity = other.arrayCapacity;
        aList = new objPos[arrayCapacity];

        for (int i = 0; i < listSize; ++i) { //copy list
            aList[i] = other.aList[i];
        }
    }

    return *this; //return
}

objPosArrayList::~objPosArrayList() //clean up
{
    delete[] aList; //delete list
}

int objPosArrayList::getSize() const //return number of elements in list
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos) //insert objPos at start of list
{
    if(listSize >= arrayCapacity) return; //if size is already at capacity
    
    for(int i = listSize; i > 0; i--) //iterate through entire list from last element
    {
        aList[i] = aList[i - 1]; //set current element to previous element
    }
    
    aList[0] = thisPos; //set first element to given objPos

    listSize++; //increment list size by 1
}

void objPosArrayList::insertTail(objPos thisPos) //insert objPos at end of list
{
    if(listSize >= arrayCapacity) //if array is at capacity
    {
        throw std::out_of_range("Index out of bounds"); //throw out of bounds error
    }

    aList[listSize++] = thisPos; //make next element given objPos
}

void objPosArrayList::removeHead() //remove first element from list
{
    if (listSize <= 0){ //if list is empty throw out of bounds error
        throw std::out_of_range("Index out of bounds");
    }

    for(int i = 0; i < listSize - 1; i++) { //iterate through list
        aList[i] = aList[i + 1]; //overwrite current element with next element
    }
    
    listSize--; //decrement list size by 1
}

void objPosArrayList::removeTail() //remove last element from list
{
    if(listSize > 0) //if list size is greater than 0
        listSize--; //decrement size by 1

}

objPos objPosArrayList::getHeadElement() const //return first element in list
{
    if (listSize <= 0){ //if empty throw out of bounds error
        throw std::out_of_range("Index out of bounds");
    }

    return aList[0]; //return first item in list
}

objPos objPosArrayList::getTailElement() const //return last element in list
{
    if (listSize <= 0){ //if list is empty throw out of bounds error
        throw std::out_of_range("Index out of bounds");
    }

    return aList[listSize - 1]; //return last element
}

objPos objPosArrayList::getElement(int index) const //return element at index
{
    if(index < 0) { //if index is less than 0 make it 0
        index = 0;  
    }

    else if (index >= arrayCapacity) { //if index is greater than size make index last element's index
        index = listSize - 1;
    }

    return aList[index]; //return element at index
}
