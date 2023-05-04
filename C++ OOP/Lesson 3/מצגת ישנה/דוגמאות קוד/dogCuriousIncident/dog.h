#ifndef DOG_H
#define DOG_H

#include <string>
#include <iostream>

using namespace std;

class Dog
{
public:
	Dog(string name , string type, string color);
	Dog(const Dog &doggy);

	string getName();
	string getType();
	string getColor();

	void setName(string name);
	void setType(string type);
	void setColor(string color);

private:
	string _name;
	string _type;
	string _color;

};
#endif /* DOG_H */