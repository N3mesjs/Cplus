#include "raz.h"
#include <iostream>

Raz::Raz(int num, int den) : _num(num), _den(den != 0 ? den : 1) {}

Raz Raz::inverso() const {
    return Raz(_den, _num);
}

Raz::operator double() const {
    return(1.0*_num) / (1.0*_den);
}

Raz Raz::operator+(const Raz& r) const {
    int num = (_num * r._den) + (r._num * _den);
    int den = _den * r._den;
    return Raz(num, den);
}

Raz Raz::operator*(const Raz& r) const {
    int num = _num * r._num;
    int den = _den * r._den;
    return Raz(num, den);
}

Raz& Raz::operator++() {
    return *this = *this + Raz(1);
}

Raz Raz::operator++(int){
    Raz aux(*this);
    *this = *this + Raz(1);
    return aux;
}

bool Raz::operator==(const Raz& r) const {
    return _num*r._den == r._num*_den;
}

std::ostream& operator<<(std::ostream& os, const Raz& r){
    return os << r.operator double();
    //static_cast<double>(r); stessa roba ma piu esplicito
}

Raz Raz::unTerzo() {
    return Raz(1,3);
}