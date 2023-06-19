#include "Children.h"

Children::Children() :TVprogram()
{
    this->minAge = 0;
    this->maxAge = 18;
}

Children::Children(string name, Time_ start, int maxAge, int minAge):TVprogram(name,start)
{
    this->minAge = minAge;
    this->maxAge = maxAge;
}

void Children::setmaxAge(int maxAge)
{
    this->maxAge = maxAge;
}

int Children::getmaxAge() const
{
    return this->maxAge;
}

void Children::setminAge(int minAge)
{
    this->minAge = minAge;
}

int Children::getminAge() const
{
    return this->minAge;
}

string Children::tostring() const
{
    string s;
    s.append("Name: " + this->getname() + "\nStart: " + this->getstart().timetostring() + "\nRange of age: from" + to_string(minAge) + " to " + to_string(maxAge));
    return s;
}
