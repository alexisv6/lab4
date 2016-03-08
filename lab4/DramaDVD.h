#pragma once
#include "DVD.h"
class DramaDVD: public DVD
{
public:
	DramaDVD();
	DramaDVD(const DramaDVD &);
	~DramaDVD();
	virtual void setData(ifstream &);
	virtual Item* create();
	bool operator==(const DramaDVD &) const;
	bool operator!=(const DramaDVD &) const;
	bool operator>(const DramaDVD &) const;
	bool operator<(const DramaDVD &) const;
	bool operator>=(const DramaDVD &) const;
	bool operator<=(const DramaDVD &) const;
	virtual string getItem() const;

};

