#pragma once
#include "Transaction.h"
//class Customer;
class ReturnTrans :
	public Transaction
{
public:
	//PSEUDO DESCRIPTION -- Constructor //
	ReturnTrans();
	/*
	* initiallize the type to RETURN
	*/
	//PSEUDO DESCRIPTION -- Copy Constructor //
	ReturnTrans(const ReturnTrans &other);
	/*
	* set values in this to other
	*/
	//PSEUDO DESCRIPTION -- Destructor //
	virtual~ReturnTrans();
	//PSEUDO DESCRIPTION -- Set DAta //
	virtual void setData(string media, Item *theItem, Customer *theCustomer);
	/*
	* gets the file stream to set the information
	* for this tranascation of type RETURN
	*/
	//PSEUDO DESCRIPTION -- DISPLAY //
	virtual void Display() const;
	/*
	* displays the media type and the trans type
	*/
	//PSEUDO DESCRIPTION -- Create //
	virtual Transaction* create();
	/*
	* return the newly created RETURN obj
	*
	*/
};

