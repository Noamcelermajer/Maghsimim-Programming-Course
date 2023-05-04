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

bool test3BSTUtils()
{
	bool result = false;

	try
	{
		// Tests Ex9 part 1c - binary search tree advanced test

		set_console_color(TEAL);
		cout <<
			"***********************************\n" <<
			"Test 1c - Binary Search Tree Utils \n" <<
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

		/////////////////////
		// checking search //
		/////////////////////

		cout <<
			"\nSearching for value \"AAA\" -- t1.search(\"AAA\") ... \n" << endl;

		t1.search("AAA");
		expected = "false";
		got = t1.search("AAA") ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::search(string)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nSearching for value \"VVV\" -- t1.search(\"VVV\") ... \n" << endl;


		t1.search("VVV");
		expected = "true";
		got = t1.search("VVV") ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::search(string)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nSearching for value \"MMM\" -- t1.search(\"MMM\") ... \n" << endl;

		t1.search("MMM");
		expected = "true";
		got = t1.search("MMM") ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::search(string)\n";
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
			"\nSearching for value \"AAA\" -- t1.search(\"AAA\") ... \n" << endl;

		t1.search("AAA");
		expected = "true";
		got = t1.search("AAA") ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::search(string)\n";
			set_console_color(WHITE);
			return false;
		}

		////////////////////////////
		// checking height & depth//
		////////////////////////////

		cout <<
			"\nCalculating t1 height -- t1.getHeight() ... \n" << endl;

		expected = "4";
		got = std::to_string(t1.getHeight());
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::getHeight()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalculating the depth of node \"KKK\" from t1 root ... \n" << endl;
		BSNode* bs = t1.getLeft()->getRight()->getLeft();

		expected = "3";
		got = std::to_string(bs->getDepth(t1));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::getDepth(BSNode&)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nChecking if node \"KKK\" is a leaf on t1 ... \n" << endl;

		expected = "true";
		got = bs->isLeaf() ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::isLeaf()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nChecking if node \"LLL\" is a leaf on t1 ... \n" << endl;

		bs = t1.getLeft()->getRight();
		expected = "false";
		got = bs->isLeaf() ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::isLeaf()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalculating the depth of node \"TTT\" from t1 root ... \n" << endl;
		bs = t1.getRight()->getLeft();

		expected = "2";
		got = std::to_string(bs->getDepth(t1));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::getDepth(BSNode&)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nChecking if node \"TTT\" is a leaf on t1 ... \n" << endl;

		expected = "true";
		got = bs->isLeaf() ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::isLeaf()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing a new tree t2(\"1\")... \n" << endl;

		BSNode t2("1");
		set_console_color(GREEN);
		cout << "OK" << std::endl;
		set_console_color(WHITE);

		cout <<
			"\nInserting values [\"2\",\"3\",\"4\",\"5\",\"6\",\"7\",\"8\"] ... \n" << endl;

		t2.insert("2");
		t2.insert("3");
		t2.insert("4");
		t2.insert("5");
		t2.insert("6");
		t2.insert("7");
		t2.insert("8");

		convertBTToString(&t2);
		got = globalTreeString;

		expected = "|--1,<1>\n";
		expected += "    [R]--2,<1>\n";
		expected += "        [R]--3,<1>\n";
		expected += "            [R]--4,<1>\n";
		expected += "                [R]--5,<1>\n";
		expected += "                    [R]--6,<1>\n";
		expected += "                        [R]--7,<1>\n";
		expected += "                            [R]--8,<1>\n";

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
			"\nCalculating t2 height \"AAA\" -- t2.getHeight() ... \n" << endl;

		expected = "8";
		got = std::to_string(t2.getHeight());
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::getHeight()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalculating the depth of node \"8\" from t2 root ... \n" << endl;
		
		bs = &t2;
		for(unsigned int i = 0; i < 7; i++)
			bs = bs->getRight();

		expected = "7";
		got = std::to_string(bs->getDepth(t2));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::getDepth(BSNode&)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nChecking if node \"8\" is a leaf on t2 ... \n" << endl;

		expected = "true";
		got = bs->isLeaf() ? "true" : "false";
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::search(string)\n";
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
	cout << "\n########## Binary Search Tree - Utils TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"################################################\n" <<
		"Exercise 9 - Binary Search Trees and Templates\n" <<
		"Part 1c - Binary Search Tree Utils\n" <<
		"################################################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test3BSTUtils();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex9 Binary Search Tree Advanced Tests Passed!!! ##########" << "\n\n";
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