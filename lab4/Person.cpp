#include "stdafx.h"
#include "Person.h"


Person::Person()
{
	firstName = "";
	lastName = "";
}


Person::~Person()
{
}

void Person::setName(string newName)
{
	int pos = newName.find_first_of(' ');
	firstName = newName.substr(pos + 1);
	lastName = newName.substr(0, pos);

}

string Person::getName() const
{
	return firstName + " " + lastName;
}

string Person::getLastName() const
{
	return lastName;
}

string Person::getFirstName() const
{
	return firstName;
}
