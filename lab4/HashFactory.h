#ifndef HASH_FACTORY_H
#define HASH_FACTORY_H
#include <string>
#include <iostream>
#include "ClassicDVD.h"
#include "ComedyDVD.h"
#include "DramaDVD.h"
#include "Store.h"
#include "Transaction.h"
#include "BorrowTrans.h"
#include "HistoryTrans.h"
#include "ReturnTrans.h"
class DVD;
class Transaction;
using namespace std;
class HashFactory
{
public:
	//PSEUDO DESCRIPTION -- CONSTRUCTOR //
	HashFactory();
	/*
	* initialize the arrays
	* Hash the genres into genreArray
	* hash the transtypes into TransType Array
	*/
	//PSEUDO DESCRIPTION -- DESTRUCTOR //
	~HashFactory();
	/*
	* for (entire movie genre and tranaction type)
	*	delete genre BINtrees in each bucket
	*	delete trans types in each bucket
	*	set pointers to null
	*/
	//PSEUDO DESCRIPTION -- Create Movie Item //
	Item* createMovie(char code, istream &);
	/*
	* takes in code and ifstream
	* hashes the code to check if valid movie code
	* if (invalid)
	*	throw some error about bad input
	* if (valid)
	*	create the movie item that will be returned
	*/
	//PSEUDO DESCRIPTION -- CREATE TRANSACTION //
	Transaction* createTransaction(char type, istream &);
	/*
	* takes in code and ifstream
	* hashes the code to check if valid transaction code
	* if (invalid)
	*	throw some error about bad input
	* if (valid)
	*	create the trasnaction item that will be returned
	*/
	//PSEUDO DESCRIPTION -- HASH FUNCTION //
	int hash(char);
	/*
	*	function that will take a char passed in 
	*   and hash it to an index within the genre and trans arrays
	*/
	string getMediaType(char type);
	
private:
	Item* movieGenre[MAX_GENRES];
	Transaction* transactionType[MAX_TRANSACTIONS];
	string mediaTypes[MAX_TRANSACTIONS];
};
#endif

