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
	Item* movieLocation = NULL;
	Item *theMovie = NULL;
	bool found = false;
	for (;;)
	{
		theStream >> actionType;
		if (theStream.eof())
		{
			break;
		}
		
		if (actionType == 'S') // or invalid 
		{
			// what to do when invalid
			// actionType = ' ';
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
					//set data
					bool isHistoryAction = (actionType == 'H');
					if (isHistoryAction) {
						newTransaction->setData(theStream);
					}

					if (theStream.get() != (isHistoryAction && '\n'))
					{
						theStream >> mediaType;
						//get media code from factory
						media = factory.getMediaType(mediaType);

						if (media != "")
						{
							theStream >> movieType; //get movie genre

												  //create new movie object used for comaprison
							theMovie = factory.createMovie(movieType, theStream);

							if (theMovie != NULL)
							{
								theMovie->setData(theStream);
								//Retrieve VideoStoreItem* in BST
								found = movieInventory[factory.hash(movieType)]
									.Retrieve(*theMovie, movieLocation);

								if (found == false) //if movie is not found
								{
									cout << "ERROR: Invalid Movie "
										<< "PRINT ITEM NAME>????" << endl;
								}
								delete theMovie; //Delete after using as search key
								theMovie = NULL;

								//check if movie found and mediatype exists
								if (found && media != "")
								{
									//Add transaction to customer account
									customerAccounts[customerID].addHistoryItem(*newTransaction);
								}
								delete newTransaction;
								newTransaction = NULL;
							}
							else
							{
								cout << "ERROR: Genre: " << movieType << " not found"
									<< endl;

								//Check if transaction was deleted
								if (newTransaction != NULL)
								{
									delete newTransaction;
									newTransaction = NULL;
								}
								//discard rest of line
								string temp;
								getline(theStream, temp, '\n');
								delete theMovie;
								theMovie = NULL;
							}

						}
						else
						{
							//discard rest of line
							string temp;
							getline(theStream, temp, '\n');

							cout << "ERROR: Invalid Media Code: "
								<< mediaType << endl;

							if (newTransaction != NULL)
								delete newTransaction;
								newTransaction = NULL;
						}

					}
					else
					{
						if (newTransaction != NULL)
							delete newTransaction;
							newTransaction = NULL;
					}
				}
				else
				{
					cout << "ERROR: Customer ID: " << customerID
						<< " not found" << endl;

					if (newTransaction != NULL)
						delete newTransaction;
						newTransaction = NULL;

					//discard rest of line
					string temp;
					getline(theStream, temp, '\n');
				}
			}
			else
			{
				cout << "ERROR: Action Code: " << actionType
					<< " not found" << endl;

				if (newTransaction != NULL)
					delete newTransaction;
					newTransaction = NULL;
			}
		}
		found = false;
		customerID = 0;
		movieLocation = NULL;
		theCustomer = NULL;
		theMovie = NULL;
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
