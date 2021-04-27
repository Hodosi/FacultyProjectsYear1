#include "validare.h"
#include <string.h>

int valideaza(Produs* p) {
	if (strlen(p -> nume) == 0) {
		return 1;
	}
	if (strlen(p -> producator) == 0) {
		return 1;
	}
	if ((int)p -> cantitate < 0) {
		return 1;
	}
	return 0;
}
