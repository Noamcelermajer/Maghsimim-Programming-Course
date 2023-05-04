//#include "CaesarText.h"
//#include "SubstitutionText.h"
//#include <iostream>
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
//void printSubDictionary(const std::string csvFileName)
//{
//	std::cout << "Printing \"" << csvFileName << "\"..." << std::endl;
//	std::ifstream csv(csvFileName);
//	std::string sourceLetter, destLetter, line;
//	while (std::getline(csv, line))
//	{
//		sourceLetter = line[0];
//		destLetter = line[2];
//		cout << "" << sourceLetter << " ";
//		cout << "<------> " << destLetter << std::endl;;
//	}
//}
//
//bool test3Static()
//{
//	bool result = false;
//
//	try
//	{
//		// Tests Ex4 part 3 - Static
//
//		set_console_color(LIGHT_PURPLE);
//		cout <<
//			"**********************************\n" <<
//			"Test 3 - Static fields & methods \n" <<
//			"**********************************\n" << endl;
//		set_console_color(WHITE);
//
//		///////////////
//		// ShiftText //
//		///////////////
//
//		cout <<
//			"Checking ShiftText::encrypt ... \n" << endl;
//
//		std::string text = "abcdefghijklmnopqrstuvwxyz";
//		cout << "Text: \"" << text << "\" , key = 10" << endl;
//		std::string expected = "klmnopqrstuvwxyzabcdefghij";
//		std::string got = ShiftText::encrypt(text, 10);
//
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: ShiftText information is not as expected" <<
//				"check function ShiftText::encrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		text = "abc, def, ghi, jkl, mno, pqr, stu, vwx, yz.";
//		cout << "\nText: \"" << text << "\" , key = 5" << endl;
//		expected = "fgh, ijk, lmn, opq, rst, uvw, xyz, abc, de.";
//		got = ShiftText::encrypt(text, 5);
//
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: ShiftText information is not as expected\n" <<
//				"check function ShiftText::encrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout <<
//			"\nChecking ShiftText::decrypt ... \n" << endl;
//
//		text = "klmnopqrstuvwxyzabcdefghij";
//		cout << "Text: \"" << text << "\" , key = 10" << endl;
//		expected = "abcdefghijklmnopqrstuvwxyz";
//		got = ShiftText::decrypt(text, 10);
//
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: ShiftText information is not as expected" <<
//				"check function ShiftText::decrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		text = "fgh, ijk, lmn, opq, rst, uvw, xyz, abc, de.";
//		cout << "\nText: \"" << text << "\" , key = 5" << endl;
//		expected = "abc, def, ghi, jkl, mno, pqr, stu, vwx, yz.";
//		got = ShiftText::decrypt(text, 5);
//
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: ShiftText information is not as expected\n" <<
//				"check function ShiftText::decrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		////////////////
//		// CaesarText //
//		////////////////
//
//		cout << "\nChecking CaesarText::encrypt ... \n" << endl;
//
//		text = "roses are red, my name is dave, this makes no sense, microwave.";
//		cout << "Text: \"" << text << "\"" << endl;
//		expected = "urvhv duh uhg, pb qdph lv gdyh, wklv pdnhv qr vhqvh, plfurzdyh.";
//		got = CaesarText::encrypt(text);
//
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: CaesarText information is not as expected" <<
//				"check function CaesarText::encrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout << "\nChecking CaesarText::decrypt ... \n" << endl;
//
//		text = "urvhv duh uhg, pb qdph lv gdyh, wklv pdnhv qr vhqvh, plfurzdyh.";
//		cout << "Text: \"" << text << "\"" << endl;
//		expected = "roses are red, my name is dave, this makes no sense, microwave.";
//		got = CaesarText::decrypt(text);
//
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: CaesarText information is not as expected" <<
//				"check function CaesarText::decrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		//////////////////////
//		// SubstitutionText //
//		//////////////////////
//
//		std::cout << "\n";
//		const std::string dictFile = "dictionary.csv";
//		printSubDictionary(dictFile);
//
//		cout << "\nChecking SubstitutionText::encrypt ..." << endl;
//
//		text = "abc, def, ghi, jkl, mno, pqr, stu, vwx, yz.";
//		cout << "\nText: \"" << text << "\" , key = " << dictFile << endl;
//		expected = "rov, pxd, ncw, esm, bzi, jta, uqh, kfy, lg.";
//		got = SubstitutionText::encrypt(text, dictFile);
//
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: SubstitutionText information is not as expected\n" <<
//				"check function SubstitutionText::encrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		text = "sometimes when i close my eyes, i cant see.";
//		cout << "\nText: \"" << text << "\" , key = " << dictFile << endl;
//		expected = "uibxqwbxu fcxz w vmiux bl xlxu, w vrzq uxx.";
//		got = SubstitutionText::encrypt(text, dictFile);
//
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: SubstitutionText information is not as expected\n" <<
//				"check function SubstitutionText::encrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout << "\nChecking SubstitutionText::decrypt ..." << endl;
//
//		text = "rov, pxd, ncw, esm, bzi, jta, uqh, kfy, lg.";
//		cout << "\nText: \"" << text << "\" , key = " << dictFile << endl;
//		expected = "abc, def, ghi, jkl, mno, pqr, stu, vwx, yz.";
//		got = SubstitutionText::decrypt(text, dictFile);
//
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: SubstitutionText information is not as expected\n" <<
//				"check function SubstitutionText::encrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		text = "uibxqwbxu fcxz w vmiux bl xlxu, w vrzq uxx.";
//		cout << "\nText: \"" << text << "\" , key = " << dictFile << endl;
//		expected = "sometimes when i close my eyes, i cant see.";
//		got = SubstitutionText::decrypt(text, dictFile);
//
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: SubstitutionText information is not as expected\n" <<
//				"check function SubstitutionText::encrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		/////////////////////////
//		// Number of instances //
//		/////////////////////////
//
//		cout << "\nPrinting number of instances -- PlainText::numOfTexts " << std::endl;
//
//		expected = "0";
//		got = std::to_string(PlainText::numOfTexts);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: Cannot print PlainText::numOfTexts ...\n" <<
//				"is the field numOfTexts private? it should be public...\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout << "\nInitializing 5 instances\n"
//			<< "{PlainText p1, Shiftext s1, PlainText p2, CaesarText c1, SubstitutionText sb1}" 
//			<< std::endl;
//
//		PlainText p1("blabla");	
//		ShiftText s1("Yalla yalla", 4);				
//		PlainText p2("zoom zoom zoom");			
//		CaesarText c1("abcdefghi");			
//		SubstitutionText sb1("boo foo zoo", "dictionary.csv");	
//
//		cout << "\nPrinting number of instances -- PlainText::numOfTexts " << std::endl;
//
//		expected = "5";
//		got = std::to_string(PlainText::numOfTexts);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: Expected different value on PlainText::numOfTexts ...\n" <<
//				"Did you count all Text class objects?...\n";
//			set_console_color(WHITE);
//			return false;
//		}
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
//	cout << "\n########## Static fields & methods - TEST Passed!!! ##########\n\n";
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
//		"Part 3 - Static\n" <<
//		"###################################\n" << std::endl;
//	set_console_color(WHITE);
//
//	bool testResult = test3Static();
//
//	if (testResult)
//	{
//		set_console_color(GREEN);
//		std::cout << "\n########## Ex4 Static fields & methods Tests Passed!!! ##########" << "\n\n";
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