#pragma once
#include"Item.h"
#include<set>
#include<map>

class Customer
{
public:
	// constructors
	Customer(std::string);
	Customer();

	// destructors
	~Customer();
	
	// methods
	
	double shoppingCartSum(std::string shoppingCartName); // returns the payment sum for a given shopping cart;
	double totalSum();//returns the total sum for payment

	void addItem(Item, std::string shoppingCartName);//add item to the set
	void removeItem(Item, std::string shoppingCartName);//remove item from the set

	//get and set functions

	std::string getName();	// returns the customer name
	std::set<Item>* getShoppingCart(std::string shoppingCartName) ; // returns the shopping cart with the given name

private:
	std::string _name; // Customer name
	std::map<std::string, std::set<Item>*> _shoppingCarts; // Shopping carts


};
