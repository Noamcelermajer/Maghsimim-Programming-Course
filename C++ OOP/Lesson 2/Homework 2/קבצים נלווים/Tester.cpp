#include <iostream>
#include <windows.h> // WinApi header - needed for setting console color
#include <random>

#include "SocialNetwork.h"

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

std::string posts[] = { "Hello world!",
						"Good morning :)",
						"Magshimim forever ***" ,
						"Ekronot is the best...",
						"Happy birthday! Ad 120" };

std::string statusMessages[] = 
					{"Feeling sick, need chicken soup... can you bring me some?",
					"Which witch watched which watch??? you must tell me!!!",
					"Finally got my driver license !!!, when are you getting yours?",
					"\"No matter how smart you are, you can never convince someone stupid that they are stupid.\"",
					"Have you ever wondered why you can't taste your tongue?"};

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

// gets a random number between a range of numbers
int getRandomInt(int min, int max)
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

	auto random_integer = uni(rng);
	return random_integer;
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

std::string getProfileString(const Profile& profile)
{
	return
		"Owner: " + getUserString(profile.getOwner()) + "\n" +
		profile.getOwner().getUserName() + "'s page:\n" + 
		profile.getPage();
}

void allFriends(Profile* profiles[], const int numOfProfiles)
{
	for (unsigned int i = 0; i < numOfProfiles; i++)
	{
		for (unsigned int j = 0; j < numOfProfiles; j++)
		{
			if (j != i)
			{
				profiles[i]->addFriend(profiles[j]->getOwner());
			}
		}
	}
}

void generateRandomPage(Profile& profile)
{
	std::string status = statusMessages[getRandomInt(0, 4)];
	profile.setStatus(status);

	int numberOfPosts = getRandomInt(0, 3);
	std::string post;
	for (unsigned int i = 0; i < numberOfPosts; i++)
	{
		post = posts[getRandomInt(0, 4)] ;
		profile.addPostToProfilePage(post);
	}
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
			"Clears user objects: ... \n" << endl;

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

bool test3Profile()
{
	bool result = false;

	try
	{
		// Tests Ex2 part 3 - Profile
		set_console_color(LIGHT_BLUE);
		cout <<
			"*******************\n" <<
			"Test 3 - Profile				\n" <<
			"*******************\n" << endl;

		set_console_color(WHITE);
		cout <<
			"Initializing 12 Devices: ... \n" << endl;

		Device device1;
		device1.init(2123, LAPTOP, WINDOWS11);

		Device device2;
		device2.init(3212, PC, UbuntuOS);

		Device device3;
		device3.init(1121, TABLET, WINDOWS10);

		Device device4;
		device4.init(4134, PHONE, ANDROID);

		Device device5;
		device5.init(5522, LAPTOP, MacOS);

		Device device6;
		device6.init(5361, PC, WINDOWS7);

		Device device7;
		device7.init(6611, PHONE, IOS);

		Device device8;
		device8.init(6613, LAPTOP, RedHatOS);

		Device device9;
		device9.init(7711, TABLET, WINDOWS11);

		Device device10;
		device10.init(8181, TABLET, ANDROID);

		Device device11;
		device11.init(8654, LAPTOP, UbuntuOS);

		Device device12;
		device12.init(9444, PC, WINDOWS11);

		cout <<
			"Initializing 6 Users: ... \n" << endl;

		User user1;
		user1.init(123456789, "Gal", 17);
		User user2;
		user2.init(987654321, "Avi", 15);
		User user3;
		user3.init(135792486, "Tom", 12);
		User user4;
		user4.init(123456789, "Nitzan", 12);
		User user5;
		user5.init(111222333, "Shlomo", 14);
		User user6;
		user6.init(222444666, "Rinat", 16);
		cout <<
			"Adding 2 devices to each user: ... \n" << endl;

		user1.addDevice(device1);
		user1.addDevice(device2);
		user2.addDevice(device3);
		user2.addDevice(device4);
		user3.addDevice(device5);
		user3.addDevice(device6);
		user4.addDevice(device7);
		user4.addDevice(device8);
		user5.addDevice(device9);
		user5.addDevice(device10);
		user6.addDevice(device11);
		user6.addDevice(device12);

		cout <<
			"Creating a profile for each user with empty status and posts: ... \n" << endl;

		Profile profile1;
		profile1.init(user1);
		Profile profile2;
		profile2.init(user2);
		Profile profile3;
		profile3.init(user3);
		Profile profile4;
		profile4.init(user4);
		Profile profile5;
		profile5.init(user5);
		Profile profile6;
		profile6.init(user6);

		std::string expected = "";
		expected += "Owner: [ID: 123456789, Username: Gal, Age: 17, All devices On: Yes]\n";
		expected += "Gal's page:\nStatus: \n*******************\n*******************\n";
		expected += "Owner: [ID: 987654321, Username: Avi, Age: 15, All devices On: Yes]\n";
		expected += "Avi's page:\nStatus: \n*******************\n*******************\n";
		expected += "Owner: [ID: 135792486, Username: Tom, Age: 12, All devices On: Yes]\n";
		expected += "Tom's page:\nStatus: \n*******************\n*******************\n";
		expected += "Owner: [ID: 123456789, Username: Nitzan, Age: 12, All devices On: Yes]\n";
		expected += "Nitzan's page:\nStatus: \n*******************\n*******************\n";
		expected += "Owner: [ID: 111222333, Username: Shlomo, Age: 14, All devices On: Yes]\n";
		expected += "Shlomo's page:\nStatus: \n*******************\n*******************\n";
		expected += "Owner: [ID: 222444666, Username: Rinat, Age: 16, All devices On: Yes]\n";
		expected += "Rinat's page:\nStatus: \n*******************\n*******************\n";
		std::string got = 
			getProfileString(profile1) +
			getProfileString(profile2) +
			getProfileString(profile3) + 
			getProfileString(profile4) +
			getProfileString(profile5) +
			getProfileString(profile6);

		cout << "Expected:\n" << expected << endl;
		cout << "\nGot:\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Profile information is not as expected\n" <<
						"check if the profile is initialized properly\n";
			return false;
			set_console_color(WHITE);
		}

		cout <<
			"Adding friends (all to all): ... \n" << endl;
		Profile* profiles[] = { (&profile1), (&profile2), &profile3, (&profile4), (&profile5) , (&profile6)};
		allFriends(profiles, 6);
		
		cout <<
			"Printing Gal's friends: ... \n" << endl;

		expected = "Avi,Tom,Nitzan,Shlomo,Rinat";
		got = profile1.getFriends();

		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Expected different result\n" <<
				"check function Profile::getFriends()\n";
			return false;
			set_console_color(WHITE);
		}

		cout <<
			"\nPrinting friends with same names for Gal: ... \n" << endl;

		expected = "Avi,Tom";
		got = profile1.getFriendsWithSameNameLength();

		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Wrong users printed\n" <<
						"check function Profile::getFriendsWithSameNameLength\n";
			return false;
			set_console_color(WHITE);
		}

		cout <<
			"\nPrinting friends with same names for Nitzan: ... \n" << endl;

		expected = "Shlomo";
		got = profile4.getFriendsWithSameNameLength();

		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Wrong users printed\n" <<
				"check function Profile::getFriendsWithSameNameLength\n";
			return false;
			set_console_color(WHITE);
		}

		cout <<
			"\nPrinting friends with same names for Rinat: ... \n" << endl;

		expected = "";
		got = profile6.getFriendsWithSameNameLength();

		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Wrong users printed\n" <<
				"check function Profile::getFriendsWithSameNameLength\n";
			return false;
			set_console_color(WHITE);
		}

		cout <<
			"\nAdding status and posts to user1's profile: ... \n" << endl;

		profile1.setStatus(statusMessages[1]); // "Which witch ... watch"
		profile1.addPostToProfilePage(posts[0]); // "Hello world!",
		profile1.addPostToProfilePage(posts[1]); // "Good morning :)"
		profile1.addPostToProfilePage(posts[2]); // "Magshimim forever ***"

		expected = "Owner: [ID: 123456789, Username: Gal, Age: 17, All devices On: Yes]\n";
		expected += "Gal's page:\n";
		expected += "Status: Which witch watched which watch??? you must tell me!!!\n";
		expected += "*******************\n";
		expected += "*******************\n";
		expected += "Hello world!\n";
		expected += "Good morning :)\n";
		expected += "Magshimim forever ***\n";
		got = getProfileString(profile1);

		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Page information is not as expected\n" <<
				"check functions Profile::getPage(), Profile::getStatus(), " <<
				"Profile::setStatus(), Profile::addPostToProfilePage() \n";
			return false;
			set_console_color(WHITE);
		}

		cout <<
			"Clears User objects: ... \n" << endl;

		user1.clear();
		user2.clear();
		user3.clear();
		user4.clear();
		user5.clear();
		user6.clear();

		cout <<
			"Clears Profile object: ... \n" << endl;

		profile1.clear();
		profile2.clear();
		profile3.clear();
		profile4.clear();
		profile5.clear();
		profile6.clear();

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
	std::cout << "\n########## Profile - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}

bool checkAllWordsAreAlikeInStatus(std::string str)
{
	const std::string word = "Magshimim";
	int pos = -1;

	// removes seperators

	while ((pos = str.find('\n')) != std::string::npos)
		str.replace(pos, 1, "");
	
	while ((pos = str.find(' ')) != std::string::npos)
		str.replace(pos, 1, "");

	while ((pos = str.find('\t')) != std::string::npos)
		str.replace(pos, 1, "");

	// removes all the instances of the word
	while ((pos = str.find(word)) != std::string::npos)
		str.replace(pos, word.length(), "");
	
	// if any characters left, return false
	if (str.length() != 0)
		return false;

	return true;
}

bool checkWordDoesNotExistInStatus(std::string status, const std::string& word)
{
	return status.find(word) == std::string::npos;
}

bool test3Bonus()
{
	// Tests Ex2 part 3 - Profile
	set_console_color(PURPLE);
	cout <<
		"****************************\n" <<
		"Test 3 Bonus - Word Change				\n" <<
		"****************************\n" << endl;

	set_console_color(WHITE);
	cout <<
		"Initializing 2 Devices: ... \n" << endl;

	Device device1;
	device1.init(2123, LAPTOP, WINDOWS11);

	Device device2;
	device2.init(3212, PC, UbuntuOS);

	cout <<
		"Initializing user1: ... \n" << endl;

	User user1;
	user1.init(123456789, "Gal", 17);

	cout <<
		"Creating a profile for the user with random status and posts: ... \n" << endl;

	Profile profile1;
	profile1.init(user1);

	generateRandomPage(profile1);
	std::string got = getProfileString(profile1);
	cout << got << endl;

	cout <<
		"Changing all words in the status to \"Magshimim\": ... \n" << endl;
	profile1.changeAllWordsInStatus("Magshimim");
	got = getProfileString(profile1);
	cout << got << endl;

	// cutting the status out of the page
	std::string statusToCheck = profile1.getPage();
	statusToCheck = statusToCheck.substr(8, statusToCheck.length());
	statusToCheck = statusToCheck.substr(0, statusToCheck.find_first_of('\n'));
	
	// if there is one word that is different from the other return false
	if (checkAllWordsAreAlikeInStatus(statusToCheck) == false)
	{
		set_console_color(RED);
		cout << "FAILED: There are words different than \"Magshimim\" in the status" << endl;
		set_console_color(WHITE);
		return false;
	}

	cout <<
		"Initializing a user1: ... \n" << endl;

	User user2;
	user2.init(123456789, "Nitzan", 12);

	cout <<
		"Creating a profile for the user with random status and posts: ... \n" << endl;

	Profile profile2;
	profile2.init(user2);

	generateRandomPage(profile2);
	got = getProfileString(profile2);
	cout << got << endl;

	std::string word_to_replace = "you";
	std::string replacement = "MMMMMMMMMM";

	cout <<
		"Changing the word \"" << word_to_replace << "\" in the status to \"" << replacement << "\": ... \n" << endl;
	profile2.changeWordInStatus(word_to_replace, "MMMMMMMMMM");
	got = getProfileString(profile2);
	cout << got << endl;

	// cutting the status out of the page
	statusToCheck = profile2.getPage();
	statusToCheck = statusToCheck.substr(8, statusToCheck.length());
	statusToCheck = statusToCheck.substr(0, statusToCheck.find_first_of('\n'));
	
	// checks that the word is not in the status
	if (checkWordDoesNotExistInStatus(statusToCheck, word_to_replace) == false)
	{
		set_console_color(RED);
		cout << "The word \"" << word_to_replace << "\" appers in the status" << endl;
		set_console_color(WHITE);
		return false;
	}

	cout <<
		"\nClears User objects: ... \n" << endl;

	user1.clear();
	user2.clear();

	cout <<
		"\nClears User objects: ... \n" << endl;

	profile1.clear();
	profile2.clear();

	set_console_color(LIGHT_GREEN);
	std::cout << "\n########## Profile Bonus - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;
}

bool test4SocialNetwork()
{
	bool result = false;

	try
	{
		// Tests Ex2 part 3 - Profile
		set_console_color(6);
		cout <<
			"*************************\n" <<
			"Test 4 - Social Network \n" <<
			"*************************\n" << endl;

		set_console_color(WHITE);
		cout <<
			"Initializing 12 Devices: ... \n" << endl;

		Device device1;
		device1.init(2123, LAPTOP, WINDOWS11);

		Device device2;
		device2.init(3212, PC, UbuntuOS);

		Device device3;
		device3.init(1121, TABLET, WINDOWS10);

		Device device4;
		device4.init(4134, PHONE, ANDROID);

		Device device5;
		device5.init(5522, LAPTOP, MacOS);

		Device device6;
		device6.init(5361, PC, WINDOWS7);

		Device device7;
		device7.init(6611, PHONE, IOS);

		Device device8;
		device8.init(6613, LAPTOP, RedHatOS);

		Device device9;
		device9.init(7711, TABLET, WINDOWS11);

		Device device10;
		device10.init(8181, TABLET, ANDROID);

		Device device11;
		device11.init(8654, LAPTOP, UbuntuOS);

		Device device12;
		device12.init(9444, PC, WINDOWS11);

		cout <<
			"Initializing 6 Users: ... \n" << endl;

		User user1;
		user1.init(123456789, "Gal", 17);
		User user2;
		user2.init(987654321, "Avi", 15);
		User user3;
		user3.init(135792486, "Tom", 13);
		User user4;
		user4.init(123456789, "Nitzan", 12);
		User user5;
		user5.init(111222333, "Shlomo", 14);
		User user6;
		user6.init(222444666, "Rinat", 16);
		cout <<
			"Adding 2 devices to each user: ... \n" << endl;

		user1.addDevice(device1);
		user1.addDevice(device2);
		user2.addDevice(device3);
		user2.addDevice(device4);
		user3.addDevice(device5);
		user3.addDevice(device6);
		user4.addDevice(device7);
		user4.addDevice(device8);
		user5.addDevice(device9);
		user5.addDevice(device10);
		user6.addDevice(device11);
		user6.addDevice(device12);

		cout <<
			"Creating a profile for each user with empty status and posts: ... \n" << endl;

		Profile profile1;
		profile1.init(user1);
		Profile profile2;
		profile2.init(user2);
		Profile profile3;
		profile3.init(user3);
		Profile profile4;
		profile4.init(user4);
		Profile profile5;
		profile5.init(user5);
		Profile profile6;
		profile6.init(user6);

		std::string expected = "";
		std::string got =
			getProfileString(profile1) +
			getProfileString(profile2) +
			getProfileString(profile3) +
			getProfileString(profile4) +
			getProfileString(profile5) +
			getProfileString(profile6);

		cout << "Profiles:\n" << got << endl;

		cout <<
			"Creating a social network with minimal age of 13 ... \n" << endl;

		SocialNetwork sn;
		sn.init("Magshimim Network", 13);

		expected = "[Name: Magshimim Network, Minimal Age: 13]";
		got = "[Name: " + sn.getNetworkName();
		got += ", Minimal Age: " + std::to_string(sn.getMinAge()) + "]";

		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Wrong devices printed\n" <<
				"check function SocialNetwork::getWindowsDevices\n";
			return false;
			set_console_color(WHITE);
		}

		cout <<
			"\nTrying to add all users ... \n" << endl;

		std::cout << "profile1 " << 
			(sn.addProfile(profile1) ? "Added Successfully\n":"Cannot add because user is too young\n");
		std::cout << "profile2 " << 
			(sn.addProfile(profile2) ? "Added Successfully\n":"Cannot add because user is too young\n");
		std::cout << "profile3 " << 
			(sn.addProfile(profile3) ? "Added Successfully\n":"Cannot add because user is too young\n");
		std::cout << "profile4 " << 
			(sn.addProfile(profile4) ? "Added Successfully\n":"Cannot add because user is too young\n");
		std::cout << "profile5 " << 
			(sn.addProfile(profile5) ? "Added Successfully\n":"Cannot add because user is too young\n");
		std::cout << "profile6 " << 
			(sn.addProfile(profile6) ? "Added Successfully\n":"Cannot add because user is too young\n");

		cout <<
			"\nAdding friends (all to all): ... \n" << endl;
		Profile* profiles[] = { (&profile1), (&profile2), &profile3, (&profile4), (&profile5) , (&profile6) };
		allFriends(profiles, 6);

		cout <<
			"Printing devices that runs Windows OS: ... \n" << endl;

		expected = "[2123, Windows11], [1121, Windows10], [5361, Windows7], [7711, Windows11], [9444, Windows11]";
		got = sn.getWindowsDevices();

		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			std::cout << "FAILED: Wrong devices printed\n" <<
				"check function SocialNetwork::getWindowsDevices\n";
			return false;
			set_console_color(WHITE);
		}

		cout <<
			"Clears User objects: ... \n" << endl;

		user1.clear();
		user2.clear();
		user3.clear();
		user4.clear();
		user5.clear();
		user6.clear();

		cout <<
			"Clears Profile object: ... \n" << endl;

		profile1.clear();
		profile2.clear();
		profile3.clear();
		profile4.clear();
		profile5.clear();
		profile6.clear();
		
		cout <<
			"\nClears SocialNetwork object: ... \n" << endl;
		sn.clear();

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
	std::cout << "\n########## Social Network - TEST Passed!!! ##########\n";
	set_console_color(WHITE);

	return true;

}

std::string goodJob()
{
	std::string result = "";
	result += "  ________                  .___      ____.     ___.    \n";
	result += " /  _____/  ____   ____   __| _/     |    | ____\\_ |__  \n" ;
	result += "/   \\  ___ /  _ \\ /  _ \\ / __ |      |    |/  _ \\| __ \\ \n" ;
	result += "\\    \\_\\  (  <_> |  <_> ) /_/ |  /\\__|    (  <_> ) \\_\\ \\ \n" ;
	result += " \\______  /\\____/ \\____/\\____ |  \\________|\\____/|___  / \n" ;
	result += "        \\/                   \\/                      \\/  \n";

	return result;
}

int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout << 
		"###########################\n" <<
		"Exercise 2 - Social Network\n" << 
		"###########################\n" << std::endl;
	set_console_color(WHITE);

	bool test1Result = test1Device();
	bool test2Result = test2User();
	bool test3Result = test3Profile();
	bool test3BResult = test3Bonus();
	bool test4Result = test4SocialNetwork();

	if (test1Result && test2Result && test3Result)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex2 Tests Passed!!! ##########\n" << goodJob() <<
					"\n\t\t\tYou are amazing!!!\n" << 
					(test3BResult ? "\t\t\tAnd you also did the bonus, that's wonderful!!!" : "") << "\n\n";
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