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

		Item* newItem = factory.createMovie(code, theStream);

		if (newItem == NULL) {
			delete newItem;
			newItem = NULL;
		}
		else
		{
			newItem->setData(theStream);
			bool inserted = movieInventory[factory.hash(code)].Insert(newItem, MAX_COPIES);
			if (!inserted)
			{
				delete newItem;
				newItem = NULL;
			}
		}
	}
}

void Store::readTransactions(ifstream &)
{

}

void Store::PopulateAccounts(istream & theStream)
{
	for (;;)
	{
		if (theStream.eof())
		{
			break;
		}

		Customer *newCustomer = new Customer();
		newCustomer->setData(theStream);

		customerArray[newCustomer->getID()] = *newCustomer;
		delete newCustomer;
		newCustomer = NULL;
	}
}
