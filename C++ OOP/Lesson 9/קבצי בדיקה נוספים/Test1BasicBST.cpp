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

std::string getBSTNodeInfo(const BSNode& t)
{
	std::string result = "{ data: \"" + t.getData() + "\" <" + std::to_string(t.getCount()) + ">, ";
	std::string sonData = "";
	if (t.getLeft())
		sonData = "\"" + t.getLeft()->getData() + "\" <" + std::to_string(t.getCount()) + ">";
	else
		sonData = "NULL";

	result += "left: " + sonData + " ,";

	if (t.getRight())
		sonData = "\""+ t.getRight()->getData() + "\" <" + std::to_string(t.getCount()) + ">";
	else
		sonData = "NULL";

	result += "right: " + sonData + " }";
	return result;
}

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

bool test1aBasicBST()
{
	bool result = false;

	try
	{
		// Tests Ex9 part 1a - basic binary tree

		set_console_color(LIGHT_PURPLE);
		cout <<
			"***********************************\n" <<
			"Test 1a - Basic Binary Search Tree \n" <<
			"***********************************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Trying to initialize a new Binary Search Tree t1(\"Hello\") ... \n" << endl;

		BSNode t1("Hello");

		std::string expected = "{ data: \"Hello\" <1>, left: NULL ,right: NULL }";
		std::string got = getBSTNodeInfo(t1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check constructor BSNode::BSNode(string)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nTrying to insert new value to tree t1.insert(\"Shalom\") ... \n" << endl;

		t1.insert("Shalom");
		expected = "{ data: \"Hello\" <1>, left: NULL ,right: \"Shalom\" <1> }";
		got = getBSTNodeInfo(t1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::insert(string)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nTrying to insert new value to tree t1.insert(\"Bekef\") ... \n" << endl;

		t1.insert("Bekef");
		expected = "{ data: \"Hello\" <1>, left: \"Bekef\" <1> ,right: \"Shalom\" <1> }";
		got = getBSTNodeInfo(t1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::insert(string)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInserting values [\"AAA\",\"ZZZ\",\"CCC\",\"YYY\"] ... \n" << endl;

		t1.insert("AAA");
		t1.insert("ZZZ");
		t1.insert("CCC");
		t1.insert("YYY");

		convertBTToString(&t1);
		got = globalTreeString;

		expected = "|--Hello,<1>\n";
		expected += "    [L]--Bekef,<1>\n";
		expected += "       [L]--AAA,<1>\n";
		expected += "       [R]--CCC,<1>\n";
		expected += "    [R]--Shalom,<1>\n";
		expected += "        [R]--ZZZ,<1>\n";
		expected += "            [L]--YYY,<1>\n";

		cout << "Expected:\n" << expected << endl;
		cout << "Got:\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode::insert(string)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInserting values [\"Bekef\",\"CCC\",\"CCC\",\"Hello\",\"YYY\",\"YYY\",\"YYY\"] ... \n" << endl;

		t1.insert("Bekef");
		t1.insert("CCC");
		t1.insert("CCC");
		t1.insert("Hello");
		t1.insert("YYY");
		t1.insert("YYY");
		t1.insert("YYY");

		convertBTToString(&t1);
		got = globalTreeString;

		expected = "|--Hello,<2>\n";
		expected += "    [L]--Bekef,<2>\n";
		expected += "       [L]--AAA,<1>\n";
		expected += "       [R]--CCC,<3>\n";
		expected += "    [R]--Shalom,<1>\n";
		expected += "        [R]--ZZZ,<1>\n";
		expected += "            [L]--YYY,<4>\n";

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
	cout << "\n########## Binary Search Tree - Basic TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"################################################\n" <<
		"Exercise 9 - Binary Search Trees and Templates\n" <<
		"Part 1a - Basic Binary Search Tree\n" <<
		"################################################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test1aBasicBST();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex9 Basic Binary Search Tree Tests Passed!!! ##########" << "\n\n";
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