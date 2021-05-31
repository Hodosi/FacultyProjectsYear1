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
/*
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
*/

Nod MDO::radacina() const {
    return this->_elemente[_index_radacina];
}


void MDO::redim() {

    Nod *new_elemente = new Nod [2 * this->_capacitate];
    int *new_stanga = new int [2 * this->_capacitate];
    int *new_dreapta = new int [2 * this->_capacitate];

    for(int i = 0; i < this->_capacitate; i++){
        new_elemente[i] = this->_elemente[i];
        new_stanga[i] = this->_stanga[i];
        new_dreapta[i] = this->_dreapta[i];
    }

    delete[] _elemente;
    delete[] _stanga;
    delete[] _dreapta;

    this->_elemente = new_elemente;
    this->_stanga = new_stanga;
    this->_dreapta = new_dreapta;

    for(int i = this->_capacitate; i < 2 * this->_capacitate; i++){
        this->_stanga[i] = i - 1;
        this->_dreapta[i] = i + 1;
    }

    this->_stanga[this->_capacitate] = -1;
    this->_dreapta[2*this->_capacitate - 1] = -1;

    this->prim_liber = this->_capacitate;
    this->_capacitate = this->_capacitate * 2;
}

MDO::MDO(Relatie r) {
    /* de adaugat */

    this->_relatie = r;

    this->_capacitate = 1;
    this->_dimensiune = 0;

    this->_elemente = new Nod [this->_capacitate];
    this->_stanga = new int [this->_capacitate];
    this->_dreapta = new int [this->_capacitate];

    _index_radacina = -1;

    for(int i = this->_capacitate; i < this->_capacitate; i++){
        this->_stanga[i] = i - 1;
        this->_dreapta[i] = i + 1;
    }

    this->_dreapta[this->_capacitate - 1] = -1;
    this->prim_liber = 0;
}

int MDO::aloca() {
    int i = this->prim_liber;
    this->prim_liber = this->_dreapta[prim_liber];

    this->_dimensiune++;
    return i;
}


void MDO::dealoca(int i) {
    this->_stanga[i] = -1;
    this->_dreapta[i] = this->prim_liber;

    this->prim_liber = i;

    this->_dimensiune--;
}

// Q(1) - amortizat
int MDO::creeazaNod(TElem elem) {
    if(this->prim_liber == -1){
        redim();
    }

    int i = aloca();
    vector<TValoare> valori;
    valori.push_back(elem.second);
    this->_elemente[i] = make_pair(elem.first, valori);
    this->_stanga[i] = -1;
    this->_dreapta[i] = -1;

    return i;
}

void MDO::adauga(TCheie c, TValoare v) {
    /* de adaugat */

    TElem new_element;
    new_element.first = c;
    new_element.second = v;

    if(this->_index_radacina == -1){
        int i = creeazaNod(new_element);
        this->_index_radacina = i;
        return;
    }

    Nod curent = this->radacina();
    Nod parent;
    int index = _index_radacina;
    int index_parent = -1;
    while (true){
        if(index == -1){
            int i = creeazaNod(new_element);
            if(_relatie(c, parent.first)){
                this->_stanga[index_parent] = i;
            }
            else {
                this->_dreapta[index_parent] = i;
            }
            return;
        }
        index_parent = index;

        if(curent.first == c){
            this->_elemente[index].second.push_back(v);
            this->_dimensiune++;
            return;
        }
        if(_relatie(c, curent.first)){
            index = this->_stanga[index];
        }
        else{
            index = this->_dreapta[index];
        }
        parent = curent;
        if(index != -1){
            curent = this->_elemente[index];
        }
    }

}

vector<TValoare> MDO::cauta(TCheie c) const {
    /* de adaugat */
    //return vector<TValoare>  ();

    if(_index_radacina == -1){
        return {};
    }
    Nod curent = this->radacina();
    int index = _index_radacina;
    while (true){
        if(index == -1){
            return {};
        }
        if(curent.first == c){
            return curent.second;
        }
        if(_relatie(c, curent.first)){
            index = this->_stanga[index];
        }
        else{
            index = this->_dreapta[index];
        }
        if(index != -1){
            curent = this->_elemente[index];
        }
    }
}


Nod MDO::stergeMin(int index, int index_parinte){
    int index_bunic = index_parinte;
    while (index != -1){
        index_bunic = index_parinte;
        index_parinte = index;
        index = this->_stanga[index];
    }
    Nod min_nod = this->_elemente[index_parinte];
    stergeNod(index_parinte, index_bunic);
    return min_nod;
}



void MDO::stergeNod(int index, int index_parinte) {
    Nod curent_nod = this->_elemente[index];
   // Nod stanga_nod = this->_elemente[this->_stanga[index]];
   // Nod dreapta_nod = this->_elemente[this->_dreapta[index]];

   int index_stanga = this->_stanga[index];
   int index_dreapta = this->_dreapta[index];

    if(index_stanga == -1 && index_dreapta == -1){
        dealoca(index);
        return;
    }

    if (index_stanga == -1) {
        if(index_parinte == -1){
            _index_radacina = this->_dreapta[index];
            dealoca(index);
            return;
        }
        if(_dreapta[index_parinte] == index){
            _dreapta[index_parinte] = _dreapta[index];
        }
        else {
            _stanga[index_parinte] = _stanga[index];
        }
        dealoca(index);
        return;
    }

    if(index_dreapta == -1){
        if(index_parinte == -1){
            _index_radacina = this->_stanga[index];
            dealoca(index);
            return;
        }
        if(_dreapta[index_parinte] == index){
            _dreapta[index_parinte] = _dreapta[index];
        }
        else {
            _stanga[index_parinte] = _stanga[index];
        }
        dealoca(index);
        return;
    }

    Nod min_nod = stergeMin(this->_dreapta[index], index);

    this->_elemente[index] = min_nod;
}


bool MDO::sterge(TCheie c, TValoare v) {
    /* de adaugat */
    //return false;
    if(_index_radacina == -1){
        return false;
    }
    Nod curent = this->radacina();
    int index_parinte = -1;
    int index = _index_radacina;
    while (true){
        if(index == -1) {
            return false;
        }
        if(curent.first == c){
            auto iterator = find_if(this->_elemente[index].second.begin(), this->_elemente[index].second.end(),
                                    [&](const TValoare crt_val){
                                        return crt_val == v;
            });
            if(iterator != this->_elemente[index].second.end()){
                this->_elemente[index].second.erase(iterator);
                if(this->_elemente[index].second.empty()){
                    this->stergeNod(index, index_parinte);
                    return true;
                }
                this->_dimensiune--;
                return true;
            }
            return false;
        }
        index_parinte = index;
        if(_relatie(c, curent.first)){
            index = this->_stanga[index];
        }
        else{
            index = this->_dreapta[index];
        }
        if(index != -1){
            curent = this->_elemente[index];
        }
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

    delete[] this->_elemente;
    delete[] this->_stanga;
    delete[] this->_dreapta;
}
