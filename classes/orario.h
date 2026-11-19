#include <iostream>

/**
 * Dichiarazione di una classe orario che rappresenta
 * l'ora del giorno usando i secondi trascorsi da mezzanotte,
 * max secondi 86399, bastano 2 byte e quindi si potrebbe usare
 * short int.
 * 
 * Nelle classi ce una distinzione netta tra public e private.
 * 
 * Posso fare la dichiarazione inline delle funzioni
 * 
 * Si ha anche la dichiarazione del costruttore, si dichiara con 
 * il medesimo nome della classe e si mettono i parametri se necessario
 */

class orario {
    private:
        int sec;
    
    public:
        // orario();
        // orario(int hours);
        // orario(int hours, int minutes);
        // orario(int hours, int minutes, int seconds);
        explicit orario(int o=0, int m=0, int s=0);
        int Ore() const; //{ return sec/3600; };
        int Minuti() const; // { return (sec / 60) % 60; }
        int Secondi() const; // { return sec % 60; }
        int Secondi(int) const; //example of overloading

        orario UnOraPiuTardi() const;
        void AvanzaUnOra();

        static void stampa(const orario&);
        static orario OraDiPranzo();

        orario operator+(const orario& o) const;
        orario operator-(const orario& o) const;
        bool operator==(const orario& o) const;
};

std::ostream& operator<<(std::ostream& out, const orario& o);

/**
Possiamo definire anche l'operatore relativo alla classe orario
pero si ha il problema che si inverte l'ordine del cout
inolte definendolo per la classe orario otteniamo che
possiamo accedere ai suoi membri privati


Nota bene l'overloading dell'operatore << si usa ostream,
classe dell'oggetto std::cout, nella quale viene passato
dove stampare le cose e l'oggetto da stampare.
*/