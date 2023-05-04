 #include <iostream>
 #include <windows.h> // WinApi header - needed for setting console color
 #include <random>

 #include "GenericList.hpp"
 #include "Device.h"
 #include "User.h"
 #include "Profile.h"

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
 	DeviceList userDevices = user.getDevices();
 	DeviceNode* device = userDevices.get_first();
 	for (; device != nullptr; device = device->get_next())
 	{
 		result += getDeviceString(device->get_item());
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

  bool testGenericList()
  {
        // Tests Ex2 part 1 - Device

 		set_console_color(TEAL);
 		cout <<
 			"**************************\n" <<
 			"Test 2 - Basic Templates				\n" <<
 			"**************************\n" << endl;

 		set_console_color(WHITE);

       // creating devices, users and profiles

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

        set_console_color(LIGHT_GREEN);
        std::cout << "OK\n" << std::endl;
        set_console_color(WHITE);

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

        set_console_color(LIGHT_GREEN);
        std::cout << "OK\n" << std::endl;
        set_console_color(WHITE);

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
 
        set_console_color(LIGHT_GREEN);
        std::cout << "OK\n" << std::endl;
        set_console_color(WHITE);

      //////////////////////////////////////
      // Testing Generic List with Device //
      //////////////////////////////////////

      GenericList<Device> myDeviceList;

      // adding devices to list
      myDeviceList.add(device1);
      myDeviceList.add(device2);
      myDeviceList.add(device3);
      myDeviceList.add(device4);
      myDeviceList.add(device5);
      myDeviceList.add(device6);
      myDeviceList.add(device7);
      myDeviceList.add(device8);
      myDeviceList.add(device9);
      myDeviceList.add(device10);
      myDeviceList.add(device11);
      myDeviceList.add(device12);

      // starting from first element
      GenericNode<Device>* curr = myDeviceList.get_first();

      cout <<
          "\nPrinting devices ... \n" << endl;

      // go over the lists elements (stop when "nullptr" is reached)
      for (; curr != nullptr; curr = curr->get_next())
      {
          std::cout << getDeviceString(curr->get_item()) << std::endl;
      }

      //////////////////////////////////////
      // Testing Generic List with User   //
      //////////////////////////////////////

      GenericList<User> myUserList;

      // adding users to list
      myUserList.add(user1);
      myUserList.add(user2);
      myUserList.add(user3);
      myUserList.add(user4);
      myUserList.add(user5);
      myUserList.add(user6);

      // starting from first element
      GenericNode<User>* curr2 = myUserList.get_first();

      cout <<
          "\nPrinting users ... \n" << endl;

      // go over the lists elements (stop when "nullptr" is reached)
      for (; curr2 != nullptr; curr2 = curr2->get_next())
      {
          std::cout << getUserString(curr2->get_item()) << std::endl;
      }

      ////////////////////////////////////////
      // Testing Generic List with Profile  //
      ////////////////////////////////////////

      GenericList<Profile> myProfileList;

      // adding users to list
      myProfileList.add(profile1);
      myProfileList.add(profile2);
      myProfileList.add(profile3);
      myProfileList.add(profile4);
      myProfileList.add(profile5);
      myProfileList.add(profile6);

      // starting from first element
      GenericNode<Profile>* curr3 = myProfileList.get_first();

      cout <<
          "\nPrinting profiles ... \n" << endl;

      // go over the lists elements (stop when "nullptr" is reached)
      for (; curr3 != nullptr; curr3 = curr3->get_next())
      {
          std::cout << getProfileString(curr3->get_item()) << std::endl;
      }

      return true;
  }

  int main()
  {
  	set_console_color(LIGHT_YELLOW);
  	std::cout <<
  		"######################################################\n" <<
  		"Exercise 9 - Binary Search Tree and Templates\n" <<
  		"Part 2 - Introduction to templates\n" << 
  		"######################################################\n" << std::endl;
  	set_console_color(WHITE);

  	bool testResult = testGenericList();

  	if (testResult)
  	{
  		set_console_color(GREEN);
  		std::cout << "\n########## Ex9 Part2 Tests Passed!!! ##########" << "\n\n";
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