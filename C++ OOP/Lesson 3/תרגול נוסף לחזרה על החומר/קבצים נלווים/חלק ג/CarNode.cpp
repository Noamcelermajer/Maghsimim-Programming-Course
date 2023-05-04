#include "CarNode.h"

CarNode::CarNode(const Car car): _data(car), _next(nullptr) {}

CarNode* CarNode::getNext() const{return this->_next;}
Car CarNode::getData() const{return this->_data;}

void CarNode::setNext(CarNode *next){this->_next = next;}
void CarNode::setData(const Car car){this->_data = car;}