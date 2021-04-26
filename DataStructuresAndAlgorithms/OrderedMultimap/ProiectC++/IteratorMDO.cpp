#include "IteratorMDO.h"
#include "MDO.h"

// Q(1)
IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
    /* de adaugat */
    curent = d.prim;
}

// Q(1)
void IteratorMDO::prim(){
    /* de adaugat */
    curent = this->dict.prim;
}

// Q(1)
void IteratorMDO::urmator(){
    /* de adaugat */
    curent = this->dict.leg_urmator[curent];
}

//Q(1)
bool IteratorMDO::valid() const{
    /* de adaugat */
    // return false
    if(curent == -1){
        return false;
    }
    return true;
}

//Q(1)
TElem IteratorMDO::element() const{
    /* de adaugat */
    //return pair <TCheie, TValoare>  (-1, -1);

    return this->dict.elemente[curent];
}


