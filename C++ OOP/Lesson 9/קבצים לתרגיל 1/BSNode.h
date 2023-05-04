#pragma once

#include <string>

class BSNode
{
public:
	BSNode(std::string data);
	BSNode(const BSNode& other);

	~BSNode();
	
	void insert(std::string value);
	BSNode& operator=(const BSNode& other);

	bool isLeaf() const;
	std::string getData() const;
	int getCount() const;
	/***/ getLeft() const;
	/***/ getRight() const;


	bool search(std::string val) const;

	int getHeight() const;
	int getDepth(const BSNode& root) const;

	void printNodes() const; //for question 1 part C

private:
	std::string _data;
	/***/ _left;
	/***/ _right;

	int _count; //for question 1 part B
	int getCurrNodeDistFromInputNode(const BSNode* node) const; //auxiliary function for getDepth

};