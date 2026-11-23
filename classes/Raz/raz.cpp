#include "raz.h"
#include <iostream>

Raz::Raz(int num, den) : _num(num), _den(den != 0 ? den : 1) {}

Raz::inverso() {
    return Raz(_den, _num);
}

Raz::operator double() const {
    return(1.0*_num, 1.0*_den);
}

Raz Raz::operator+(const Raz& r) const {
    num = (_num * r._den) + (r._num * _den);
    den = _den * r._den;
    return Raz(num, den);
}

Raz Raz::operator*(const Raz& r) const {
    num = _num * r._num;
    den = _den * r._den;
    return Raz(num, den);
}

Raz& operator++() {
    return *this++
}