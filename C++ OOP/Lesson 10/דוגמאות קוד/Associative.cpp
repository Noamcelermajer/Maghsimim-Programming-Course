#include <iostream>
#include <set>
#include <map>
#include <string>

using std::cout;
using std::endl;


// class that not have operator <
class test
{
public: 
};

int main()
{

	std::set<double> mySet;

	mySet.insert(4.5);
	mySet.insert(3.5);
	mySet.insert(10.5);

	// if want to change
	mySet.erase(3.5);
	mySet.insert(3.2);
	mySet.insert(3.2);

	
	cout << "3.2 exist " << mySet.count(3.2) << " time(s)" << endl;
	cout << "3.5 exist " << mySet.count(3.5) << " time(s)" << endl;

	system("PAUSE");
	system("cls");


	test a;
	std::set<test> testSet;
	// testSet.insert(a); // Compilation error!!! 

	std::multimap<int, std::string> myMutliMap;
	myMutliMap.insert(std::pair<int, std::string>(3, "Car"));

	std::pair<int, std::string> keyVal;
	keyVal.first = 5;
	keyVal.second = "Energy";

	myMutliMap.insert(keyVal);

	cout << "Key=5, Value=" << myMutliMap.find(5)->second << endl;
	std::multimap<int, std::string>::const_iterator it = myMutliMap.find(12);


	system("PAUSE");
	return 0;
}
