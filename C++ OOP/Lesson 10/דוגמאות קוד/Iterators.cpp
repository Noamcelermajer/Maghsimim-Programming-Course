#include <iostream> 
#include <vector> 
#include <map>
#include <set>

using std::cout;
using std::endl;

class myClass
{
};


int main()
{
	std::vector<int> myvector;
	for (int i = 1; i <= 5; i++)
	{
		myvector.push_back(i);
	}

	std::cout << "myvector contains:";
	std::vector<int>::iterator it;
	for (it = myvector.begin(); it != myvector.end(); ++it)
	{
		cout << ' ' << *it << endl;
	}

	system("PAUSE");
	system("CLS");

	std::set<double> mySet;
	mySet.insert(3.2);
	mySet.insert(1.2);
	mySet.insert(2.4);
	mySet.insert(1.2);
	
	std::set<double>::iterator setIt;

	for (setIt = mySet.begin(); setIt != mySet.end(); setIt++)
	{
		cout << *setIt << ", ";
	}
	
	cout << endl;
	setIt = mySet.find(2.4);
	if (setIt != mySet.end())
	{
		cout << "2.4 exist" << endl;
	}
	else
	{
		cout << "2.4 not exist" << endl;
	}

	setIt = mySet.find(2.9);
	if (setIt != mySet.end())
	{
		cout << "2.9 exist" << endl;
	}
	else
	{
		cout << "2.9 not exist" << endl;
	}

	setIt = mySet.find(2.4);
	// (*setIt) = 2.5; // Compilation Error!!!


	// ** example with auto ** 

	std::map<std::string, myClass*> myMap;
	// instead of writing std::map<std::string, myClass*>::iterator
	for (auto it = myMap.begin(); it != myMap.end(); it++)
	{
		cout << "first: " << it->first  << endl;
	}

	system("PAUSE");
	system("CLS");

	return 0;
}