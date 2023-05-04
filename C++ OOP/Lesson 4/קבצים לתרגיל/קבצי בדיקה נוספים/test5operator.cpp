#include "CaesarText.h"
#include "SubstitutionText.h"
#include <iostream>
#include <windows.h> // WinApi header - needed for setting console color
#include <string>

using std::cout;
using std::endl;

#define GREEN 2
#define BLUE 3
#define DARK_RED 4
#define PURPLE 5
#define YELLOW 6
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define TEAL 11
#define RED 12
#define LIGHT_PURPLE 13
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

bool test5Operator()
{
	bool result = false;

	try
	{
		// Tests Ex4 part 5 - Operator <<

		set_console_color(LIGHT_BLUE);
		cout <<
			"*********************\n" <<
			"Test 5 - Operator <<  \n" <<
			"*********************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Checking Operator << ... \n" << endl;

		cout << "\nInitializing 5 instances\n"
			<< "{PlainText p1, Shiftext s1, PlainText p2, CaesarText c1, SubstitutionText sb1}" 
			<< std::endl;
			
		PlainText p1("blabla");	
		ShiftText s1("Yalla yalla", 4);				
		PlainText p2("zoom zoom zoom");			
		CaesarText c1("abcdefghi");			
		SubstitutionText sb1("boo foo zoo", "dictionary.csv");	
		
		std::string got, expected;

		cout << "\nUsing operator << on each instance " << std::endl;

		cout << "\nstd::cout << p1 << std::endl; " << std::endl;
		std::cout << p1 << std::endl;

		cout << "\nstd::cout << s1 << std::endl; " << std::endl;
		std::cout << s1 << std::endl;

		cout << "\nstd::cout << p2 << std::endl; " << std::endl;
		std::cout << p2 << std::endl;

		cout << "\nstd::cout << c1 << std::endl; " << std::endl;
		std::cout << c1 << std::endl;

		cout << "\nstd::cout << sb1 << std::endl; " << std::endl;
		std::cout << sb1 << std::endl;

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
	cout << "\n########## Operator << - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"###################################\n" <<
		"Exercise 4 - Encryption\n" <<
		"Part 5 - Operator << \n" <<
		"###################################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test5Operator();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex4 Operator << Test Passed!!! ##########" << "\n\n";
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