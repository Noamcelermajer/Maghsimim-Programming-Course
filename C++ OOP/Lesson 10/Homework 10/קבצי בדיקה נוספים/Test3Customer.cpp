#include <iostream>
#include <windows.h> // WinApi header - needed for setting console color
#include <random>
#include <fstream>
#include <sstream>

#include "Store.h"
#include "Customer.h"

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

std::string getShoppingCartString(std::set<Item>* shoppingCart, const std::string shoppingCartName)
{
    std::string result = "Items in shopping cart: " + shoppingCartName + "\n";
    for (auto it = shoppingCart->begin(); it != shoppingCart->end(); it++)
    {
        result += getItemString(*it) + "\n";
    }
    return result;
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



bool test3Customer()
{
    bool result = false;

    try
    {
        // Tests Ex10 part 3 - Customer

        set_console_color(PURPLE);
        cout <<
            "*******************\n" <<
            "Test 3 - Customer	\n" <<
            "*******************\n" << endl;

        set_console_color(WHITE);


        cout <<
            "Initializing 2 stores\n" <<
            "Store1(\"MagshIKEA\", \"InventoryIKEA.csv\"): ... \n" <<
            "Store2(\"Shefa Isaschar\", \"InventorySuperMarket.csv\"): ... \n" << endl;

        Store s1("MagshIKEA", "InventoryIKEA.csv");
        Store s2("Shefa Isaschar", "InventorySuperMarket.csv");

        cout <<
            "\nInitializing customer c1(\"Moti Vazia\": ... \n" << endl;
        
        Customer c1("Moti Vazia");

 		set_console_color(GREEN);
		cout << "OK" << std::endl;
		set_console_color(WHITE);

        const std::string shoppingCart1Name = "HomeStuff";

        cout <<
            "\nCreating a new shopping cart for the customer - c1.createNewShoppingCart(\"HomeStuff\"): ... \n" << endl;
        c1.createNewShoppingCart(shoppingCart1Name);

        cout <<
            "\nadding the following items from store 1: ... \n" << 
            "item #11 - Wooden Chair X 4\n" << 
            "item #12 - Bar Chair X 4\n" << 
            "item #21 - OfficeDesk X 1\n" << endl;

        c1.addItem(s1[11], shoppingCart1Name);
        c1.addItem(s1[11], shoppingCart1Name);
        c1.addItem(s1[11], shoppingCart1Name);
        c1.addItem(s1[11], shoppingCart1Name);

        c1.addItem(s1[12], shoppingCart1Name);
        c1.addItem(s1[12], shoppingCart1Name);
        c1.addItem(s1[12], shoppingCart1Name);
        c1.addItem(s1[12], shoppingCart1Name);

        c1.addItem(s1[21], shoppingCart1Name);

        cout <<
            "\nPrinting shopping basket customer \"" << shoppingCart1Name << "\" ... \n" << endl;
        std::set<Item>* shoppingCart1 = c1.getShoppingCart(shoppingCart1Name);

        std::string expected = readFileToString("outputPart31a.txt");
        std::string got = getShoppingCartString(c1.getShoppingCart(shoppingCart1Name), shoppingCart1Name);
        cout << "Expected:\n" << expected << endl;
        cout << "Got     :\n" << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Customer information is not as expected\n" <<
                "check functions Customer::getShoppingCart(string), addItem(Item, string) \n";
            return false;
            set_console_color(WHITE);
        }

        const std::string shoppingCart2Name = "Groceries";

        cout <<
            "\nCreating a new shopping cart for the customer - c1.createNewShoppingCart(\"Groceries\"): ... \n" << endl;
        c1.createNewShoppingCart(shoppingCart2Name);

        cout <<
            "\nadding the following items from store 2: ... \n" <<
            "item #02 - Milk 3% 1 liter X 2\n" <<
            "item #21 - Mineral Water 6 pack X 1\n" <<
            "item #24 - Olive Oil 750ml X 1\n" << 
            "item #11 - Tomato 0.5 kg X 3\n" <<
            "item #12 - Carrot 0.5 kg X 1\n" <<
            "item #15 - Red Onion 0.5 kg X 1\n" <<
            "item #06 - Butter 100g X 2\n" <<
            "item #09 - Eggs size Large X 2\n" <<
            "item #20 - Pasta 1kg X 4\n" << endl;

        c1.addItem(s2[2], shoppingCart2Name);
        c1.addItem(s2[2], shoppingCart2Name);

        c1.addItem(s2[21], shoppingCart2Name);

        c1.addItem(s2[24], shoppingCart2Name);

        c1.addItem(s2[11], shoppingCart2Name);
        c1.addItem(s2[11], shoppingCart2Name);
        c1.addItem(s2[11], shoppingCart2Name);

        c1.addItem(s2[12], shoppingCart2Name);

        c1.addItem(s2[15], shoppingCart2Name);

        c1.addItem(s2[6], shoppingCart2Name);
        c1.addItem(s2[6], shoppingCart2Name);
        
        c1.addItem(s2[9], shoppingCart2Name);
        c1.addItem(s2[9], shoppingCart2Name);

        c1.addItem(s2[20], shoppingCart2Name);
        c1.addItem(s2[20], shoppingCart2Name);
        c1.addItem(s2[20], shoppingCart2Name);
        c1.addItem(s2[20], shoppingCart2Name);

        cout <<
            "\nPrinting shopping cart customer \"" << shoppingCart2Name << "\" ... \n" << endl;
        std::set<Item>* shoppingCart2 = c1.getShoppingCart(shoppingCart2Name);

        expected = readFileToString("outputPart31b.txt");
        got = getShoppingCartString(c1.getShoppingCart(shoppingCart2Name), shoppingCart2Name);
        cout << "Expected:\n" << expected << endl;
        cout << "Got     :\n" << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Customer information is not as expected\n" <<
                "check functions Customer::getShoppingCart(string), addItem(Item, string) \n";
            return false;
            set_console_color(WHITE);
        }

        cout <<
            "\nremoving the following items from shopping basket \"Groceries\": ... \n" <<
            "item #11 - Tomato 0.5 kg X 2\n" <<
            "item #12 - Carrot 0.5 kg X 1\n" <<
            "item #06 - Butter 100g X 2\n" <<
            "item #09 - Eggs size Large X 1\n" <<
            "item #20 - Pasta 1kg X 1\n" << endl;

        c1.removeItem(s2[11], shoppingCart2Name);
        c1.removeItem(s2[11], shoppingCart2Name);
        c1.removeItem(s2[11], shoppingCart2Name);

        c1.removeItem(s2[15], shoppingCart2Name);

        c1.removeItem(s2[6], shoppingCart2Name);
        c1.removeItem(s2[6], shoppingCart2Name);

        c1.removeItem(s2[9], shoppingCart2Name);

        c1.removeItem(s2[20], shoppingCart2Name);

        cout <<
            "\nPrinting shopping cart customer \"" << shoppingCart2Name << "\" ... \n" << endl;

        expected = readFileToString("outputPart31c.txt");
        got = getShoppingCartString(c1.getShoppingCart(shoppingCart2Name), shoppingCart2Name);
        cout << "Expected:\n" << expected << endl;
        cout << "Got     :\n" << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Customer information is not as expected\n" <<
                "check functions Customer::getShoppingCart(string), removeItem(Item, string) \n";
            return false;
            set_console_color(WHITE);
        }

        ////////////////////////////
        // Checking Sum functions //
        ////////////////////////////
        cout <<
            "\nPrinting shopping cart sum \"" << shoppingCart1Name << "\" ... \n" << endl;

        expected = "3598.000000";
        got = std::to_string(c1.shoppingCartSum(shoppingCart1Name));

        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Customer information is not as expected\n" <<
                "check function Customer::shoppingCartSum(string) \n";
            return false;
            set_console_color(WHITE);
        }

        cout <<
            "\nPrinting shopping cart sum \"" << shoppingCart2Name << "\" ... \n" << endl;
        expected = "97.808000";
        got = std::to_string(c1.shoppingCartSum(shoppingCart2Name));

        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Customer information is not as expected\n" <<
                "check function Customer::shoppingCartSum(string) \n";
            return false;
            set_console_color(WHITE);
        }

        cout <<
            "\nPrinting total sum for the customer ... \n" << endl;
        expected = "3695.808000";
        got = std::to_string(c1.totalSum());

        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Customer information is not as expected\n" <<
                "check function Customer::totalSum() \n";
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
    std::cout << "\n########## Customer - TEST Passed!!! ##########\n\n";
    set_console_color(WHITE);

    return true;

}

int main()
{
    set_console_color(LIGHT_BLUE);
    std::cout <<
        "###########################\n" <<
        "Exercise 10 - Magshistore\n" <<
        "Part 3 - Customer\n" <<
        "###########################\n" << std::endl;
    set_console_color(WHITE);

    bool testResult = test3Customer();

    if (testResult)
    {
        set_console_color(GREEN);
        std::cout << "\n########## Ex10 Part3 Tests Passed!!! ##########" << "\n\n";
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