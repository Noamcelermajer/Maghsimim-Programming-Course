#include "Profile.h"

void Profile::init(User owner)
{
	this->_owner = owner;
	this->_page.init();
}

std::string Profile::getFriends() const
{
	// create an empty string to store result
	std::string friends = "";

	// starts in the first element
	UserNode* userFriend = this->_friends.get_first();
	for (; userFriend != nullptr; userFriend = userFriend->get_next())
	{
		// adds the username to the result string
		friends += userFriend->get_item().getUserName() + ",";
	}
	if (friends != "")
	{
		// removes the ',' at the end of the string
		friends = friends.substr(0, friends.length() - 1);
	}
	return friends;
}

std::string Profile::getPage() const
{
	return "Status: " + this->_page.getStatus() + "\n" 
		+ "*******************" + "\n" 
		+ "*******************" + "\n" 
		+ this->_page.getPosts();
}

User Profile::getOwner() const
{
	return this->_owner;
}

void Profile::setStatus(const std::string new_status)
{
	// calls Page::setUserStatus
	this->_page.setStatus(new_status);
}

void Profile::addPostToProfilePage(const std::string post)
{
	// calls Page::addLineToPage
	this->_page.addLineToPosts(post);
}

void Profile::addFriend(const User friend_to_add)
{
	// calls UserList::add
	this->_friends.add(friend_to_add);
}

std::string Profile::getFriendsWithSameNameLength() const
{
	// create an empty string to store result
	std::string result = "";

	// starts in the first element
	UserNode* userFriend = this->_friends.get_first();
	for (; userFriend != nullptr; userFriend = userFriend->get_next())
	{
		// adds the username to the result string
		if(this->_owner.getUserName().length() == userFriend->get_item().getUserName().length())
			result += userFriend->get_item().getUserName() + ",";
	}
	if (result != "")
	{
		// removes the ',' at the end of the string
		result = result.substr(0, result.length() - 1);
	}
	return result;
}

void Profile::changeAllWordsInStatus(const std::string word)
{
	const std::string status = this->_page.getStatus();
	std::string newStatus = "";
	bool inWord = false; // true if we reached a new word, false if we finished going over it
	int wordCount = 0; // number of words in the string
	char ch;

	// Going over the status char by char
	for (unsigned int i = 0; i < status.length(); i++)
	{
		// If next character is a separator, set the 
		// add it to the new status, and set inWord to false
		ch = status[i];
		if (ch == ' ' || ch == '\n' || ch == '\t')
		{
			newStatus += ch;
			inWord = false;
		}

		// If next character is not a seperator and 
		// inWord is false, then set inWord to true and 
		// add the word to the newStatus 
		else if (inWord == false)
		{
			newStatus += word;
			inWord = true;
		}
	}
	this->_page.setStatus(newStatus);
}

void Profile::changeWordInStatus(const std::string word_to_replace, const std::string word)
{
	std::string status = this->_page.getStatus();

	// while the word_to_replace appears in the status (uses std::string::find)
	while (status.find(word_to_replace) != std::string::npos)
	{
		// replace the word with the given word (uses std::string::replace)
		status.replace(status.find(word_to_replace), word_to_replace.length(), word);
	}

	// sets the user's status to the new one
	this->_page.setStatus(status);
}
