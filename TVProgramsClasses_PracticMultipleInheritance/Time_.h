#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define p = 3.14
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <fstream> // для работы с файлами
#include <string> // для работы со строками
#include <time.h>  // подкл времени
#include <cmath> // для работы с корнями и степенями
#include <iomanip>
#include <sstream> // для конвертации чисел в строки (char[])
#include <fstream>
using namespace std;
class Time_
{
    int hour;
    int minutes;
    int seconds;
    char format[6]{}; // am/pm (12-hours), utc (24-hours)

public:
    Time_(); // Current local time
    Time_(int hour, int minutes, int seconds, const char* format = "utc");
    Time_(const Time_& obj);
    Time_& operator = (const Time_& obj);
    ~Time_();
    void showTime(); //show time by the format
    string timetostring()const&;

    void setHour(int hour);
    int getHour();
    void setMinutes(int minutes);
    int getMinutes();
    void setSeconds(int seconds);
    int getSeconds();
    int gettimeseconds()const;
    bool setFormat(const char* format); // !!! to update time by the new format
    const char* getFormat();
    bool valid(); //time check
    void tickTime(); //every tick add one second


    //--------- Comparison operators ---------
    bool operator == (const Time_& obj);
    bool operator != (const Time_& obj);
    bool operator > (const Time_& obj);
    bool operator < (const Time_& obj);
    bool operator >= (const Time_& obj);
    bool operator <= (const Time_& obj);
    void operator - (int minutes);
    void operator + (int minutes);
    //--------- Инкремент/Декремент -----------
    Time_& operator += (int sec);

    friend void print(Time_ t);
    friend istream& operator >> (istream& is, Time_& t);
    friend ostream& operator << (ostream& os, const Time_& t);

};

