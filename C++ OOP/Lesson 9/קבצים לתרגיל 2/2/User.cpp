#include "User.h"

void User::init(const unsigned int id, const std::string username, const unsigned int age)
{
	this->_id = id;
	this->_username = username;
	this->age = age;
}

unsigned int User::getID() const
{
	return this->_id;
}

std::string User::getUserName() const
{
	return this->_username;
}

unsigned int User::getAge() const
{
	return this->age;
}

DeviceList& User::getDevices()
{
	// returns a reference to the user device list
	return this->_devices;
}

void User::addDevice(const Device newDevice)
{
	// calls the add method of DeviceList class
	this->_devices.add(newDevice);
}

bool User::checkIfDevicesAreOn() const
{
	// starts in the first element
	DeviceNode* device = this->_devices.get_first();

	// go over the lists elements (stop when "nullptr" is reached)
	for (; device != nullptr; device = device->get_next())
	{
		// checking the state of the current device
		if (device->get_item().isActive() == false)
			return false;
	}
	return true;
}
