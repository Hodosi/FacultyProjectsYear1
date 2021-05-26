#include "TestScurt.h"
#include <assert.h>
#include "../ProiectC++/Matrice.h"
#include <iostream>

using namespace std;

void testAll() { //apelam fiecare functie sa vedem daca exista
    Matrice m(4,4);
    assert(m.nrLinii() == 4);
    assert(m.nrColoane() == 4);
    //adaug niste elemente
    m.modifica(1,1,5);
    assert(m.element(1,1) == 5);
    m.modifica(1,1,6);
    assert(m.element(1,2) == NULL_TELEMENT);
}

void testIterator(){
    Matrice m(4,4);
    assert(m.nrLinii() == 4);
    assert(m.nrColoane() == 4);
    //adaug niste elemente
    m.modifica(1,1,5);
    assert(m.element(1,1) == 5);
    m.modifica(1,1,6);
    assert(m.element(1,2) == NULL_TELEMENT);

    m.modifica(1,2, 7);

    IteratorMatrice iterator_front = m.iterator(1);
    iterator_front.prim();
    while (iterator_front.valid()){
        TElem e = iterator_front.element();
        iterator_front.urmator();
        cout << e << " ";
    }
    cout << "\n";

    IteratorMatrice iterator_back = m.iterator(1);
    iterator_back.ultim();
    while (iterator_back.valid()){
        TElem e = iterator_back.element();
        iterator_back.precedent();
        cout << e << " ";
    }
    cout << "\n";

    try{
        IteratorMatrice iterator_wrong = m.iterator(-1);
    }
    catch (exception& ex){
        cout << "iterator invalid\n";
    }

    try{
        IteratorMatrice iterator_wrong = m.iterator(4);
    }
    catch (exception& ex){
        cout << "iterator invalid\n";
    }

}

void testIteratorAssert(){
    Matrice m(4,4);
    assert(m.nrLinii() == 4);
    assert(m.nrColoane() == 4);
    //adaug niste elemente
    m.modifica(1,1,5);
    assert(m.element(1,1) == 5);
    m.modifica(1,1,6);
    assert(m.element(1,2) == NULL_TELEMENT);

    m.modifica(1,2, 7);

    IteratorMatrice iterator_front = m.iterator(1);
    iterator_front.prim();
    TElem e = iterator_front.element();
    assert(e == NULL_TELEMENT);
    iterator_front.urmator();
    e = iterator_front.element();
    assert(e == 6);
    iterator_front.urmator();
    e = iterator_front.element();
    assert(e == 7);

    IteratorMatrice iterator_back = m.iterator(1);
    iterator_back.ultim();
    e = iterator_back.element();
    assert(e == NULL_TELEMENT);
    iterator_back.precedent();
    e = iterator_back.element();
    assert(e == 7);
    iterator_back.precedent();
    e = iterator_back.element();
    assert(e == 6);

    try{
        IteratorMatrice iterator_wrong = m.iterator(-1);
    }
    catch (exception& ex){
        cout << "iterator invalid\n";
    }

    try{
        IteratorMatrice iterator_wrong = m.iterator(4);
    }
    catch (exception& ex){
        cout << "iterator invalid\n";
    }
}
