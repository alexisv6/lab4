#pragma once
#include "Item.h"
class DVD: public Item
{
public:
	DVD();
	DVD(const DVD&);
	virtual ~DVD();

	virtual void setData(ifstream&);
	virtual void display() const;
	virtual Item * create();
	virtual string getItem() const;
	string getDirector() const;
	string getTitle() const;
	string getGenre() const;
	int getYear() const;
protected:
	string director, title, genre;
	int year;
};

