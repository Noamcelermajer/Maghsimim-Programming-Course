#pragma once
#include "GenericList.hpp"
#include "Device.h"

typedef GenericNode<Device> DeviceNode;
typedef  GenericList<Device> DeviceList;

class User
{
public:
	// initializes a new user with id, username and age
	void init(const unsigned int id, const std::string username, const unsigned int age);

	// getters
	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DeviceList& getDevices();

	// adds a Device object to the user's devices list
	void addDevice(const Device newDevice);

	// return false if there is a device which is NOT active
	bool checkIfDevicesAreOn() const;

private:

	// fields
	unsigned int _id;
	std::string _username;
	unsigned int age;
	DeviceList _devices;
};

