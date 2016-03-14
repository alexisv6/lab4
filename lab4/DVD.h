/*
* DVD is a child class of Item, and is one of the many ways we can store movies.
* It will hold a director, title, genre, and year. It will be able to display the information
* about the DVD, and return it as a string.
*/
#pragma once
#include "Item.h"
class DVD: public Item
{
public:
	DVD();
	DVD(const DVD&);
	virtual ~DVD();

	virtual void setData(ifstream&);
	virtual void display() const; // displays the DVD and all information related to it
	virtual Item * create(); // create a pointer to the Item
	virtual string getItem() const; // return the DVD and all information as a string
	string getDirector() const; // return the director
	string getTitle() const; // return the title
	string getGenre() const; // return the genre
	int getYear() const; // return the year
protected:
	string director, title, genre; // 
	int year; // holds the given year

};

