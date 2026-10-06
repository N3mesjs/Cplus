#include <iostream>
#include "orario.h"


orario::orario(int o, int m, int s){
    if(o < 0 || o > 23 || m<0 || m>59 || s<0 || s>59){
        sec = 0;
    } else {
        sec = o*3600 + m*60 + s;
    }
}

orario::orario(int o, int m){
    if(o < 0 || o > 23 || m<0 || m>59){
        sec = 0;
    } else {
        sec = o*3600 + m*60;
    }
}

orario::orario(int o){
    if(o < 0 || o > 23){
        sec = 0;
    } else {
        sec = o*3600;
    }
}

orario::orario(){
    sec = 0;
}

int orario::Ore(){
    return sec/3600;
}

int orario::Minuti(){
    return (sec / 60) % 60;
}

int orario::Secondi(){
    return this->sec % 60; //il this è inutile qua dato che è implicito
}

int orario::Secondi(int num){
    return sec + num;
}

// dichiarazione esplicita della classe, illegale

//int orario::Secondi(orario* this){
//    return (*this).sec % 60;
//}