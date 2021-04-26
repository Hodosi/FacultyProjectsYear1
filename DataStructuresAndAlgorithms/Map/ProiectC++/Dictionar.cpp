#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"

void Dictionar::redim() {
    TElem *new_elemente = new TElem [2 * capacitate];

    for(int i = 0; i < dimensiune; i++){
        new_elemente[i] = elemente[i];
    }

    capacitate = 2 * capacitate;

    delete[] elemente;

    elemente = new_elemente;
}

Dictionar::Dictionar() {
    /* de adaugat */
    this -> capacitate = 1;
    elemente = new TElem [this -> capacitate];
    this -> dimensiune = 0;
}

Dictionar::~Dictionar() {
    /* de adaugat */
    delete[] elemente;
}

TValoare Dictionar::adauga(TCheie c, TValoare v){
    /* de adaugat */
    TElem new_element;
    new_element.first = c;
    new_element.second = v;
    for(int i = 0; i < dimensiune; i++){
        if(elemente[i].first == c){
            TValoare vecheTValoare = elemente[i].second;
            elemente[i].second = v;
            return vecheTValoare;
        }
    }
    if(dimensiune == capacitate){
        redim();
    }
    this -> elemente[dimensiune] = new_element;
    dimensiune++;
    return NULL_TVALOARE;
}



//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare Dictionar::cauta(TCheie c) const{
    /* de adaugat */
    for(int i = 0; i < dimensiune; i++){
        if(elemente[i].first == c){;
            return elemente[i].second;
        }
    }
    return NULL_TVALOARE;
}


TValoare Dictionar::sterge(TCheie c){
    /* de adaugat */
    for(int i = 0; i < dimensiune; i++){
        if(elemente[i].first == c){
            TValoare TValoare = elemente[i].second;
            for(int j = i; j < dimensiune - 1; j++){
                elemente[j] = elemente[j + 1];
            }
            dimensiune--;
            return TValoare;
        }
    }
    return NULL_TVALOARE;
}


int Dictionar::dim() const {
    /* de adaugat */
    return dimensiune;
}

bool Dictionar::vid() const{
    /* de adaugat */
    if(dimensiune == 0){
        return true;
    }
    return false;
}


IteratorDictionar Dictionar::iterator() const {
    return  IteratorDictionar(*this);
}


