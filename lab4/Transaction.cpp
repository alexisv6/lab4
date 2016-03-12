#include "Transaction.h"

/*
* set the item pointer
* set some transaction type as default
*/
Transaction::Transaction()
{
	this->thisItem = NULL;
	this->transactionType = "Transaction";
	this->mediaType = "";
}

/*
* set each value
*/
Transaction::~Transaction()
{
}

/*
* uses instream to get the data
* of the transaction into the obj
*/
void Transaction::setData(string media, Item * theItem, Customer * theCustomer)
{
	this->mediaType = media;
	this->thisItem = theItem;
}

/*
* cout the tranasaction
*/
void Transaction::Display() const
{
	cout << mediaType << " " << transactionType << " ";
	thisItem->display();
}

/*
* return a newly created transaction object
*/
Transaction * Transaction::create()
{
	return new Transaction();
}

/*
*	return the type of media in transaction
*/
string Transaction::getMediaType() const
{
	return this->mediaType;
}

/*
* return the trans type
*/
string Transaction::getTransactionType() const
{
	return this->transactionType;
}

/*
* return the item
*/
Item * Transaction::getItem() const
{
	return this->thisItem;
}

/*
* Copy Constructor - copy all of the values in struct
*/
Transaction::Transaction(const Transaction &other)
{
	this->thisItem = other.thisItem;
	this->transactionType = other.transactionType;
	this->mediaType = other.mediaType;
}

