#include <iostream>
#include "orario.h"

int main(void){
    orario pomeriggio(14, 55, 30);

    std::cout << pomeriggio.Minuti();

    return 0;
}