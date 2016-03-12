#include "stdafx.h"
#include "BorrowTrans.h"


/*
* initiallize the type to BORROW
*/
BorrowTrans::BorrowTrans()
{
	transactionType = "Borrow";
}

/*
* set values in this to other
*/
BorrowTrans::BorrowTrans(const BorrowTrans & other)
{
	this->transactionType = other.transactionType;
	this->mediaType = other.mediaType;
	this->thisItem = other.thisItem;
}


BorrowTrans::~BorrowTrans()
{
}

/*
* gets the file stream to set the information
* for this tranascation of type borrow
*/
void BorrowTrans::setData(string media, Item *theItem, Customer *theCustomer)
{
	if (theItem != NULL)
	{
		this->mediaType = media;
		this->thisItem = theItem;
		theItem->decreaseCopies();
	}
}

/*
* displays the media type and the trans type
*/
void BorrowTrans::Display() const
{
	cout << mediaType << " " << transactionType;
	if (thisItem != NULL)
	{
		cout << " ";
		thisItem->display();
	}
	cout << endl;
}

/*
* return the newly created BOrrow obj
*
*/
Transaction * BorrowTrans::create()
{
	return new BorrowTrans();
}
