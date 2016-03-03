#pragma once
#include "DVD.h"
#include <vector>
class ClassicDVD :
	public DVD
{
public:
	ClassicDVD();
	ClassicDVD(const ClassicDVD &other);
	~ClassicDVD();
	virtual void setData(ifstream &);
	virtual Item* create();
	bool operator==(const ClassicDVD &) const;
	bool operator!=(const ClassicDVD &) const;
	bool operator<(const ClassicDVD &) const;
	bool operator<=(const ClassicDVD &) const;
	bool operator>(const ClassicDVD &) const;
	bool operator>=(const ClassicDVD &) const;
	virtual string getItem() const;

private:
	vector<string> majorActors;
};

