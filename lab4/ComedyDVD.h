/*
 *
 *
 *
 */
#pragma once
#include "DVD.h"
class ComedyDVD: public DVD
{
public:
	ComedyDVD();
	ComedyDVD(const ComedyDVD &);
	~ComedyDVD();

	virtual void setData(ifstream &); // read the information from a file and store all of it
	virtual Item* create(); // create a pointer to an Item
	bool operator==(const ComedyDVD &) const; //will check and compare two ComedyDVDs first
	bool operator!=(const ComedyDVD &) const; // by checking the Title of the movie, and then
	bool operator>(const ComedyDVD &) const; // by the date that it was released
	bool operator<(const ComedyDVD &) const; // 
	bool operator>=(const ComedyDVD &) const; // 
	bool operator<=(const ComedyDVD &) const; // 
	virtual string getItem() const; // return the ComedyDVD as a string


};

