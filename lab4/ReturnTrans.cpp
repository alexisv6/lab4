#include "stdafx.h"
#include "ReturnTrans.h"


/*
* initiallize the type to RETURN
*/
ReturnTrans::ReturnTrans()
{
	transactionType = "Return";
}

/*
* COPY CONTRUCTOR - set values in this to other
*/
ReturnTrans::ReturnTrans(const ReturnTrans & other)
{
	this->transactionType = other.transactionType;
	this->mediaType = other.mediaType;
	this->thisItem = other.thisItem;
}


ReturnTrans::~ReturnTrans()
{
}

/*
* gets the file stream to set the information
* for this tranascation of type RETURN
*/
void ReturnTrans::setData(string media, Item * theItem, Customer * theCustomer)
{
	if (theItem != NULL)
	{
		this->mediaType = media;
		this->thisItem = theItem;
		theItem->increaseCopies();
	}
}

/*
* displays the media type and the trans type
*/
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

/*
* return the newly created RETURN obj
* 
*/
Transaction * ReturnTrans::create()
{
	return new ReturnTrans();
}
