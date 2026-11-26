#include "orario.h"
#include "telefonata.h"
#include <iostream>

// Constructor definition
Telefonata::Telefonata(Orario inizio, Orario fine, int numero) 
    : _numero(numero) 
{
    _inizio = inizio;
    _fine = fine;
}

// Getters definition
Orario Telefonata::Inizio() const { return _inizio; }
Orario Telefonata::Fine() const { return _fine; }
int Telefonata::Numero() const { return _numero; }

// Operators overloading
bool Telefonata::operator==(const Telefonata& t) const {
    return t._inizio == _inizio &&
           t._fine == _fine &&
           t._numero == _numero;
}

std::ostream& operator<<(std::ostream& os, const Telefonata& t){
    return os << "INIZIO: " << t.Inizio()
              << " FINE: " << t.Fine()
              << " NUMERO CHIAMATO: " << t.Numero();
}