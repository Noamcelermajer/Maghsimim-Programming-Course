#include"Customer.h"
#include "Store.h"
#include<map>


int main()
{

	std::map<std::string, Customer> abcCustomers;
	
	Store s1("Shefa Isaschar", "InventorySuperMarket.csv");
	Store s2("MagshIKEA", "InventoryIKEA.csv");
	Store s3("MagshiPharm", "InventoryPharm.csv");

	return 0;
}