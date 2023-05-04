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


std::string getVectorString(const Vector v)
{
	return
		"[capacity: " + std::to_string(v.capacity()) +
		", size: " + std::to_string(v.size()) +
		", resize factor: " + std::to_string(v.resizeFactor()) + "]";
}

void addElementsToVector(Vector& v, const int elements[], const int numberOfElements)
{
	int element;
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		v.push_back(elements[i]);
	}
}

std::string getVectorElementsString(Vector& v)
{
	std::string result = "";
	for (unsigned int i = 0; i < v.size(); i++)
	{
		result += std::to_string(v[i]) + ",";
	}
	if (v.size() > 0)
		result = result.substr(0, result.length() - 1);
	return result;
}


bool test4()
{
	bool result = false;

	try
	{
		// Tests Ex3 part 4 - operator[] , assign, resize

		set_console_color(YELLOW);
		cout <<
			"************************************\n" <<
			"Test 4 - resize, assign, operator[] \n" <<
			"************************************\n" << endl;
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

		std::string expected = "v1: 1,2,3,4,5,6,7,8,9,10\n";
		expected += "v2: 11,22,33,44,55,66,77,88,99,110";
		std::string got = "v1: " + getVectorElementsString(v1) + "\nv2: " + getVectorElementsString(v2);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function push_back(), access operator[]\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nAccessing element v1[5] ... \n" << endl;

		expected = "6";
		got = std::to_string(v1[5]);
		cout << "Expected:" << expected << endl;
		cout << "Got     :" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check access operator []\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nAccessing element v2[9] ... \n" << endl;

		expected = "110";
		got = std::to_string(v2[9]);
		cout << "Expected:" << expected << endl;
		cout << "Got     :" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check access operator []\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nAccessing element v2[10] ... \n" << endl;

		expected = "11";
		got = std::to_string(v2[10]);
		cout << "Expected:" << expected << endl;
		cout << "Got     :" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check access operator []\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nAccessing element v1[-1] ... \n" << endl;

		expected = "11";
		got = std::to_string(v2[-1]);
		cout << "Expected:" << expected << endl;
		cout << "Got     :" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check access operator []\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing Vector v3, using copy constructor with v1  \n" << endl;

		Vector v3(v1);

		expected = "v1: 1,2,3,4,5,6,7,8,9,10\n";
		expected += "v3: 1,2,3,4,5,6,7,8,9,10";
		got = "v1: " + getVectorElementsString(v1) + "\nv3: " + getVectorElementsString(v3);
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
			"\ncopying v2 to v3, using operator= (v3 = v2) ... \n" << endl;
		v3 = v2;

		expected = "v2: 11,22,33,44,55,66,77,88,99,110\n";
		expected += "v3: 11,22,33,44,55,66,77,88,99,110";
		got = "v2: " + getVectorElementsString(v2) + "\nv3: " + getVectorElementsString(v3);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check operator=\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\ncalling v1.assign(999)... \n" << endl;
		v1.assign(999);
		expected = "v1: 999,999,999,999,999,999,999,999,999,999";
		got = "v1: " + getVectorElementsString(v1);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function assign()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\ncalling v2.resize(15, 1234)... \n" << endl;
		v2.resize(15, 1234);
		expected = "v2: 11,22,33,44,55,66,77,88,99,110,1234,1234,1234,1234,1234";
		got = "v2: " + getVectorElementsString(v2);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check function resize(int n,int &val)\n";
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
	std::cout << "\n########## operator[], resize(), assign() - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}

int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"###################\n" <<
		"Exercise 3 - Vector\n" <<
		"Part 4 - operator[], resize(), assign() \n" <<
		"###################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test4();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex3 Part4 Tests Passed!!! ##########" << "\n\n";
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