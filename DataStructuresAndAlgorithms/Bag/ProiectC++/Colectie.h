#ifndef BAG_COLECTIE_H
#define BAG_COLECTIE_H

#define NULL_TELEM -1
typedef int TElem;

class Nod;

typedef Nod *PNod;

class Nod{

private:
    TElem e;
    int frecv;
    PNod urm, prec;

public:
    friend class Colectie;

    Nod(TElem e, PNod urm, PNod prec);
    TElem element();
    int frecventa();
    PNod urmator();
    PNod precedent();
};

class IteratorColectie;

class Colectie
{
    friend class IteratorColectie;

private:
    /* aici e reprezentarea */
    PNod prim, ultim;
public:
    //constructorul implicit
    Colectie();

    //adauga un element in colectie
    void adauga(TElem e);

    //sterge o aparitie a unui element din colectie
    //returneaza adevarat daca s-a putut sterge
    bool sterge(TElem e);

    //verifica daca un element se afla in colectie
    bool cauta(TElem elem) const;

    //returneaza numar de aparitii ale unui element in colectie
    int nrAparitii(TElem elem) const;


    //intoarce numarul de elemente din colectie;
    int dim() const;

    //verifica daca colectia e vida;
    bool vida() const;

    //returneaza un iterator pe colectie
    IteratorColectie iterator() const;

    // destructorul colectiei
    ~Colectie();

    // păstrează doar o apariție a tuturor elementelor din colecție

    // returnează numărul de elemente eliminate

    int transformaInMultime();

};

#endif //BAG_COLECTIE_H
