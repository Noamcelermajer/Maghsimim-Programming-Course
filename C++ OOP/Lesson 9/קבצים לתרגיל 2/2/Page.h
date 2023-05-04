#pragma once
#include <string>

class Page
{
public:
	
	// initiates a new empty page with no status
	void init();

	// NOTE: Device class doesn't need a clear() method,
	//		 No dynamic memory allocated for the object

	// getters
	std::string getPosts() const;
	std::string getStatus() const;

	// clears the page and sets a new user status 
	void setStatus(const std::string status);

	// adds a line to the page
	void addLineToPosts(const std::string new_line);

	// clears all lines from page except status
	void clearPage();

private:
	std::string _posts;
	std::string _status;
};

