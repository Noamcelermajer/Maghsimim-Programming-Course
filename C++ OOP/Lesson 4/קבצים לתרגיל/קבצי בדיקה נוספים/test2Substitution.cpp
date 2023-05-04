#include "SubstitutionText.h"
#include <fstream>
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

std::string getSubTextinfo(const SubstitutionText& s)
{
	return
		"[text: " + s.getText() +
		", encrypted: " + (s.isEncrypted() ? "true" : "false") + "]";
}

void printSubDictionary(const std::string csvFileName)
{
	std::cout << "Printing \"" << csvFileName << "\"..." << std::endl;
	std::ifstream csv(csvFileName);
	std::string sourceLetter , destLetter, line;
	while (std::getline(csv, line)) 
	{
		sourceLetter = line[0];
		destLetter = line[2];
		cout << "" << sourceLetter << " ";
		cout << "<------> " << destLetter << std::endl;;
	}
}

bool test2Sub()
{
	bool result = false;

	try
	{
		// Tests Ex4 part 2 - SubstitutionText

		set_console_color(BLUE);
		cout <<
			"*****************************\n" <<
			"Test 2 - SubstitutionText \n" <<
			"*****************************\n" << endl;
		set_console_color(WHITE);

		const std::string dictFile = "dictionary.csv";
		printSubDictionary(dictFile);

		cout <<
			"\nInitializing SubstitutionText object s1 with text = \"abcdefghijk\" , key = " << dictFile << "... \n" << endl;
		SubstitutionText s1("abcdefghijk", dictFile);

		std::string expected = "[text: rovpxdncwes, encrypted: true]";
		std::string got = getSubTextinfo(s1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: SubstitutionText information is not as expected\n" <<
				"check functions SubstitutionText(text, filename), PlainText::getText(), PlainText::isEncrypted()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling s1.decrypt() ... \n" << endl;

		s1.decrypt();
		expected = "[text: abcdefghijk, encrypted: false]";
		got = getSubTextinfo(s1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: SubstitutionText information is not as expected\n" <<
				"check function SubstitutionText::decrypt()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling s1.decrypt() again ... \n" << endl;

		s1.decrypt();
		expected = "[text: abcdefghijk, encrypted: false]";
		got = getSubTextinfo(s1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: SubstitutionText information is not as expected\n" <<
				"Not suppose to encrypt twice\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling s1.encrypt() ... \n" << endl;

		s1.encrypt();
		expected = "[text: rovpxdncwes, encrypted: true]";
		got = getSubTextinfo(s1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: SubstitutionText information is not as expected\n" <<
				"check function SubstitutionText::decrypt()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling s1.encrypt() again... \n" << endl;

		s1.encrypt();
		expected = "[text: rovpxdncwes, encrypted: true]";
		got = getSubTextinfo(s1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: SubstitutionText information is not as expected\n" <<
				"Not suppose to encrypt twice\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing SubstitutionText object s2 with text = \"this is a string with comma, space and dots ...\" , key = " 
			<< dictFile << "... \n" << endl;
		SubstitutionText s2("this is a string with comma, space and dots ...", dictFile);

		expected = "[text: qcwu wu r uqawzn fwqc vibbr, ujrvx rzp piqu ..., encrypted: true]";
		got = getSubTextinfo(s2);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: SubstitutionText information is not as expected\n" <<
				"check functions SubstitutionText(text, filename), PlainText::getText(), PlainText::isEncrypted()\n";
			set_console_color(WHITE);
			return false;
		}


		cout <<
			"\nCalling s2.decrypt() ... \n" << endl;
		s2.decrypt();
		expected = "[text: this is a string with comma, space and dots ..., encrypted: false]";
		got = getSubTextinfo(s2);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: SubstitutionText information is not as expected\n" <<
				"check functions SubstitutionText(text, filename), PlainText::getText(), PlainText::isEncrypted()\n";
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
	cout << "\n########## ShiftText & CaesarText - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"###################################\n" <<
		"Exercise 4 - Encryption\n" <<
		"Part 2 - SubstitutionText\n" <<
		"###################################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test2Sub();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex4 SubstitutionText Tests Passed!!! ##########" << "\n\n";
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