#include "service.h"
#include "validare.h"
#include <string.h>
#include "mySort.h"

int adaugaProdus(MyList* l, char* nume, char* producator, int cantitate) {
	Produs* produs = creazaProdus(nume, producator, cantitate);
	int err = valideaza(produs);
	if (err != 0) {
		distrugeProdus(produs);
		return err;
	}
	err = adaugaSf(l, produs);
	if (err != 0) {
		return err;
	}
	return 0;
}

int modificaProdus(MyList* l, char* nume, char* producator, int cantitate) {
	for (int i = 0; i < sizeLista(l); i++)
	{
		if (strcmp((l->elemente[i])->nume, nume) == 0)
		{
			Produs *produs = creazaProdus(nume, producator, cantitate);
			int err = valideaza(produs);
			if (err != 0) {
				distrugeProdus(produs);
				return 1;
			}
			modificaProdusRepo(l, produs);			// in repo se distruge produsul nou creat
			return 0;
		}
	}
	return 1;
}

int stergeProdus(MyList* l, char* nume) {
	return stergeProdusRepo(l, nume);
}

// Sortari


int cmpNume(Produs* p1, Produs* p2, int opt) {
	if (opt == 1)
		return strcmp(p1->nume, p2->nume);
	else
		return (strcmp(p1->nume, p2->nume) * (-1));
}

int cmpCantitate(Produs* p1, Produs* p2, int opt) {
	if (opt == 1)
		return (p1->cantitate > p2->cantitate);
	else
		return (p1->cantitate < p2->cantitate);
}

MyList* sortByNume(MyList* lista, int opt) {
	MyList* copie = copyList(lista);
	sortareDupaCriteriu(copie, cmpNume, opt);
	return copie;
}

MyList* sortByCantitate(MyList* lista, int opt) {
	MyList* copie = copyList(lista);
	sortareDupaCriteriu(copie, cmpCantitate, opt);
	return copie;
}

MyList* multiplu(MyList* produse, char* nume) {
	MyList* rez = creazaListaVida();
	for (int i = 0; i < produse->lg; i++) {
		Produs* pr = getProdus(produse, i);
		if (strcmp(nume, getNume(pr)) == 0) {
			if (getCantitate(pr) % 3 == 0) {
				Produs* cpy = creazaProdus(getNume(pr), getProducator(pr), getCantitate(pr));
				adaugaSf(rez, cpy);
			}
		}
	}
	return rez;
}
