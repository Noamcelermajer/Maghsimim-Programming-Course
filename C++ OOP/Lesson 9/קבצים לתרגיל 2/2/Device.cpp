#include "Device.h"

void Device::init(const unsigned int id, DeviceType type, std::string os)
{
	this->_id = id;
	this->_type = type;
	this->_os = os;
	this->_active = true;	// device starts in "active" mode
}

unsigned int Device::getID() const
{
	return this->_id;
}

DeviceType Device::getType() const
{
	return this->_type;
}

std::string Device::getOS() const
{
	return this->_os;
}

bool Device::isActive() const
{
	return this->_active;
}

void Device::activate()
{
	this->_active = true;
}

void Device::deactivate()
{
	this->_active = false;
}
