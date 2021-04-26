#pragma once
#include "MyList.h"


typedef int(*FunctieComparare)(Produs* p1, Produs* p2, int opt);
/*
* Tipul functie de comparare pentru 2 elemente
* daca opt == 1
*		returneaza 0 daca sunt egale, 1 daca p1>p2, -1 altfel
* daca opt == 2
*		returneaza 0 daca sunt egale, -1 daca p1>p2, 1 altfel
*/


void sortareDupaCriteriu(MyList* l, FunctieComparare cmpF, int opt);
/**
* Sorteaza in place
* cmpf - relatia dupa care se sorteaza
* opt: int -> daca opt == 1: se sorteaza crescator
*				   opt == 2: se sorteaza descrescator
*/