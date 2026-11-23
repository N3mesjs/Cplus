#include <iostream>
using namespace std;

class C {
public:
    C() { cout << "C0 "; }
    C(const C&) { cout << "Cc "; }
};


/**
Se omettiamo il costruttore di copia per D
il compilatore se ce una chiamata con una copia
ne genera uno lui del tipo:
// Generato automaticamente dal compilatore dentro class D:
D(const D& sorgente) : c(sorgente.c) {}

va ad assegnare alle varie varibili della classe quelle
della classe passata come parametro
*/
class D {
public:
    C c;
    D() { cout << "D0 "; }
    //D(const D&) { cout << "D1"; }
};

int main() {
    D x;
    cout << endl;   // Stampa: C0 D0

    D y(x);
    cout << endl;   // Stampa: Cc

    return 0;
}