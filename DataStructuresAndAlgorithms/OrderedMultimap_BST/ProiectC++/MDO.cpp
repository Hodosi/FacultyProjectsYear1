//
// Created by Hodosi on 5/28/2021.
//

#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#include <exception>
using namespace std;

Nod::Nod(TElem elem, int st, int dr) {
    this->_cheie = elem.first;
    _valori.push_back(elem.second);
    this->_stanga = st;
    this->_dreapta = dr;
}

int Nod::stanga() const{
    return this->_stanga;
}

int Nod::dreapta() const {
    return this->_dreapta;
}

TCheie Nod::cheie() const {
    return this->_cheie;
};

vector<TValoare> Nod::valori() const{
    return this->_valori;
}

PNod MDO::radacina() const {
    return this->_elemente[_index_radacina];
}


void MDO::redim() {

    PNod *new_elemente = new PNod [2 * this->_capacitate + 1];

    for(int i = 0; i < this->_capacitate; i++){
        TElem new_element;
        PNod old_nod = this->_elemente[i];
        if(old_nod != nullptr){
            PNod new_nod  = new Nod(new_element, -1, -1);

            new_nod->_cheie = old_nod->_cheie;
            new_nod->_valori = old_nod->_valori;
            new_nod->_stanga = old_nod->_stanga;
            new_nod->_dreapta = old_nod->_dreapta;

            new_elemente[i] = new_nod;
            delete old_nod;
        } else{
            new_elemente[i] = nullptr;
        }
    }

    for(int i = this->_capacitate; i < 2 * this->_capacitate + 1; i++){
        new_elemente[i] = nullptr;
    }

    this->_capacitate = this->_capacitate * 2 + 1;

    delete[] _elemente;
    this->_elemente = new_elemente;
}

MDO::MDO(Relatie r) {
    /* de adaugat */

    this->_relatie = r;
    _index_radacina = 1;

    this->_capacitate = 4;
    this->_dimensiune = 0;

    this->_elemente = new PNod [this->_capacitate];
    for(int i = 0; i < this->_capacitate; i++){
        this->_elemente[i] = nullptr;
    }
}


void MDO::adauga(TCheie c, TValoare v) {
    /* de adaugat */

    TElem new_element;
    new_element.first = c;
    new_element.second = v;
    this->_dimensiune++;

    PNod curent = this->radacina();
    int index = 1;
    while (true){
        if(curent == nullptr){
            PNod new_nod = new Nod(new_element, index * 2, index * 2 + 1);
            if(index * 2 + 1 >= this->_capacitate){
                redim();
            }
            this->_elemente[index] = new_nod;
            return;
        }
        if(curent->_cheie == c){
            curent->_valori.push_back(v);
            return;
        }
        if(_relatie(c, curent->_cheie)){
            //index = index * 2;
            index = curent->stanga();
        }
        else{
            //index = index * 2 + 1;
            index = curent->dreapta();
        }
        curent = this->_elemente[index];
    }

}

vector<TValoare> MDO::cauta(TCheie c) const {
    /* de adaugat */
    //return vector<TValoare>  ();

    PNod curent = this->radacina();
    int index = 1;
    while (true){
        if(curent == nullptr){
            return {};
        }
        if(curent->_cheie == c){
            return curent->_valori;
        }
        if(_relatie(c, curent->_cheie)){
            //index = index * 2;
            index = curent->stanga();
        }
        else{
            //index = index * 2 + 1;
            index = curent->dreapta();
        }
        curent = this->_elemente[index];
    }
}

PNod MDO::stergeMin(int index, int index_parinte){
    PNod curent_nod = this->_elemente[index];
    while (this->_elemente[curent_nod->stanga()] != nullptr){
        index_parinte = index;
        index = curent_nod->stanga();
        curent_nod = this->_elemente[curent_nod->stanga()];
    }
    stergeNod(index, index_parinte);
    return curent_nod;
}

void MDO::stergeNod(int index, int index_parinte) {
    PNod curent_nod = this->_elemente[index];
    PNod stanga_nod = this->_elemente[curent_nod->stanga()];
    PNod dreapta_nod = this->_elemente[curent_nod->dreapta()];

    if(stanga_nod == nullptr && dreapta_nod == nullptr){
        delete curent_nod;
        this->_elemente[index] = nullptr;
        return;
    }

    if (stanga_nod == nullptr) {
        if(index_parinte == -1){
            _index_radacina = curent_nod->dreapta();
            return;
        }
        PNod parinte_nod = this->_elemente[index_parinte];
        if(parinte_nod->dreapta() == index){
            parinte_nod->_dreapta = curent_nod->dreapta();
        }
        else {
            parinte_nod->_stanga = curent_nod->dreapta();
        }
        return;
    }

    if(dreapta_nod == nullptr){
        if(index_parinte == -1){
            _index_radacina = curent_nod->stanga();
            return;
        }
        PNod parinte_nod = this->_elemente[index_parinte];
        if(parinte_nod->dreapta() == index){
            parinte_nod->_dreapta = curent_nod->stanga();
        }
        else {
            parinte_nod->_stanga = curent_nod->stanga();
        }
        return;
    }

    PNod min_nod = stergeMin(curent_nod->dreapta(), index);

    min_nod->_stanga = curent_nod->stanga();
    min_nod->_dreapta = curent_nod->dreapta();
}

bool MDO::sterge(TCheie c, TValoare v) {
    /* de adaugat */
    //return false;
    PNod curent = this->radacina();
    int index_parinte = -1;
    int index = 1;
    while (true){
        if(curent == nullptr) {
            return false;
        }
        if(curent->_cheie == c){
            auto iterator = find_if(curent->_valori.begin(), curent->_valori.end(),
                                    [&](const TValoare crt_val){
                                        return crt_val == v;
            });
            if(iterator != curent->_valori.end()){
                curent->_valori.erase(iterator);
                if(curent->_valori.empty()){
                    this->stergeNod(index, index_parinte);
                }
                this->_dimensiune--;
                return true;
            }
            return false;
        }
        index_parinte = index;
        if(_relatie(c, curent->_cheie)){
            //index = index * 2;
            index = curent->stanga();
        }
        else{
            //index = index * 2 + 1;
            index = curent->dreapta();
        }
        curent = this->_elemente[index];
    }
}

int MDO::dim() const {
    /* de adaugat */
    //return 0;

    return this->_dimensiune;
}

bool MDO::vid() const {
    /* de adaugat */
    //return true;

    if(this->_dimensiune == 0){
        return true;
    }
    return false;
}

IteratorMDO MDO::iterator() const {
    return IteratorMDO(*this);
}

MDO::~MDO() {
    /* de adaugat */
    /*
    stack<PNod> de_sters;
    if(this->radacina() != nullptr){
        de_sters.push(this->radacina());
    }

    while (!de_sters.empty()){
        PNod curent = de_sters.top();
        de_sters.pop();

        int dr = curent->_dreapta;
        if(this->_elemente[dr] != nullptr){
            de_sters.push(this->_elemente[dr]);
        }

        int st = curent->_dreapta;
        if(this->_elemente[st] != nullptr){
            de_sters.push(this->_elemente[st]);
        }

        delete curent;
    }
    */
    for(int i = 0; i < this->_capacitate; i++){
        if(this->_elemente[i] != nullptr){
            delete this->_elemente[i];
        }
    }

    delete[] _elemente;
}
