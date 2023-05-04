#include "BSNode.h"
#include <iostream>
#include <windows.h> // WinApi header - needed for setting console color
#include <string>
#include <vector>

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

std::string globalTreeString = "";

void convertBTToString(const std::string& prefix, const BSNode* node, bool isLeft, bool isAbsoluteRoot)
{
	if (node)
	{
		globalTreeString += prefix;
		if (isAbsoluteRoot)
		{
			globalTreeString = "|--";
		}
		else
			globalTreeString += (isLeft ? "[L]--" : "[R]--");

		// print the value of the node
		globalTreeString += node->getData() + ",<" + std::to_string(node->getCount()) + ">\n";

		// enter the next tree level - left and right branch
		convertBTToString(prefix + (isLeft ? "   " : "    "), node->getLeft(), true, false);
		convertBTToString(prefix + (isLeft ? "   " : "    "), node->getRight(), false, false);
	}
}

void convertBTToString(const BSNode* node)
{
	convertBTToString("", node, false, true);
}

bool test2bCopyBST()
{
	bool result = false;

	try
	{
		// Tests Ex9 part 1b - copy binary search tree

		set_console_color(LIGHT_BLUE);
		cout <<
			"***********************************\n" <<
			"Test 1b - Binary Search Tree Copy \n" <<
			"***********************************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Initializing a new tree t1(\"MMM\")... \n" << endl;

		BSNode t1("MMM");
		set_console_color(GREEN);
		cout << "OK" << std::endl;
		set_console_color(WHITE);

		cout <<
			"\nInserting values [\"DDD\",\"LLL\",\"VVV\",\"VVV\",\"BBB\",\"KKK\",\"TTT\"] ... \n" << endl;

		t1.insert("DDD");
		t1.insert("LLL");
		t1.insert("VVV");
		t1.insert("VVV");
		t1.insert("BBB");
		t1.insert("KKK");
		t1.insert("TTT");

		convertBTToString(&t1);
		std::string got = globalTreeString;

		std::string expected = "";
		expected = "|--MMM,<1>\n";
		expected += "    [L]--DDD,<1>\n";
		expected += "       [L]--BBB,<1>\n";
		expected += "       [R]--LLL,<1>\n";
		expected += "           [L]--KKK,<1>\n";
		expected += "    [R]--VVV,<2>\n";
		expected += "        [L]--TTT,<1>\n";

		cout << "Expected:\n" << expected << endl;
		cout << "Got:\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check functions BSNode::insert(string), BSNode::getCount()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing an tree using copy constructor -- BSNode t2(t1) ... \n" << endl;
		BSNode t2(t1);

		convertBTToString(&t2);
		got = globalTreeString;

		expected = "|--MMM,<1>\n";
		expected += "    [L]--DDD,<1>\n";
		expected += "       [L]--BBB,<1>\n";
		expected += "       [R]--LLL,<1>\n";
		expected += "           [L]--KKK,<1>\n";
		expected += "    [R]--VVV,<2>\n";
		expected += "        [L]--TTT,<1>\n";

		cout << "Expected:\n" << expected << endl;
		cout << "Got:\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check copy constructor\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInserting elements to t1 - [\"DDD\",\"AAA\"] ... \n" << endl;

		t1.insert("DDD");
		t1.insert("AAA");

		set_console_color(GREEN);
		cout << "OK" << std::endl;
		set_console_color(WHITE);

		cout <<
			"\nPrinting t1 ... \n" << endl;

		convertBTToString(&t1);
		got = globalTreeString;

		expected = "|--MMM,<1>\n";
		expected += "    [L]--DDD,<2>\n";
		expected += "       [L]--BBB,<1>\n";
		expected += "          [L]--AAA,<1>\n";
		expected += "       [R]--LLL,<1>\n";
		expected += "           [L]--KKK,<1>\n";
		expected += "    [R]--VVV,<2>\n";
		expected += "        [L]--TTT,<1>\n";

		cout << "Expected:\n" << expected << endl;
		cout << "Got:\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check functions BSNode::insert(string), BSNode::getCount()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nPrinting t2 (should be unchanged) ... \n" << endl;

		convertBTToString(&t2);
		got = globalTreeString;

		expected = "|--MMM,<1>\n";
		expected += "    [L]--DDD,<1>\n";
		expected += "       [L]--BBB,<1>\n";
		expected += "       [R]--LLL,<1>\n";
		expected += "           [L]--KKK,<1>\n";
		expected += "    [R]--VVV,<2>\n";
		expected += "        [L]--TTT,<1>\n";

		cout << "Expected:\n" << expected << endl;
		cout << "Got:\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check copy constructor\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nUsing copy operator t2 = t1 ... \n" << endl;

		t2 = t1;

		set_console_color(GREEN);
		cout << "OK" << std::endl;
		set_console_color(WHITE);

		cout <<
			"\nPrinting t2 again (should be like t1) ... \n" << endl;

		convertBTToString(&t2);
		got = globalTreeString;

		expected = "|--MMM,<1>\n";
		expected += "    [L]--DDD,<2>\n";
		expected += "       [L]--BBB,<1>\n";
		expected += "          [L]--AAA,<1>\n";
		expected += "       [R]--LLL,<1>\n";
		expected += "           [L]--KKK,<1>\n";
		expected += "    [R]--VVV,<2>\n";
		expected += "        [L]--TTT,<1>\n";

		cout << "Expected:\n" << expected << endl;
		cout << "Got:\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check copy constructor\n";
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
	cout << "\n########## Binary Search Tree - Copy TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"################################################\n" <<
		"Exercise 9 - Binary Search Trees and Templates\n" <<
		"Part 1b - Copy Binary Search Tree\n" <<
		"################################################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test2bCopyBST();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex9 Binary Search Tree Copy Tests Passed!!! ##########" << "\n\n";
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