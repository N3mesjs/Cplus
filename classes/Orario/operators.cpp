#include <iostream>
#include "orario.h"

int main(void){
    Orario adesso(14, 55, 25);
    Orario::stampa(adesso);

    Orario pranzo = Orario::OraDiPranzo();
    Orario::stampa(pranzo);
    Orario pranzo2 = Orario::OraDiPranzo();
    Orario::stampa(pranzo2);

    if(pranzo == pranzo2){
        std::cout << "Sono uguali" << "\n";
    }

    Orario sottr = adesso - pranzo;
    Orario::stampa(sottr);

    std::cout << sottr << "\n";
}