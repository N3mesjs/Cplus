#ifndef BOLLETTA_H
#define BOLLETTA_H

#include "telefonata.h"

class Bolletta {
    public:
        Bolletta();
        Bolletta(const Bolletta&);
        bool vuota() const;
        void aggiungiTelefonata(const Telefonata&);
        void togliTelefonata(const Telefonata&);
        Telefonata estraiUna();

        Bolletta& operator=(const Bolletta& y);

    private:
        class Nodo {
            public:
                Nodo();
                Nodo(const Telefonata&, Nodo*);
                Telefonata info;
                Nodo* next;
        };
        Nodo* first;

        static Nodo* copia(Nodo*);
        static void distruggi(Nodo*);
};

#endif