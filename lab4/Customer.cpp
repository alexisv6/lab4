#include "stdafx.h"
#include "Customer.h"

Customer::Customer() :id(0)
{
	firstName = "";
	lastName = "";
}

Customer::Customer(istream &infile)
{
	setData(infile);
}

Customer::Customer(const Customer &other)
{
	id = other.id;
	firstName = other.firstName;
	lastName = other.lastName;
}

Customer::~Customer()
{
	int tempSize = transHistory.size();
	for (int i = 0; i < tempSize; i++)
	{
		transHistory.erase(transHistory.begin());
	}
}



int Customer::getID() const
{
	return id;
}

void Customer::setData(istream &infile)
{
	infile >> id; //read customer ID number

	infile.get();
	infile >> lastName; //read last name

	infile.get();
	infile >> firstName; //read firstname
}

string Customer::getData()
{
	return string();
}

void Customer::displayHistory() const
{
	cout << "Customer ID : " << id << "      Name : " << firstName << " " << 
		lastName << endl;
	cout << "-----------------------------------------------------------------"
		<< endl;
	
	for (int i = 0; i < transHistory.size(); i++)
	{
		cout << " ";
		transHistory[i].Display();
		cout << endl;
	}
	cout << endl;
}

void Customer::addHistoryItem(Transaction &newTransaction)
{
	transHistory.push_back(newTransaction);
}

bool Customer::operator==(const Customer &rhs) const
{
	return id == rhs.id;
}

bool Customer::operator!=(const Customer &rhs) const
{
	return !(id == rhs.id);
}
