#include "stdafx.h"
#include "DramaDVD.h"


DramaDVD::DramaDVD(): DVD()
{
	genre = "Drama";
}

DramaDVD::DramaDVD(const DramaDVD &other):DVD(other)
{
	genre = other.genre;
}

DramaDVD::~DramaDVD()
{
}

void DramaDVD::setData(istream &infile)
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

void DramaDVD::setData2(istream &infile)
{

	infile.get();                       // get (and ignore) blank before title
	getline(infile, director, ',');

	infile.get();                       // get (and ignore) blank before title
	getline(infile, title, ',');
}

Item * DramaDVD::create()
{
	return new DramaDVD();
}

bool DramaDVD::operator==(const Item &rhs) const
{
	const DramaDVD& theDVD = static_cast<const DramaDVD&>(rhs);
	return director == theDVD.director && title == theDVD.title;
}

bool DramaDVD::operator<(const Item &rhs) const
{
	const DramaDVD& theDVD = static_cast<const DramaDVD&>(rhs);
	if (director < theDVD.director)
	{
		return true;
	}
	else if (director == theDVD.director)
	{
		return title < theDVD.title;
	}
	else
	{
		return false;
	}
}

string DramaDVD::getItem() const
{
	return title;
}
void DramaDVD::display() const
{
	cout << left << setw(30) << title << setw(5) << year << setw(38) << director << endl;
}
void DramaDVD::displayHeader() const
{
	cout << "-----------------------------------Drama----------------------------------- " << endl;
	cout << "Stock     Title                         Year	Director                         " << endl;
}
