#include "Movie.h"

Movie::Movie():TVprogram()
{
    this->directBox = "";
    this->year = 0;
}

Movie::Movie(string name, Time_ start, string directBox, int year):TVprogram(name,start)
{
    this->directBox = directBox;
    this->year = year;
}

void Movie::setdirectBox()
{
    this->directBox = directBox;
}

void Movie::setyear()
{
    this->year = year;
}

string Movie::getdirectBox() const&
{
    return this->directBox;
}

int Movie::getyear() const&
{
    return this->year;
}

string Movie::toStrign() const&
{
    string s = "";
    s.append("Name: " + getname() + "\nDirectBox: " + getdirectBox() + "\nYear: " + to_string(getyear()) + "\nStart: " + this->getstart().timetostring());
    return s;
}
