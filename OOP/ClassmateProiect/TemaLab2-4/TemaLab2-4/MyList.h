#pragma once
#include "produs.h"

//typedef void* Element;


/*
* creaza o structura de tip MyList
*	elemente: lista de pointeri catre produsele din MyList
*	lg: lungimea listei
*	capagitatea: capacitatea maxima
*/
typedef struct {
	Produs** elemente;
	int lg;
	int capacitate;
} MyList;

MyList* creazaListaVida();
/*
* initializeaza o lista vida de produse
*/

void distrugereLista(MyList* l);
/*
* dealoca memoria ocupata de lista de produse
* params: l - de tip MyList - lista tuturor produselor
* return: - 
*/

int adaugaSf(MyList* lista, Produs* produs);
/*
* adauga un produs nou in lista de produse la sfarsitul listei daca produsul nu exista deja
*			- numele trebuie sa fie unic
*			- daca se adauga un produs cu un nume exitent, se modifica doar cantitatea ddaca producatorii sunt identici
*			- daca se adauga un produs cu un nume existent, dar producatori diferiti, adaugarea nu are loc
* params: lista: tip MyList - lista de produse
*		  produs: tip Produs
* return: 0 - daca adaugarea a avut loc cu succes
*		  1 - altfel
*/

void modificaProdusRepo(MyList* lista, Produs* produs);
/*
* modifica un produs din lista de produse ddaca numele introdus exista deja in lista (modifica producatorul si cantitatea)
* params: lista: tip MyList - lista de produse
*	      produs: tip Produs
* return: -
*/

int stergeProdusRepo(MyList* lista, char* nume);
/*
* sterge un produs din lista dupa nume
* params: lista: tip MyList -lista de produse
*	      nume: cstring - numele produsului
* return: 0 - daca stergerea a avut loc cu succes
*		  1 - altfel
*/

Produs* getProdus(MyList* lista, int poz);
/*
* returneaza un pointer catre un produs dupa pozitia sa in lista de produse
* params: lista: tip MyList - lista tuturor produselor
*		  poz: int - pozitia unui element in lista
* return: un produs de tip Produs - produsul cautat
*/

int sizeLista(MyList* lista);
/*
* returneaza numarul de produse din lista
* params: lista: tip MyList - lista tuturor produselor
*/

MyList* copyList(MyList* lista);
/*
* creaza o copie a unei liste
* returneaza o lista avand aceleasi elemente ca "lista"
*/

