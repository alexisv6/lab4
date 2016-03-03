#pragma once
#include <string>
#include <iostream>
using namespace std;
class Person
{
public:
	Person();
	~Person();
	void setName(string newName);
	string getName() const;
	string getLastName() const;
	string getFirstName() const;
	virtual void setData(ifstream&) = 0;
protected:
	string firstName, lastName;
};

