#include "IteratorDictionar.h"
#include "Dictionar.h"

using namespace std;

IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d){
    /* de adaugat */

    curent = 0;

    //v2
    //curent = d.elemente;
}


void IteratorDictionar::prim() {
    /* de adaugat */

    curent = 0;

    //v2
    //curent = dict.elemente;
}


void IteratorDictionar::urmator() {
    /* de adaugat */

    curent++;
}


TElem IteratorDictionar::element() const{
    /* de adaugat */

    return dict.elemente[curent];

    //v2
    //return *curent;

    //return pair <TCheie, TValoare>  (-1, -1);
}


bool IteratorDictionar::valid() const {
    /* de adaugat */

    if(curent < dict.dim()){
        return true;
    }
    return false;


    //v2
    //return curent-dict.elemente < dict.dim();
}

