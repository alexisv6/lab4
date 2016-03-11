/*
* A Customer is someone who uses the video store. The will have a first name and last name, as well
* as an ID. The Customer will also have a transaction history of all borrows and returns for movies.
*/
#pragma once
#include "Person.h"
#include "Transaction.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Customer: public Person
{
public:
	Customer();
	Customer(istream &);
	Customer(const Customer&);
	~Customer();


	int getID() const; // return the customer ID
	virtual void setData(istream&); // read the Customer's data from a file and save all information for them
	string getData(); // return the ID number, first name, last name as a string
	void displayHistory() const; // print out the Customerís borrow and return history to the display
	void addHistoryItem(Transaction &); // add a transaction to the Customerís history
	bool operator==(const Customer&) const; // compare two Customers IDs and check if they are equal
	bool operator!=(const Customer&) const; // compare two Customers IDs and check if they are not equal
	bool operator>(const Customer&) const; // compare two Customers IDs and see if this one is greater
	bool operator<(const Customer&) const; // compare two Customers IDs and see if this one is lesser
	bool operator>=(const Customer&) const; // compare two Customers IDs and see if this one is greater or 
											//equal
	bool operator<=(const Customer&) const; // compare two Customers IDs and see if this one is lesser or 
											//equal

private:
	int id; // the unique ID for the Customer
	vector<Transaction> transHistory; // a vector of all the borrowing and returns the Customer has done

};