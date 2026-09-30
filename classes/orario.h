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
        orario(int o, int m, int s);
        int Ore(); //{ return sec/3600; };
        int Minuti(); // { return (sec / 60) % 60; }
        int Secondi(); // { return sec % 60; }
        int Secondi(int num); //example of overloading
};