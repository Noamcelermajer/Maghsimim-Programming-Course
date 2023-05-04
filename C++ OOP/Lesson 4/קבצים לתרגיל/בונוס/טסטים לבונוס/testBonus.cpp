#include "BonusText.h"
#include <fstream>
#include <sstream>
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

std::string readFileToString(const std::string fileName)
{
	std::ifstream inFile;
	inFile.open(fileName); //open the input file

	std::stringstream strStream;
	strStream << inFile.rdbuf(); //read the file
	std::string str = strStream.str(); //str holds the content of the file

	return str;
}

bool testBonus()
{
	bool result = false;

	try
	{
		// Tests Ex4 part 6 - Bonus

		set_console_color(YELLOW);
		cout <<
			"*****************\n" <<
			"Test 6 - Bonus	      \n" <<
			"*****************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Checking BonusTest ... \n" << endl;

		const std::string encryptedFileName = "encrypted.txt";

		cout << "\nInitializing BonusText instances b1 with encrypted file name\n"
			 << "\ncalling b1.decrypt(encrypted.txt)\n"
			<< std::endl;

		BonusText b1(encryptedFileName);
		std::string text = b1.decrypt();

		std::string decryptedText = readFileToString("decrypted.txt");

		set_console_color(79);
		cout << "Expected:\n";
		set_console_color(WHITE);
		cout << decryptedText << "\n" << endl;

		set_console_color(79);
		cout << "Got:\n"; 
		set_console_color(WHITE);
		cout << text << endl;
		if (decryptedText != text)
			{
				set_console_color(RED);
				cout << "FAILED: BonusText information is not as expected" <<
					"check function BonusText::decrypt()\n";
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
	cout << "\n########## Bonus - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"###################################\n" <<
		"Exercise 4 - Encryption\n" <<
		"Bonus \n" <<
		"###################################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = testBonus();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex4 Bonus Test Passed!!! ##########" << "\n\n";
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