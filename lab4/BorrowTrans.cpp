#include "stdafx.h"
#include "BorrowTrans.h"



BorrowTrans::BorrowTrans()
{
	transactionType = "Borrow";
}

BorrowTrans::BorrowTrans(const BorrowTrans & other)
{
	this->transactionType = other.transactionType;
	this->mediaType = other.mediaType;
	this->thisItem = other.thisItem;
}


BorrowTrans::~BorrowTrans()
{
}

void BorrowTrans::setData(string media, Item *theItem, Customer *theCustomer)
{
	if (theItem != NULL)
	{
		this->mediaType = media;
		this->thisItem = theItem;
		theItem->decreaseCopies();
	}
}

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

Transaction * BorrowTrans::create()
{
	return new BorrowTrans();
}
