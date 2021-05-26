#include "Matrice.h"
#include "math.h"

#include <exception>

using namespace std;

//Q(1)
Nod::Nod(TElem _element, PNod _urmator, int _linie, int _coloana) {

    this->_element = _element;
    this->_urmator = _urmator;
    this->_linie = _linie;
    this->_coloana = _coloana;
}

//Q(1)
TElem Nod::element() {
    return this->_element;
}

//Q(1)
PNod Nod::urmator(){
    return this->_urmator;
}

//Q(1)
int Matrice::hashCode(int _linie, int _coloana) const {
    return abs(_linie) + abs(_coloana);
}

//Q(1)
int Matrice::hashFunction(int _linie, int  _coloana) const {
    return hashCode(_linie, _coloana) % this->_dimensiune;
}

//n - numarul de liste independente
//Q(n)
Matrice::Matrice(int m, int n) {
    /* de adaugat */

    if(m <= 0 || n <= 0){
        throw exception();
    }

    this->_linii = m;
    this->_coloane = n;

    this->_dimensiune = MAX;
    for(int i = 0; i < this->_dimensiune; i++){
        this->_liste_independente[i] = nullptr;
    }
}

//n - numarul de liste independente
//m - numarul de elemente
//Q(max(n, m))
Matrice::~Matrice() {

    for(int i = 0; i < this->_dimensiune; i++){
        while(this->_liste_independente[i] != nullptr){
            PNod _curent = this->_liste_independente[i];
            this->_liste_independente[i] = this->_liste_independente[i]->_urmator;
            delete _curent;
        }
    }
}

//Q(1)
int Matrice::nrLinii() const{
    /* de adaugat */
    //return 0;

    return this->_linii;
}

//Q(1)
int Matrice::nrColoane() const{
    /* de adaugat */
    //return 0;

    return this->_coloane;
}

//n - numarul de elemente aflate in coliziune
//Q(n) - caz defavorabil
//O(1) - in general
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


//n - numarul de elemente aflate in coliziune
//Q(n) - caz defavorabil
//O(1) - in general
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

/*
 * Caz defavorabil: Q(1)
 * Caz favorabil: Q(1)
 * Caz mediu: Q(1)
 * Total: Q(1)
 */

IteratorMatrice Matrice::iterator(int _linie) const{
    return IteratorMatrice(*this, _linie);
}

//Q(1)
IteratorMatrice::IteratorMatrice(const Matrice &_matrix, int _linie) : matrix{ _matrix }, linie { _linie } {
    if(this->linie < 0 || this->linie >= matrix.nrLinii()){
        throw exception();
    }

   this->coloana = 0;
}

//Q(1)
void IteratorMatrice::prim() {
    this->coloana = 0;
}

//Q(1)
void IteratorMatrice::ultim() {
    this->coloana = matrix._coloane - 1;
}

//Q(1)
void IteratorMatrice::urmator() {
    this->coloana++;
}

//Q(1)
void IteratorMatrice::precedent() {
    this->coloana--;
}

//Q(1)
bool IteratorMatrice::valid() const {
    return this->coloana < matrix._coloane && this->coloana >= 0;
}

//n - numarul de elemente aflate in coliziune
//Q(n) - caz defavorabil
//O(1) - in general
TElem IteratorMatrice::element() const {
    return matrix.element(this->linie, this->coloana);
}

/*
 * subalgoritm IteratorMatrice iterator(matrice, linia, iterator){
 *   {
 *   pre:
 *        matrice : matrice rara, TD
 *        linia : intreg
 *   }
 *   {
 *   post:
 *        iterator : iterator valid pe matricea asociata
 *        execptie : daca linia este invalida
 *   }
 *
 *   Daca line < 0 sau line >= nrLinii(matrice) atunci
 *       arunca exceptie
 *
 *   iterator.coloana <- 0
 */

/*
subalgoritm prim(iterator) {
    iterator.coloana <- 0
}

subalgoritm ultim(iterator, matrice) {
    iterator.coloana <- nrColoane(matrice) - 1
}


subalgoritm urmator(iterator) {
    iterator.coloana += 1
}

subalgoritm precedent(iterator) {
    iterator.coloana -= 1
}

subalgoritm valid(iterator, matrice, valid) {
    Daca iterator.coloana < nrColoane(matrice) si iterator.coloana >= 0 atunci
        valid = true
    altfel
        valid = false
}

subalgoritm element(matrice, elem) {
    elem <- element(matrice, iterator.linie, iterator.coloana)
}
*/