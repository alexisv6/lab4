/*
* Person is an abstract class that other classes such as customer will call upon.
* A Person has a first name, last name, and can set it’s name, as well as holding a
* pure virtual function that will take in all data for the child classes.
* Person is general enough that we can add onto it in the future.
*/

#pragma once
#include <string>
#include <iostream>
using namespace std;
class Person
{
public:
	Person();
	~Person();
	void setName(string newName); //Given a string, change the first and last name of this Person
	string getName() const; // return the full name as a string, first name last name
	string getLastName() const; // return the last name as a string
	string getFirstName() const; // return the first name as a string
	virtual void setData(istream&) = 0; // a pure virtual function that child classes will need to use
										 // It will take in data from a file and fill out all the needed information
										 // from the file
protected:
	string firstName, lastName; // A Person has a first name and a last name

};

