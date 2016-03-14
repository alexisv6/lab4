#include "stdafx.h"
#include "ClassicDVD.h"


ClassicDVD::ClassicDVD(): DVD()
{
	genre = "Classic";
	month = 0;
}

ClassicDVD::ClassicDVD(const ClassicDVD &other): DVD(other)
{
	genre = other.genre;
	month = other.month;
}

ClassicDVD::~ClassicDVD()
{
}

void ClassicDVD::setData(ifstream &infile)
{
	infile.get();                      // get (and ignore) blank before director
	getline(infile, director, ',');    // input director

	infile.get();                      // get (and ignore) blank before title
	getline(infile, title, ',');       // input title

	infile.get();                      // get (and ignore) blank before actor
	string newActor;
	infile >> newActor;   // input star's name
	majorActors.push_back(newActor);
	infile >> month >> year;           // input month and year
}

Item * ClassicDVD::create()
{
	return nullptr;
}

bool ClassicDVD::operator==(const ClassicDVD &) const
{
	return false;
}

bool ClassicDVD::operator<(const ClassicDVD &) const
{
	return false;
}

string ClassicDVD::getItem() const
{
	return string();
}
