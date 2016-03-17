#ifndef CLASSIC_DVD_H
#define CLASSSIC_DVD_H
#include "DVD.h"
#include <vector>
class ClassicDVD: public DVD
{
public:
	ClassicDVD();
	ClassicDVD(const ClassicDVD&);
	~ClassicDVD();

	virtual void setData(istream &); // read the information from a file
	virtual void setData2(istream &);				//and store all of it
	virtual Item* create(); // create a pointer to an Item
	virtual bool operator==(const Item&) const; //will check and compare
										//two ClassicDVD to see if equal
	virtual bool operator<(const Item&) const; //checking the date it was
									//released, then by the major actors
	virtual string getItem() const; // return the ClassicDVDas a string
	virtual void display() const; // displays the DVD and all information
														//related to it
	virtual void displayHeader() const;
private:
	vector<string> majorActors;
	string actorFirstName, actorLastName;
	int month;


};
#endif

