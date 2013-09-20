#ifndef FUNC_H
#define FUNC_H
#include"time.h"
#include "workers.h"


typedef int (*Ptf)(Workers, Workers);

int cmpSurname (Workers x, Workers y);
int cmpDate (Workers x,Workers y);
int cmpExperience (Workers x,Workers y);
int cmpSalary (Workers x,Workers);

void piramidalSorting(Workers *mass, int N,Ptf cmp, int order);
void createBase(Workers *mass,int N);
void outputTable(Workers *mass,int N);
#endif

