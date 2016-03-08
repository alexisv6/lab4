#pragma once
#include <iostream>
using namespace std;
class Item
{
public:
	Item();
	Item(const Item&);
	virtual ~Item();
	virtual void setData(istream &) = 0;
	virtual void Display()const = 0;
	void setMaxCopies(const int);
	void increaseCopies();
	void decreaseCopies();
	int getAmountIn();
	int getAmountOut();
	virtual Item * create();
protected:
	int maxCopies, numOfCopies;
};

