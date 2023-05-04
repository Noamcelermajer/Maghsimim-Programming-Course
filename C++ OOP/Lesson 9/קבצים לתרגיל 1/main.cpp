#include "BSNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "printTreeToFile.h"

using std::cout;
using std::endl;

int main()
{
	BSNode* bs = new BSNode("6");
	bs->insert("2");
	bs->insert("8");
	bs->insert("3");
	bs->insert("5");
	bs->insert("9");
	bs->insert("6");

	
	cout << "Tree height: " << bs->getHeight() << endl;
	cout << "depth of node with 5 depth: " << bs->getLeft()->getRight()->getRight()->getDepth(*bs) << endl;
	cout << "depth of node with 3 depth: " << bs->getLeft()->getRight()->getDepth(*bs) << endl;

	
	std::string textTree = "BSTData.txt";
	printTreeToFile(bs, textTree);

	system("BinaryTree.exe");
	system("pause");
	remove(textTree.c_str());
	delete bs;

	return 0;
}

