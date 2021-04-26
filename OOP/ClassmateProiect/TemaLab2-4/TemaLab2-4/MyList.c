#include "MyList.h"
#include <string.h>
#include "produs.h"
#include <stdlib.h>

MyList* creazaListaVida() {
	MyList *lista = malloc(sizeof(MyList));
	lista -> capacitate = 1;
	lista -> elemente = (Produs**)malloc(sizeof(Produs*) * lista -> capacitate);
	lista -> lg = 0;
	return lista;
}

void distrugereLista(MyList* l) {
	//MyList* l = (MyList*)list;
	for (int i = 0; i < l->lg; i++) {
		Produs* p = (Produs*)l->elemente[i];
		distrugeProdus(p);
	}
	l->lg = 0;
	free(l->elemente);
	free(l);
}

int adaugaSf(MyList* lista, Produs* produs) {
	// realocare -> vector dinamic
	if (lista->capacitate <= lista->lg) {
		// alocam un spatiu mai mare
		Produs** aux = (Produs**)malloc(sizeof(Produs*) * (lista->capacitate + 10));
		// copiem elementele
		if (aux) {
			for (int i = 0; i < lista->lg; i++) {
				*(aux + i) = lista->elemente[i];
			}
		}
		free(lista->elemente);
		lista->elemente = aux;
		lista->capacitate += 10;
	}
	// adaugarea
	for (int i = 0; i < sizeLista(lista); i++) {
		if (lista->elemente && strcmp((*(lista->elemente + i))->nume, produs->nume) == 0) {
			if (strcmp((lista->elemente[i])->producator, produs->producator) != 0) {			// verific daca producatorii sunt identici sau nu
				distrugeProdus(produs);
				return 1;		}
			else {
				lista->elemente[i]->cantitate = produs->cantitate;
				distrugeProdus(produs);
				return 0;
			}
		}
	}
	/*
	if (lista->elemente) {			// constructia asta ma scapa de un warning :))
		*(lista->elemente + lista->lg) = produs;
	}
	*/
	lista->elemente[lista->lg] = produs;
	lista->lg = lista->lg + 1;
	return 0;
}

void modificaProdusRepo(MyList* lista, Produs* produs) {
	for (int i = 0; i < lista->lg; i++) {
		if (strcmp((lista->elemente[i])->nume, produs->nume) == 0) {
			char* p = lista->elemente[i] -> producator;
			lista->elemente[i] ->producator = (char*)malloc(sizeof(char) * (strlen(produs->producator) + 1));
			if (lista->elemente[i] -> producator) {		// constructia asta ma scapa de un warning cauzat de strcpy
				strcpy(lista->elemente[i] -> producator, produs->producator);
			}
			free(p);
			lista->elemente[i] -> cantitate = produs->cantitate;
			distrugeProdus(produs);
			return;		}}	
}

int stergeProdusRepo(MyList* lista, char* nume) {
	if (sizeLista(lista) > 0) {
		int ok = 0;
		for (int i = 0, j = 0; i < lista->lg; i++) {
			if (strcmp((lista->elemente[i]) -> nume, nume) != 0) {
				lista->elemente[j] = lista->elemente[i];
				j++;
			}
			else {
				ok = 1;
				distrugeProdus((lista->elemente[i]));
			}
		}
		if (ok == 0) {		// elementul nu se afla in lista
			return 1;
		}
		lista->lg = lista->lg - 1;
		return 0;			// stergerea a avut loc cu succes
	}
	return 1;				// lista este vida
}

Produs* getProdus(MyList* lista, int poz) {
	return lista->elemente[poz];
}

int sizeLista(MyList* lista) {
	return lista->lg;
}

MyList* copyList(MyList* lista) {
	MyList* copie = creazaListaVida();
	for (int i = 0; i < sizeLista(lista); i++) {
		Produs* p = getProdus(lista, i);
		adaugaSf(copie, creazaProdus(p -> nume, p->producator, p->cantitate));
	}
	return copie;
}

