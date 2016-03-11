#include "stdafx.h"
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

void DVD::display() const
{
	cout << title << " " << director << " " << year  << " " << genre << endl;
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
