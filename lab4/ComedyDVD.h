#pragma once
#include "DVD.h"
class ComedyDVD :
	public DVD
{
public:
	ComedyDVD();
	ComedyDVD(const ComedyDVD &other);
	~ComedyDVD();
	virtual void setData(ifstream &);
	virtual Item* create();
	bool operator==(const ComedyDVD &) const;
	bool operator!=(const ComedyDVD &) const;
	bool operator<(const ComedyDVD &) const;
	bool operator<=(const ComedyDVD &) const;
	bool operator>(const ComedyDVD &) const;
	bool operator>=(const ComedyDVD &) const;
	virtual string getItem() const;

};

