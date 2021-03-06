//
// Created by Hodosi on 5/28/2021.
//

#ifndef ORDEREDMULTIMAP_BST_ITERATORMDO_H
#define ORDEREDMULTIMAP_BST_ITERATORMDO_H

#include "MDO.h"


class IteratorMDO{
    friend class MDO;
private:

    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container
    IteratorMDO(const MDO& dictionar);

    //contine o referinta catre containerul pe care il itereaza
    const MDO& dict;
    /* aici e reprezentarea  specifica a iteratorului */

    int curent_chei;
    int curent_val;
    vector<pair<TCheie, vector<TValoare>>> _elemente_inordine;

public:

    //reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void urmator();

    //verifica daca iteratorul e valid (indica un element al containerului)
    bool valid() const;

    //returneaza valoarea elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    TElem element() const;

    // mută cursorul iteratorului a.î. să refere a k-a pereche în urmă, începând de la cea curentă. Iteratorul devine nevalid în cazul în care există mai puțin de  k perechi anterioare perechi curente în multidicționar.

    // aruncă excepție în cazul în care iteratorul este nevalid sau k este zero ori negativ.
    void revinoKPasi(int k);
};


#endif //ORDEREDMULTIMAP_BST_ITERATORMDO_H
