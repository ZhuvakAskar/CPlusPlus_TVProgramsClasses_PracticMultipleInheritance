#pragma once
#include "TVprogram.h"
class Movie :
    public TVprogram
{
    string directBox;
    int year;
public:
    Movie();
    Movie(string name, Time_ start, string directBox,int year);

    void setdirectBox();
    void setyear();

    string getdirectBox()const&;
    int getyear()const&;

    string toStrign()const&;
};

