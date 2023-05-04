#include <iostream>
#include <thread>

using std::cout;


void function1()
{
	int i;
	for (i = 0; i < 100; ++i)
	{
		cout << "**** " ;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void function2()
{
	int i;
	for (i = 0; i < 100; ++i)
	{
		cout << "---- " ;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

int main() 
{
	std::thread t1(function1); 
	// at this point thread t1 is running

	std::thread t2(function2);
	// at this point thread t2 is running


	t1.join(); // wait until t1 will end
	t2.join(); // wait until t2 will end

	system("pause");
	return 0;
}