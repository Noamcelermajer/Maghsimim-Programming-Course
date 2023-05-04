#include "Car.h"

class CarNode
{
    public:

        // constructor
        CarNode(const Car car);

        // getters
        CarNode* getNext() const;
        Car getData() const;

        // setters
        void setNext(CarNode* next);        
        void setData(const Car car);

    private:

        Car _data;
        CarNode* _next;
};