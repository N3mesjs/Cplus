#include <iostream>
#include "orario.h"

int main(void){
    orario adesso(14, 55, 25);
    orario::stampa(adesso);

    orario pranzo = orario::OraDiPranzo();
    orario::stampa(pranzo);
    orario pranzo2 = orario::OraDiPranzo();
    orario::stampa(pranzo2);

    if(pranzo == pranzo2){
        std::cout << "Sono uguali" << "\n";
    }

    orario sottr = adesso - pranzo;
    orario::stampa(sottr);

    std::cout << sottr << "\n";
}