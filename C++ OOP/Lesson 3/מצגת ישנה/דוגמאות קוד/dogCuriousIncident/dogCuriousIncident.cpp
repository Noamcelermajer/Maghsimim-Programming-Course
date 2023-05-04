#include "dog.h"

void dontCopy(Dog d)
{
	Dog newDog("", "", "");

	newDog.setColor(d.getColor());
	newDog.setName(d.getName());
	newDog.setType(d.getType());
}

void main()
{
	Dog oldDog("Rocky", "Lavrador", "Black");
	dontCopy(oldDog);
	
	/*run this and see if the dog barks*/
	system("pause");
}