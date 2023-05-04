#include "CarNode.h"

class CarList
{
    public: 

        CarList();

        // copy constructor
        CarList(const CarList& other);

        // copy operator
        CarList& operator=(const CarList& other);

        // getters
        CarNode *getFirst() const;
        unsigned int getSize() const;

        // setters
        void setFirst(CarNode *first);

        // returns true if carToFind is in the list
        bool find(const Car& carToFind) const;

        /** adds a car to the end of the car list
         * returns true if car added successfully, false otherwise **/
        void add(const Car carToAdd);

        /** removes a car from the car list
         * returns true if the car removed successfully, false otherwise **/
        bool remove(const Car carToRemove);


        /** the following methods need to be implemented */
        // ***************************************************
        // prints the most expansive car
        void printMostExpansive() const;

        // returns the number of red cars in CarList
        int numOfRedCars() const;

        // returns the number of cars owned by the given owner
        int numOfOwnerCars(const std::string owner) const;

        // prints all cars in the list
        void print() const;

        // prints all cars that their car module begins with the given char
        void printByModule(const char c) const;
        // ***************************************************

        
      private:

        CarNode* _first;
        unsigned int _size;
};