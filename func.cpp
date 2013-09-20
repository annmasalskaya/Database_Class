#include "func.h"
#include <fstream>
#include <cstdlib>


void createBase(Workers *mass,int N)
{
    fstream file;
    string temp;
    Date date;
    int  experience, salary;
    int day,month,year;

    file.open("surname.txt");
    for(int i=0; i<N && !file.eof(); ++i)
    {
        file>>temp;
        mass[i].setSurname(temp);
        day=rand()%31+1;
        month=rand()%12+1;
        year=rand()%16+1998;
        experience=rand()%20+1;
        salary=rand()%1000+500;
        mass[i].setDate(day,month,year);
        mass[i].setExperience(experience);
        mass[i].setSalary(salary);

    }
    file.close();

}
//===========================================

int cmpSurname (Workers x, Workers y)
{
    return x.getSurname()<y.getSurname()?-1:(x.getSurname()>y.getSurname()?1:0);
}

int cmpDate (Workers x,Workers y)
{
    return (372*(x.getDate().getYear()-1)+31*(x.getDate().getMonth()-1)+x.getDate().getDay())- (372*(y.getDate().getYear()-1)+31*(y.getDate().getMonth()-1)+y.getDate().getDay());

}

int cmpExperience (Workers x,Workers y)
{
    return (x.getExperience()- y.getExperience());

}
int cmpSalary (Workers x,Workers y)
{
    return (x.getSalary()- y.getSalary());

}

void swap (Workers  &a, Workers  &b)
{
    Workers  temp=a;
    a=b;
    b=temp;

}
void repair (Workers *mass,int i, int N,Ptf cmp, int order)
{
    int l=2*i+1;
    int r=2*i+2;
    int larg=i;
    if ( order==1)
    {
        if(l<N && cmp(mass[l],mass[i])>0)larg=l;
        if(r<N && cmp(mass[r], mass[larg])>0)larg=r;
    }
    else
    {
        if(l<N && cmp(mass[l],mass[i])<0)larg=l;
        if(r<N && cmp(mass[r], mass[larg])<0)larg=r;
    }
    if(larg!=i)
    {
        swap(mass[larg],mass[i]);
        repair(mass,larg,N,cmp,order);
    }

}

void build(Workers *mass, int N,Ptf cmp,int  order)
{
    for (int i=N/2; i>=0; --i) repair (mass,i,N,cmp, order);
}

void piramidalSorting(Workers *mass, int N,Ptf cmp, int order)
{

    build (mass, N,cmp, order);
    for (  int i=N-1; i>=1; --i)
    {
        swap(mass[0],mass[i]);
        --N;
        repair (mass, 0, N,cmp, order);
    }
}

//===========================================

void draw_line () // линии для таблицы
{
    char simbol_horiz='-';
    {
        for ( int k=0; k<88; k++)
            cout<< simbol_horiz;
    }
}


void outputTable(Workers *mass,int N)
{
    draw_line();
    cout<<endl;
    char simbol_vert='|';
    cout<<simbol_vert<<"  ";
    cout.width(10);
    cout<<"ФАМИЛИЯ";
    cout.width(15);
    cout<<simbol_vert<<"  ";
    cout.width(10);
    cout<< "ДАТА ПРИЁМА НА РАБОТУ";
    cout.width(10);
    cout<<simbol_vert<<"  ";
    cout.width(10);
    cout<<"СТАЖ(в годах)";
    cout.width(3);
    cout<<simbol_vert<<"  ";
    cout.width(7);
    cout<<"ЗАРПЛАТА";
    cout.width(2);
    cout<<simbol_vert<<endl;
    for (int i=0; i<N; ++i)
    {
        draw_line();
        cout<<endl;
        cout<<simbol_vert<<"  ";
        cout.width(10);
        cout<<mass[i].getSurname();
        cout.width(20);
        if (mass[i].getDate().getDay()<10)
        {
            cout<< '0'<<mass[i].getDate().getDay();
        }
        else cout<< mass[i].getDate().getDay();
        cout<<".";
        if (mass[i].getDate().getMonth()<10)
        {
            cout<< '0'<<mass[i].getDate().getMonth();
        }
        else cout<< mass[i].getDate().getMonth();
        cout<<".";
        cout<< mass[i].getDate().getYear()<<" г.";
        cout.width(25);
        cout<<mass[i].getExperience();
        cout.width(15);
        cout<<mass[i].getSalary()<<" $";
        cout<<endl;
        if ( i==N-1)
        {
            draw_line();
            cout<<endl;
        }
    }

}

