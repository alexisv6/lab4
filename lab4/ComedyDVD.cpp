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

void ComedyDVD::setData(istream &infile)
{
	string max = "";
	infile.get();
	getline(infile, max, ',');
	setMaxCopies(stoi(max));
	infile.get();                       // get (and ignore) blank before director
	getline(infile, director, ',');     // input director

	infile.get();                       // get (and ignore) blank before title
	getline(infile, title, ',');        // input title

	infile.get();                       // get (and ignore) blank before year
	infile >> year;                   // input year
}

void ComedyDVD::setData2(istream &infile)
{
	infile.get();                       // get (and ignore) blank before title
	getline(infile, title, ',');

	infile >> year;
}

Item * ComedyDVD::create()
{
	return new ComedyDVD();
}

bool ComedyDVD::operator==(const Item &rhs) const
{
	const ComedyDVD& theDVD = static_cast<const ComedyDVD&>(rhs);
	return title == theDVD.title && year == theDVD.year;
}
bool ComedyDVD::operator<(const Item &rhs) const
{
	const ComedyDVD& theDVD = static_cast<const ComedyDVD&>(rhs);
	if (title < theDVD.title)
	{
		return true;
	}
	else if (title == theDVD.title)
	{
		return year < theDVD.year;
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
void ComedyDVD::display() const
{
	cout << left << setw(30) << title << setw(5) << year << setw(38) << director <<endl;
}

void ComedyDVD::displayHeader() const
{
	cout << "-----------------------------------Comedies----------------------------------- " << endl;
	cout << "Stock    Title                         Year	Director                       " << endl;
}
