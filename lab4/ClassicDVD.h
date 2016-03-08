#pragma once
#include "DVD.h"
class ClassicDVD: public DVD
{
public:
	ClassicDVD();
	ClassicDVD(const ClassicDVD &);
	~ClassicDVD();
	virtual void setData(ifstream &);
	virtual Item* create();
	bool operator==(const ClassicDVD &) const;
	bool operator!=(const ClassicDVD &) const;
	bool operator>(const ClassicDVD &) const;
	bool operator<(const ClassicDVD &) const;
	bool operator>=(const ClassicDVD &) const;
	bool operator<=(const ClassicDVD &) const;
	virtual string getItem() const;

};

