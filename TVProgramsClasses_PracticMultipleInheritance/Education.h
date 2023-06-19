#pragma once
#include "TVprogram.h"
class Education :
    public TVprogram
{
    string science;
public:
    Education();
    Education(string name,Time_ start,string science);

    void setsci(string science);
    string getsci()const;

    string tostring()const;
};

