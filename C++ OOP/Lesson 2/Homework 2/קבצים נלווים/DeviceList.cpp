#include "DeviceList.h"
#include <iostream>
using std::cout;
using std::endl;

/* initialize a new Node object that stores the given data */

void DeviceNode::init(const Device device)
{
	this->_data = device;
	this->_next = nullptr;
}

// getters

DeviceNode* DeviceNode::get_next() const
{
	return this->_next;
}

Device& DeviceNode::get_data()
{
	return this->_data;
}

// setters

void DeviceNode::set_next(DeviceNode* next)
{
	this->_next = next;
}

void DeviceNode::set_data(const Device new_data)
{
	this->_data = new_data;
}

/** initialize an empty list */
void DevicesList::init()
{
	this->_first = nullptr;
}

/** clears the list's memory */
void DevicesList::clear()
{
	DeviceNode* temp;
	while (this->_first != nullptr) // as long as the list is not empty
	{
		temp = this->_first;    // temp points to the first element
		this->_first = this->_first->get_next();   // the list now starts from the 2nd element
		delete temp;    // deletes the previous first element
	}
}

// getters
DeviceNode* DevicesList::get_first() const
{
	return this->_first;
}

// setters
void DevicesList::set_first(DeviceNode* first)
{
	this->_first = first;
}

/** adds a device to the end of the list **/
void DevicesList::add(const Device new_device)
{
	// create a new node to store the Device object
	DeviceNode* new_node = new DeviceNode;
	new_node->init(new_device);

	if (this->_first == nullptr) // list is empty
	{
		this->_first = new_node; // the new node is the first node
	}
	else        // list has at least one element
	{
		DeviceNode* curr = this->_first;      // start from first
		while (curr->get_next() != nullptr) // advance to the last element
		{
			curr = curr->get_next();
		}
		curr->set_next(new_node); // add the new node at the end of the list
	}
}

