//#include "stdafx.h"
#include "DVD.h"


DVD::DVD() : Item(), director(""), title(""), year(0), genre("")
{
}

DVD::DVD(const DVD &other): Item(other), director(other.director), title(other.title), year(other.year)
{
}
DVD::~DVD()
{
}

void DVD::setData(ifstream &infile)
{
	infile.get();                       // get (and ignore) blank before director
	getline(infile, director, ',');     // input director

	infile.get();                       // get (and ignore) blank before title
	getline(infile, title, ',');        // input title

	infile.get();                       // get (and ignore) blank before year
	infile >> year;                   // input year
}

void DVD::display() const
{
	cout << title << " " << director << " " << year  << " " << genre << endl;
}

Item * DVD::create()
{
	return nullptr;
}



string DVD::getItem() const
{
	return title;
}


string DVD::getDirector() const
{
	return director;
}

string DVD::getTitle() const
{
	return title;
}

string DVD::getGenre() const
{
	return genre;
}

int DVD::getYear() const
{
	return year;
}
