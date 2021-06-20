//
// Created by Hodosi on 5/28/2021.
//

#include "IteratorMDO.h"
#include "MDO.h"
#include "stack"

//Q(nr_elemente)
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

//Q(1)
void IteratorMDO::prim(){
    /* de adaugat */
    this->curent_chei = 0;
    this->curent_val = 0;
}

//Q(1)
void IteratorMDO::urmator(){
    /* de adaugat */
    curent_val++;
    if(_elemente_inordine[curent_chei].second.size() == curent_val){
        curent_chei++;
        curent_val = 0;
    }
}

//Q(1)
bool IteratorMDO::valid() const{
    /* de adaugat */
    if(curent_chei < _elemente_inordine.size()){
        return true;
    }
    return false;
}

//Q(1)
TElem IteratorMDO::element() const{
    /* de adaugat */
    //return pair <TCheie, TValoare>  (-1, -1);
    return { _elemente_inordine[curent_chei].first, _elemente_inordine[curent_chei].second[curent_val] };
}

/*
 * Caz defavorabil: O(k)
 * Caz favorabil: O(1)
 * Caz mediu: O(k)
 * Total: O(k)
 */

void IteratorMDO::revinoKPasi(int k){
    if(curent_chei >= _elemente_inordine.size()){
        throw exception();
    }
    if(k <= 0){
        throw exception();
    }
    int old_chei = curent_chei;
    int old_val = curent_val;

    while (k > 0){
        int nr_elemente_nod = _elemente_inordine[curent_chei].second.size();
        if(nr_elemente_nod <= k){
            k -= nr_elemente_nod;
            curent_chei--;
            if(curent_chei < 0){
                curent_chei = old_chei;
                curent_val = old_val;
                throw exception();
            }
            curent_val = _elemente_inordine[curent_chei].second.size() - 1;
        }
        else{
            curent_val -= k;
            k = 0;
        }
    }
}

/*
 *Subalgoritm revinoKPasi(mdo, it, k)
 * {
 * pre:
 *     mdo : MDO
 *     it : MDO.ITERATOR
 *     k: int
 * }
 * {
 * post:
 *     it : revenit k pasi daca se poate
 *     exceptie altfel
 * }
 *
 * daca curent_chei >= size(_elemente_inordine) atunci
        @arunca execeptie;
   sfarsit_daca

   daca k <= 0 atunci
        @arunca execeptie
   sfarsit_daca

   old_chei <- curent_chei;
   old_val <- curent_val;

   cat_timp k > 0 executa
        nr_elemente_nod = size(_elemente_inordine[curent_chei].second);
        daca nr_elemente_nod <= k atunci
            k <- k - nr_elemente_nod;
            curent_chei--;
            daca curent_chei < 0 atunci
                curent_chei <- old_chei;
                curent_val <- old_val;
                arunca execeptie;

            curent_val <- size(_elemente_inordine[curent_chei].second) - 1;
        alfel
            curent_val <- curent_val - k;
            k <- 0;
        sfarsit_daca
    sfarsit cat_timp
 */


