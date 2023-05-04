
#include <iostream>
#include <thread>

using std::cout;
using std::endl;

int global_arr[2];

void fact(int from, int to)
{
	static int place = 0;
	int result = 1;

	
	for (int i = from; i <= to; i++)
	{
		result *= i;
	}

	global_arr[place] = result;
	place++;
}

int  main() 
{
	std::thread t1(fact, 1, 3);
	std::thread t2(fact, 4, 6);


	t1.join();	// wait for thread t1 to finish before advancing to the next line
	t2.join();	// wait for thread t2 to finish before advancing to the next line


	// t1 & t2 are now running simultaneously
	cout << endl << "The fact is: " << global_arr[0] * global_arr[1] << endl;

	system("PAUSE");
	return 0;
}