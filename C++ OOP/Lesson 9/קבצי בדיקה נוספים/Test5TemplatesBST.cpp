#include "BSNode.hpp"
#include <iostream>
#include <windows.h> // WinApi header - needed for setting console color
#include <string>
#include <vector>

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

std::string globalTreeString = "";

template<class T>
std::string getBSTNodeInfo(const BSNode<T>& t)
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

template<class T>
void convertBTToString(const std::string& prefix, const BSNode<T>* node, bool isLeft, bool isAbsoluteRoot)
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

template<class T>
void convertBTToString(const BSNode<T>* node)
{
	convertBTToString("", node, false, true);
}

bool test5TemplateBST()
{
	bool result = false;

	try
	{
		// Tests Ex9 part 3 - binary search tree with templates

		set_console_color(BLUE);
		cout <<
			"***************************************\n" <<
			"Test 1a - Generic Binary Search Tree \n" <<
			"***************************************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Trying to initialize a new Binary Search Tree for std::strings t1(\"TTT\") ... \n" << endl;

		BSNode<std::string> t1("Imagine");

		set_console_color(GREEN);
		cout << "OK" << std::endl;
		set_console_color(WHITE);

		cout <<
			"\nInserting values [\"All\",\"The\",\"People\",\"Living\",\"Life\",\"In\",";
		cout<<
			"\"Peace\",\"WhoohooOooooo\",\"You\",\"May\",\"Say\",\"I'm\",\"A\",\"Dreamer\",";
		cout <<
			"\"But\",\"I'm\",\"Not\",\"The\",\"Only\",\"One\"] ... \n" << endl;

		t1.insert("All");
		t1.insert("The");
		t1.insert("People");
		t1.insert("Living");
		t1.insert("Life");
		t1.insert("In");
		t1.insert("Peace");
		t1.insert("WhoohooOooooo");
		t1.insert("You");
		t1.insert("May");
		t1.insert("Say");
		t1.insert("I'm");
		t1.insert("A");
		t1.insert("Dreamer");
		t1.insert("But");
		t1.insert("I'm");
		t1.insert("Not");
		t1.insert("The");
		t1.insert("Only");
		t1.insert("One");



		set_console_color(GREEN);
		cout << "OK" << std::endl;
		set_console_color(WHITE);

		convertBTToString(&t1);
		std::string got = globalTreeString;

		std::string expected;
		expected = "|--Imagine,<1>\n";
		expected += "    [L]--All,<1>\n";
		expected += "       [L]--A,<1>\n";
		expected += "       [R]--I'm,<2>\n";
		expected += "           [L]--Dreamer,<1>\n";
		expected += "              [L]--But,<1>\n";
		expected += "    [R]--The,<2>\n";
		expected += "        [L]--People,<1>\n";
		expected += "           [L]--Living,<1>\n";
		expected += "              [L]--Life,<1>\n";
		expected += "                 [L]--In,<1>\n";
		expected += "              [R]--Peace,<1>\n";
		expected += "                  [L]--May,<1>\n";
		expected += "                     [R]--Not,<1>\n";
		expected += "                         [R]--Only,<1>\n";
		expected += "                             [L]--One,<1>\n";
		expected += "           [R]--Say,<1>\n";
		expected += "        [R]--WhoohooOooooo,<1>\n";
		expected += "            [R]--You,<1>\n";

		cout << "\nExpected:\n" << expected << endl;
		cout << "Got:\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode<T>::insert(string)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing a new binary search tree for integers ... \n" << endl;

		const int arr_size = 15;
		int intArr[arr_size] = { 6,24,74,-54,0,24,67,34,67,789,34,234,57,787,34 };

		cout << "\nInserting values [";

		for (int i = 0; i < arr_size - 1; i++) {
			std::cout << intArr[i] << ", ";
		}
		std::cout << intArr[arr_size - 1] << "]" << std::endl;

		BSNode<int> bs(intArr[0]);
		for (int i = 1; i < arr_size; i++) {
			bs.insert(intArr[i]);
		}

		set_console_color(GREEN);
		cout << "\nOK" << std::endl;
		set_console_color(WHITE);

		cout << "\nPrinting Tree using BSNode<T>::printNodes\n" << std::endl;;
		bs.printNodes();

		cout <<
			"\nCalculating t2 height \"AAA\" -- t2.getHeight() ... \n" << endl;
		expected = "6";
		got = std::to_string(bs.getHeight());
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode<T>::getHeight()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalculating the depth of node \"8\" from t2 root ... \n" << endl;
		
		BSNode<int>* bs1 = bs.getRight()->getRight()->getLeft()->getLeft();

		expected = "4";
		got = std::to_string(bs1->getDepth(bs));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: BSNode information is not as expected\n" <<
				"check function BSNode<T>::getDepth(BSNode&)\n";
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
	cout << "\n########## Binary Search Tree - Templates TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"################################################\n" <<
		"Exercise 9 - Binary Search Trees and Templates\n" <<
		"Part 3 - Generic Binary Search Tree\n" <<
		"################################################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test5TemplateBST();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex9 Generic Binary Search Tree Tests Passed!!! ##########" << "\n\n";
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