#include "ListaCopii.h"
#include "MyList.h"

void creazaListaCopiiVida() {
	ListaCopii lista;
	lista.capacitate = 10;
	lista.elemente = (Produs*)malloc(sizeof(MyList) * lista.capacitate);
	lista.lg = 0;
	return lista;
}

void distrugeListaCopii(ListaCopii* l_c) {
	for (int i = 0; i < l_c->lg; i++) {
		MyList l = l_c->elemente[i];
		distrugereLista(&l);
	}
	l_c->lg = 0;
	free(l_c->elemente);
}

void adaugaCopie(ListaCopii* l_c, MyList l) {
	// realocare -> vector dinamic
	if (l_c->capacitate <= l_c ->lg) {
		// alocam un spatiu mai mare
		MyList* aux = (MyList*)malloc(sizeof(Produs) * (l_c->capacitate + 10));
		// copiem elementele
		if (aux) {
			for (int i = 0; i < l_c->lg; i++) {
				aux[i] = l_c->elemente[i];
			}
		}
		free(l_c->elemente);
		l_c->elemente = aux;
		l_c->capacitate += 10;
	}
	// adaugarea
	if (l_c->elemente) {			
		l_c->elemente[l_c->lg] = l;
	}
	l_c->lg = l_c->lg + 1;
	return 0;
}

void undo(ListaCopii* l_c) {

}