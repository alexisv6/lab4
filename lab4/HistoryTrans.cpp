#include "stdafx.h"
#include "HistoryTrans.h"



HistoryTrans::HistoryTrans()
{
	this->transactionType = "History";
}

HistoryTrans::HistoryTrans(const HistoryTrans & other)
{
	this->transactionType = other.transactionType;
	this->mediaType = other.mediaType;
	this->thisItem = other.thisItem;
}


HistoryTrans::~HistoryTrans()
{
}

void HistoryTrans::setData(string media, Item * theItem, Customer * theCustomer)
{
	theCustomer->displayHistory();
}

void HistoryTrans::Display() const
{
	cout << "Display History Transaction" << endl;
}

Transaction * HistoryTrans::create()
{
	return new HistoryTrans();
}
