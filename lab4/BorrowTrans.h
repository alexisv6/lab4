#pragma once
#include "Transaction.h"
class BorrowTrans :
	public Transaction
{
public:
	//PSEUDO DESCRIPTION -- Constructor //
	BorrowTrans();
	/*
	* initiallize the type to BORROW
	*/
	//PSEUDO DESCRIPTION -- Copy Constructor //
	BorrowTrans(const BorrowTrans &other);
	/*
	* set values in this to other
	*/
	//PSEUDO DESCRIPTION -- Destructor //
	virtual~BorrowTrans();
	//PSEUDO DESCRIPTION -- Set DAta //
	virtual void setData(string media, Item *theItem, Customer *theCustomer);
	/*
	* gets the file stream to set the information
	* for this tranascation of type borrow
	*/
	//PSEUDO DESCRIPTION -- DISPLAY //
	virtual void Display() const;
	/*
	* displays the media type and the trans type
	*/
	//PSEUDO DESCRIPTION -- Create //
	virtual Transaction* create();
	/*
	* return the newly created BOrrow obj
	*
	*/
};

