#pragma once
#include "GenericList.hpp"
#include "Page.h"
#include "User.h"
#include <string>

typedef GenericNode<User> UserNode;
typedef  GenericList<User> UserList;


class Profile
{
public:

	// intialize a new profile and sets the owner
	void init(User owner);

	// releases momory allocated and clears object
	void clear();

	// returns the user that owns the profile
	User getOwner() const;

	// returns a string with the usernames of the owner's friends seperated by comma
	// example: "friend_1, friend_2, ... , friend_n"
	std::string getFriends() const;

	// returns the page of the user
	std::string getPage() const;


	// sets a status for the profile page
	void setStatus(const std::string new_status);

	// sets a status for the profile page
	void addPostToProfilePage(const std::string post);

	// adds a friend to the user's friends list
	void addFriend(const User friend_to_add);

	// gets a string with all friends that has the same username length
	// example: owner = "Shlomo" , Friends: "Avner,Nitzan,Motti,Maya,Lilach"
	// result: "Nitzan,Lilach"
	std::string getFriendsWithSameNameLength() const;

	///////////// Bonus /////////////

	// changes all the words in the user's status to the given word
	void changeAllWordsInStatus(const std::string word);

	// replaces all instances of a word in the user's status to the given word
	void changeWordInStatus(const std::string word_to_replace, const std::string word);
	
private:
	User _owner;
	UserList _friends;
	Page _page;
};

