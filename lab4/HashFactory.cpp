#include "stdafx.h"
#include "HashFactory.h"



HashFactory::HashFactory()
{
	for (int i = 0; i < MAX_TRANSACTIONS; i++) 
	{
		movieGenre[i] = NULL;
		transactionType[i] = NULL;
	}
	char possibleGenres[3] = { 'C', 'D', 'F' };
	char possibleTransactions[3] = { 'B', 'H', 'R' };
	for each (char genre in possibleGenres)
	{
		switch (genre)
		{
		case 'C':
			movieGenre[hash(genre)] = new ClassicDVD();
		case 'D':
			movieGenre[hash(genre)] = new DramaDVD();
		case 'F':
			movieGenre[hash(genre)] = new ComedyDVD();
		default:
			break;
		}
	}
	for each (char type in possibleTransactions)
	{
		switch (type)
		{
		case 'B':
			transactionType[hash(type)] = new BorrowTrans();
		case 'R':
			transactionType[hash(type)] = new ReturnTrans();
		case 'H':
			transactionType[hash(type)] = new HistoryTrans();
		default:
			break;
		}
	}
}


HashFactory::~HashFactory()
{
	for (int i = 0; i < MAX_TRANSACTIONS; i++)
	{
		if (movieGenre[i] != NULL)
		{
			delete movieGenre[i];
			movieGenre[i] = NULL;
		}

		if (transactionType[i] != NULL)
		{
			delete transactionType[i];
			transactionType[i] = NULL;
		}
	}
}

Item * HashFactory::createMovie(char code, istream &theStream)
{
	string temp;
	int hashVal = hash(code);
	if (movieGenre[hashVal] != NULL)
	{
		return movieGenre[hashVal]->create();
	}
	else
	{
		getline(theStream, temp, '\n');
		return NULL;
	}
}

Transaction * HashFactory::createTransaction(char type, istream &theStream)
{
	string temp;
	int hashVal = hash(type);
	if (transactionType[hashVal] != NULL)
	{
		return transactionType[hashVal]->create();
	}
	else
	{
		getline(theStream, temp, '\n');
		return NULL;
	}
}

int HashFactory::hash(char code)
{
	int hashVal = code % MAX_TRANSACTIONS;
	return hashVal;
}

string HashFactory::getMediaType(char type)
{
	return mediaTypes[hash(type)];
}
