#pragma once
#include "TVprogram.h"
class Children :
    public TVprogram
{
    int minAge, maxAge;
public:
    Children();
    Children(string name, Time_ start, int maxAge, int minAge);

    void setmaxAge(int maxAge);
    int getmaxAge()const;
    void setminAge(int minAge);
    int getminAge()const;

    string tostring()const;
};

