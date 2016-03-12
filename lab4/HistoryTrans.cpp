#include "HistoryTrans.h"
/*
* initiallize the type to HISTORY
*/
HistoryTrans::HistoryTrans()
{
	this->transactionType = "History";
}

/*
* set values in this to other
*/
HistoryTrans::HistoryTrans(const HistoryTrans & other)
{
	this->transactionType = other.transactionType;
	this->mediaType = other.mediaType;
	this->thisItem = other.thisItem;
}


HistoryTrans::~HistoryTrans()
{
}

/*
* gets the file stream to set the information
* for this tranascation of type HISTORY
*/
void HistoryTrans::setData(string media, Item * theItem, Customer * theCustomer)
{
	theCustomer->displayHistory();
}

/*
* displays the media type and the trans type
*/
void HistoryTrans::Display() const
{
	cout << "Display History Transaction" << endl;
}

/*
* return the newly created HISTORY obj
*
*/
Transaction * HistoryTrans::create()
{
	return new HistoryTrans();
}
