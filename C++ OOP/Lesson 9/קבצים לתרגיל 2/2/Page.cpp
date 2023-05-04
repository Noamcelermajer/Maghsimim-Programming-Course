#include "Page.h"

void Page::init()
{
	this->_posts = "";
	this->_status = "";
}

std::string Page::getPosts() const
{
	return this->_posts;
}

std::string Page::getStatus() const
{
	return this->_status;
}

void Page::clearPage()
{
	this->_posts = "";
}

void Page::setStatus(const std::string status)
{
	this->_status = status;
}

void Page::addLineToPosts(const std::string new_line)
{
	this->_posts += new_line + "\n";
}

