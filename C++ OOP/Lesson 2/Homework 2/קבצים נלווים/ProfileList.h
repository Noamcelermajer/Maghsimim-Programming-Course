#pragma once
#include "Profile.h"

/** A short class that represents a Node in a devices linked list */
class ProfileNode
{

public:
	void init(const Profile profile);

	// getters
	ProfileNode* get_next() const;
	Profile get_data() const;

	// setters
	void set_next(ProfileNode* next);
	void set_data(const Profile new_device);

private:
	Profile _data;
	ProfileNode* _next;

};

class ProfileList
{

public:

	/** initialize an empty list */
	void init();
	void clear();

	// getters
	ProfileNode* get_first() const;

	// setters
	void set_first(ProfileNode* first);

	/** adds a Profile object to the end of the list
	 * returns true if the string added successfully, false otherwise **/
	bool add(const Profile user_to_add);

private:
	ProfileNode* _first;   // first Node in the list

};

