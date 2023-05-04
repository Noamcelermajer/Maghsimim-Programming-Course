#include "UserList.h"

#include <iostream>
using std::cout;
using std::endl;

/* initialize a new Node object that stores the given data */
void UserNode::init(const User user)
{
	this->_data = user;
	this->_next = nullptr;
}

// getters

UserNode* UserNode::get_next() const
{
	return this->_next;
}

User UserNode::get_data() const
{
	return this->_data;
}

// setters

void UserNode::set_next(UserNode* next)
{
	this->_next = next;
}

void UserNode::set_data(const User new_data)
{
	this->_data = new_data;
}

/** initialize an empty list */
void UserList::init()
{
	this->_first = nullptr;
}

/** clears the list's memory */
void UserList::clear()
{
	UserNode* temp;
	while (this->_first != nullptr) // as long as the list is not empty
	{
		temp = this->_first;    // temp points to the first element
		this->_first = this->_first->get_next();   // the list now starts from the 2nd element
		delete temp;    // deletes the previous first element
	}
}

// getters
UserNode* UserList::get_first() const
{
	return this->_first;
}

// setters
void UserList::set_first(UserNode* first)
{
	this->_first = first;
}

/** adds a User to the end of the list **/
bool UserList::add(const User new_user)
{
	// create a new node to store the User object
	UserNode* new_node = new UserNode;
	new_node->init(new_user);

	if (this->_first == nullptr) // list is empty
	{
		this->_first = new_node; // the new node is the first node
	}
	else        // list has at least one element
	{
		UserNode* curr = this->_first;      // start from first
		while (curr->get_next() != nullptr) // advance to the last element
		{
			curr = curr->get_next();
		}
		curr->set_next(new_node); // add the new node at the end of the list
	}
	return true;
}
