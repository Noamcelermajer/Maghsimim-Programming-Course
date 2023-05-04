 #include <iostream>
 #include <windows.h> // WinApi header - needed for setting console color
 #include <random>

 #include "Item.h"

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

 std::string getItemCategoryString(const ItemCategory type)
 {
     if (type == NONE)
         return "NONE";
     else if (type == FOOD)
         return "Food";
     else if (type == PHARM)
         return "Pharm";
     else if (type == CLEANING)
         return "Cleaning";
     else if (type == HOME)
         return "Home";
 	return "Unknown";
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

 bool test1Item()
 {
 	bool result = false;

 	try
 	{
 		// Tests Ex10 part 1 - Item

 		set_console_color(TEAL);
 		cout <<
 			"*******************\n" <<
 			"Test 1 - Item				\n" <<
 			"*******************\n" << endl;

 		set_console_color(WHITE);

 		cout <<
 			"Initializing Item1: ... \n" << endl;

 		Item item1("White Sliced Bread 750g", "BFTRZ", 5.12, FOOD);
 		std::string expected = "[Serial: BFTRZ, Name: White Sliced Bread 750g, Category: Food, Price: 5.120000, Amount: 1]";
 		std::string got = getItemString(item1);
 		cout << "Expected: " << expected << endl;
 		cout << "Got     : " << got << std::endl;
 		if (got != expected)
 		{
 			set_console_color(RED);
 			std::cout << "FAILED: Item information is not as expected\n" <<
 				"check Item Constructor and functions Item::getSerial(), Item::getName(), \n" <<
 				"Item::getCategory(), Item::getPrice(), Item::getCount\n";
 			return false;
 			set_console_color(WHITE);
 		}

        cout <<
            "\nInitializing Item2: ... \n" << endl;

        Item item2("Table Salt 1kg", "vT0LC", 2.07, FOOD);
        expected = "[Serial: vT0LC, Name: Table Salt 1kg, Category: Food, Price: 2.070000, Amount: 1]";
        got = getItemString(item2);
        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Item information is not as expected\n" <<
                "check Item Constructor and functions Item::getSerial(), Item::getName(), \n" <<
                "Item::getCategory(), Item::getPrice(), Item::getCount\n";
            return false;
            set_console_color(WHITE);
        }

        cout <<
            "\nInitializing Item3: ... \n" << endl;

        Item item3("Milk 3% 1 liter", "USlOG", 5.17, FOOD);
        expected = "[Serial: USlOG, Name: Milk 3% 1 liter, Category: Food, Price: 5.170000, Amount: 1]";
        got = getItemString(item3);
        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Item information is not as expected\n" <<
                "check Item Constructor and functions Item::getSerial(), Item::getName(), \n" <<
                "Item::getCategory(), Item::getPrice(), Item::getCount\n";
            return false;
            set_console_color(WHITE);
        }

        cout <<
            "\nInitializing Item4: ... \n" << endl;

        Item item4("Office Desk IKEA", "pj77k", 1050.0, HOME);
        expected = "[Serial: pj77k, Name: Office Desk IKEA, Category: Home, Price: 1050.000000, Amount: 1]";
        got = getItemString(item4);
        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Item information is not as expected\n" <<
                "check Item Constructor and functions Item::getSerial(), Item::getName(), \n" <<
                "Item::getCategory(), Item::getPrice(), Item::getCount\n";
            return false;
            set_console_color(WHITE);
        }

        cout <<
            "\nInitializing Item5: ... \n" << endl;

        Item item5("Leather Sofa Brown 3 Seats IKEA", "LBbGn", 1099.0, HOME);
        expected = "[Serial: LBbGn, Name: Leather Sofa Brown 3 Seats IKEA, Category: Home, Price: 1099.000000, Amount: 1]";
        got = getItemString(item5);
        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Item information is not as expected\n" <<
                "check Item Constructor and functions Item::getSerial(), Item::getName(), \n" <<
                "Item::getCategory(), Item::getPrice(), Item::getCount\n";
            return false;
            set_console_color(WHITE);
        }

        cout <<
            "\nInitializing Item6: ... \n" << endl;

        Item item6("Mouth Wash 500ml", "8sZ4N", 36.9, PHARM);
        expected = "[Serial: 8sZ4N, Name: Mouth Wash 500ml, Category: Pharm, Price: 36.900000, Amount: 1]";
        got = getItemString(item6);
        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Item information is not as expected\n" <<
                "check Item Constructor and functions Item::getSerial(), Item::getName(), \n" <<
                "Item::getCategory(), Item::getPrice(), Item::getCount\n";
            return false;
            set_console_color(WHITE);
        }

        cout <<
            "\nInitializing Item7: ... \n" << endl;

        Item item7("Shampoo 750ml", "G9vKR", 10.9, PHARM);
        expected = "[Serial: G9vKR, Name: Shampoo 750ml, Category: Pharm, Price: 10.900000, Amount: 1]";
        got = getItemString(item7);
        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Item information is not as expected\n" <<
                "check Item Constructor and functions Item::getSerial(), Item::getName(), \n" <<
                "Item::getCategory(), Item::getPrice(), Item::getCount\n";
            return false;
            set_console_color(WHITE);
        }

        cout <<
            "\nInitializing Item8: ... \n" << endl;

        Item item8("Bleach 2 liter", "boPnl", 12.5, CLEANING);
        expected = "[Serial: boPnl, Name: Bleach 2 liter, Category: Cleaning, Price: 12.500000, Amount: 1]";
        got = getItemString(item8);
        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Item information is not as expected\n" <<
                "check Item Constructor and functions Item::getSerial(), Item::getName(), \n" <<
                "Item::getCategory(), Item::getPrice(), Item::getCount\n";
            return false;
            set_console_color(WHITE);
        }

        //////////////////////////////
        // Checking Price and Count //
        //////////////////////////////

 		cout <<
 			"\nSetting Item1 Counter to 5: ... \n" << endl;
 		item1.setCount(5);

        expected = "[Serial: BFTRZ, Name: White Sliced Bread 750g, Category: Food, Price: 5.120000, Amount: 5]";
        got = getItemString(item1);
        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Item information is not as expected\n" <<
                "check functions Item::setCount(int) Item::getSerial(), Item::getName(), \n" <<
                "Item::getCategory(), Item::getPrice(), Item::getCount\n";
            return false;
            set_console_color(WHITE);
        }

        cout <<
            "\nCalculating item1 total price: ... \n" << endl;
        item1.setCount(5);

        expected = "25.600000";
        got = std::to_string(item1.totalPrice());
        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Item information is not as expected\n" <<
                "check functions Item::totalPrice() \n";
            return false;
            set_console_color(WHITE);
        }

        cout <<
            "\nSetting Item7 Counter to 34 and Calculating item7 total price: ... \n" << endl;
        item7.setCount(34);

        expected = "370.600000";
        got = std::to_string(item7.totalPrice());
        cout << "Expected: " << expected << endl;
        cout << "Got     : " << got << std::endl;
        if (got != expected)
        {
            set_console_color(RED);
            std::cout << "FAILED: Item information is not as expected\n" <<
                "check functions Item::setCount(int), Item::totalPrice() \n";
            return false;
            set_console_color(WHITE);
        }

        ////////////////////////////
        // Checking Bad Arguments //
        ////////////////////////////

        try
		{
            cout <<
                "\nTrying to initialize a bad item: ..." << endl;
            cout << "[Serial: y3hMm, Name: Eye Contacts liquid 350ml, Category: Pharm, Price: -49.900000, Amount: 1]\n";
            cout <<
                "Price is negative - Expecting std::invalid_argument... \n" << endl;

            Item badItem1("Eye Contacts liquid 350ml", "y3hMm", -49.9, PHARM);

            set_console_color(RED);
			std::cout << "Should have thrown an std::invalid_argument" << std::endl;
            set_console_color(WHITE);
			return false;
		}
		catch (const std::invalid_argument& e)
		{
			cout << "Got std::invalid_argument " << std::endl;
			set_console_color(GREEN);
			cout << "OK" << std::endl;
			set_console_color(WHITE);
		}
		catch (const std::exception& e)
		{
			set_console_color(YELLOW);
			cout << "Got <" << typeid(e).name() << ">" << std::endl;
			cout << "WARNING: got an exception, should be std::invalid_argument\n";
			set_console_color(WHITE);
		}
		catch (...)
		{
			set_console_color(RED);
			cout << "Object thrown" << std::endl;
			cout << "FAILED: catched an object, should be either std::invalid_argument or exception\n";
			set_console_color(WHITE);
			return false;
		}

        try
        {
            cout <<
                "\nTrying to initialize a bad item: ..." << endl;
            cout << "[Serial: abcdefg, Name: Dishwash Soap 515ml, Category: Cleaning, Price: 13.9, Amount: 1]\n";
            cout <<
                "\nSerial is not 5 characters - Expecting std::invalid_argument... \n" << endl;

            Item badItem2("Dishwash Soap 515ml", "abcdefg", 13.9, CLEANING);

            set_console_color(RED);
            std::cout << "Should have thrown an std::invalid_argument" << std::endl;
            set_console_color(WHITE);
            return false;
        }
        catch (const std::invalid_argument& e)
        {
            cout << "Got std::invalid_argument" << std::endl;
            set_console_color(GREEN);
            cout << "OK" << std::endl;
            set_console_color(WHITE);
        }
        catch (const std::exception& e)
        {
            set_console_color(YELLOW);
            cout << "Got <" << typeid(e).name() << ">" << std::endl;
            cout << "WARNING: got an exception, should be std::InvalidArgument\n";
            set_console_color(WHITE);
        }
        catch (...)
        {
            set_console_color(RED);
            cout << "Object thrown" << std::endl;
            cout << "FAILED: catched an object, should be either std::InvalidArgument or exception\n";
            set_console_color(WHITE);
            return false;
        }

        try
        {
            cout <<
                "\nTrying to set a bad parameter to item4: ..." << endl;
            cout << "item4.setCount(0)\n";
            cout <<
                "\nItem's count must be positive - Expecting std::invalid_argument... \n" << endl;

            item4.setCount(0);

            set_console_color(RED);
            std::cout << "Should have thrown an std::invalid_argument" << std::endl;
            set_console_color(WHITE);
            return false;
        }
        catch (const std::invalid_argument& e)
        {
            cout << "Got std::invalid_argument" << std::endl;
            set_console_color(GREEN);
            cout << "OK" << std::endl;
            set_console_color(WHITE);
        }
        catch (const std::exception& e)
        {
            set_console_color(YELLOW);
            cout << "Got <" << typeid(e).name() << ">" << std::endl;
            cout << "WARNING: got an exception, should be std::InvalidArgument\n";
            set_console_color(WHITE);
        }
        catch (...)
        {
            set_console_color(RED);
            cout << "Object thrown" << std::endl;
            cout << "FAILED: catched an object, should be either std::InvalidArgument or exception\n";
            set_console_color(WHITE);
            return false;
        }

        try
        {
            cout <<
                "\nTrying to set a bad parameter to item6: ..." << endl;
            cout << "item6.setCount(-10)\n";
            cout <<
                "\nItem's count must be positive - Expecting std::invalid_argument... \n" << endl;

            item6.setCount(-10);

            set_console_color(RED);
            std::cout << "Should have thrown an std::invalid_argument" << std::endl;
            set_console_color(WHITE);
            return false;
        }
        catch (const std::invalid_argument& e)
        {
            cout << "Got std::invalid_argument" << std::endl;
            set_console_color(GREEN);
            cout << "OK" << std::endl;
            set_console_color(WHITE);
        }
        catch (const std::exception& e)
        {
            set_console_color(YELLOW);
            cout << "Got <" << typeid(e).name() << ">" << std::endl;
            cout << "WARNING: got an exception, should be std::InvalidArgument\n";
            set_console_color(WHITE);
        }
        catch (...)
        {
            set_console_color(RED);
            cout << "Object thrown" << std::endl;
            cout << "FAILED: catched an object, should be either std::InvalidArgument or exception\n";
            set_console_color(WHITE);
            return false;
        }

        ///////////////////////////////
        // Checking Operators <,>,== //
        ///////////////////////////////

        cout <<
            "\nComparing items: ... \n" << endl;

        bool result = item1 < item2;
        cout <<
            "item1 < item2: expected: true got: " << (result ? "true" : "false") << " -->";
        if (result == true)
        {
            set_console_color(GREEN);
            cout << " OK" << std::endl;
            set_console_color(WHITE);
        }
        else
        {
   		    set_console_color(YELLOW);
		    cout << " NOT OK" << std::endl;
		    set_console_color(WHITE);
            return 1;
        }

        result = item5 > item7;
        cout <<
            "item5 > item7: expected: true got: " << (result ? "true" : "false") << " -->";
        if (result == true)
        {
            set_console_color(GREEN);
            cout << " OK" << std::endl;
            set_console_color(WHITE);
        }
        else
        {
            set_console_color(YELLOW);
            cout << " NOT OK" << std::endl;
            set_console_color(WHITE);
            return 1;
        }

        result = item1 == item2;
        cout <<
            "item1 == item2: expected: false got: " << (result ? "true" : "false") << " -->";
        if (result == false)
        {
            set_console_color(GREEN);
            cout << " OK" << std::endl;
            set_console_color(WHITE);
        }
        else
        {
            set_console_color(YELLOW);
            cout << " NOT OK" << std::endl;
            set_console_color(WHITE);
            return 1;
        }

        result = item8 < item7;
        cout <<
            "item8 < item7: expected: false got: " << (result ? "true" : "false") << " -->";
        if (result == false)
        {
            set_console_color(GREEN);
            cout << " OK" << std::endl;
            set_console_color(WHITE);
        }
        else
        {
            set_console_color(YELLOW);
            cout << " NOT OK" << std::endl;
            set_console_color(WHITE);
            return 1;
        }

        result = item5 > item2;
        cout <<
            "item5 < item2: expected: false got: " << (result ? "true" : "false") << " -->";
        if (result == false)
        {
            set_console_color(GREEN);
            cout << " OK" << std::endl;
            set_console_color(WHITE);
        }
        else
        {
            set_console_color(YELLOW);
            cout << " NOT OK" << std::endl;
            set_console_color(WHITE);
            return 1;
        }

        result = item3 > item8;
        cout <<
            "item3 > item8: expected: false got: " << (result ? "true" : "false") << " -->";
        if (result == false)
        {
            set_console_color(GREEN);
            cout << " OK" << std::endl;
            set_console_color(WHITE);
        }
        else
        {
            set_console_color(YELLOW);
            cout << " NOT OK" << std::endl;
            set_console_color(WHITE);
            return 1;
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
 	std::cout << "\n########## Item - TEST Passed!!! ##########\n\n";
 	set_console_color(WHITE);

 	return true;

 }

 int main()
 {
 	set_console_color(LIGHT_YELLOW);
 	std::cout <<
 		"###########################\n" <<
 		"Exercise 10 - Magshistore\n" <<
 		"Part 1 - Item\n" << 
 		"###########################\n" << std::endl;
 	set_console_color(WHITE);

 	bool testResult = test1Item();

 	if (testResult)
 	{
 		set_console_color(GREEN);
 		std::cout << "\n########## Ex10 Part1 Tests Passed!!! ##########" << "\n\n";
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