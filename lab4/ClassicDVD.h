/*
*
*
*
*/
#pragma once
#include "DVD.h"
#include <vector>
class ClassicDVD: public DVD
{
public:
	ClassicDVD();
	ClassicDVD(const ClassicDVD&);
	~ClassicDVD();

	virtual void setData(ifstream &); // read the information from a file and store all of it
	virtual Item* create(); // create a pointer to an Item
	bool operator==(const ClassicDVD&) const; //will check and compare two ClassicDVDfirst
	bool operator!=(const ClassicDVD&) const; // by checking the date it was released, and then
	bool operator>(const ClassicDVD&) const; // by the major actors
	bool operator<(const ClassicDVD&) const; // 
	bool operator>=(const ClassicDVD&) const; // 
	bool operator<=(const ClassicDVD&) const; // 
	virtual string getItem() const; // return the ClassicDVDas a string
private:
	vector<string> majorActors;
	int month;


};

