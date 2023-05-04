//#include "CaesarText.h"
//#include <iostream>
//#include <windows.h> // WinApi header - needed for setting console color
//#include <string>
//
//using std::cout;
//using std::endl;
//
//#define GREEN 2
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
//std::string getShiftTextinfo(const ShiftText& s)
//{
//	return
//		"[text: " + s.getText() +
//		", encrypted: " + (s.isEncrypted() ? "true" : "false") + "]";
//}
//
//bool test1Shift()
//{
//	bool result = false;
//
//	try
//	{
//		// Tests Ex4 part 1 - ShiftText & CaesarText
//
//		set_console_color(TEAL);
//		cout <<
//			"********************\n" <<
//			"Test 1 - ShiftText \n" <<
//			"********************\n" << endl;
//		set_console_color(WHITE);
//
//		cout <<
//			"Initializing ShiftText object s1 with text = \"abcdefghijk\" , key = 10 ... \n" << endl;
//		ShiftText s1("abcdefghijk", 10);
//
//		std::string expected = "[text: klmnopqrstu, encrypted: true]";
//		std::string got = getShiftTextinfo(s1);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: ShiftText information is not as expected\n" <<
//				"check functions ShiftText(text, key), PlainText::getText(), PlainText::isEncrypted()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout <<
//			"\nCalling s1.decrypt() ... \n" << endl;
//
//		s1.decrypt();
//		expected = "[text: abcdefghijk, encrypted: false]";
//		got = getShiftTextinfo(s1);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: ShiftText information is not as expected\n" <<
//				"check function ShifText::decrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout <<
//			"\nCalling s1.decrypt() again... \n" << endl;
//
//		s1.decrypt();
//		expected = "[text: abcdefghijk, encrypted: false]";
//		got = getShiftTextinfo(s1);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: ShiftText information is not as expected\n" <<
//				"Not suppose to decrypt twice\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout <<
//			"\nCalling s1.encrypt() ... \n" << endl;
//
//		s1.encrypt();
//		expected = "[text: klmnopqrstu, encrypted: true]";
//		got = getShiftTextinfo(s1);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: ShiftText information is not as expected\n" <<
//				"check function ShifText::decrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout <<
//			"\nCalling s1.encrypt() again... \n" << endl;
//
//		s1.encrypt();
//		expected = "[text: klmnopqrstu, encrypted: true]";
//		got = getShiftTextinfo(s1);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: ShiftText information is not as expected\n" <<
//				"Not suppose to encrypt twice\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout <<
//			"\nInitializing ShiftText object s1 with text = \"lmnopqrstuvwxyz\" , key = 5 ... \n" << endl;
//		ShiftText s2("lmnopqrstuvwxyz", 5);
//
//		expected = "[text: qrstuvwxyzabcde, encrypted: true]";
//		got = getShiftTextinfo(s2);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: ShiftText information is not as expected\n" <<
//				"check functions ShiftText(text, key), PlainText::getText(), PlainText::isEncrypted()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout <<
//			"\nCalling s2.decrypt() ... \n" << endl;
//
//		s2.decrypt();
//		expected = "[text: lmnopqrstuvwxyz, encrypted: false]";
//		got = getShiftTextinfo(s2);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: ShiftText information is not as expected\n" <<
//				"check function ShifText::decrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout <<
//			"\nInitializing CaesarText object c1 with text = \"abcdefghijklmnopqrstuvwxyz\" ... \n" << endl;
//		CaesarText c1("abcdefghijklmnopqrstuvwxyz");
//
//		expected = "[text: defghijklmnopqrstuvwxyzabc, encrypted: true]";
//		got = getShiftTextinfo(c1);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: CaesarText information is not as expected\n" <<
//				"check functions CaesarText(text, key), PlainText::getText(), PlainText::isEncrypted()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout <<
//			"\nCalling c1.decrypt() ... \n" << endl;
//
//		c1.decrypt();
//		expected = "[text: abcdefghijklmnopqrstuvwxyz, encrypted: false]";
//		got = getShiftTextinfo(c1);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: CaesarText information is not as expected\n" <<
//				"check function CaesarText::decrypt()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//
//		cout <<
//			"\nInitializing CaesarText object c2 with text = \"this is a string with comma, space and dots ...\" ... \n" << endl;
//		CaesarText c2("this is a string with comma, space and dots ...");
//
//		expected = "[text: wklv lv d vwulqj zlwk frppd, vsdfh dqg grwv ..., encrypted: true]";
//		got = getShiftTextinfo(c2);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: CaesarText information is not as expected\n" <<
//				"check functions CaesarText(text, key), PlainText::getText(), PlainText::isEncrypted()\n";
//			set_console_color(WHITE);
//			return false;
//		}
//		
//		cout <<
//			"\nCalling c2.decrypt() ... \n" << endl;
//
//		c2.decrypt();
//		expected = "[text: this is a string with comma, space and dots ..., encrypted: false]";
//		got = getShiftTextinfo(c2);
//		cout << "Expected: " << expected << endl;
//		cout << "Got     : " << got << endl;
//		if (got != expected)
//		{
//			set_console_color(RED);
//			cout << "FAILED: CaesarText information is not as expected\n" <<
//				"check function CaesarText::decrypt()\n";
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
//	cout << "\n########## ShiftText & CaesarText - TEST Passed!!! ##########\n\n";
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
//		"Part 1 - ShiftText & CaesarText\n" <<
//		"###################################\n" << std::endl;
//	set_console_color(WHITE);
//
//	bool testResult = test1Shift();
//
//	if (testResult)
//	{
//		set_console_color(GREEN);
//		std::cout << "\n########## Ex4 ShiftText & CaesarText Tests Passed!!! ##########" << "\n\n";
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