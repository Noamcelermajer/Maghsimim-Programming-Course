#include "Vector.h"
#include <windows.h> // WinApi header - needed for setting console color
#include <iostream>
#include <sstream>
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

std::string getStreamOperatorString(Vector& v)
{
	std::stringstream ss;
	ss << v;
	return ss.str();
}

bool testBonus()
{
	bool result = false;

	try
	{
		// Tests Ex3 Bonus - More operators
		set_console_color(94);
		cout <<
			"************************************\n" <<
			"Test Bonus - operators +,+=,-,-=,<< \n" <<
			"************************************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Initializing Vector v1 with n=5 ... \n" << endl;

		Vector v1(5);

		cout <<
			"Adding 3 elements to vector v1 (20,30,40) ... \n" << endl;

		const int v1elements[] = { 20,30,40 };
		addElementsToVector(v1, v1elements, 3);

		cout <<
			"Initializing Vector v2 with n=5 ... \n" << endl;

		Vector v2(5);

		cout <<
			"Adding 3 elements to vector v2 (2,3,4) ... \n" << endl;

		const int v2elements[] = { 2,3,4 };
		addElementsToVector(v2, v2elements, 3);

		std::string expected = "v1: 20,30,40\n";
		expected += "v2: 2,3,4";
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
			"\nInitializing Vector v3, using operator+ with v1 and v2\n" <<
			"Vector v3 = v1 + v2" << endl;
		Vector v3 = v1 + v2;

		expected = "v1: 20,30,40\n";
		expected += "v2: 2,3,4\n";
		expected += "v3: 22,33,44";
		got = "v1: " + getVectorElementsString(v1) + "\nv2: "
			+ getVectorElementsString(v2) + "\nv3: " + getVectorElementsString(v3);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check operator +\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nUsing operator+= with v3 and v2\n" <<
			"v3 += v2" << endl;
		v3 += v2;
		expected = "v2: 2,3,4\n";
		expected += "v3: 24,36,48";
		got = "v2: " + getVectorElementsString(v2) + "\nv3: " + getVectorElementsString(v3);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check operator +=\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing Vector v4, using operator- with v1 and v2\n" <<
			"Vector v4 = v1 - v2" << endl;
		Vector v4 = v1 - v2;

		expected = "v1: 20,30,40\n";
		expected += "v2: 2,3,4\n";
		expected += "v4: 18,27,36";
		got = "v1: " + getVectorElementsString(v1) + "\nv2: "
			+ getVectorElementsString(v2) + "\nv4: " + getVectorElementsString(v4);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check operator -\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nUsing operator-= with v4 and v1\n" <<
			"v4 -= v1" << endl;
		v4 -= v1;
		expected = "v1: 20,30,40\n";
		expected += "v4: -2,-3,-4";
		got = "v1: " + getVectorElementsString(v1) + "\nv4: " + getVectorElementsString(v4);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check operator -=\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nUsing operator<< with v1\n" <<
			"std::cout << v1" << endl;
		expected = "Vector info:\nCapacity is 5\nSize is 3\n{20,30,40}\n";
		got = getStreamOperatorString(v1);
		cout << "Expected:\n" << expected << endl;
		cout << "Got     :\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Vector information is not as expected\n" <<
				"check operator << and make sure to follow string format\n";
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
	std::cout << "\n########## operators + , += , - , -= , << - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}

int main()
{
	std::cout <<
		"###################\n" <<
		"Exercise 3 - Vector\n" <<
		"Bonus - more operators \n" <<
		"###################\n" << std::endl;

	bool testResult = testBonus();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex3 Bonus Tests Passed!!! ##########" << "\n\n";
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