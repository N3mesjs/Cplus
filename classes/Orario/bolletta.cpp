#include "bolletta.h"
#include <iostream>

/**
Vediamo che usiamo sia 0 che null ptr per l'inizializzazione a NULL
Sono letteralmente la stessa cosa!
*/

// --- Node class implementation ---
Bolletta::Nodo::Nodo() : next(0) {}

Bolletta::Nodo::Nodo(const Telefonata& tel, Nodo* nodo) : info(tel), next(nodo) {}

// --- Bolletta main class implementation ---
Bolletta::Bolletta() : first(0) {}

bool Bolletta::vuota() const {
    return first == 0;
}

void Bolletta::aggiungiTelefonata(const Telefonata& t){
    first = new Nodo(t, first);
}

void Bolletta::togliTelefonata(const Telefonata& t) {
    Nodo *p = first, *prec = nullptr;

    while(p && !(p->info == t)){
        prec = p;
        p = p->next;
    }

    //ho trovato p ed esiste
    if(p) {
        if(prec == nullptr)
            first = p->next;
        else 
            prec->next = p->next;
        delete p;
    }
}

Telefonata Bolletta::estraiUna() {
    if(first != 0){
        Nodo *p = first;
        first = first->next;
        Telefonata aux = p->info;
        delete p;

        return aux;
    }
}