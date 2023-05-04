#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::string;

int main(){
	
	std::list<string>* l = new std::list<string>();

	l->push_back("The");
	l->push_back("Sea");
	l->push_front("Under");

	
	string s;
	while (!l->empty())
	{
		s = l->front();
		l->pop_front();
		cout << s + " ";
	}

	delete l;
	cout << std::endl;

	system("PAUSE");
	system("cls");

	std::queue<int, std::list<int>> myQueue;

	myQueue.push(10);
	myQueue.push(25);
	myQueue.push(56);

	while (!myQueue.empty())
	{
		cout << myQueue.front() << " - ";
		myQueue.pop();
	}
	cout << endl;
	system("PAUSE");
	return 0;
}
