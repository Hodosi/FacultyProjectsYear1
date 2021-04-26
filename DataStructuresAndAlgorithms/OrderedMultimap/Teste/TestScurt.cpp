#include <assert.h>

#include "../ProiectC++/MDO.h"
#include "../ProiectC++/IteratorMDO.h"

#include <exception>
#include <vector>

using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

void testAll(){
    MDO dictOrd = MDO(relatie1);
    assert(dictOrd.dim() == 0);
    assert(dictOrd.vid());
    dictOrd.adauga(1,2);
    dictOrd.adauga(1,3);
    assert(dictOrd.dim() == 2);
    assert(!dictOrd.vid());
    vector<TValoare> v= dictOrd.cauta(1);
    assert(v.size()==2);
    v= dictOrd.cauta(3);
    assert(v.size()==0);
    IteratorMDO it = dictOrd.iterator();
    it.prim();
    while (it.valid()){
        TElem e = it.element();
        it.urmator();
    }
    assert(dictOrd.sterge(1, 2) == true);
    assert(dictOrd.sterge(1, 3) == true);
    assert(dictOrd.sterge(2, 1) == false);
    assert(dictOrd.vid());

}

void testElementeIdentice(){
    MDO dictOrd = MDO(relatie1);
    assert(dictOrd.dim() == 0);
    assert(dictOrd.vid());
    dictOrd.adauga(1,2);
    dictOrd.adauga(1,2);
    assert(dictOrd.dim() == 1);
}

void testNou(){
    MDO dictOrd = MDO(relatie1);
    assert(dictOrd.dim() == 0);
    assert(dictOrd.vid());
    dictOrd.adauga(1,2);
    dictOrd.adauga(1,3);
    dictOrd.adauga(4, 6);
    dictOrd.adauga(3,2);
    dictOrd.adauga(5,5);

    MDO dictOrdNou = MDO(relatie1);
    assert(dictOrdNou.dim() == 0);
    assert(dictOrdNou.vid());
    dictOrdNou.adauga(1,2);
    dictOrdNou.adauga(1,3);
    dictOrdNou.adauga(4, 6);
    dictOrdNou.adauga(3,2);
    dictOrdNou.adauga(5,5);

    assert(dictOrd.adaugaInexistente(dictOrdNou) == 0);

    dictOrdNou.adauga(1,4);
    dictOrdNou.adauga(4, 7);

    assert(dictOrd.adaugaInexistente(dictOrdNou) == 2);

    dictOrdNou.adauga(4,3);
    dictOrdNou.adauga(5, 6);

    assert(dictOrd.adaugaInexistente(dictOrdNou) == 2);
}

