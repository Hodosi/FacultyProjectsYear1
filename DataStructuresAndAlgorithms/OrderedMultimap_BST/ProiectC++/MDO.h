//
// Created by Hodosi on 5/28/2021.
//

#ifndef ORDEREDMULTIMAP_BST_MDO_H
#define ORDEREDMULTIMAP_BST_MDO_H

#include <vector>

typedef int TCheie;
typedef int TValoare;

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

using namespace std;

class MDO;

class Nod;

typedef Nod *PNod;
class Nod {
public:
    friend class MDO;

    Nod(TElem elem, int st, int dr);
    int stanga() const;
    int dreapta() const;
    TCheie cheie() const;
    vector<TValoare> valori() const;

private:
    TCheie _cheie;
    vector<TValoare> _valori;
    int _stanga, _dreapta;
};

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);

class MDO {
    friend class IteratorMDO;
private:
    /* aici e reprezentarea */

    int _index_radacina;

    PNod radacina() const;
    Relatie _relatie;

    int _capacitate;
    int _dimensiune;

    PNod *_elemente;

    void stergeNod(int index, int index_parinte);
    PNod stergeMin(int index, int index_parinte);
    void redim();

public:

    // constructorul implicit al MultiDictionarului Ordonat
    MDO(Relatie r);

    // adauga o pereche (cheie, valoare) in MDO
    void adauga(TCheie c, TValoare v);

    //cauta o cheie si returneaza vectorul de valori asociate
    vector<TValoare> cauta(TCheie c) const;

    //sterge o cheie si o valoare
    //returneaza adevarat daca s-a gasit cheia si valoarea de sters
    bool sterge(TCheie c, TValoare v);

    //returneaza numarul de perechi (cheie, valoare) din MDO
    int dim() const;

    //verifica daca MultiDictionarul Ordonat e vid
    bool vid() const;

    // se returneaza iterator pe MDO
    // iteratorul va returna perechile in ordine in raport cu relatia de ordine
    IteratorMDO iterator() const;

    // destructorul
    ~MDO();

};


#endif //ORDEREDMULTIMAP_BST_MDO_H
