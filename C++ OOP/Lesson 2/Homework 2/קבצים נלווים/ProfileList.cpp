#include "ProfileList.h"

#include <iostream>
using std::cout;
using std::endl;

/* initialize a new Node object that stores the given data */

void ProfileNode::init(const Profile profile)
{
	this->_data = profile;
	this->_next = nullptr;
}

// getters

ProfileNode* ProfileNode::get_next() const
{
	return this->_next;
}

Profile ProfileNode::get_data() const
{
	return this->_data;
}

// setters

void ProfileNode::set_next(ProfileNode* next)
{
	this->_next = next;
}

void ProfileNode::set_data(const Profile new_data)
{
	this->_data = new_data;
}

/** initialize an empty list */
void ProfileList::init()
{
	this->_first = nullptr;
}

/** clears the list's memory */
void ProfileList::clear()
{
	ProfileNode* temp;
	while (this->_first != nullptr) // as long as the list is not empty
	{
		temp = this->_first;    // temp points to the first element
		this->_first = this->_first->get_next();   // the list now starts from the 2nd element
		delete temp;    // deletes the previous first element
	}
}

// getters
ProfileNode* ProfileList::get_first() const
{
	return this->_first;
}

// setters
void ProfileList::set_first(ProfileNode* first)
{
	this->_first = first;
}

/** adds a Profile to the end of the list **/
bool ProfileList::add(const Profile new_Profile)
{
	// create a new node to store the profile object
	ProfileNode* new_node = new ProfileNode;
	new_node->init(new_Profile);

	if (this->_first == nullptr) // list is empty
	{
		this->_first = new_node; // the new node is the first node
	}
	else        // list has at least one element
	{
		ProfileNode* curr = this->_first;      // start from first
		while (curr->get_next() != nullptr) // advance to the last element
		{
			curr = curr->get_next();
		}
		curr->set_next(new_node); // add the new node at the end of the list
	}
	return true;
}
