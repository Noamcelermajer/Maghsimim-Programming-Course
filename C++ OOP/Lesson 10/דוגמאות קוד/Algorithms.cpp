#include <iostream> 
#include <vector> 
#include <algorithm>
#include <thread>

using std::cout;
using std::endl;

void printVec(const std::vector<int>& v)
{
	int i ;
	for (i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << endl;
}

int main()
{
	char alpha[] = "abcdefghijklmnopqrstuvwxyz";
	cout << "Before rotation: " << alpha << endl;
	std::rotate(alpha, alpha + 3, alpha + 6); // swap the 4th char with 1st char, sawp the 5th char with 2nd char, swap the 6th char with 3rd char
	cout << "After rotation: " << alpha << endl;

	std::vector<int> vec({ 1, 12, 31, 96, 3,34, 99,223, -2, -3 });
	printVec(vec);

	std::random_shuffle(vec.begin()+1, vec.end());
	printVec(vec);

	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::random_shuffle(vec.begin()+1, vec.end());
	printVec(vec);

	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::random_shuffle(vec.begin() + 1, vec.end());
	printVec(vec);

	system("PAUSE");
	system("CLS");

	return 0;


}