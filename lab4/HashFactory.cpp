#include "stdafx.h"
#include "HashFactory.h"



HashFactory::HashFactory()
{
	for (int i = 0; i < MAX_AMT; i++) 
	{
		movieGenre[i] = NULL;
		transactionType[i] = NULL;
		mediaTypes[i] = "";
	}
	movieGenre[2] = new ClassicDVD();
	movieGenre[3] = new DramaDVD();
	movieGenre[5] = new ComedyDVD();

	transactionType[1] = new BorrowTrans();
	transactionType[7] = new HistoryTrans();
	transactionType[17] = new ReturnTrans();

	mediaTypes[3] = "DVD";
}


HashFactory::~HashFactory()
{
	for (int i = 0; i < MAX_AMT; i++)
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
	return code - 'A';
}

string HashFactory::getMediaType(char type)
{
	return mediaTypes[hash(type)];
}
