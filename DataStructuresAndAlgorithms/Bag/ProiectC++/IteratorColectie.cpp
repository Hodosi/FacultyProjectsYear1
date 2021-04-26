#include "IteratorColectie.h"
#include "Colectie.h"

//Q(1)
IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
    /* de adaugat */
    nod_curent = c.prim;
    index_curent = 1;
}

//Q(1)
void IteratorColectie::prim() {
    /* de adaugat */
    nod_curent = col.prim;
    index_curent = 1;
}

//Q(1)
void IteratorColectie::urmator() {
    /* de adaugat */
    if(nod_curent->frecventa() > index_curent){
        index_curent++;
    }
    else{
        nod_curent = nod_curent -> urmator();
        index_curent = 1;
    }
}

//Q(1)
bool IteratorColectie::valid() const {
    /* de adaugat */
    return nod_curent != nullptr;
}

//Q(1)
TElem IteratorColectie::element() const {
    /* de adaugat */
    return nod_curent -> element();
}

