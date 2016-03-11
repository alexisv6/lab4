/*
*
*
*
*/
#ifndef DRAMA_DVD_H
#define DRAMA_DVD_H
#include "DVD.h"
class DramaDVD: public DVD
{
public:
	DramaDVD();
	DramaDVD(const DramaDVD&);
	~DramaDVD();

	virtual void setData(istream &); // read the information from a file
													//and store all of it
	virtual Item* create(); // create a pointer to an Item
	virtual bool operator==(const Item&) const; //will check and compare two 
						//ComedyDVDs seeing if they are equal
	virtual bool operator<(const Item&) const; //checking the director of
											//the movie, and then by the title
	virtual string getItem() const; // return the DramaDVDas a string


};
#endif

