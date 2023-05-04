 #include <iostream>
 #include <windows.h> // WinApi header - needed for setting console color
 #include <random>

 #include "Device.h"

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

 std::string getDeviceTypeString(const DeviceType type)
 {
 	if (type == PC)
 		return "PC";
 	else if (type == LAPTOP)
 		return "Laptop";
 	else if (type == TABLET)
 		return "Tablet";
 	else if (type == PHONE)
 		return "Phone";
 	return "Unknown";
 }

 std::string getDeviceString(const Device& device)
 {
 	return
 		"[ID: " + std::to_string(device.getID()) +
 		", Type: " + getDeviceTypeString(device.getType()) +
 		", OS: " + device.getOS() +
 		", Activated: " + (device.isActive() ? "Yes" : "No") + "]";
 }

 bool test1Device()
 {
 	bool result = false;

 	try
 	{
 		// Tests Ex2 part 1 - Device

 		set_console_color(TEAL);
 		cout <<
 			"*******************\n" <<
 			"Test 1 - Device				\n" <<
 			"*******************\n" << endl;

 		set_console_color(WHITE);

 		cout <<
 			"Initializing Device1: ... \n" << endl;

 		Device device1;
 		device1.init(3343, PC, WINDOWS11);
 		std::string expected = "[ID: 3343, Type: PC, OS: Windows11, Activated: Yes]";
 		std::string got = getDeviceString(device1);
 		cout << "Expected: " << expected << endl;
 		cout << "Got     : " << got << std::endl;
 		if (got != expected)
 		{
 			set_console_color(RED);
 			std::cout << "FAILED: Device information is not as expected\n" <<
 				"check functions Device::init(), Device::getID(), \n" <<
 				"Device::getOS(), Device::getType()\n";
 			return false;
 			set_console_color(WHITE);
 		}

 		cout <<
 			"\nDeactivating Device1: ... \n" << endl;
 		device1.deactivate();

 		expected = "[ID: 3343, Type: PC, OS: Windows11, Activated: No]";
 		got = getDeviceString(device1);
 		cout << "Expected: " << expected << endl;
 		cout << "Got     : " << got << std::endl;
 		if (got != expected)
 		{
 			set_console_color(RED);
 			std::cout << "FAILED: Device information is not as expected\n" <<
 				"check functions Device::init(), Device::deactivate()\n";
 			return false;
 			set_console_color(WHITE);
 		}

 		cout <<
 			"\nActivating Device1: ... \n" << endl;
 		device1.activate();

 		expected = "[ID: 3343, Type: PC, OS: Windows11, Activated: Yes]";
 		got = getDeviceString(device1);
 		cout << "Expected: " << expected << endl;
 		cout << "Got     : " << got << std::endl;
 		if (got != expected)
 		{
 			set_console_color(RED);
 			std::cout << "FAILED: Device should be ON\n" <<
 				"check function Device::activate()\n";
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
 	std::cout << "\n########## Device - TEST Passed!!! ##########\n\n";
 	set_console_color(WHITE);

 	return true;

 }

 int main()
 {
 	set_console_color(LIGHT_YELLOW);
 	std::cout <<
 		"###########################\n" <<
 		"Exercise 2 - Social Network\n" <<
 		"Part 1 - Device\n" << 
 		"###########################\n" << std::endl;
 	set_console_color(WHITE);

 	bool testResult = test1Device();

 	if (testResult)
 	{
 		set_console_color(GREEN);
 		std::cout << "\n########## Ex2 Part1 Tests Passed!!! ##########" << "\n\n";
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