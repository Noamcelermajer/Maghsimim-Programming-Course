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

std::string getPoppedElementsString(Vector& v, const int numberOfElements)
{
	std::string result = "";
	int element;
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		element = v.pop_back();
		if (element < 0)
		{
			return "ERROR " + std::to_string(element);
		}
		result += std::to_string(element);
	}
	return result;
}

bool test2AddElements()
{
	bool result = false;

	try
	{
		// Tests Ex3 part 2 - push_back(), pop_back(), reserve()

		set_console_color(PURPLE);
		cout <<
			"********************************************\n" <<
			"Test 2 - push_back(), pop_back(), reserve() \n" <<
			"********************************************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Initializing Vector v1 with n=5 ... \n" << endl;

		cout <<
			"Adding 3 elements to vector v1 ... \n" << endl;

		Vector v1(5);
		addRandomElementsToVector(v1, 3);

		std::string expected = "[capacity: 5, size: 3, resize factor: 5]";
		std::string got = getVectorString(v1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << std::endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function push_back()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nChecking if v1 is empty ... " << endl;


		expected = "false";
		got = v1.empty() ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << std::endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Vector v1 should NOT be empty\n" <<
				"check function empty()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nAdding 3 more elements to vector v1 ... \n" << endl;
		addRandomElementsToVector(v1, 3);

		expected = "[capacity: 10, size: 6, resize factor: 5]";
		got = getVectorString(v1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << std::endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function push_back(), resize(), reserve()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nAdding 24 more elements to vector v1 ... \n" << endl;
		addRandomElementsToVector(v1, 24);

		expected = "[capacity: 30, size: 30, resize factor: 5]";
		got = getVectorString(v1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << std::endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check functions push_back(), resize(), reserve()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nPopping 20 elements from vector ... \n" << endl;
		getPoppedElementsString(v1, 20);

		expected = "[capacity: 30, size: 10, resize factor: 5]";
		got = getVectorString(v1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << std::endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function pop_back()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nChecking if v1 is empty ... " << endl;

		expected = "false";
		got = v1.empty() ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << std::endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function empty()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nPopping 10 elements from vector ... \n" << endl;
		getPoppedElementsString(v1, 10);

		expected = "[capacity: 30, size: 0, resize factor: 5]";
		got = getVectorString(v1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << std::endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function pop_back()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nChecking if v1 is empty ... " << endl;

		expected = "true";
		got = v1.empty() ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << std::endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function empty()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nPopping one more element from vector ... \n" << endl;

		expected = "ERROR -9999";
		got = getPoppedElementsString(v1, 1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << std::endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function pop_back()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing Vector v2 with n=5 ... \n" << endl;

		Vector v2(5);

		cout <<
			"\ncalling v2.reserve(23) ... \n" << endl;

		v2.reserve(23);

		expected = "[capacity: 25, size: 0, resize factor: 5]";
		got = getVectorString(v2);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << std::endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function reserve()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\ncalling v2.reserve(12) ... \n" << endl;

		v2.reserve(12);

		expected = "[capacity: 25, size: 0, resize factor: 5]";
		got = getVectorString(v2);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << std::endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function reserve()\n";
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
	std::cout << "\n########## push_back() , pop_back() , reserve() - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}

int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"########################################\n" <<
		"Exercise 3 - Vector\n" <<
		"Part 2 - push_back, pop_back, reserve() \n" <<
		"#########################################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test2AddElements();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex3 Part 2 Tests Passed!!! ##########" << "\n\n";
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

