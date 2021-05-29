//
// Created by Hodosi on 5/28/2021.
//

#include "IteratorMDO.h"
#include "MDO.h"
#include "stack"
IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
    /* de adaugat */
    this->curent_chei = 0;
    this->curent_val = 0;

    PNod curent_nod = dict.radacina();
    if(curent_nod == nullptr){
        return;
    }

    vector<bool> deja_adaugat(this->dict._capacitate, false);
    deja_adaugat[this->dict._index_radacina] = true;

    stack<PNod> stiva;
    stiva.push(curent_nod);

    while (!stiva.empty()) {
        PNod crt = stiva.top();

        if (!deja_adaugat[crt->stanga()]) {
            deja_adaugat[crt->stanga()] = true;

            PNod stanga_nod = this->dict._elemente[crt->stanga()];

            while (stanga_nod != nullptr) {
                crt = stanga_nod;
                stiva.push(crt);
                stanga_nod = this->dict._elemente[crt->stanga()];
            }
        }

        this->_elemente_inordine.push_back({crt->cheie(), crt->valori()});
        stiva.pop();

        PNod dreapta_nod = this->dict._elemente[crt->dreapta()];

        if (dreapta_nod != nullptr) {
            stiva.push(dreapta_nod);
        }
    }
}

void IteratorMDO::prim(){
    /* de adaugat */
    this->curent_chei = 0;
    this->curent_val = 0;
}

void IteratorMDO::urmator(){
    /* de adaugat */
    curent_val++;
    if(_elemente_inordine[curent_chei].second.size() == curent_val){
        curent_chei++;
        curent_val = 0;
    }
}

bool IteratorMDO::valid() const{
    /* de adaugat */
    if(curent_chei < _elemente_inordine.size()){
        return true;
    }
    return false;
}

TElem IteratorMDO::element() const{
    /* de adaugat */
    //return pair <TCheie, TValoare>  (-1, -1);
    return { _elemente_inordine[curent_chei].first, _elemente_inordine[curent_chei].second[curent_val] };
}


