#pragma once

/*
* creaza o structura de tip Produs
* nume: lista de pointeri catre numele produselor din Produs
* producator: lista de pointeri catre producatorii produselor din Produs
* cantitatea: cantitatea de materie prima
*/
typedef struct {
	char* nume;
	char* producator;
	int cantitate;
} Produs;


Produs* creazaProdus(char* nume, char* producator, int cantitate);
/*
* initializeaza un produs
* param: nume: cstring - numele produsului
*		 producator: cstring - producatorul unui produs
*		 cantitate: int
* return: un produs de tip Produs
*/

void distrugeProdus(Produs* produs);
/*
* Dealoca memoria ocupata de un produs
* param: produs: de tip Produs
* return: -
*/

char* getNume(Produs* produs);
/*
* returneaza numele unui produs
* param: produs: tip Produs
*/

char* getProducator(Produs* produs);
/*
* returneaza producatorul unui produs
* param: produs: tip Produs
*/

int getCantitate(Produs* produs);
/*
* returneaza cantitatea unui produs
* param: produs: tip Produs
*/

void setProducator(Produs* produs, char* producator);
/*
* schimba producatorul unui produs
* param: produs: tip Produs
*		 producator: cstring - noul producator
*/

void setCantitate(Produs* produs, int cantitate);
/*
* schimba cantitatea unui produs
* param: produs: tip Produs
*		 cantitate: int - noua cantitate
*/
