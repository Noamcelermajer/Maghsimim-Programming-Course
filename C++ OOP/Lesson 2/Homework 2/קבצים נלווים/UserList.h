#pragma once
#include "User.h"

/** A short class that represents a Node in a user linked list */
class UserNode
{
public:
	void init(const User user);

	// getters
	UserNode* get_next() const;
	User get_data() const;

	// setters
	void set_next(UserNode* next);
	void set_data(const User new_user);

private:
	// fields
	User _data;
	UserNode* _next;
};

/** A short class that represents a linked list that holds Devices */
class UserList
{
public:
	/** initialize an empty list */
	void init();
	void clear();

	// getters
	UserNode* get_first() const;

	// setters
	void set_first(UserNode* first);

	/** adds a User object to the end of the list
	 * returns true if the string added successfully, false otherwise **/
	bool add(const User user_to_add);

private:
	UserNode* _first;   // first Node in the list
};


