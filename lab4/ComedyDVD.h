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
	bool operator==(const ComedyDVD &) const; //will check and compare two 
										//ComedyDVDs see if they are equal
	bool operator<(const ComedyDVD &) const; // checking the Title of the
						//movie, and then by the date that it was released
	virtual string getItem() const; // return the ComedyDVD as a string


};

