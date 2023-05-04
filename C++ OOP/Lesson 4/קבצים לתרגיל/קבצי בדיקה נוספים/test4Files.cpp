//#include "FileHelper.h"
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <windows.h> // WinApi header - needed for setting console color
//#include <string>
//
//using std::cout;
//using std::endl;
//
//#define GREEN 2
//#define BLUE 3
//#define DARK_RED 4
//#define PURPLE 5
//#define YELLOW 6
//#define LIGHT_BLUE 9
//#define LIGHT_GREEN 10
//#define TEAL 11
//#define RED 12
//#define LIGHT_PURPLE 13
//#define LIGHT_YELLOW 14
//#define WHITE 15
//
//void set_console_color(unsigned int color)
//{
//	// colors are 0=black 1=blue 2=green and so on to 15=white
//	// colorattribute = foreground + background * 16
//	// to get red text on yellow use 4 + 14*16 = 228
//	// light red on yellow would be 12 + 14*16 = 236
//	// a Dev-C++ tested console application by vegaseat 07nov2004
//
//	HANDLE hConsole;
//
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, color);
//}
//
//std::string readFileToString(const std::string fileName)
//{
//	std::ifstream inFile;
//	inFile.open(fileName); //open the input file
//
//	std::stringstream strStream;
//	strStream << inFile.rdbuf(); //read the file
//	std::string str = strStream.str(); //str holds the content of the file
//
//	return str;
//}
//
//bool test4Files()
//{
//	bool result = false;
//
//	try
//	{
//		// Tests Ex4 part 4 - FileHelper
//
//		set_console_color(PURPLE);
//		cout <<
//			"*********************\n" <<
//			"Test 4 - FileHelper  \n" <<
//			"*********************\n" << endl;
//		set_console_color(WHITE);
//
//		cout <<
//			"Checking FileHelper ... \n" << endl;
//
//		const std::string file1name = "example.txt";
//		std::string file1text = readFileToString(file1name);
//
//		cout <<
//			"Calling FileHelper::readFileToString(example.txt) ... \n" << endl;
//
//		std::string expected = file1text;
//		std::string got = FileHelper::readFileToString(file1name);
//
//		cout << "Expected:\n" << expected << endl;
//		cout << "\nGot     :\n" << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: FileHelper information is not as expected" <<
//				"check function FileHelper::readFileToString\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		const std::string outputFileName = "output.txt";
//		cout <<
//			"\nCalling FileHelper::saveTextInFile(file1Text, " << outputFileName << ") ... \n" << endl;
//
//		FileHelper::saveTextInFile(file1text, outputFileName);
//
//		cout <<
//			"Comparing example.txt and " << outputFileName << " ... \n" << endl;
//
//		expected = file1text;
//		got = FileHelper::readFileToString(outputFileName);
//
//		cout << "Expected: " << "true" << endl;
//		cout << "Got     : " << (got == expected ? "true" : "false") << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: FileHelper information is not as expected" <<
//				"check function FileHelper::saveTextInFile\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		const std::string output2FileName = "output2.txt";
//		cout <<
//			"\nCalling FileHelper::writeWordsToFile(" << file1name << ", " << output2FileName << ") ... \n" << endl;
//
//		const std::string expectedResultFileName = "expected.txt";
//		FileHelper::writeWordsToFile(file1name, output2FileName);
//
//		expected = readFileToString(expectedResultFileName);
//		got = FileHelper::readFileToString(output2FileName);
//
//		cout << "Expected:\n" << expected << endl;
//		cout << "\nGot     :\n" << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: FileHelper information is not as expected" <<
//				"check function FileHelper::writeWordsToFile\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//	}
//	catch (...)
//	{
//		set_console_color(RED);
//		std::cerr << "Test crashed" << endl;
//		std::cout << "FAILED: The program crashed, check the following things:\n" <<
//			"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" <<
//			"3. Did you remember to initialize array before accessing it?";
//		set_console_color(WHITE);
//		return false;
//	}
//
//	set_console_color(LIGHT_GREEN);
//	cout << "\n########## File Helper - TEST Passed!!! ##########\n\n";
//	set_console_color(WHITE);
//
//	return true;
//
//}
//
//
//int main()
//{
//	set_console_color(LIGHT_YELLOW);
//	std::cout <<
//		"###################################\n" <<
//		"Exercise 4 - Encryption\n" <<
//		"Part 4 - Files\n" <<
//		"###################################\n" << std::endl;
//	set_console_color(WHITE);
//
//	bool testResult = test4Files();
//
//	if (testResult)
//	{
//		set_console_color(GREEN);
//		std::cout << "\n########## Ex4 File Helper Test Passed!!! ##########" << "\n\n";
//		set_console_color(WHITE);
//	}
//	else
//	{
//		set_console_color(DARK_RED);
//		std::cout << "\n########## TEST Failed :( ##########\n";
//		set_console_color(WHITE);
//	}
//	return testResult ? 0 : 1;
//}