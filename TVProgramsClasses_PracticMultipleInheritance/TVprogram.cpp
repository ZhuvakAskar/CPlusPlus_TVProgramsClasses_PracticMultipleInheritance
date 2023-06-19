#include "TVprogram.h"

TVprogram::TVprogram()
{
    this->name = "";
    this->start = Time_();
}

TVprogram::TVprogram(string name, Time_ start)
{
    this->name = name;
    this->start = start;
}

TVprogram::TVprogram(const TVprogram& obj)
{
    this->name = obj.name;
    this->start = obj.start;
}

void TVprogram::setname(string name)
{
    this->name = name;
}

string TVprogram::getname() const
{
    return this->name;
}

void TVprogram::setstart(Time_ start)
{
    this->start = start;
}

Time_ TVprogram::getstart() const
{
    return this->start;
}

istream& operator>>(istream& in, TVprogram& tv)
{
    cout << "������ �������� �������� ";
    in >> tv.name;
    cout << "������ ������ ������ �������� ";
    in >> tv.start;
    // TODO: �������� ����� �������� return
}

ostream& operator<<(ostream& os, const TVprogram& tv)
{
    os << "��������: " << tv.name << endl
        << "������ ������: " << tv.start << endl;
        // TODO: �������� ����� �������� return
        return os;
}
