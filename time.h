#ifndef TIME_H
#define TIME_H

#include <iostream>

class Date
{
public:
    Date(int day=1,int  month=1,int year=2013);
    ~Date();

    void setDay(int);
    void setMonth(int);
    void setYear(int);

    int getDay();
    int getMonth();
    int getYear();

private:
    int day;
    int month;
    int year;
};

#endif


