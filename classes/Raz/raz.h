#ifndef RAZ_H
#define RAZ_H

#include <iostream>

class Raz {
    private:
        int _num, _den; //den != 0
    public:
        Raz(int num = 0, den = 1);

        Raz inverso() const;
        /**
        Si può fare l'overloading di operatori di casting
        non prende parametri ma agisce direttamente sul this.
        se dichiaro una variabile double e faccio l'assegnazione
        di questa classe che lo implementa si ottiene 
        un casting esplicito.
        */
        operator double() const;
        Raz operator+(const Raz&) const;
        Raz operator*(const Raz&) const;
        Raz& operator++() const;
        Raz operator++(int) const; //dummy int
        bool operator==(const Raz&) const;
        static Raz unTerzo();
}

std::ostream& operator<<(std::ostream&, const Raz&);

#endif