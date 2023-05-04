#include "Vector.h"
#include <windows.h> // WinApi header - needed for setting console color
#include <iostream>
#include <string>

using std::cout;
using std::endl;

#define GREEN 2
#define DARK_RED 4
#define PURPLE 5
#define YELLOW 6
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define TEAL 11
#define RED 12
#define PURPLE 13
#define LIGHT_YELLOW 14
#define WHITE 15

void set_console_color(unsigned int color)
{
	// colors are 0=black 1=blue 2=green and so on to 15=white
	// colorattribute = foreground + background * 16
	// to get red text on yellow use 4 + 14*16 = 228
	// light red on yellow would be 12 + 14*16 = 236
	// a Dev-C++ tested console application by vegaseat 07nov2004

	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

std::string getVectorString(const Vector& v)
{
	return
		"[capacity: " + std::to_string(v.capacity()) +
		", size: " + std::to_string(v.size()) +
		", resize factor: " + std::to_string(v.resizeFactor()) + "]";
}

bool test1Basic()
{
	bool result = false;

	try
	{
		// Tests Ex3 part 1 - Vector Constructor and Destructor

		set_console_color(TEAL);
		cout <<
			"********************\n" <<
			"Test 1 - CTOR, DTOR \n" <<
			"********************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Initializing Vector v1 with n=10: ... \n" << endl;

		Vector v1(10);
		std::string expected = "[capacity: 10, size: 0, resize factor: 10]";
		std::string got = getVectorString(v1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Vector information is not as expected\n" <<
				"check functions Vector(int n), capacity(), size(), resizeFactor()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nChecking if v1 is empty ... " << endl;


		expected = "true";
		got = v1.empty() ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: A new Vector should be empty\n" <<
				"check function empty()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing Vector v2 with n=1 ... \n" << endl;

		Vector v2(1);
		expected = "[capacity: 2, size: 0, resize factor: 2]";
		got = getVectorString(v2);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Vector information is not as expected\n" <<
				"check functions Vector(int n), capacity(), size(), resizeFactor()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nChecking if v2 is empty ... " << endl;


		expected = "true";
		got = v2.empty() ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: A new Vector should be empty\n" <<
				"check function empty()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing Vector v3 with n=-42 ... \n" << endl;

		Vector v3(-42);
		expected = "[capacity: 2, size: 0, resize factor: 2]";
		got = getVectorString(v2);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Vector information is not as expected\n" <<
				"check functions Vector(int n), capacity(), size(), resizeFactor()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nChecking if v3 is empty ... " << endl;


		expected = "true";
		got = v3.empty() ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: A new Vector should be empty\n" <<
				"check function empty()\n";
			set_console_color(WHITE);
			return false;
		}
	}
	catch (...)
	{
		set_console_color(RED);
		std::cerr << "Test crashed" << endl;
		std::cout << "FAILED: The program crashed, check the following things:\n" <<
			"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" <<
			"3. Did you remember to initialize array before accessing it?";
		set_console_color(WHITE);
		return false;
	}

	set_console_color(LIGHT_GREEN);
	cout << "\n########## CTOR & DTOR - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"###########################\n" <<
		"Exercise 3 - Vector\n" <<
		"Part 1 - CTOR & DTOR\n" <<
		"###########################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test1Basic();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex3 Part 1 Tests Passed!!! ##########" << "\n\n";
		set_console_color(WHITE);
	}
	else
	{
		set_console_color(DARK_RED);
		std::cout << "\n########## TEST Failed :( ##########\n";
		set_console_color(WHITE);
	}
	return testResult ? 0 : 1;
}