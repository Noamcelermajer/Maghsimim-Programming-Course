
#include <iostream>
#include <thread>

using std::cout;
using std::endl;

long long data;

void writeToLog()
{
	while (true)
	{
		cout << "Log Message. data is " << data << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));  // 3000 miliseconds = 3 seconds
	}

}

int  main()
{

	data = 0;
	std::thread t1(writeToLog);
	t1.detach();	// main thread does not wait for t1 to finish, t1 is detached from the main thread.

	while (data < pow(2,28))
	{
		data++;
	}


	// t1 & t2 are now running simultaneously
	cout << "*************   FINISH   *************" << endl;

	
	system("PAUSE"); // in the original software it wont be here. it's only for now, that we will see what is happening
	return 0;
}