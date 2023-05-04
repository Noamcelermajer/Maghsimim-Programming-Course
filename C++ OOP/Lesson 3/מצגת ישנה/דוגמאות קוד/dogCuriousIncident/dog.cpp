#include "dog.h"


Dog ::Dog(string name , string type, string color): _name(name), _type(type), _color(color)
{
}

/****************************
 *This is the important one:
 ****************************/
Dog::Dog(const Dog &doggy)
{
	_name = doggy._name;
	_type = doggy._type;
	_color = doggy._color;

	cout<< "WOOOF! WOOF! DONT COPY ME! WOOF! WOOF!"<<endl; //dog barks whenever copy ctor is called
}

/* Getters */
string Dog :: getName()
{
	return _name;
}
string Dog :: getType()
{
	return _type;
}
string Dog :: getColor()
{
	return _color;
}

/* Setters */
void Dog :: setName(string name)
{
	_name = name;
}
void Dog :: setType(string type)
{
	_type = type;
}
void Dog :: setColor(string color)
{
	_color = color;
}