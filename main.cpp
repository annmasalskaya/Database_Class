#include<iostream>
#include "func.h"

void  menuSort (Workers *mass, int N)
{
    int choose;
    int order;
    Ptf array[4]= {cmpSurname,cmpDate,cmpExperience,cmpSalary};
    cout<<"\n\n  Выполнить сортировку:  \n 1.-по фамилии \n 2.-по дате \n 3.-по стажу \n 4.-по зарплате  "<<endl;
    cin>>choose;
    cout<<"\n  Выполнить сортировку: \n 1. - по возрастанию \n 2. - по убыванию"<<endl;
    cin>>order;
    piramidalSorting(mass,N,array[choose-1],order);
}

int main()
{

    int N=30;
    Workers  *mass=new Workers[N];
    createBase(mass,N);
    cout<<"\n\n";
    cout.width(50);
    cout<<" MINI DATABASE \n\n";
    cout.width(59);
    cout<<"[Отдел кадров] "<<endl;
    outputTable(mass,N);
    menuSort (mass,N);
    cout<<"\n\n Отсортированная база данных : "<<endl<<endl;
    outputTable(mass,N);

    delete []mass;

    return 0;

}



