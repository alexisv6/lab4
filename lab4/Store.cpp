#include "Store.h"


/* DEFAULT CONSTRUCTOR
* inintialize a store object with default name
* set as "The Store"
*/
Store::Store()
{
	this->name = "The Store";
}

/* CONSTRUCTOR WITH NAME
* initialize a store item by setting the name
* of the store to the name passed in
*/
Store::Store(string name)
{
	this->name = name;
}

// DESTRUCTOR
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

void Store::readTransactions(ifstream &theStream)
{
	char actionType = ' ';
	char movieType = ' ';
	char mediaType = ' ';
	int customerID = 0;
	string media = "";

	Customer* theCustomer = NULL;
	Item* theMovie = NULL;
	Item *tempMovie = NULL;
	bool found = false;
	for (;;)
	{
		theStream >> actionType;
		if (theStream.eof())
		{
			break;
		}
		else if (theStream.get() == '\n') //Do I need FIX
		{
			actionType = ' ';
		}
		else
		{
			//create trans object
			Transaction* newTransaction =
				factory.createTransaction(actionType, theStream);

			if (newTransaction != NULL) // trans type was found
			{
				theStream >> customerID;
				if (theStream.eof())
				{
					break;
				}

				if (customerExists(customerID))
				{
					theCustomer = &customerAccounts[customerID];
					char mediaCode = ' ';
					switch (actionType)
					{
					case 'B' || 'R':
						theStream >> mediaCode;
						media = factory.getMediaType(mediaCode);
						if (media != "")
						{
							theStream >> movieType;
							tempMovie = factory.createMovie(movieType, theStream);
							if (tempMovie != NULL) // was genre found
							{
								tempMovie->setData(theStream);

								found = movieInventory->Retrieve(*tempMovie, theMovie);
								if (found)
								{
									newTransaction->setData(media, theMovie, theCustomer);
									customerAccounts[customerID].addHistoryItem(*newTransaction);
								}
								else
								{
									cout << "ERROR: Invalid Movie ";
									tempMovie->display();
									cout << endl;
								}
							}
							else
							{
								cout << "ERROR: Invalid Genre " << movieType << endl;
								string badData;
								getline(theStream, badData, '\n');
							}
						}
						else
						{
							cout << "ERROR: Invalid Media Type " << mediaCode << endl;
							string badData;
							getline(theStream, badData, '\n');
						}
					case 'H':
						newTransaction->setData(media, theMovie, theCustomer);
					}

					delete tempMovie;
					tempMovie = NULL;
					if (newTransaction != NULL)
					{
						delete newTransaction;
						newTransaction = NULL;
					}

				}
				else
				{
					// customer doesnt exist
					cout << "ERROR: Customer ID " << customerID;
					cout << " does not exist" << endl;
					string badData;
					getline(theStream, badData, '\n');
					delete tempMovie;
					tempMovie = NULL;
					if (newTransaction != NULL)
					{
						delete newTransaction;
						newTransaction = NULL;
					}
				}
			}
			else
			{
				// invalid action/transaction
				cout << "ERROR: Invalid Action Code " << actionType << endl;
				string badData;
				getline(theStream, badData, '\n');
				delete tempMovie;
				tempMovie = NULL;
				if (newTransaction != NULL)
				{
					delete newTransaction;
					newTransaction = NULL;
				}
			}
		}
		found = false;
		theMovie = NULL;
		theCustomer = NULL;
		tempMovie = NULL;
		customerID = 0;
	}
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

		customerAccounts[newCustomer->getID()] = *newCustomer;
		delete newCustomer;
		newCustomer = NULL;
	}
}

bool Store::customerExists(int id) const
{
	return customerAccounts[id].getID() == 0;
}

string Store::getStoreName() const
{
	return this->name;
}
