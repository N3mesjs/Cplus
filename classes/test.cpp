#include <iostream>
#include "orario.h"

int main(void){
    orario pomeriggio(14, 55, 30);

    /**
     * Orario* mezzanotte = new orario();
     * in questo modo ottengo che mezzanotte è 
     * un puntatore a un oggetto di tipo orario,
     * e che non puo modificare l'oggetto a cui punta, 
     * quindi non posso fare secondi = 10, ma posso 
     * fare secondi() che è una funzione const.
     * Oppure usare funzioni const che danno 
     * una copia dell'oggetto con le modifiche.
     */
    const orario* mezzanotte = new orario();

    std::cout << pomeriggio.Minuti() << "\n";
    std::cout << pomeriggio.Ore() << "\n";
    std::cout << pomeriggio.Secondi() << "\n";

    std::cout << mezzanotte->Secondi() << "\n";

    return 0;
}