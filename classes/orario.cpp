#include <iostream>
#include "orario.h"


/**
 * N.B. Ho aggiunto const dopo la lezione dei constanti, 
 * in quanto le funzioni non modificano lo stato dell'oggetto, 
 * quindi è corretto dichiararle come const.
 */

orario::orario(int o=0, int m=0, int s=0){
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