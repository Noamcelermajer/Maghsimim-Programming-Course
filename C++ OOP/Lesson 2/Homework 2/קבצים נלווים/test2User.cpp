 #include <iostream>
 #include <windows.h> // WinApi header - needed for setting console color
 #include <random>

 #include "User.h"

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

 std::string getUserString(const User& user)
 {
 	return
 		"[ID: " + std::to_string(user.getID()) +
 		", Username: " + user.getUserName() +
 		", Age: " + std::to_string(user.getAge()) +
 		", All devices On: " + (user.checkIfDevicesAreOn() ? "Yes" : "No") + "]";
 }

 std::string getUserDevicesString(User& user)
 {
 	std::string result = "";
 	DevicesList userDevices = user.getDevices();
 	DeviceNode* device = userDevices.get_first();
 	for (; device != nullptr; device = device->get_next())
 	{
 		result += getDeviceString(device->get_data());
 		result += "\n";
 	}
 	if (result != "")
 	{
 		// removes the '\n' at the end of the string
 		result = result.substr(0, result.length() - 1);
 	}
 	return result;
 }

 bool test2User()
 {
 	bool result = false;

 	try
 	{
 		// Tests Ex2 part 2 - User
 		set_console_color(PURPLE);
 		cout <<
 			"********************\n" <<
 			"Test 2 - User				\n" <<
 			"********************\n" << endl;
 		set_console_color(WHITE);

 		cout <<
 			"Initializing 4 Devices: ... \n" << endl;


 		Device device1;
 		device1.init(2123, LAPTOP, WINDOWS11);

 		Device device2;
 		device2.init(3212, PC, UbuntuOS);

 		Device device3;
 		device3.init(1121, TABLET, WINDOWS10);

 		Device device4;
 		device4.init(4134, PHONE, ANDROID);

 		std::string expected = "[ID: 2123, Type: Laptop, OS: Windows11, Activated: Yes]\n";
 		expected += "[ID: 3212, Type: PC, OS: UbuntuLinux, Activated: Yes]\n";
 		expected += "[ID: 1121, Type: Tablet, OS: Windows10, Activated: Yes]\n";
 		expected += "[ID: 4134, Type: Phone, OS: Android, Activated: Yes]";
 		std::string got =
 			getDeviceString(device1) + "\n" +
 			getDeviceString(device2) + "\n" +
 			getDeviceString(device3) + "\n" +
 			getDeviceString(device4);
 		cout << "Expected:\n" << expected << endl;
 		cout << "Got:\n" << got << endl;
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
 			"\nInitializing 2 Users: ... \n" << endl;

 		User user1;
 		user1.init(123456789, "blinkybill", 17);
 		User user2;
 		user2.init(987654321, "HatichEshMiGilShesh", 15);

 		expected = "[ID: 123456789, Username: blinkybill, Age: 17, All devices On: Yes]\n";
 		expected += "[ID: 987654321, Username: HatichEshMiGilShesh, Age: 15, All devices On: Yes]";

 		got =
 			getUserString(user1) + "\n" +
 			getUserString(user2);

 		cout << "Expected:\n" << expected << endl;
 		cout << "Got:\n" << got << endl;
 		if (got != expected)
 		{
 			set_console_color(RED);
 			std::cout << "FAILED: User information is not as expected\n" <<
 				"check functions User::init(), User::getID, User::getUsername(), \n" <<
 				"Device::getAge()\n";
 			return false;
 			set_console_color(WHITE);
 		}

 		cout <<
 			"\nAdding 2 devices to user1: ... \n" << endl;

 		user1.addDevice(device1);
 		user1.addDevice(device2);

 		expected = "[ID: 2123, Type: Laptop, OS: Windows11, Activated: Yes]\n";
 		expected += "[ID: 3212, Type: PC, OS: UbuntuLinux, Activated: Yes]";
 		got = getUserDevicesString(user1);

 		cout << "Expected:\n" << expected << endl;
 		cout << "Got:\n" << got << endl;
 		if (got != expected)
 		{
 			set_console_color(RED);
 			std::cout << "FAILED: User1 information is not as expected\n" <<
 				"check function User::getDevices()\n";
 			return false;
 			set_console_color(WHITE);
 		}

 		cout <<
 			"\nAdding 2 devices to user2: ... \n" << endl;

 		user2.addDevice(device3);
 		user2.addDevice(device4);

 		expected = "[ID: 1121, Type: Tablet, OS: Windows10, Activated: Yes]\n";
 		expected += "[ID: 4134, Type: Phone, OS: Android, Activated: Yes]";
 		got = getUserDevicesString(user2);

 		cout << "Expected:\n" << expected << endl;
 		cout << "Got:\n" << got << endl;
 		if (got != expected)
 		{
 			set_console_color(RED);
 			std::cout << "FAILED: User2 information is not as expected\n" <<
 				"check function User::getDevices()\n";
 			return false;
 			set_console_color(WHITE);
 		}

 		cout <<
 			"\nChecking if devices are on for user1: ... \n" << endl;

 		expected = "true";
 		got = user1.checkIfDevicesAreOn() ? "true" : "false";

 		cout << "Expected:" << expected << endl;
 		cout << "Got     :" << got << endl;
 		if (got != expected)
 		{
 			set_console_color(RED);
 			std::cout << "FAILED: User1 devices should all be ON\n" <<
 				"check function User::init()\n";
 			return false;
 			set_console_color(WHITE);
 		}


 		cout <<
 			"\nDeactivating a device for user2: ... \n" << endl;
 		user2.getDevices().get_first()->get_data().deactivate();
 		cout <<
 			"Checking if devices are on for user2: ... \n" << endl;

 		expected = "false";
 		got = user2.checkIfDevicesAreOn() ? "true" : "false";

 		cout << "Expected:" << expected << endl;
 		cout << "Got     :" << got << endl;
 		if (got != expected)
 		{
 			set_console_color(RED);
 			std::cout << "FAILED: All of User2 devices should NOT be ON\n" <<
 				"check function Device::deactivate()\n";
 			return false;
 			set_console_color(WHITE);
 		}

 		cout <<
 			"\nClears user objects: ... \n" << endl;

 		user1.clear();
 		user2.clear();

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
 	std::cout << "\n########## User - TEST Passed!!! ##########\n\n";
 	set_console_color(WHITE);

 	return true;

 }

 int main()
 {
 	set_console_color(LIGHT_YELLOW);
 	std::cout <<
 		"###########################\n" <<
 		"Exercise 2 - Social Network\n" <<
 		"Part 2 - User\n" <<
 		"###########################\n" << std::endl;
 	set_console_color(WHITE);

 	bool testResult = test2User();

 	if (testResult)
 	{
 		set_console_color(GREEN);
 		std::cout << "\n########## Ex2 Part2 Tests Passed!!! ##########" << "\n\n";
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