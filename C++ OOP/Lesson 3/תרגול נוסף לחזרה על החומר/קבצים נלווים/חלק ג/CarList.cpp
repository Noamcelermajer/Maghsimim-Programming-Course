#include "CarList.h"
#include <iostream>
using std::cout;
using std::endl;

#define FIRST_CHAR 0

CarList::CarList(): _first(nullptr), _size(0){}

CarList::CarList(const CarList &other)
{
    *this = other; // using copy operator
}

CarList& CarList::operator=(const CarList &other)
{
    if (&other == this) // tries to copy this to itself
    {
        return *this;   
    }

    // copy fields
    this->_size = other._size;

    // deep copy members - for each CarNode in the other CarList create an independent copy using the 'new' command.

    CarNode* otherCurr = other._first; // otherCurr points to the first element in the other list
    CarNode *thisCurr = new CarNode(otherCurr->getData()); // copies first element from the other list

    while (otherCurr->getNext() != nullptr) // as long as there is an element to copy
    {
        // otherCurr points on the next Node that will be copied.
        otherCurr = otherCurr->getNext();

        // creates an independent node (copies the other node's data)
        thisCurr->setNext(new CarNode(otherCurr->getData()));

        // thisCurr points to the next CarNode
        thisCurr = thisCurr->getNext();  
    }

    return *this;
}

// getters
CarNode *CarList::getFirst() const { return this->_first; }
unsigned int CarList::getSize() const {return this->_size;}

// setters
void CarList::setFirst(CarNode *first) { this->_first = first; }

// returns true if carToFind is in the list
bool CarList::find(const Car &carToFind) const
{
    CarNode* curr = this->_first;
    while(curr != nullptr)
    {
        if(curr->getData() == carToFind)
        {
            return true;
        }
        curr = curr->getNext();
    }
}

/** adds a car to the end of the car list
         * returns true if car added successfully, false otherwise **/
void CarList::add(const Car carToAdd)
{
    if(this->_first == nullptr) // list is empty
    {
        this->_first = new CarNode(carToAdd);  // creates the first node
    }
    else    // list has at least one element
    {
        CarNode* curr = this->_first;       // start from first
        while(curr->getNext() != nullptr)   // advance to the last element
        {
            curr = curr->getNext();
        }

        curr->setNext(new CarNode(carToAdd));   // add a new CarNode at the end of the list
    }
}

/** removes a car from the car list, 
 * if there are two or more cars with that model, deletes the first one.
 * returns true if the car removed successfully, false otherwise 
**/
bool CarList::remove(const Car carToRemove)
{
    if(this->_first == nullptr) // list is empty
    {
        return false;   
    }
    else if (this->_first->getData() == carToRemove) // need to remove first element
    {
        CarNode* temp = this->_first;   
        this->_first = this->_first->getNext();  // the list starts from the next element
        delete temp;    // deletes the original first element
    }
    else
    {
        CarNode *prev = this->_first, *curr= prev->getNext();
        while(curr != nullptr)
        {
            if(curr->getData() == carToRemove)
            {
                prev->setNext(curr->getNext());
                return true;
            }
            prev = prev = prev->getNext();
            curr = prev->getNext();
        }
        return false;  // could not find the car
    }
}