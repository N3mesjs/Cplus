#include <iostream>
#include "orario.h"

int main(void){
    orario pomeriggio(14, 55, 30);

    orario* mezzanotte = new orario();

    std::cout << pomeriggio.Minuti() << "\n";
    std::cout << pomeriggio.Ore() << "\n";
    std::cout << pomeriggio.Secondi() << "\n";

    std::cout << mezzanotte->Secondi() << "\n";

    return 0;
}