#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;

//Q(1)
Nod::Nod(TElem e, PNod urm, PNod prec) {
    this -> e = e;
    this -> frecv = 1;
    this -> urm = urm;
    this -> prec = prec;
}

//Q(1)
TElem Nod::element() {
    return e;
}

//Q(1)
PNod Nod::urmator() {
    return urm;
}

//Q(1)
PNod Nod::precedent() {
    return prec;
}

//Q(1)
int Nod::frecventa(){
    return frecv;
}

//Q(1)
Colectie::Colectie() {
    /* de adaugat */
    this -> prim = nullptr;
    this -> ultim = nullptr;
}

//O(n)
void Colectie::adauga(TElem elem) {
    /* de adaugat */

    //daca lista e vida
    if(vida()){
        PNod new_nod = new Nod(elem, nullptr, nullptr);
        this -> prim = new_nod;
        this -> ultim = new_nod;
        return;
    }
    //daca elem apare in lista
    PNod curent = this -> prim;
    while(curent != nullptr){
        if(curent -> element() == elem){
            curent -> frecv = curent->frecventa() + 1;
            return;
        }
        curent = curent->urmator();
    }
    //daca elem trebuie adaugat la final
    PNod new_nod = new Nod(elem, nullptr, nullptr);
    new_nod -> prec = this -> ultim;
    this -> ultim -> urm = new_nod;
    this -> ultim = new_nod;
}

//O(n)
bool Colectie::sterge(TElem elem) {
    /* de adaugat */

    //daca lista e vida
    if(vida()){
        return false;
    }
    //daca elem apare in lista
    PNod curent = this -> prim;
    while(curent != nullptr){
        if(curent -> element() == elem){
            //daca ii ultimul element de tip elem
            if(curent -> frecventa() == 1){
                PNod crt_precedent = curent -> precedent();
                PNod crt_urmator = curent -> urmator();
                //daca ii ultimul element din lista
                if(crt_precedent == nullptr && crt_urmator == nullptr){
                    this -> prim = nullptr;
                    this -> ultim = nullptr;
                    delete curent;
                    return true;
                }
                //daca ii primul element din lista
                if(crt_precedent == nullptr){
                    crt_urmator -> prec = nullptr;
                    this -> prim = crt_urmator;
                    delete curent;
                    return true;
                }
                //daca ii ultimul element din lista
                if(crt_urmator == nullptr){
                    crt_precedent -> urm = nullptr;
                    this -> ultim = crt_precedent;
                    delete curent;
                    return true;
                }
                //daca ii intre primul si ultimul element din lista
                crt_precedent -> urm = crt_urmator;
                crt_urmator -> prec = crt_precedent;
                delete curent;
                return true;
            }
            //daca elemntul de tip elem ramane in lista
            curent -> frecv = curent -> frecventa() - 1;
            return true;
        }
        curent = curent -> urmator();
    }
    //daca elem nu apare in lista
    return false;
}

//O(n)
bool Colectie::cauta(TElem elem) const {
    /* de adaugat */

    if(vida()){
        return false;
    }
    //daca elem apare in lista
    PNod curent = this -> prim;
    while(curent != nullptr){
        if(curent -> element() == elem){
            return true;
        }
        curent = curent -> urmator();
    }
    return false;
}

//O(n)
int Colectie::nrAparitii(TElem elem) const {
    /* de adaugat */
    if(vida()){
        return 0;
    }
    //daca elem apare in lista
    PNod curent = this -> prim;
    while(curent != nullptr){
        if(curent -> element() == elem){
            return curent -> frecventa();
        }
        curent = curent -> urmator();
    }
    return 0;
}

//Q(n)
int Colectie::dim() const {
    /* de adaugat */
    int dimeniune = 0;
    if(vida()){
        return dimeniune;
    }
    //daca sunt elemente in lista
    PNod curent = this -> prim;
    while(curent != nullptr){
        dimeniune += curent -> frecventa();
        curent = curent -> urmator();
    }
    return dimeniune;
}

//Q(1)
bool Colectie::vida() const {
    /* de adaugat */
    if(this -> prim == nullptr && this -> ultim == nullptr){
        return true;
    }
    return false;
}

//Q(1)
IteratorColectie Colectie::iterator() const {
    return  IteratorColectie(*this);
}

//Q(n)
Colectie::~Colectie() {
    /* de adaugat */
    if(!vida()){
        //daca elem apare in lista
        PNod curent = this -> prim;
        while(curent != nullptr) {
            PNod aux_urmator = curent->urmator();
            delete curent;
            curent = aux_urmator;
        }
    }
}

/*
 * n - numarul de elemente distincte
 * Caz defavorabil: Q(n)
 * Caz favorabil: Q(n)
 * Caz mediu: Q(n)
 * Total: Q(n)
 */
int Colectie::transformaInMultime(){
    int dimeniune = 0;

    //daca sunt elemente in lista
    PNod curent = this -> prim;
    while(curent != nullptr){
        if(curent -> frecventa() > 1){
            dimeniune += curent -> frecventa() - 1;
            curent -> frecv = 1;
        }
        curent = curent -> urmator();
    }
    return dimeniune;
}

/*
 * Subalgoritm transformaInMultime(Colectie, dimensiune)
 *   { pre: Colectie: LDI}
 *   { post: dimensiune: intreg, returneaza numarul de elemente eliminate}
 *
 *   dimensiune <- 0
 *
 *   curent <- Colectie.prim
 *   CatTimp curent != NIL executa
 *       Daca frecventa(curent, frecv) > 1 atunci
 *           dimensiune = dimensiune + frecventa(curent, frecv) - 1
 *           curent.frecv = 1
 *       SfDaca
 *       urmator(Colectie, curent)
 *   SfCatTimp
 */



