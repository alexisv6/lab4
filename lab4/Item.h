#pragma once
#include <iostream>
#include <string>
class Item
{
public:
	Item();
	Item(const Item &other);
	virtual~Item();
	virtual void setData(ifstream &) = 0;
	virtual void display() const = 0;
	void setMaxCopies(int amt);
	void increaseCopies(int amtToAdd);
	void decreaseCopies(int amtToSubtract);
	int getAmountIn();
	int getAmountOut();
	virtual Item* create() = 0;

private:
	int maxCopies;
	int numOfCopies;
};

