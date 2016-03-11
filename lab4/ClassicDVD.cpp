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
	return new ClassicDVD();
}

bool ClassicDVD::operator==(const ClassicDVD &rhs) const
{
	return year == rhs.year && month == rhs.month && majorActors.front() == rhs.majorActors.front();
}

bool ClassicDVD::operator<(const ClassicDVD &rhs) const
{
	if (year < rhs.year)
		return true;
	else if (year == rhs.year)
	{
	
		if (month < rhs.month)
		{
			return true;
		}
		else if (month == rhs.month)
		{
			if (majorActors.front() < rhs.majorActors.front())
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
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
