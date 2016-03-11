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

}
