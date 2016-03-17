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
	string max = "";
	infile.get();
	getline(infile, max, ',');
	setMaxCopies(stoi(max));
	infile.get();                      // get (and ignore) blank before director
	getline(infile, director, ',');    // input director

	infile.get();                      // get (and ignore) blank before title
	getline(infile, title, ',');       // input title

	infile.get();                      // get (and ignore) blank before actor
	infile >> actorFirstName >> actorLastName;   // input star's name
	string newActor = actorFirstName + " " + actorLastName;
	majorActors.push_back(newActor);
	infile >> month;
	infile >> year;           // input month and year
}
void ClassicDVD::setData2(istream& infile)
{
	infile >> month;
	infile >> year;
	infile >> actorFirstName;
	infile >> actorLastName;
	string newActor = actorFirstName + " " + actorLastName;
	majorActors.push_back(newActor);
}

Item * ClassicDVD::create()
{
	return new ClassicDVD();
}

bool ClassicDVD::operator==(const Item &rhs) const
{
	const ClassicDVD& theDVD = static_cast<const ClassicDVD&>(rhs);
	return year == theDVD.year && month == theDVD.month;
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
	cout << left << setw(27) << title << setw(5) << month << setw(12) << year << setw(18) << director;
	string allActors;
	for (int i = 0; i < (int)majorActors.size(); i++)
	{
		cout << left << setw(10) << majorActors[i] << endl;
	}
	
}

void ClassicDVD::displayHeader() const
{
	cout << "-----------------------------------Classic----------------------------------- " << endl;
	cout << "Stock         Title         Month Year	         Director       Actors           " << endl;
}
