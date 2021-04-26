#include <stdio.h>
#include "service.h"
#include <stdbool.h>
#include <string.h>
#include "MyList.h"
#include "undoList.h"
#include "produs.h"

void meniuPrincipal()
{
	printf("\n=====Meniu Principal=====\n");
	printf("[1]. Adaugare materie prima\n");
	printf("[2]. Modificare materie prima\n");
	printf("[3]. Stergere materie prima\n");
	printf("[4]. Afisare materii prime a caror nume incepe cu o litera data\n");
	printf("[5]. Afisare materii prime a caror cantitate este mai mica decat un numar dat\n");
	printf("[6]. Afisare materii prime sortate dupa nume\n");
	printf("[7]. Afisare materii prime sortate dupa cantitatea disponibila\n");
	printf("[8]. Print all\n");
	printf("[0]. EXIT\n");
	printf("[9]. UNDO\n");
	printf("[10]. Afisare materii prime a caror cantitate este mai mare sau egal decat un numar dat\n");
	printf("[11]. Materii prime multiplu de 3\n");
}

MyList* my_undo(MyList* produse, UndoList* undo_list) {
	Element rez_undo = undoUndoList(undo_list);
	if (rez_undo == NULL) {
		printf("Nu se mai poate face undo!\n");
	}
	else {
		distrugereLista(produse);
		MyList* mm = (MyList*)rez_undo;
		produse = mm;
		printf("Undo Prezent!");
	}
	return produse;
}

MyList* ui_adaugare(MyList* produse, UndoList* undo_list)
{
	char nume[20];
	printf("\n>>>Introduceti numele: ");
	scanf("%s", nume);
	char producator[20];
	printf(">>>Introduceti producatorul: ");
	scanf("%s", producator);
	int cantitate;
	printf(">>>Introduceti cantitatea: ");
	scanf("%d", &cantitate);

	addUndoList(undo_list, produse);
	int err = adaugaProdus(produse, nume, producator, cantitate);
	if (err != 0) {
		produse = my_undo(produse, undo_list);
		printf("\n...Eroare la adaugare!...\n");
	}
	else {
		printf("\n...Adaugarea a fost realizata cu succes!...\n");
	}
	return produse;
}

void ui_print_all(MyList* produse, UndoList* undo_list) {
	if (sizeLista(produse) == 0) {
		printf("\n...Nu exista elemente in lista!...\n");
		return;
	}
	printf("\n");
	for (int i = 0; i < sizeLista(produse); i++) {
		Produs* pr = getProdus(produse, i);
		printf("%s %s %d\n", getNume(pr), getProducator(pr), getCantitate(pr));
	}
	printf("\n\n");
	printf("Undo List:\n\n");

	for (int i = 0; i < undo_list->length; i++) {
		MyList* produs = undo_list->items[i];
		for (int j = 0; j < produs->lg; j++) {
			Produs* p = getProdus(produs, j);
			printf("%s %s %d\n", getNume(p), getProducator(p), getCantitate(p));
		}
		printf("\n\n");
	}
	printf("\n\n");
}

MyList* ui_modificare(MyList* produse, UndoList* undo_list)
{
	char nume[20];
	printf("\n>>>Introduceti numele: ");
	scanf("%s", nume);
	char producator[20];
	printf(">>>Introduceti noul producator: ");
	scanf("%s", producator);
	int cantitate;
	printf(">>>Introduceti noua cantitate: ");
	scanf("%d", &cantitate);

	addUndoList(undo_list, produse);
	int err = modificaProdus(produse, nume, producator, cantitate);
	if (err != 0) {
		produse = my_undo(produse, undo_list);
		printf("\n...Eroare la modificare!...\n");
	}
	else {
		printf("\n...Modificarea a fost realizata cu succes!...\n");
	}
	return produse;
}

MyList* ui_stergere(MyList* produse, UndoList* undo_list)
{
	char nume[20];
	printf("\n>>>Introduceti numele: ");
	scanf("%s", nume);

	addUndoList(undo_list, produse);
	int err = stergeProdus(produse, nume);
	if (err != 0) {
		produse = my_undo(produse, undo_list);
		printf("\n...Eroare la stergere!...\n");
	}
	else {
		printf("\n...Stergerea a fost realizata cu succes!...\n");
	}
	return produse;
}

void ui_afisare_dupa_litera(MyList* produse)
{
	char litera[20] = { '\0' };
	printf("\n>>>Introduceti litera: ");
	scanf("%s", litera);
	if (strlen(litera) != 1) {
		printf("\n...Eroare la afisare!...\n");
		return;
	}
	if (sizeLista(produse) == 0) {
		printf("\n...Nu exista elemente in lista!...\n");
		return;
	}
	printf("\n");
	int ok = 0;
	for (int i = 0; i < sizeLista(produse); i++) {
		Produs* pr = getProdus(produse, i);
		if (pr->nume[0] == litera[0]) {
			printf("%s %s %d\n", getNume(pr), getProducator(pr), getCantitate(pr));
			ok = 1;
		}
	}
	if (ok == 0) {
		printf("\n...Nu exista produse cu aceasta proprietate!...\n");
	}
}

void ui_afisare_dupa_cantitate(MyList* produse)
{
	int numar;
	printf("\n>>>Introduceti numarul: ");
	if (scanf("%d", &numar) == 1);			// nu merge!! ?
	else {
		printf("\n...Introduceti un numar!...\n");
		return;
	}
	if (numar < 0) {
		printf("\n...Eroare la afisare!...\n");
		return;
	}
	if (sizeLista(produse) == 0) {
		printf("\n...Nu exista elemente in lista!...\n");
		return;
	}
	printf("\n");
	int ok = 0;
	for (int i = 0; i < sizeLista(produse); i++) {
		Produs* pr = getProdus(produse, i);
		if (pr->cantitate <= (int)numar) {
			printf("%s %s %d\n", getNume(pr), getProducator(pr), getCantitate(pr));
			ok = 1;
		}
	}
	if (ok == 0) {
		printf("\n...Nu exista produse cu aceasta proprietate!...\n");
	}
}

void ui_afisare_dupa_cantitate_mare(MyList* produse)
{
	int numar;
	printf("\n>>>Introduceti numarul: ");
	if (scanf("%d", &numar) == 1);			// nu merge!! ?
	else {
		printf("\n...Introduceti un numar!...\n");
		return;
	}
	if (numar < 0) {
		printf("\n...Eroare la afisare!...\n");
		return;
	}
	if (sizeLista(produse) == 0) {
		printf("\n...Nu exista elemente in lista!...\n");
		return;
	}
	printf("\n");
	int ok = 0;
	for (int i = 0; i < sizeLista(produse); i++) {
		Produs* pr = getProdus(produse, i);
		if (pr->cantitate >= (int)numar) {
			printf("%s %s %d\n", getNume(pr), getProducator(pr), getCantitate(pr));
			ok = 1;
		}
	}
	if (ok == 0) {
		printf("\n...Nu exista produse cu aceasta proprietate!...\n");
	}
}

void ui_afisare_sortata_nume(MyList* produse)
{
	printf("\n[1]. Crescator\n[2]. Descrescator\n");
	printf("\n>>>Introduceti optiunea dvs.: ");
	int opt;
	scanf("%d", &opt);
	if (opt != 1 && opt != 2) {
		printf("\n...Optiune invalida!...\n");
		return;
	}
	MyList* listaSortata = sortByNume(produse, opt);
	//ui_print_all(listaSortata);
	distrugereLista(listaSortata);
}

void ui_afisare_sortata_cantitate(MyList* produse)
{
	printf("\n[1]. Crescator\n[2]. Descrescator\n");
	printf("\n>>>Introduceti optiunea dvs.: ");
	int opt;
	scanf("%d", &opt);
	if (opt != 1 && opt != 2) {
		printf("\n...Optiune invalida!...\n");
		return;
	}
	MyList* listaSortata = sortByCantitate(produse, opt);
	//ui_print_all(listaSortata);
	distrugereLista(listaSortata);
}

void ui_multiplu_trei(MyList* produse) {
	char nume[20];
	printf("\n>>>Introduceti numele: ");
	scanf("%s", nume);
	
	MyList* lista = multiplu(produse, nume);

	for (int i = 0; i < lista -> lg; i++) {
		Produs* pr = getProdus(lista, i);
		printf("%s %s %d\n", getNume(pr), getProducator(pr), getCantitate(pr));
	}

	distrugereLista(lista);
	printf("\n\n");
}

void adaugaProduse_auto(MyList* produse) {
	adaugaProdus(produse, "Lapte", "Spicul", 50);
	adaugaProdus(produse, "Lapte", "Dorolact", 20);
	adaugaProdus(produse, "Oua", "Spicul", 300);
	adaugaProdus(produse, "Ciocolata_alba", "Dr_Oetker", 150);
	adaugaProdus(produse, "Zahar", "Magica", 100);
	adaugaProdus(produse, "Cacao", "Magica", 10);
	adaugaProdus(produse, "Frisca", "Eventist", 10);
	adaugaProdus(produse, "Esenta_roma", "Aroma", 40);
	adaugaProdus(produse, "Gelatina", "Dr_Oetker", 70);
}

void run()
{
	MyList* produse = creazaListaVida();
	UndoList* undo_list = createUndoList();
	adaugaProduse_auto(produse);
	//addUndoList(undo_list, produse);
	while (true)
	{
		meniuPrincipal();
		int opt;
		printf("\n>>>Introduceti optiunea dvs.: ");
		scanf("%d", &opt);
		if (opt == 0)
		{
			distrugereLista(produse);
			destroyUndoList(undo_list);
			printf("\n...Multumesc ca ai utilizat aplicatia mea! Bye!...\n");
			return;
		}
		switch (opt)
		{
		case 1:
			produse = ui_adaugare(produse, undo_list);
			break;
		case 2:
			produse = ui_modificare(produse, undo_list);
			break;
		case 3:
			produse = ui_stergere(produse, undo_list);
			break;
		case 4:
			ui_afisare_dupa_litera(produse);
			break;
		case 5:
			ui_afisare_dupa_cantitate(produse);
			break;
		case 6:
			ui_afisare_sortata_nume(produse);
			break;
		case 7:
			ui_afisare_sortata_cantitate(produse);
			break;
		case 8:
			ui_print_all(produse, undo_list);
			break;
		case 9:
			produse = my_undo(produse, undo_list);
			break;
		case 10:
			ui_afisare_dupa_cantitate_mare(produse);
			break;
		case 11:
			ui_multiplu_trei(produse);
			break;
		default:
			printf("\n...Optiune invalida!...\n");
			break;
		}
	}
}
