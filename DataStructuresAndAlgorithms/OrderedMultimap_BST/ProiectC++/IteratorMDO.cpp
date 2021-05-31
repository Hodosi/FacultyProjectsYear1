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

    if(dict._index_radacina == -1){
        return;
    }

    //Nod curent_nod = dict.radacina();

    int curent = dict._index_radacina;

    stack<pair<int, bool>> stiva; //index, prelucrat
    stiva.push(make_pair(curent, false));

    while (!stiva.empty()) {
        auto crt = stiva.top();
        int crt_index = crt.first;

        if (crt.second == false) {
            crt.second = true;
            stiva.pop();
            stiva.push(crt);

            int index_stanga = dict._stanga[crt_index];

            while (index_stanga != -1) {
                crt_index = index_stanga;
                stiva.push(make_pair(crt_index, true));
                index_stanga = dict._stanga[index_stanga];
            }
        }

        this->_elemente_inordine.push_back(dict._elemente[crt_index]);
        stiva.pop();

        int index_dreapta = dict._dreapta[crt_index];

        if (index_dreapta != -1) {
            stiva.push(make_pair(index_dreapta, false));
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


