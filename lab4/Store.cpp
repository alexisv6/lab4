#include "Store.h"



Store::Store()
{
	this->name = "The Store";
}

Store::Store(string name)
{
	this->name = name;
}


Store::~Store()
{
}

void Store::doInventory(istream &theStream)
{
	char code = ' ';

	for (;;)
	{
		theStream >> code;
		if (theStream.eof())
		{
			break;
		}
		Item* newItem = 
	}
}

void Store::readTransactions(ifstream &)
{

}
