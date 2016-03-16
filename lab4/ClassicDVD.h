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
	bool operator==(const ClassicDVD&) const; //will check and compare two ClassicDVD to see if equal
	bool operator<(const ClassicDVD&) const; //checking the date it was released, then by the major actors
	virtual string getItem() const; // return the ClassicDVDas a string
	virtual void display() const; // displays the DVD and all information related to it
private:
	vector<string> majorActors;
	int month;


};

