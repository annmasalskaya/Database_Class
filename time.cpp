#include "time.h"


Date::Date(int dayn,int  monthn,int yearn)
{
    month=monthn;
    year=yearn;
    day=dayn;
}

Date::~Date()
{
    day=0;
    month=0;
    year=0;
}

//===========================================

void Date::setDay(int dayn)
{
    day=dayn;
}

void Date::setMonth(int monthn)
{
    month=monthn;
}

void Date::setYear(int yearn)
{
    year=yearn;
}

//===========================================
int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

