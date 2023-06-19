#pragma once
#include "TVprogram.h"
class Show :
    public TVprogram
{
    string topic;
public:
    Show();
    Show(string name, Time_ start, string topic);

    void settopic(string topic);
    string gettopic()const;

    string tostring()const;
};

