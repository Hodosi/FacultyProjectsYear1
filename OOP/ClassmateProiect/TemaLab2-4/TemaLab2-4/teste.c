#include "teste.h"
#include "produs.h"
#include "validare.h"
#include "service.h"
#include "MyList.h"
#include "undoList.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void run_all_domain_tests() {
	// creez un produs
	Produs* p = creazaProdus("Lapte", "Dorolact", 10);
	// rulez testele pe domeniu
	assert(strcmp(getNume(p), "Lapte") == 0);
	assert(strcmp(getProducator(p), "Dorolact") == 0);
	assert(getCantitate(p) == 10);
	setProducator(p, "Spicul");
	setCantitate(p, 15);
	assert(strcmp(getProducator(p), "Spicul") == 0);
	assert(getCantitate(p) == 15);
	// distrug produsul creat
	distrugeProdus(p);
}

void run_all_validation_tests() {
	// creez un produs avand cantitatea invalida - "ridica exceptie"
	Produs* p = creazaProdus("Lapte", "Spicul", -2);
	int err = valideaza(p);
	assert(err == 1);
	// creez un produs avand numele invalid - "ridica exceptie"
	Produs* p2 = creazaProdus("", "Spicul", 2);
	err = valideaza(p2);
	assert(err == 1);
	// creez un produs avand producatorul invalid - "ridica exceptie"
	Produs* p3 = creazaProdus("Lapte", "", 2);
	err = valideaza(p3);
	assert(err == 1);
	// distrug produsele create
	distrugeProdus(p);
	distrugeProdus(p2);
	distrugeProdus(p3);
}


void run_undo_test() {
	UndoList* undo_list = createUndoList();
	// creez o lista goala de produse si adaug un produs
	MyList* l = creazaListaVida();
	Element el = undoUndoList(undo_list);
	addUndoList(undo_list, l);

	assert(sizeLista(l) == 0);
	Produs* pr = creazaProdus("Lapte", "Spicul", 10);
	adaugaSf(l, pr);
	assert(sizeLista(l) == 1);
	addUndoList(undo_list, l);
	el = undoUndoList(undo_list);
	distrugereLista(l);
	l = (MyList*)el;
	//addUndoList(undo_list, l);

	destroyUndoList(undo_list);
	distrugereLista(l);
	/*
	// verific daca produsul a fost realizat cu succes
	Produs* pr2 = getProdus(l, 0);			// creaza un pointer catre pr
	assert(strcmp(getNume(pr), getNume(pr2)) == 0);
	// adaug un produs care exista deja, dar are alta cantitate - se modifica cantitatea
	Produs* pr3 = creazaProdus("Lapte", "Spicul", 15);
	adaugaSf(l, pr3);
	assert(sizeLista(l) == 1);
	// adaug produs care exista deja, dar cu alt producator - "ridica exceptie" - "element existent"
	Produs* pr_3 = creazaProdus("Lapte", "Dorolact", 15);
	int err = adaugaSf(l, pr_3);
	assert(sizeLista(l) == 1);
	assert(err == 1);
	// verific daca produsul nu a fost modificat de adaugarile eronate
	Produs* pr4 = getProdus(l, 0);
	assert(strcmp(getNume(pr), getNume(pr4)) == 0);
	assert(strcmp(getProducator(pr4), "Spicul") == 0);
	assert(getCantitate(pr4) == 15);

	// distrug lista
	assert(sizeLista(l) == 1);
	distrugereLista(l);
	//assert(sizeLista(l) == 0);
	*/
} 

void run_repo_adauga_tests() {
	// creez o lista goala de produse si adaug un produs
	MyList* l = creazaListaVida();
	assert(sizeLista(l) == 0);
	Produs* pr = creazaProdus("Lapte", "Spicul", 10);
	adaugaSf(l, pr);
	assert(sizeLista(l) == 1);
	// verific daca produsul a fost realizat cu succes
	Produs* pr2 = getProdus(l, 0);			// creaza un pointer catre pr
	assert(strcmp(getNume(pr), getNume(pr2)) == 0);
	// adaug un produs care exista deja, dar are alta cantitate - se modifica cantitatea
	Produs* pr3 = creazaProdus("Lapte", "Spicul", 15);
	adaugaSf(l, pr3);
	assert(sizeLista(l) == 1);
	// adaug produs care exista deja, dar cu alt producator - "ridica exceptie" - "element existent"
	Produs* pr_3 = creazaProdus("Lapte", "Dorolact", 15);
	int err = adaugaSf(l, pr_3);
	assert(sizeLista(l) == 1);
	assert(err == 1);
	// verific daca produsul nu a fost modificat de adaugarile eronate
	Produs* pr4 = getProdus(l, 0);
	assert(strcmp(getNume(pr), getNume(pr4)) == 0);
	assert(strcmp(getProducator(pr4), "Spicul") == 0);
	assert(getCantitate(pr4) == 15);

	// distrug lista
	assert(sizeLista(l) == 1);
	distrugereLista(l);
	//assert(sizeLista(l) == 0);
}

void run_repo_modificare_tests() {
	// creez o lista vida si adaug un element
	MyList* l = creazaListaVida();
	assert(sizeLista(l) == 0);
	Produs *pr = creazaProdus("Lapte", "Spicul", 10);
	adaugaSf(l, pr);
	assert(sizeLista(l) == 1);
	// modific produsul si verific daca modificarea a avut loc cu succes
	Produs *pr5 = creazaProdus("Lapte", "Dorolact", 20);
	modificaProdusRepo(l, pr5);
	Produs* pr6 = getProdus(l, 0);
	assert(strcmp(getNume(pr6), "Lapte") == 0);
	assert(strcmp(getProducator(pr6), "Dorolact") == 0);
	assert(getCantitate(pr6) == 20);
	
	// distrug lista
	assert(sizeLista(l) == 1);
	distrugereLista(l);
	//assert(sizeLista(l) == 0);
}

void run_repo_stergere_tests() {
	// creez o lista vida
	MyList* l = creazaListaVida();
	assert(sizeLista(l) == 0);
	// creez doua produse si le adaug in lista
	Produs* pr = creazaProdus("Lapte", "Spicul", 10);
	adaugaSf(l, pr);
	assert(sizeLista(l) == 1);
	Produs* pr2 = creazaProdus("Faina", "Spicul", 10);
	adaugaSf(l, pr2);
	assert(sizeLista(l) == 2);
	// sterg un produs care nu exista - "ridica exceptie"
	int err = stergeProdusRepo(l, "Zahar");	
	assert(err == 1);
	// sterg cele doua produse din lista
	stergeProdusRepo(l, "Lapte");	
	assert(sizeLista(l) == 1);
	stergeProdusRepo(l, "Faina");
	assert(sizeLista(l) == 0);
	// sterg un produs dintr-o lista goala/un produs care nu mai exista in lista
	err = stergeProdusRepo(l, "Lapte");
	assert(err == 1);

	// distrug lista creata
	distrugereLista(l);
	//assert(sizeLista(l) == 0);
}


void run_srv_tests_adauga() {
	// creez o lista vida si adaug doua produse
	MyList* l = creazaListaVida();
	adaugaProdus(l, "Lapte", "Spicul", 10);
	adaugaProdus(l, "Paine", "Spicul", 10);
	assert(sizeLista(l) == 2);
	// adaug un produs care exista deja, dar are alta cantitate - se modifica cantitatea
	adaugaProdus(l, "Paine", "Spicul", 15);
	assert(sizeLista(l) == 2);
	// adaug produs care exista deja, dar cu alt producator - "ridica exceptie" - "element existent"
	int err = adaugaProdus(l, "Paine", "Dprolact", 15);
	assert(err == 1);
	// adaug produse invalide - "ridica exceptie"
	err = adaugaProdus(l, "Paine", "Spicul", -15);
	assert(err == 1);
	err = adaugaProdus(l, "Paine", "", 15);
	assert(err == 1);
	err = adaugaProdus(l, "", "Dorolact", 15);
	assert(err == 1);

	// distrug lista de produse
	assert(sizeLista(l) == 2);
	distrugereLista(l);
	//assert(sizeLista(l) == 0);
}

void run_srv_tests_modifica() {
	// creez o lista vida si adaug un produs
	MyList* l = creazaListaVida();
	adaugaProdus(l, "Lapte", "Spicul", 10);
	// modific produsul si verific daca modificarea a avut loc cu succes
	modificaProdus(l, "Lapte", "Dorolact", 20);
	Produs* pr = getProdus(l, 0);
	assert(strcmp(getNume(pr), "Lapte") == 0);
	assert(strcmp(getProducator(pr), "Dorolact") == 0);
	assert(getCantitate(pr) == 20);
	// incerc sa modific un produs inexistent
	int err = modificaProdus(l, "Oua", "Spicul", 20);
	assert(err == 1);
	// incerc sa modific un produs cu cantitatea invalida
	err = modificaProdus(l, "Lapte", "Spicul", -20);
	assert(err == 1);
	assert(strcmp(getNume(pr), "Lapte") == 0);
	assert(strcmp(getProducator(pr), "Dorolact") == 0);
	assert(getCantitate(pr) == 20);

	// distrug lista
	assert(sizeLista(l) == 1);
	distrugereLista(l);
	//assert(sizeLista(l) == 0);
}

void run_srv_tests_stergere() {
	// creez o lista vida si adaug doua produse
	MyList* l = creazaListaVida();
	adaugaProdus(l, "Lapte", "Spicul", 10);
	adaugaProdus(l, "Faina", "Spicul", 10);
	assert(sizeLista(l) == 2);
	// sterg cele doua produse
	stergeProdus(l, "Lapte");
	assert(sizeLista(l) == 1);
	stergeProdus(l, "Faina");
	assert(sizeLista(l) == 0);
	// sterg un produs inexistent in lista - "ridica exceptie"
	int err = stergeProdus(l, "Lapte");
	assert(err == 1);

	// distrug lista de produse
	distrugereLista(l);
	//assert(sizeLista(l) == 0);
}

void run_copy_tests() {
	// creez o lista vida si adaug doua produse
	MyList* l = creazaListaVida();
	adaugaProdus(l, "Lapte", "Spicul", 10);
	adaugaProdus(l, "Faina", "Spicul", 10);
	assert(sizeLista(l) == 2);
	// creez copia
	MyList* copie = copyList(l);
	// verific daca copia a fost creata cu succes
	assert(sizeLista(copie) == 2);
	Produs* pr = getProdus(copie, 0);
	assert(strcmp(getNume(pr), "Lapte") == 0);
	Produs* pr2 = getProdus(copie, 1);
	assert(strcmp(getNume(pr2), "Faina") == 0);

	// distrug listele
	distrugereLista(l);
	distrugereLista(copie);
}

void run_srv_sortare_dupa_nume() {
	// creez o lista vida si adaug doua produse
	MyList* l = creazaListaVida();
	adaugaProdus(l, "Lapte", "Spicul", 10);
	adaugaProdus(l, "Faina", "Spicul", 10);
	assert(sizeLista(l) == 2);
	// Crescator
	MyList* sortataCresc = sortByNume(l, 1);
	// verific daca copia sortata crescator a fost creata cu succes
	assert(sizeLista(sortataCresc) == 2);
	Produs* pr = getProdus(sortataCresc, 0);
	assert(strcmp(getNume(pr), "Faina") == 0);
	Produs* pr2 = getProdus(sortataCresc, 1);
	assert(strcmp(getNume(pr2), "Lapte") == 0);
	// Descrescator
	MyList* sortataDesc = sortByNume(l, 2);
	// verific daca copia sortata descrescator a fost creata cu succes
	assert(sizeLista(sortataDesc) == 2);
	Produs* pr3 = getProdus(sortataDesc, 0);
	assert(strcmp(getNume(pr3), "Lapte") == 0);
	Produs* pr4 = getProdus(sortataDesc, 1);
	assert(strcmp(getNume(pr4), "Faina") == 0);

	// distrug listele
	distrugereLista(l);
	distrugereLista(sortataCresc);
	distrugereLista(sortataDesc);
}

void run_srv_sortare_dupa_cantitate() {
	// creez o lista vida si adaug doua produse
	MyList* l = creazaListaVida();
	adaugaProdus(l, "Lapte", "Spicul", 15);
	adaugaProdus(l, "Faina", "Spicul", 10);
	assert(sizeLista(l) == 2);
	// Crescator
	MyList* sortataCresc = sortByCantitate(l, 1);
	// verific daca copia sortata crescator a fost creata cu succes
	assert(sizeLista(sortataCresc) == 2);
	Produs* pr = getProdus(sortataCresc, 0);
	assert(strcmp(getNume(pr), "Faina") == 0);
	Produs* pr2 = getProdus(sortataCresc, 1);
	assert(strcmp(getNume(pr2), "Lapte") == 0);
	// Descrescator
	MyList* sortataDesc = sortByCantitate(l, 2);
	// verific daca copia sortata descrescator a fost creata cu succes
	assert(sizeLista(sortataDesc) == 2);
	Produs* pr3 = getProdus(sortataDesc, 0);
	assert(strcmp(getNume(pr3), "Lapte") == 0);
	Produs* pr4 = getProdus(sortataDesc, 1);
	assert(strcmp(getNume(pr4), "Faina") == 0);

	// distrug listele
	distrugereLista(l);
	distrugereLista(sortataCresc);
	distrugereLista(sortataDesc);
}


void test_multiplu() {
	// creez o lista vida si adaug doua produse
	MyList* l = creazaListaVida();
	adaugaProdus(l, "Oua", "Spicul", 15);
	adaugaProdus(l, "Paine", "Spicul", 10);

	// distrug lista de produse
	assert(sizeLista(l) == 2);
	
	char nume[256] = "Oua";
	MyList* lista = multiplu(l, nume);

	for (int i = 0; i < lista->lg; i++) {
		Produs* pr = getProdus(lista, i);
		assert(getCantitate(pr) % 3 == 0);
		//printf("%s %s %d\n", getNume(pr), getProducator(pr), getCantitate(pr));
	}

	distrugereLista(lista);
	distrugereLista(l);
}
void run_all_tests() {
	run_all_domain_tests();
	run_all_validation_tests();
	run_repo_adauga_tests();
	run_repo_modificare_tests();
	run_repo_stergere_tests();
	run_srv_tests_adauga();
	run_srv_tests_modifica();
	run_srv_tests_stergere();
	run_copy_tests();
	run_srv_sortare_dupa_nume();
	run_srv_sortare_dupa_cantitate();
	run_undo_test();
	test_multiplu();
}
