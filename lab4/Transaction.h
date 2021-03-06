#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
#include "Item.h"
using namespace std;
class Customer;
class Transaction
{
public:
	//PSEUDO DESCRIPTION -- Constructor //
	Transaction();
	/*
	* set the item pointer 
	* set some transaction type as default
	*/
	//PSEUDO DESCRIPTION -- Copy Constructor //
	Transaction(const Transaction &);
	/*
	* set each value
	*/
	virtual ~Transaction();
	//PSEUDO DESCRIPTION -- Set Data //
	virtual void setData(string media, Item *theItem, Customer *theCustomer);
	/*
	* uses instream to get the data
	* of the transaction into the obj
	*/
	//PSEUDO DESCRIPTION -- DISPLAY //
	virtual void Display() const;
	/*
	* cout the tranasaction 
	*/
	//PSEUDO DESCRIPTION -- Create Transaction //
	virtual Transaction* create();
	/*
	* return a newly created transaction object
	*/
	//PSEUDO DESCRIPTION -- GEt MEdia Type //
	string getMediaType() const;
	/*
	*	return the type of media in transaction
	*/
	//PSEUDO DESCRIPTION -- Get Trans Type //
	string getTransactionType() const;
	/*
	* return the trans type
	*/
	//PSEUDO DESCRIPTION -- GEt Item //
	Item* getItem() const;
	/*
	* return a pointer to the item
	*/
	
protected:
	string transactionType;
	string mediaType;
	Item* thisItem;
};
#endif

