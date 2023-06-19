#include "Show.h"

Show::Show() :TVprogram()
{
    this->topic = "";
}

Show::Show(string name, Time_ start, string topic):TVprogram(name,start)
{
    this->topic = topic;
}

void Show::settopic(string topic)
{
    this->topic = topic;
}

string Show::gettopic()const
{
    return this->topic;
}

string Show::tostring()const
{
    string s;
    s.append("Name: " + this->getname() + "\nStart: " + this->getstart().timetostring() + "\nTopic: " + topic);
    return s;
}
