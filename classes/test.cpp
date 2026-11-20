#include <iostream>
#include "orario.h"

int main(void){
    Orario pomeriggio(14, 55, 30);

    /**
     * Orario* mezzanotte = new Orario();
     * in questo modo ottengo che mezzanotte è 
     * un puntatore a un oggetto di tipo Orario,
     * e che non puo modificare l'oggetto a cui punta, 
     * quindi non posso fare secondi = 10, ma posso 
     * fare secondi() che è una funzione const.
     * Oppure usare funzioni const che danno 
     * una copia dell'oggetto con le modifiche.
     */
    const Orario* mezzanotte = new Orario();

    std::cout << pomeriggio.Minuti() << "\n";
    std::cout << pomeriggio.Ore() << "\n";
    std::cout << pomeriggio.Secondi() << "\n";

    std::cout << mezzanotte->Secondi() << "\n";

    Orario adesso = pomeriggio.UnOraPiuTardi();
    std::cout << adesso.Ore() << "\n";

    //Test for the static method to print all the info about our Orario object
    Orario::stampa(adesso);

    //Static method for the lunch time
    Orario pranzo = Orario::OraDiPranzo();
    Orario::stampa(pranzo);

    //Test operator + overloading
    Orario somma = adesso + pranzo;
    Orario::stampa(somma);
    return 0;
}