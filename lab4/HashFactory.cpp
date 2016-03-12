#include "stdafx.h"
#include "HashFactory.h"


/*
* initialize the arrays
* Hash the genres into genreArray
* hash the transtypes into TransType Array
*/
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

/*
* for (entire movie genre and tranaction type)
*	delete genre BINtrees in each bucket
*	delete trans types in each bucket
*	set pointers to null
*/
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

/*
* takes in code and ifstream
* hashes the code to check if valid movie code
* if (invalid)
*	throw some error about bad input
* if (valid)
*	create the movie item that will be returned
*/
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

/*
* takes in code and ifstream
* hashes the code to check if valid transaction code
* if (invalid)
*	throw some error about bad input
* if (valid)
*	create the trasnaction item that will be returned
*/
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

/*
*	function that will take a char passed in
*   and hash it to an index within the genre and trans arrays
*/
int HashFactory::hash(char code)
{
	return code - 'A';
}

string HashFactory::getMediaType(char type)
{
	return mediaTypes[hash(type)];
}
