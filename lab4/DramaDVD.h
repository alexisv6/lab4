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

	virtual void setData(ifstream &); // read the information from a file
													//and store all of it
	virtual Item* create(); // create a pointer to an Item
	bool operator==(const DramaDVD&) const; //will check and compare two 
						//ComedyDVDs seeing if they are equal
	bool operator<(const DramaDVD&) const; //checking the director of
											//the movie, and then by the title
	virtual string getItem() const; // return the DramaDVDas a string


};

