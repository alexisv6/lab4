#include "ReturnTrans.h"



ReturnTrans::ReturnTrans()
{
	transactionType = "Return";
}

ReturnTrans::ReturnTrans(const ReturnTrans & other)
{
	this->transactionType = other.transactionType;
	this->mediaType = other.mediaType;
	this->thisItem = other.thisItem;
}


ReturnTrans::~ReturnTrans()
{
}

void ReturnTrans::setData(string media, Item * theItem, Customer * theCustomer)
{
	if (theItem != NULL)
	{
		this->mediaType = media;
		this->thisItem = theItem;
		theItem->increaseCopies();
	}
}

void ReturnTrans::Display() const
{
	cout << mediaType << " " << transactionType;
	if (thisItem != NULL)
	{
		cout << " ";
		thisItem->display();
	}
	cout << endl;
}

Transaction * ReturnTrans::create()
{
	return new ReturnTrans();
}
