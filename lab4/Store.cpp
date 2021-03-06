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

// Read the movies files create the movie objs
// place them in the correct bintree in movie inventory
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

// Read commands from file 
// creates a transaction based on action code
// allow for borrow, rent, history, and inventory
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
		else
		{
			//if (theStream.get() == '\n')
			//{
				if (actionType == 'I')
				{
					this-> diplayInventory();
					theStream >> actionType;
				}
			//}
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
					case 'B':
					case 'R':
						theStream >> mediaCode;
						media = factory.getMediaType(mediaCode);
						if (media != "")
						{
							theStream >> movieType;
							tempMovie = factory.createMovie(movieType, theStream);
							if (tempMovie != NULL) // was genre found
							{
								tempMovie->setData2(theStream);

								found = movieInventory[factory.hash(movieType)].Retrieve(*tempMovie, theMovie);
								if (found)
								{
									newTransaction->setData(media, theMovie, theCustomer);
									customerAccounts[customerID].addHistoryItem(*newTransaction);
								}
								else
								{
									cout << "ERROR: Invalid Movie ";
									tempMovie->getItem();
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

// reads from the accounts file
// creates the accounts for each person
// customers are stored in array for unique id
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

// Display the inventory of the store
void Store::diplayInventory() const
{
	if (name != "")
	{
		cout << "Inventory list of Items from " << name << endl;
		cout << "------------------------------------------------------------------" 
			<< endl;
	}

	for (int i = 0; i < MAX_AMT; i++)
	{
		if (!movieInventory[i].isEmpty())
		{
			movieInventory[i].Display();
			cout << endl;
		}
	}
}

// does the customer id exist 
// in customer accounts
bool Store::customerExists(int id) const
{
	return customerAccounts[id].getID() != 0;
}

// return the store's name
string Store::getStoreName() const
{
	return this->name;
}
