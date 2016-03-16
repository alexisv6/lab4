//#include "stdafx.h"
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

void DramaDVD::setData(ifstream &infile)
{
	infile.get();                       // get (and ignore) blank before director
	getline(infile, director, ',');     // input director

	infile.get();                       // get (and ignore) blank before title
	getline(infile, title, ',');        // input title

	infile.get();                       // get (and ignore) blank before year
	infile >> year;                   // input year
}

Item * DramaDVD::create()
{
	return nullptr;
}

bool DramaDVD::operator==(const DramaDVD &rhs) const
{
	return director == rhs.director && title == rhs.title;
}

bool DramaDVD::operator<(const DramaDVD &rhs) const
{
	if (director < rhs.director)
	{
		return true;
	}
	else if (director == rhs.director)
	{
		return title < rhs.title;
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
