#include "mySort.h"

void sortareDupaCriteriu(MyList* l, FunctieComparare cmpF, int opt) {
	for (int i = 0; i < sizeLista(l); i++) {
		for (int j = i + 1; j < sizeLista(l); j++) {
			if (cmpF(l->elemente[i], l->elemente[j], opt) > 0) {
				//interschimbam
				Produs* aux = l->elemente[i];
				l->elemente[i] = l->elemente[j];
				l->elemente[j] = aux;
			}
		}
	}
}