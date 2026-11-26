#ifndef TELEFONATA_H
#define TELEFONATA_H

#include "orario.h"
#include <iostream>

class Telefonata {
    private:
        Orario _inizio, _fine;
        const int _numero;
    public:
        Telefonata(Orario, Orario, int);
        //getters
        Orario Inizio() const;
        Orario Fine() const;
        int Numero() const;
        bool operator==(const Telefonata&) const;
};

std::ostream& operator<<(std::ostream&, const Telefonata&);

#endif