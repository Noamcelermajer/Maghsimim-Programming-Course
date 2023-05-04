#pragma once

#include "Device.h"

/** A short class that represents a Node in a devices linked list */
class DeviceNode
{
public:
	void init(const Device device);

	// getters
	DeviceNode* get_next() const;
	Device& get_data();

	// setters
	void set_next(DeviceNode* next);
	void set_data(const Device new_device);

private:

	// fields
	Device _data;
	DeviceNode* _next;
};

/** A short class that represents a linked list that holds Devices */
class DevicesList
{
public:
	/** initialize an empty list */
	void init();
	void clear();

	// getters
	DeviceNode* get_first() const;

	// setters
	void set_first(DeviceNode* first);

	// adds a Device object to the end of the list
	void add(const Device device_to_add);

private:
	DeviceNode* _first;   // first Node in the list
};


