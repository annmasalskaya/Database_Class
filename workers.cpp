#include "workers.h"


Workers::Workers(string surname1,int day1, int month1, int year1, int experience1,  int salary1):
    surname(surname1), date(day1,month1,year1), experience(experience1), salary(salary1)
{
}

Workers::~Workers()
{
    //delete surname;
    experience=0;
    salary=0;

}
//=========================================== set


void Workers::setSurname(string nsurname)
{
    surname=nsurname;
}

void Workers::setDate(int dayn, int monthn, int yearn)
{
    date=Date(dayn,monthn,yearn);
}

void Workers::setExperience(int experiencen)
{
    experience=experiencen;
}

void Workers::setSalary(int salaryn)
{
    salary=salaryn;
}

//=========================================== get

string Workers::getSurname()
{
    return surname;
}

Date Workers::getDate()
{
    return date;
}

int Workers::getExperience()
{
    return experience;
}

int Workers::getSalary()
{
    return salary;
}


