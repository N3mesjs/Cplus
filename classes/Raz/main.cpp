#include "raz.h"
#include <iostream>


// main.cpp
int main() {
  Raz x(2,3), y(2), z, u(1,8), v(3,2), w(8,4);

  Raz(2,3)*y;
  y*Raz(2,3);

  std::cout << x+y+v*u << std::endl; // 2.85417
  std::cout << u.inverso() << std::endl; // 8
  std::cout << (y == w) << std::endl; // true
  std::cout << y++ << " " << ++w << std::endl; // 2 3
  std::cout << (++y + Raz::unTerzo()) << std::endl; // 4.33333
  std::cout << 2 + Raz(1,2) << std::endl; // 2.5
}