//
// Created by Hodosi on 4/6/2021.
//

#ifndef ORDEREDMULTIMAP_MDO_H
#define ORDEREDMULTIMAP_MDO_H

#include <vector>

typedef int TCheie;
typedef int TValoare;

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

using namespace std;

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);

class MDO {
    friend class IteratorMDO;
private:
    /* aici e reprezentarea */

    // relatia intre chei
    Relatie rel;

    // vector dinamic de elemente
    int capacitate;
    int dimensiune;

    // *vectori de elemente
    TElem *elemente;

    // *vectori de legaturi
    int *leg_urmator;
    int *leg_precedent;

    // pentru redimensionare
    void redim();

    // primul element al listei
    int prim;

    // ultimul element al listei;
    int ultim;

    // primul element liber
    int prim_liber;

    // functii pentru alocarea/dealocarea unui spatiu liber
    // se returneaza pozitia unui spatiu liber in lista
    int aloca();

    // dealoca spatiul de indice i
    void dealoca(int i);

    // functie privata care creeaza un nod in lista inlantuita
    int creeazaNod(TElem element);

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

    //functionalitate noua
    int adaugaInexistente(MDO& mdo);

};


#endif //ORDEREDMULTIMAP_MDO_H
