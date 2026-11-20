#include <iostream>
#include "orario.h"


/**
 * N.B. Ho aggiunto const dopo la lezione dei constanti, 
 * in quanto le funzioni non modificano lo stato dell'oggetto, 
 * quindi è corretto dichiararle come const.
 */


/**
 * NB: Ho tolto i valori di default, basta mettergli nel
 * header file
 */
Orario::Orario(int o, int m, int s){
    if(o < 0 || o > 23 || m<0 || m>59 || s<0 || s>59){
        sec = 0;
    } else {
        sec = o*3600 + m*60 + s;
    }
}

int Orario::Ore() const{
    return sec/3600;
}

int Orario::Minuti() const{
    return (sec / 60) % 60;
}

int Orario::Secondi() const{
    return this->sec % 60; //il this è inutile qua dato che è implicito
}

int Orario::Secondi(int num) const{
    return sec + num;
}

// dichiarazione esplicita della classe, illegale

//int orario::Secondi(orario* this){
//    return (*this).sec % 60;
//}

Orario Orario::UnOraPiuTardi() const {
    Orario aux;
    aux.sec = (sec + 3600) % 86400;
    return aux;
}

void Orario::AvanzaUnOra() {
    sec = (sec + 3600) %86400;
}

void Orario::stampa(const Orario& orario){
    std::cout << "Ora: " <<  orario.Ore() 
    << ", Minuti: " << orario.Minuti()
    << ", Secondi: " << orario.Secondi() << "\n";
}


/**
Metodo che ritorna l'ora di pranzo ed e un metodo statico
*/
Orario Orario::OraDiPranzo(){
    return Orario(13, 15);
}

/**
Definizione operazione somma con overloading del operator +
*/

Orario Orario::operator+(const Orario& o) const {
    Orario aux;
    aux.sec = (sec + o.sec) % 86400;
    return aux;
}

Orario Orario::operator-(const Orario& o) const{
    Orario aux;
    aux.sec = (sec - o.sec) % 86400;
    if(aux.sec < 0) {
        aux.sec = 0;
    } 
    return aux;
}

bool Orario::operator==(const Orario& o) const{
    return sec == o.sec;
}

std::ostream& operator<<(std::ostream& out, const Orario& o){
    return out << o.Ore() << ":" << o.Minuti() << ":" << o.Secondi();
}