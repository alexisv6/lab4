#pragma once
#include "Item.h"
#include <string>
class DVD :
	public Item
{
public:
	DVD();
	DVD(const DVD &other);
	virtual~DVD();
	virtual void setData(ifstream &);
	virtual void display() const;
	virtual Item* create();
	virtual string getItem() cosnt;
	string getDirector() const;
	string getTitle() const;
	string getGenre() const;
	int getYear() const;

private:
	string director;
	string title;
	string genre;
	int year;
};

