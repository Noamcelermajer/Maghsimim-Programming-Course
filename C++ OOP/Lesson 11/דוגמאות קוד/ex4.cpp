#include <iostream>
#include <thread>

using std::cout;
using std::endl;


void F() {
	static short counter = 1;
	int ins = counter++; // save instance number

	int i = 10;
	while (i--)
		cout << "Instance #" << ins << " is now running" << endl;

	cout << "Instance #" << ins << " is now exiting..." << endl;
}

int main() {
	std::thread t1(F);
	std::thread t2(F);

	t1.join();
	t2.join();

	// t1 & t2 are now running simultaneously

	system("PAUSE");
	return 0;
}