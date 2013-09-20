#ifndef WORKERS_H
#define WORKERS_H

#include"time.h"
using namespace std;


class Workers
{
public:

    Workers() {};
    Workers(string,int, int, int, int,int);
    ~Workers();

    void setSurname(string);
    void setDate(int,int,int);
    void setExperience(int);
    void setSalary(int);

    string getSurname();
    Date getDate();
    int getExperience();
    int getSalary();



private:
    string surname;
    Date date; // дата приёма на работу
    int  experience; // опыт работы
    int salary;

};

#endif
