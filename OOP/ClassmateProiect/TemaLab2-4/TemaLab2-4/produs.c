#include "produs.h"
#include <string.h>
#include <stdlib.h>

Produs* creazaProdus(char* nume, char* producator, int cantitate) {
	Produs* p = malloc(sizeof(Produs));
	//int nrC = strlen(nume) + 1;
	p -> nume = (char*)malloc((strlen(nume) + 1) * sizeof(char));
	if (p -> nume) {
		strcpy(p -> nume, nume);
	}
	//nrC = strlen(producator) + 1;
	p -> producator = (char*)malloc((strlen(producator) + 1) * sizeof(char));
	if (p -> producator) {
		strcpy(p -> producator, producator);
	}
	p -> cantitate = cantitate;
	return p;
}

void distrugeProdus(Produs* produs) {
	free(produs->nume);
	free(produs->producator);
	free(produs);
}

char* getNume(Produs* produs) {
	return produs->nume;
}

char* getProducator(Produs* produs) {
	return produs->producator;
}

int getCantitate(Produs* produs) {
	return produs->cantitate;
}

void setProducator(Produs* produs, char* producator) {
	strcpy(produs->producator, producator);
}

void setCantitate(Produs* produs, int cantitate) {
	produs->cantitate = cantitate;
}

