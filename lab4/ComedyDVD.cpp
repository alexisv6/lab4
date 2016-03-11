#include "stdafx.h"
#include "ComedyDVD.h"


ComedyDVD::ComedyDVD(): DVD()
{
	genre = "Comedy";
}

ComedyDVD::ComedyDVD(const ComedyDVD &other): DVD(other)
{
	genre = other.genre;
}


ComedyDVD::~ComedyDVD()
{
}

void ComedyDVD::setData(ifstream &infile)
{
	infile.get();                       // get (and ignore) blank before director
	getline(infile, director, ',');     // input director

	infile.get();                       // get (and ignore) blank before title
	getline(infile, title, ',');        // input title

	infile.get();                       // get (and ignore) blank before year
	infile >> year;                   // input year
}

Item * ComedyDVD::create()
{
	return new ComedyDVD();
}

bool ComedyDVD::operator==(const ComedyDVD &rhs) const
{
	
	return title == rhs.title && year == rhs.year;
}
bool ComedyDVD::operator<(const ComedyDVD &rhs) const
{
	if (title < rhs.title)
	{
		return true;
	}
	else if (title == rhs.title)
	{
		return year < rhs.year;
	}
	else
	{
		return false;
	}
}
string ComedyDVD::getItem() const
{
	return title;
}
