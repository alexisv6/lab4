#pragma once
#include "Person.h"
#include <iostream>
#include <vector>
using namespace std;

class Customer: public Person
{
public:
	Customer();
	Customer(istream &);
	Customer(const Customer&);
	~Customer();
	int getID() const;
	virtual void setData(istream&) const;
	string getData();
	void displayHistory() const;
	void addHistoryItem(Transaction);
	bool operator==(const Customer&) const;
	bool operator!=(const Customer&) const;
	bool operator>(const Customer&) const;
	bool operator<(const Customer&) const;
	bool operator>=(const Customer&) const;
	bool operator<=(const Customer&) const;
private:
	int id;
	vector<Transaction> transHistory;
};