#include "Transaction.h"

Transaction::Transaction()
{
	this->thisItem = NULL;
	this->transactionType = "Transaction";
	this->mediaType = "";
}


Transaction::~Transaction()
{
}

string Transaction::getMediaType() const
{
	return this->mediaType;
}

string Transaction::getTransactionType() const
{
	return this->transactionType;
}

Item * Transaction::getItem() const
{
	return this->thisItem;
}

Transaction::Transaction(const Transaction &other)
{
	this->thisItem = other.thisItem;
	this->transactionType = other.transactionType;
	this->mediaType = other.mediaType;
}

