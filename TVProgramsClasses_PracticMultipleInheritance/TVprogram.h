#pragma once
#include "Header.h"
class TVprogram
{
	string name;
	Time_ start;
public:
	TVprogram();
	TVprogram(string name, Time_ start);
	TVprogram(const TVprogram& obj);

	void setname(string name);
	string getname()const;
	void setstart(Time_ start);
	Time_ getstart()const;

	friend istream& operator >> (istream& is, TVprogram& tv);
	friend ostream& operator << (ostream& os, const TVprogram& tv);
};

