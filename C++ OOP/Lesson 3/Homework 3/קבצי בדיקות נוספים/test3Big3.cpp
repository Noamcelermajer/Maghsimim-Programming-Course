#include "Vector.h"
#include <windows.h> // WinApi header - needed for setting console color
#include <random>
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


// gets a random number between a range of numbers
int getRandomInt(int min, int max)
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

	auto random_integer = uni(rng);
	return random_integer;
}

std::string getVectorString(const Vector& v)
{
	return
		"[capacity: " + std::to_string(v.capacity()) +
		", size: " + std::to_string(v.size()) +
		", resize factor: " + std::to_string(v.resizeFactor()) + "]";
}

void addRandomElementsToVector(Vector& v, const int numberOfElements)
{
	int element;
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		element = getRandomInt(0, 100000);
		v.push_back(element);
	}
}

void addElementsToVector(Vector& v, const int elements[], const int numberOfElements)
{
	int element;
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		v.push_back(elements[i]);
	}
}

bool test3Big3()
{
	bool result = false;

	try
	{
		// Tests Ex3 part 3 - Big 3

		set_console_color(LIGHT_BLUE);
		cout <<
			"******************************\n" <<
			"Test 3 - Copy CTOR, operator= \n" <<
			"******************************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Initializing Vector v1 with n=5 ... \n" << endl;

		Vector v1(5);

		cout <<
			"Adding 10 elements to vector v1 (1,2, ... ,10) ... \n" << endl;

		const int v1elements[] = { 1,2,3,4,5,6,7,8,9,10 };
		addElementsToVector(v1, v1elements, 10);

		cout <<
			"Initializing Vector v2 with n=7 ... \n" << endl;

		Vector v2(7);

		cout <<
			"Adding 10 elements to vector v2 (11,22, ... ,99,110) ... \n" << endl;

		const int v2elements[] = { 11,22,33,44,55,66,77,88,99,110 };
		addElementsToVector(v2, v2elements, 10);



		std::string expected = "v1: [capacity: 10, size: 10, resize factor: 5]\n";
		expected += "v2: [capacity: 14, size: 10, resize factor: 7]";
		std::string got = "v1: " + getVectorString(v1) + "\nv2: " + getVectorString(v2);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function push_back()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"Initializing Vector v3, using copy constructor with v1 ... \n" << endl;

		Vector v3(v1);

		expected = "v1: [capacity: 10, size: 10, resize factor: 5]\n";
		expected += "v3: [capacity: 10, size: 10, resize factor: 5]";
		got = "v1: " + getVectorString(v1) + "\nv3: " + getVectorString(v3);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check copy constructor - Vector(const Vector&)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nadding 3 elements to v3 ... \n" << endl;
		addRandomElementsToVector(v3, 3);

		expected = "v1: [capacity: 10, size: 10, resize factor: 5]\n";
		expected += "v3: [capacity: 15, size: 13, resize factor: 5]";
		got = "v1: " + getVectorString(v1) + "\nv3: " + getVectorString(v3);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"Are you are doing deep or shallow copy?\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\ncopying v2 to v1, using operator= (v1 = v2) ... \n" << endl;
		v1 = v2;

		expected = "v1: [capacity: 14, size: 10, resize factor: 7]\n";
		expected += "v2: [capacity: 14, size: 10, resize factor: 7]";
		got = "v1: " + getVectorString(v1) + "\nv2: " + getVectorString(v2);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check operator= \n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nadding 9 elements to v2 ... \n" << endl;
		addRandomElementsToVector(v2, 9);

		expected = "v1: [capacity: 14, size: 10, resize factor: 7]\n";
		expected += "v2: [capacity: 21, size: 19, resize factor: 7]";
		got = "v1: " + getVectorString(v1) + "\nv2: " + getVectorString(v2);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"Are you are doing deep or shallow copy?\n";
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
	std::cout << "\n########## Big 3 - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}

int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"###################\n" <<
		"Exercise 3 - Vector\n" <<
		"Part 3 - Big 3 \n" <<
		"###################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test3Big3();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex3 Part3 Tests Passed!!! ##########" << "\n\n";
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