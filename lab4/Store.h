#ifndef STORE_H
#define STORE_H
#include <string>
#include <iostream>
#include <iomanip>
#include "Item.h"
#include "BinTree.h"
#include "Customer.h"
#include "HashFactory.h"
#include "Globals.h"
using namespace std;
extern const int MAX_COPIES;
extern const int MAX_CUSTOMERS;
extern const int MAX_AMT;

class Store
{
public:
	
	//PSEUDO DESCRIPTION -- CONSTRUCTOR //
	Store();
	/*
	* inintialize a store object with default name
	* set as "The Store"
	*/
	//PSEUDO DESCRIPTION -- CONSTRUCTOR W/ NAME//
	Store(string name);
	/*
	* initialize a store item by setting the name 
	* of the store to the name passed in
	*/
	// DEFAULT DESTRUCTOR
	~Store();
	//PSEUDO DESCRIPTION -- DO INVENTORY //
	void doInventory(istream &);
	/*
	* char code = ""
	* for each line in the file 
	*	take in the char code
	*	check for end of file
	*	create pointer for the new item 
	*	use the factory to create and pass back the item
	*	if (valid item)
	*		use hash function to get index
	*		set the data of the item 
	*		place the item into an inventory array
	*		use the hashed index when placing
	*	if (couldnt insert || invalid item)
	*		delete the pointer for no leaks
	*		set things to null
	*/
	//PSEUDO DESCRIPTION -- Read Transactions //
	void readTransactions(ifstream &);
	/*
	*
	*
	*
	*/
	//PSEUDO DESCRIPTION -- Display Inventory //
	
	void PopulateAccounts(istream &theStream);

	void diplayInventory() const;
	/*
	*	print out name of store
	*	some kind of formatting
	*	for (length of inventory array)
	*		print out available items in BinTree
	*/
	//PSEUDO DESCRIPTION -- Does Customer Exist //
	bool customerExists(int id) const;
	/*
	*	takes in id
	*	search customer array for id
	*	return whether id was found
	*/
	//PSEUDO DESCRIPTION -- Get Name of Store //
	string getStoreName() const;
	/*
	*	return the store name
	*/

private:
	// Array that holds customer records
	Customer customerAccounts[MAX_CUSTOMERS];
	// Creates the items
	HashFactory factory;
	// name of the business
	string name;
	// Array with Bintrees representing movie
	// inventory by genre
	BinTree movieInventory[MAX_AMT];
};
#endif
