// lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Store.h"
using namespace std;

int main()
{
	// setup file streams
	ifstream theCustomers("data4customers.txt");
	if (!theCustomers)
	{
		cout << "ERROR: Customer file could not be opened" << endl;
		return 1;
	}
	ifstream theMovies("data4movies.txt");
	if (!theMovies)
	{
		cout << "ERROR: Movies file could not be opened" << endl;
		return 1;
	}
	ifstream theCommands("data4commands.txt");
	if (!theCommands)
	{
		cout << "ERROR: Commands file could not be opened" << endl;
		return 1;
	}
	// Create the Store object with name
	Store *myStore = new Store();// "Super Videos");
	// stock the inventory
	myStore->doInventory(theMovies);
	// create the customer accounts
	myStore->PopulateAccounts(theCustomers);
	// read and do the transactions
	myStore->readTransactions(theCommands);
	return 0;
}

