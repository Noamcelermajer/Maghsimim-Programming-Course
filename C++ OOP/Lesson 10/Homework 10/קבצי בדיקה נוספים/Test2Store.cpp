#include <iostream>
#include <windows.h> // WinApi header - needed for setting console color
#include <random>
#include <fstream>
#include <sstream>

#include "Store.h"

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
#define PURPLE 13
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

std::string getItemString(const Item& item)
{
	return
		"[Serial: " + item.getSerial() +
       ", Name: " + item.getName() +
		", Category: " + getItemCategoryString(item.getCategory()) +
		", Price: " + std::to_string(item.getPrice()) +
		", Amount: " + std::to_string(item.getCount()) + "]";
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

bool test2Store()
{
	bool result = false;

	try
	{
		// Tests Ex10 part 2 - Store

		set_console_color(PURPLE);
		cout <<
			"*******************\n" <<
			"Test 2 - Store				\n" <<
			"*******************\n" << endl;

	    set_console_color(WHITE);


        ///////////////////////////
        // Checking Sort Methods //
        ///////////////////////////
	   cout <<
		    "Initializing Store1(\"MagshIKEA\", \"InventoryIKEA.csv\"): ... \n" << endl;
       Store s1("IKEA", "InventoryIKEA.csv");

       cout <<
           "\nSorting store items by Name: ... \n" << endl;

       std::string expected = readFileToString("output1a.txt");
       std::string got = s1.getSortedProductList(NAME);
       cout << "Expected:\n" << expected << endl;
       cout << "Got     :\n" << got << std::endl;
       if (got != expected)
       {
           set_console_color(RED);
           std::cout << "FAILED: Store information is not as expected\n" <<
               "check Store Constructor and functions Store::getSortedProductList(SortingCriteria) \n" ;
           return false;
           set_console_color(WHITE);
       }

       cout <<
           "\nSorting store items by Price: ... \n" << endl;

       expected = readFileToString("output1b.txt");
       got = s1.getSortedProductList(PRICE);
       cout << "Expected:\n" << expected << endl;
       cout << "Got     :\n" << got << std::endl;
       if (got != expected)
       {
           set_console_color(RED);
           std::cout << "FAILED: Store information is not as expected\n" <<
               "check Store Constructor and functions Store::getSortedProductList(SortingCriteria) \n";
           return false;
           set_console_color(WHITE);
       }

       cout <<
           "\nSorting store items by Serial Number: ... \n" << endl;

       expected = readFileToString("output1c.txt");
       got = s1.getSortedProductList(SERIAL);
       cout << "Expected:\n" << expected << endl;
       cout << "Got     :\n" << got << std::endl;
       if (got != expected)
       {
           set_console_color(RED);
           std::cout << "FAILED: Store information is not as expected\n" <<
               "check Store Constructor and functions Store::getSortedProductList(SortingCriteria) \n";
           return false;
           set_console_color(WHITE);
       }

       cout <<
           "Initializing Store2(\"Shefa Isaschar\", \"InventorySuperMarket.csv\"): ... \n" << endl;
       Store s2("Shefa Isaschar", "InventorySuperMarket.csv");

       cout <<
           "\nSorting store items by Name: ... \n" << endl;

       expected = readFileToString("output2a.txt");
       got = s2.getSortedProductList(NAME);
       cout << "Expected:\n" << expected << endl;
       cout << "Got     :\n" << got << std::endl;
       if (got != expected)
       {
           set_console_color(RED);
           std::cout << "FAILED: Store information is not as expected\n" <<
               "check Store Constructor and functions Store::getSortedProductList(SortingCriteria) \n";
           return false;
           set_console_color(WHITE);
       }

       cout <<
           "\nSorting store items by Category: ... \n" << endl;

       expected = readFileToString("output2b.txt");
       got = s2.getSortedProductList(CATEGORY);
       cout << "Expected:\n" << expected << endl;
       cout << "Got     :\n" << got << std::endl;
       if (got != expected)
       {
           set_console_color(RED);
           std::cout << "FAILED: Store information is not as expected\n" <<
               "check Store Constructor and functions Store::getSortedProductList(SortingCriteria) \n";
           return false;
           set_console_color(WHITE);
       }

       cout <<
           "Initializing Store3(\"MagshiPharm\", \"InventoryPharm.csv\"): ... \n" << endl;
       Store s3("MagshiPharm", "InventoryPharm.csv");

       cout <<
           "\nSorting store items by Name: ... \n" << endl;

       expected = readFileToString("output3a.txt");
       got = s3.getSortedProductList(NAME);
       cout << "Expected:\n" << expected << endl;
       cout << "Got     :\n" << got << std::endl;
       if (got != expected)
       {
           set_console_color(RED);
           std::cout << "FAILED: Store information is not as expected\n" <<
               "check Store Constructor and functions Store::getSortedProductList(SortingCriteria) \n";
           return false;
           set_console_color(WHITE);
       }

       cout <<
           "\nSorting store items by Category: ... \n" << endl;

       expected = readFileToString("output3b.txt");
       got = s3.getSortedProductList(CATEGORY);
       cout << "Expected:\n" << expected << endl;
       cout << "Got     :\n" << got << std::endl;
       if (got != expected)
       {
           set_console_color(RED);
           std::cout << "FAILED: Store information is not as expected\n" <<
               "check Store Constructor and functions Store::getSortedProductList(SortingCriteria) \n";
           return false;
           set_console_color(WHITE);
       }

       //////////////////////////////
       // Checking Filter Methods  //
       //////////////////////////////

       cout <<
           "\nFiltering store items by Category = FOOD: ... \n" << endl;

       expected = readFileToString("output3c.txt");
       got = s3.getProductListFilteredByCategory(FOOD);
       cout << "Expected:\n" << expected << endl;
       cout << "Got     :\n" << got << std::endl;
       if (got != expected)
       {
           set_console_color(RED);
           std::cout << "FAILED: Store information is not as expected\n" <<
               "check function Store::getProductListFilteredByCategory(ItemCategory) \n";
           return false;
           set_console_color(WHITE);
       }

       cout <<
           "\nFiltering store items by Category = CLEANING: ... \n" << endl;

       expected = readFileToString("output3d.txt");
       got = s3.getProductListFilteredByCategory(CLEANING);
       cout << "Expected:\n" << expected << endl;
       cout << "Got     :\n" << got << std::endl;
       if (got != expected)
       {
           set_console_color(RED);
           std::cout << "FAILED: Store information is not as expected\n" <<
               "check function Store::getProductListFilteredByCategory(ItemCategory) \n";
           return false;
           set_console_color(WHITE);
       }

       cout <<
           "\nFiltering store items by Category = PHARM: ... \n" << endl;

       expected = readFileToString("output3e.txt");
       got = s3.getProductListFilteredByCategory(PHARM);
       cout << "Expected:\n" << expected << endl;
       cout << "Got     :\n" << got << std::endl;
       if (got != expected)
       {
           set_console_color(RED);
           std::cout << "FAILED: Store information is not as expected\n" <<
               "check function Store::getProductListFilteredByCategory(ItemCategory) \n";
           return false;
           set_console_color(WHITE);
       }
	}
	catch (...)
	{
		set_console_color(RED);
		std::cerr << "Test crashed" << endl;
		std::cout << "FAILED: The program crashed, check the following things:\n" <<
			"1. Did you delete a pointer twice?\n2. Did you accesse index out of bounds?\n" <<
			"3. Did you remember to initialize the lists before using them?";
		return false;
	}

	set_console_color(LIGHT_GREEN);
	std::cout << "\n########## Store - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}

int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"###########################\n" <<
		"Exercise 10 - Magshistore\n" <<
		"Part 2 - Store\n" << 
		"###########################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test2Store();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex10 Part2 Tests Passed!!! ##########" << "\n\n";
		set_console_color(WHITE);
	}
	else
	{
		set_console_color(RED);
		std::cout << "\n########## TEST Failed :( ##########\n";
		set_console_color(WHITE);
	}

	return 0;
}