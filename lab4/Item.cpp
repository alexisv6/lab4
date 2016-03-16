//#include "stdafx.h"
#include "Item.h"


Item::Item() :maxCopies(0), numOfCopies(-1)
{
}

Item::Item(const Item &other): maxCopies(other.numOfCopies), numOfCopies(other.maxCopies)
{
}


Item::~Item()
{
}

void Item::setMaxCopies(const int maxAmount)
{
	maxCopies = maxAmount;
	if (numOfCopies < 0)
	{
		numOfCopies = maxCopies;
	}
}

void Item::increaseCopies()
{
	if (numOfCopies < maxCopies)
	{
		numOfCopies++;
	}
}

void Item::decreaseCopies()
{
	if (numOfCopies > 0)
	{
		numOfCopies++;
	}
}

int Item::getAmountIn()
{
	return numOfCopies;
}

int Item::getAmountOut()
{
	return maxCopies - numOfCopies;
}

Item * Item::create()
{
	return nullptr;
}
