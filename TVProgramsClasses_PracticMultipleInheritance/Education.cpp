#include "Education.h"

Education::Education() :TVprogram()
{
    this->science = "";
}

Education::Education(string name,Time_ start,string science) : TVprogram(name, start)
{
    this->science = science;
}

void Education::setsci(string science)
{
    this->science = science;
}

string Education::getsci() const
{
    return this->science;
}

string Education::tostring() const
{
    string s;
    s.append("Name: " + this->getname() + "\nStart: " + this->getstart().timetostring() + "\nScience: " + science);
    return s;
}
