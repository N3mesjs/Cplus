#ifndef BOLLETTA_H
#define BOLLETTA_H

#include "telefonata.h"

class Bolletta {
    public:
        Bolletta();
        bool vuota() const;
        void aggiungiTelefonata(const Telefonata&);
        void togliTelefonata(const Telefonata&);
        Telefonata estraiUna();

    private:
        class Nodo {
            public:
                Nodo();
                Nodo(const Telefonata&, Nodo*);
                Telefonata info;
                Nodo* next;
        };
        Nodo* first;
};

#endif