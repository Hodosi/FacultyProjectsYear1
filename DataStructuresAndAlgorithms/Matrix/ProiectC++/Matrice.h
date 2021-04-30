#ifndef MATRIX_MATRICE_H
#define MATRIX_MATRICE_H

#define MAX 100

typedef int TElem;

#define NULL_TELEMENT 0

//class Iterator;

class Nod;

typedef Nod* PNod;

class Nod {

private:
    int _linie;
    int _coloana;
    TElem _element;
    PNod _urmator;

public:
    friend class Matrice;
    //friend class Iterator;
    Nod(TElem _element, PNod _urmator, int _linie, int _coloana);
    TElem element();
    PNod urmator();

};

class Matrice {

private:
    /* aici e reprezentarea */

    int _linii;
    int _coloane;
    int _dimensiune;
    PNod _liste_independente[MAX];

    int hashCode(int _linie, int _coloana) const;
    int hashFunction(int _linie, int _coloana) const;

public:

    //constructor
    //se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
    Matrice(int nrLinii, int nrColoane);


    //destructor
    ~Matrice();

    //returnare element de pe o linie si o coloana
    //se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
    //indicii se considera incepand de la 0
    TElem element(int i, int j) const;


    // returnare numar linii
    int nrLinii() const;

    // returnare numar coloane
    int nrColoane() const;


    // modificare element de pe o linie si o coloana si returnarea vechii valori
    // se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
    TElem modifica(int i, int j, TElem);

};


#endif //MATRIX_TESTEXTINS_H




