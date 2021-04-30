#include "Matrice.h"
#include "math.h"

#include <exception>

using namespace std;

Nod::Nod(TElem _element, PNod _urmator, int _linie, int _coloana) {

    this->_element = _element;
    this->_urmator = _urmator;
    this->_linie = _linie;
    this->_coloana = _coloana;
}

TElem Nod::element() {
    return this->_element;
}

PNod Nod::urmator(){
    return this->_urmator;
}

int Matrice::hashCode(int _linie, int _coloana) const {
    return abs(_linie) + abs(_coloana);
}

int Matrice::hashFunction(int _linie, int  _coloana) const {
    return hashCode(_linie, _coloana) % this->_dimensiune;
}

Matrice::Matrice(int m, int n) {
    /* de adaugat */

    if(m <= 0 || n <= 0){
        throw 1;
    }

    this->_linii = m;
    this->_coloane = n;

    this->_dimensiune = MAX;
    for(int i = 0; i < this->_dimensiune; i++){
        this->_liste_independente[i] = nullptr;
    }
}

Matrice::~Matrice() {

    for(int i = 0; i < this->_dimensiune; i++){
        while(this->_liste_independente[i] != nullptr){
            PNod _curent = this->_liste_independente[i];
            this->_liste_independente[i] = this->_liste_independente[i]->_urmator;
            delete _curent;
        }
    }
}



int Matrice::nrLinii() const{
    /* de adaugat */
    //return 0;

    return this->_linii;
}


int Matrice::nrColoane() const{
    /* de adaugat */
    //return 0;

    return this->_coloane;
}


TElem Matrice::element(int i, int j) const{
    /* de adaugat */
    //return -1;

    if(i < 0 || i >= _linii || j < 0 || j >= _coloane){
        throw exception();
    }

    int _hash_position = this->hashFunction(i, j);

    PNod _curent = _liste_independente[_hash_position];
    while (_curent != nullptr){
        if(_curent->_linie == i && _curent->_coloana == j) {
            TElem old_element = _curent->_element;
            return old_element;
        }
        _curent = _curent -> _urmator;
    }

    return NULL_TELEMENT;
}



TElem Matrice::modifica(int i, int j, TElem e) {
    /* de adaugat */
    //return -1;

    if(i < 0 || i >= _linii || j < 0 || j >= _coloane){
        throw exception();
    }

    int _hash_position = this->hashFunction(i, j);

    PNod _curent = _liste_independente[_hash_position];
    while (_curent != nullptr){
        if(_curent->_linie == i && _curent->_coloana == j) {
            TElem old_element = _curent->_element;
            _curent->_element = e;
            return old_element;
        }
        _curent = _curent -> _urmator;
    }

    PNod _element = new Nod(e, nullptr, i, j);

    _element->_urmator = _liste_independente[_hash_position];

    _liste_independente[_hash_position] = _element;

    return NULL_TELEMENT;
}


