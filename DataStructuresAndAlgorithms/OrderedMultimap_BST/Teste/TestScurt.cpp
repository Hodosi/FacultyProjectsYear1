//
// Created by Hodosi on 5/28/2021.
//

#include "TestScurt.h"

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


void testNou(){
    MDO dictOrd = MDO(relatie1);
    assert(dictOrd.dim() == 0);
    assert(dictOrd.vid());
    dictOrd.adauga(2,1);
    dictOrd.adauga(2,2);
    dictOrd.adauga(1,1);
    dictOrd.adauga(1,2);
    dictOrd.adauga(4,1);
    dictOrd.adauga(4,2);
    dictOrd.adauga(3,1);
    dictOrd.adauga(3,2);
    assert(dictOrd.dim() == 8);
    assert(!dictOrd.vid());

    IteratorMDO it = dictOrd.iterator();
    it.prim();
    try {
        it.revinoKPasi(0);
        assert(false);
    }
    catch (exception&){
        assert(true);
    }
    try {
        it.revinoKPasi(-1);
        assert(false);
    }
    catch (exception&){
        assert(true);
    }
    TElem super_old_e = it.element();
    it.urmator();
    TElem old_e = it.element();
    it.urmator();
    it.urmator();
    try {
        it.revinoKPasi(4);
        assert(false);
    }
    catch (exception&){
        assert(true);
    }
    it.revinoKPasi(2);
    TElem new_e = it.element();
    it.urmator();
    it.urmator();
    it.revinoKPasi(3);
    TElem super_new_e = it.element();
    assert(old_e.first == new_e.first);
    assert(old_e.second == new_e.second);
    assert(super_old_e.first == super_new_e.first);
    assert(super_old_e.second == super_new_e.second);
    while (it.valid()){
        TElem e = it.element();
        it.urmator();
    }
}
