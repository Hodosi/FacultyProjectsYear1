#pragma once
#include "MyList.h"

int adaugaProdus(MyList* l, char* nume, char* producator, int cantitate);
/*
* adauga un produs nou in lista de produse la sfarsitul listei
* params: l: tip MyList -lista tuturor produselor
*		  nume: cstring - denumire produs
*	      producator: cstring - producatorul
*		  cantitate: int
* return: 0 - daca adaugarea a avut loc cu succes
*		  1 - altfel
*/

int modificaProdus(MyList* l, char* nume, char* producator, int cantitate);
/*
* modifica un produs din lista de produse
* params: l: tip MyList -lista tuturor produselor
*	      nume: cstring - denumire produs
*	      producator: cstring - producatorul
*		  cantitate: int
* return: 0 - daca modificarea a avut loc cu succes
*         1 - altfel
*/


int stergeProdus(MyList* l, char* nume);
/*
* sterge un produs din lista dupa nume
* params: l: tip MyList - lista tuturor produselor
*	      nume: cstring - denumire produs
* return: 0 - daca stergerea a avut loc cu succes
*		  1 - altfel
*/


MyList* sortByNume(MyList* lista, int opt);
/*
* returneaza o copie sortata dupa nume a unei liste de produse
* params: lista: de tip MyList - lista tuturor produselor
*		  opt: int - daca opt = 1 returneaza o lista sortata dupa nume crescatoare
*				   - daca opt = 2 returneaza o lista sortata dupa nume descrescatoare
* return: o copie sortata dupa nume a unei liste de produse
*/

MyList* sortByCantitate(MyList* lista, int opt);
/*
* returneaza o copie sortata dupa cantitate a unei liste de produse
* params: lista: de tip MyList - lista tuturor produselor
*		  opt: int - daca opt = 1 returneaza o lista sortata dupa cantitate crescatoare
*				   - daca opt = 2 returneaza o lista sortata dupa cantitate descrescatoare
* return: o copie sortata dupa cantitate a unei liste de produse
*/

MyList* multiplu(MyList* , char*);


