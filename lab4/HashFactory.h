#ifndef HASH_FACTORY_H
#define HASH_FACTORY_H
#include <string>
#include <iostream>
#include "ClassicDVD.h"
#include "ComedyDVD.h"
#include "DramaDVD.h"
#include "Transaction.h"
#include "BorrowTrans.h"
#include "HistoryTrans.h"
#include "ReturnTrans.h"
#include "Globals.h"
using namespace std;
extern const int MAX_AMT;
class HashFactory
{
public:
	//PSEUDO DESCRIPTION -- CONSTRUCTOR //
	HashFactory();
	//PSEUDO DESCRIPTION -- DESTRUCTOR //
	~HashFactory();
	
	//PSEUDO DESCRIPTION -- Create Movie Item //
	Item* createMovie(char code, istream &);
	
	//PSEUDO DESCRIPTION -- CREATE TRANSACTION //
	Transaction* createTransaction(char type, istream &);
	
	//PSEUDO DESCRIPTION -- HASH FUNCTION //
	int hash(char);
	
	string getMediaType(char type);
	
private:
	Item* movieGenre[MAX_AMT];
	Transaction* transactionType[MAX_AMT];
	string mediaTypes[MAX_AMT];
};
#endif

