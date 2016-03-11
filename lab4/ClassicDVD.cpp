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

void ClassicDVD::setData(istream &infile)
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
	return new ClassicDVD();
}

bool ClassicDVD::operator==(const Item &rhs) const
{
	const ClassicDVD& theDVD = static_cast<const ClassicDVD&>(rhs);
	return year == theDVD.year && month == theDVD.month && majorActors.front() == theDVD.majorActors.front();
}

bool ClassicDVD::operator<(const Item &rhs) const
{
	const ClassicDVD& theDVD = static_cast<const ClassicDVD&>(rhs);
	if (year < theDVD.year)
		return true;
	else if (year == theDVD.year)
	{
	
		if (month < theDVD.month)
		{
			return true;
		}
		else if (month == theDVD.month)
		{
			if (majorActors.front() < theDVD.majorActors.front())
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}
	return false;
}

string ClassicDVD::getItem() const
{
	return title;
}

void ClassicDVD::display() const
{
	cout << title << " " << director << " " << year << " " << genre;
	for (int i = 0; i < majorActors.size(); i++)
	{
		cout << " " << majorActors[i];
	}
	cout << endl;
}
