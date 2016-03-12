/*
* Item is an abstract parent class that all items within the store will call upon
* Item will be able to keep track of the max number of copies and the current number of copies,
* will be able to increase and decrease the current copies,
*/
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class Item
{
public:
	Item();
	Item(const Item&);
	virtual ~Item();

	virtual void setData(istream &) = 0; // a pure virtual function that will get the data from a file and set all
										  //data
	virtual void setData2(istream &) = 0;
	virtual void display()const = 0; // a pure virtual function that will display all information about the given item
	void setMaxCopies(const int); // sets the maximum number of copies to hold in the store
	void increaseCopies();	 //increases the current copies by one for returns
	void decreaseCopies(); //decreases the current copies by one for borrowing
	int getAmountIn(); // returns the number of copies still in the store
	int getAmountOut(); // returns the number of copies not in the store
	virtual Item * create() = 0; // creates a pointer to an Item
	virtual bool operator==(const Item &other) const = 0;
	virtual bool operator<(const Item &other) const = 0;
	virtual void displayHeader()const = 0;
	virtual string getItem()const = 0;
protected:
	int maxCopies, numOfCopies; // holds the maximum number of copies and the number of copies currently
								// in the store

};
#endif

