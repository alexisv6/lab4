#ifndef HISTORY_TRANS_H
#define HISTORY_TRANS_H
#include "Transaction.h"
#include "Item.h"
#include "Customer.h"
using namespace std;
class HistoryTrans :
	public Transaction
{
public:
	//PSEUDO DESCRIPTION -- Constructor //
	HistoryTrans();
	/*
	* initiallize the type to HISTORY
	*/
	//PSEUDO DESCRIPTION -- Copy Constructor //
	HistoryTrans(const HistoryTrans &other);
	/*
	* set values in this to other
	*/
	//PSEUDO DESCRIPTION -- Destructor //
	virtual~HistoryTrans();
	//PSEUDO DESCRIPTION -- Set DAta //
	virtual void setData(string media, Item *theItem, Customer *theCustomer);
	/*
	* gets the file stream to set the information
	* for this tranascation of type HISTORY
	*/
	//PSEUDO DESCRIPTION -- DISPLAY //
	virtual void Display() const;
	/*
	* displays the media type and the trans type
	*/
	//PSEUDO DESCRIPTION -- Create //
	virtual Transaction* create();
	/*
	* return the newly created HISTORY obj
	*
	*/
};
#endif

