#pragma once
#include "MyList.h"

typedef struct {
	MyList* elemente;
	int lg;
	int capacitate;
} ListaCopii;

void creazaListaCopiiVida();

void distrugeListaCopii(ListaCopii* l_c);

void adaugaCopie(ListaCopii* l_c, MyList l);

void undo(ListaCopii* l_c);

