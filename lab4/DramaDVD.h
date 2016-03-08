/*
*
*
*
*/
#pragma once
#include "DVD.h"
class DramaDVD: public DVD
{
public:
	DramaDVD();
	DramaDVD(const DramaDVD&);
	~DramaDVD();

	virtual void setData(ifstream &); // read the information from a file and store all of it
	virtual Item* create(); // create a pointer to an Item
	bool operator==(const DramaDVD&) const; //will check and compare two ComedyDVDs first
	bool operator!=(const DramaDVD&) const; // by checking the director of the movie, and then
	bool operator>(const DramaDVD&) const; // by the title
	bool operator<(const DramaDVD&) const; // 
	bool operator>=(const DramaDVD&) const; // 
	bool operator<=(const DramaDVD&) const; // 
	virtual string getItem() const; // return the DramaDVDas a string


};

