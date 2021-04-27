#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;

// Q(this->capacitate)
void MDO::redim(){
    TElem *new_elemente = new TElem [2 * this->capacitate];
    int *new_leg_urmator = new int [2 * this->capacitate];
    int *new_leg_precedent = new int [2 * this->capacitate];

    for(int i = 0; i < this->capacitate; i++){
        new_elemente[i] = this->elemente[i];
        new_leg_urmator[i] = this->leg_urmator[i];
        new_leg_precedent[i] = this->leg_precedent[i];
    }

    delete[] elemente;
    delete[] leg_urmator;
    delete[] leg_precedent;

    this->elemente = new_elemente;
    this->leg_urmator = new_leg_urmator;
    this->leg_precedent = new_leg_precedent;

    // lista spatiului liber
    for(int i = this->capacitate; i <= 2*this->capacitate - 1; i++){
        this->leg_precedent[i] = i - 1;
        this->leg_urmator[i] = i + 1;
    }

    this->leg_precedent[this->capacitate] = -1;
    this->leg_urmator[2*this->capacitate - 1] = -1;

    this->prim_liber = this->capacitate;

    this->capacitate = 2*this->capacitate;
}


// Q(this->capacitate)
MDO::MDO(Relatie r) {
    /* de adaugat */

    // relatiea
    this->rel = r;

    // vector dinamic
    this->capacitate = 1;
    this->dimensiune = 0;

    elemente = new TElem [this->capacitate];
    leg_urmator = new int [this->capacitate];
    leg_precedent = new int [this->capacitate];

    // lista
    this->prim = -1;
    this->ultim = -1;

    // lista spatiului liber
    for(int i = 0; i <= this->capacitate - 1; i++){
        this->leg_precedent[i] = i - 1;
        this->leg_urmator[i] = i + 1;
    }

    this->leg_urmator[this->capacitate - 1] = -1;

    this->prim_liber = 0;
}

// Q(1)
int MDO::aloca() {
    int i = this->prim_liber;
    this->prim_liber = this->leg_urmator[prim_liber];

    this->dimensiune++;
    return i;
}

// Q(1)
void MDO::dealoca(int i) {
    this->leg_precedent[i] = -1;
    this->leg_urmator[i] = this->prim_liber;

    this->prim_liber = i;

    this->dimensiune--;
}

// Q(1) - amortizat
int MDO::creeazaNod(TElem element) {
    if(this->prim_liber == -1){
        redim();
    }

    int i = aloca();
    this->elemente[i] = element;
    this->leg_urmator[i] = -1;
    this->leg_precedent[i] = -1;

    return i;
}

// Q(n)
void MDO::adauga(TCheie c, TValoare v) {
    /* de adaugat */

    vector<TValoare> valori = this->cauta(c);
    for(auto val : valori){
        if(val == v) {
            return;
        }
    }

    TElem new_element;
    new_element.first = c;
    new_element.second = v;

    int i = creeazaNod(new_element);

    // daca nu avem elemente in lista
    if(this->prim == -1){
        this->prim = i;
        this->ultim = i;
        return;
    }

    // daca putem adauga la inceputul listei
    if(rel(c, elemente[this->prim].first)){
        leg_precedent[this->prim] = i;

        leg_precedent[i] = -1;
        leg_urmator[i] = this->prim;

        this->prim = i;
        return;
    }

    // daca putem adauga la sfarsitul listei
    if(rel(elemente[this->ultim].first, c)){
        leg_urmator[this->ultim] = i;

        leg_precedent[i] = this->ultim;
        leg_urmator[i] = -1;

        this->ultim = i;
        return;
    }

    // daca trebuie sa adaugam intre primul si ultimul element al listei
    // *cautam locul inserarii ...
    int curent = leg_urmator[this->prim];
    while (!rel(c, elemente[curent].first)){
        curent = leg_urmator[curent];
    }

    // *inseram in lista inainte de curent
    int precedentul_curentului = this->leg_precedent[curent];
    this->leg_urmator[precedentul_curentului] = i;
    this->leg_precedent[curent] = i;

    this->leg_precedent[i] = precedentul_curentului;
    this->leg_urmator[i]= curent;

    return;
}

// Q(n)
vector<TValoare> MDO::cauta(TCheie c) const {
    /* de adaugat */
    //return vector<TValoare>  ();

    vector<TValoare> valori;
    int curent = this->prim;
    while(curent != -1){
        if(this->elemente[curent].first == c){
            valori.push_back(this->elemente[curent].second);
        }
        curent = this->leg_urmator[curent];
    }

    return valori;

}

// O(n)
bool MDO::sterge(TCheie c, TValoare v) {
    /* de adaugat */
    // return false;

    // daca nu avem elemente in lista
    if(this->prim == -1){
        return false;
    }

    // daca stergem primul element al listei care ii defapt ultimul ramas in lista
    if(elemente[this->prim].first == c && elemente[this->prim].second == v && dimensiune == 1){
        int cpy_prim = this->prim;
        this->prim = -1;
        this->ultim = -1;

        dealoca(cpy_prim);
        return true;
    }

    // daca stergem primul element al listei
    if(elemente[this->prim].first == c && elemente[this->prim].second == v){
        int cpy_prim = this->prim;
        this->prim = this->leg_urmator[this->prim];
        this->leg_precedent[this->prim] = -1;

        dealoca(cpy_prim);
        return true;
    }

    // daca stergem ultimul element al listei
    if(elemente[this->ultim].first == c && elemente[this->ultim].second == v){
        int cpy_ultim = this->ultim;
        this->ultim = this->leg_precedent[this->ultim];
        this->leg_urmator[this->ultim] = -1;

        dealoca(cpy_ultim);
        return true;
    }

    // daca trebuie sa stergem intre primul si ultimul element al listei
    // *cautam locul inserarii ...
    int curent = leg_urmator[this->prim];
    while (curent != -1){
        if((elemente[curent].first == c && elemente[curent].second == v)){
            int precedentul_curentului = this->leg_precedent[curent];
            int urmatorul_curentului = this->leg_urmator[curent];

            this->leg_urmator[precedentul_curentului] = urmatorul_curentului;
            this->leg_precedent[urmatorul_curentului] = precedentul_curentului;

            dealoca(curent);
            return true;
        }
        curent = leg_urmator[curent];
    }

    return false;
}

// Q(1)
int MDO::dim() const {
    /* de adaugat */
    //return 0;

    return this->dimensiune;
}

// Q(1)
bool MDO::vid() const {
    /* de adaugat */
    //return true;

    if(this->dimensiune == 0){
        return true;
    }
    return false;
}

//Q(1)
IteratorMDO MDO::iterator() const {
    return IteratorMDO(*this);
}

//Q(this->capacitate)
MDO::~MDO() {
    /* de adaugat */

    delete[] this->elemente;
    delete[] this->leg_urmator;
    delete[] this->leg_precedent;
}

/*
 * n - numarul perechi self dictionar
 * m - numarul de perechi new dictionar
 *
 * Caz defavorabil: Q(m*n)
 * Caz favorabil: Q(m*n)
 * Caz mediu: Q(m*n)
 * Total: Q(m*n)
 */

//functionalitate noua
int MDO::adaugaInexistente(MDO& mdo){
    int nr_inexistente = 0;
    bool exista;

    int curent = mdo.prim;
    while(curent != -1){
        auto elem = mdo.elemente[curent];
        exista = false;
        vector<TValoare> valori = this->cauta(elem.first);
        for(auto val : valori){
            if(val == elem.second) {
                exista = true;
                break;
            }
        }
        if(exista == false){
            nr_inexistente++;
            this->adauga(elem.first, elem.second);
        }
        curent = mdo.leg_urmator[curent];
    }
    return nr_inexistente;
}

/*
 * pseudocod
 * Subalgoritm adaugaInexistente(MDO, new_mdo, nr_inexistente)
 * {
 *  pre: MDO: LDI
 *       new_mdo: LDI
 *  }
 *  {
 *  post: nr_inexistente - numarul de perechi adaugate
 *        MDO -
 *  }
 *
 *  nr_inexistente <- 0
 *
 *  curent <- new_mdo.prim
 *  CatTimp curent != -1 executa
 *      elem <- mdo.elemente[curent]
 *      exista <- false
 *      cauta(MDO, elem.first, valori)
 *      Pentru i = 0, size(valori) executa
 *          Daca valori[i] = elem.second atunci
 *              exista <- true
 *              break
 *          SfDaca
 *      SfPentru
 *      Daca exista = false atunci
 *          nr_inexistente += 1
 *          adauga(MDO, elem.first, elem.second)
 *      SfDaca
 *      curent = new_mdo.leg_urmator[curent];
 * SfCatTimp
 */

