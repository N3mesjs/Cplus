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
orario::orario(int o, int m, int s){
    if(o < 0 || o > 23 || m<0 || m>59 || s<0 || s>59){
        sec = 0;
    } else {
        sec = o*3600 + m*60 + s;
    }
}

int orario::Ore() const{
    return sec/3600;
}

int orario::Minuti() const{
    return (sec / 60) % 60;
}

int orario::Secondi() const{
    return this->sec % 60; //il this è inutile qua dato che è implicito
}

int orario::Secondi(int num) const{
    return sec + num;
}

// dichiarazione esplicita della classe, illegale

//int orario::Secondi(orario* this){
//    return (*this).sec % 60;
//}

orario orario::UnOraPiuTardi() const{
    orario aux;
    aux.sec = (sec + 3600) % 86400;
    return aux;
}

void orario::AvanzaUnOra() {
    sec = (sec + 3600) %86400;
}

void orario::stampa(const orario& orario){
    std::cout << "Ora: " <<  orario.Ore() 
    << ", Minuti: " << orario.Minuti()
    << ", Secondi: " << orario.Secondi() << "\n";
}