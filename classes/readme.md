# Classes in C++

## Definition vs Implementation
Si ha una separazione netta tra dichiarazione e
implementazione delle classi.

Nel file .h o header file si ha la dichiarazione della
classe e delle funzioni
ed e una buona usanza mettere in un file .cpp con nome
uguale per correttezza
le sue implementazioni delle funzioni, sara poi il linker
(traduttore a linguaggio macchina) a trovare il file delle relative implementazioni.

Quindi quando importiamo una classe in un file basta fare l'include del file
header e quindi relativo alla definizione

## R-Values vs L-Values
i valori l-values sono valori che hanno un indirizzo di
memoria in cui sono salvati e a cui ci possiamo 
accedere in qualiasi momento.

Gli r-values invece sono valori temporanei che non vengono
salvati in memoria. Sono ad esempio risultati di operazioni:

```cpp
int x = 2;
int y = x+3;
```

x e' un l-value. x+3 dara 5, ma il suo risultato e' un
r-value

### r-values nelle classi
Possiamo avere una implementazione in cui
il costruttore viene considerato `oggetto temporaneo anonino`

```cpp
orario t;
t = orario(12,33,25)
```

## new Syntax
Possiamo usare l'operatore new per la
creazione degli oggetti per una classe
questo consiste nel usare new che crea
un oggetto pero nel heap, quindi una parte
di memoria libera utilizzabile dal programmatore
per allocare in modo dinamico la memoria.

Lo `stack` differisce dato che e una parte di memoria
gestita dal calcolatore per le variabili locali.

Quando usiamo il `new` ci viene restituito un indirizzo
di memoria all'oggetto nella heap, dovremmo quindi usare
un puntatore.

```cpp
orario* ptr = new orario();
```

## Costruttore implicito.
In C++ possiamo dichiarare una variabile e chiamare
il costruttore della funzione implicitamente, ecco un es:
```cpp
//vedi orario.h se serve
orario t;
t = 2
```

chiamera cosi implicitamente `orario(2)`.
Possiamo pero omettere questa scrittura mettendo nel
nostro file header la keyword `explicit`.

## 1. Panoramica Concettuale del `const`

In C++, la parola chiave `const` applicata alla programmazione ad oggetti stabilisce un **contratto formale di sola lettura**. 

È fondamentale distinguere la posizione sintattica di `const`:

| Sintassi | Significato | Oggetto chiamante (`*this`) | Valore di ritorno |
| :--- | :--- | :--- | :--- |
| `int f();` | Metodo ordinario | **Modificabile** | Modificabile per copia |
| `const int f();` | Ritorno costante | **Modificabile** | Costante (poco comune su tipi primitivi) |
| `int f() const;` | **Metodo costante** | **NON modificabile (Read-Only)** | Modificabile per copia |
| `const int& f() const;` | Metodo costante + ref const | **NON modificabile (Read-Only)** | Costante per riferimento |

> **Regola d'oro del `const` in coda:** Un `const` posto dopo la lista dei parametri di un metodo garantisce che l'invocazione di tale metodo **non produrrà effetti collaterali (*side-effects*)** sullo stato interno dell'oggetto invocante.

---

## 2. Metodi con Side-Effect vs Metodi Funzionali

Prendiamo come esempio la classe per la gestione dell'orario:

```cpp
class orario {
private:
    int sec; // Secondi trascorsi dalla mezzanotte [0, 86399]

public:
    orario(int s = 0) : sec(s % 86400) {}

    // Metodo FUNZIONALE (senza side-effect sull'oggetto invocante)
    orario UnOraPiuTardi() const {
        orario aux;
        aux.sec = (sec + 3600) % 86400;
        return aux; // Ritorna un nuovo oggetto, l'originale non cambia!
    }

    // Metodo PROCEDURALE / MUTATORE (con side-effect)
    void AvanzaUnOra() {
        sec = (sec + 3600) % 86400; // Modifica lo stato interno di *this!
    }

    int Ore() const {
        return sec / 3600;
    }
};
```

### Confronto del comportamento a runtime:

```cpp
orario mezzanotte;                    // sec = 0
std::cout << mezzanotte.Ore();        // Stampa: 0

orario adesso = mezzanotte.UnOraPiuTardi();
std::cout << adesso.Ore();            // Stampa: 1
std::cout << mezzanotte.Ore();        // Stampa: 0 (mezzanotte è rimasto intatto!)

mezzanotte.AvanzaUnOra();             // Mutazione sul posto
std::cout << mezzanotte.Ore();        // Stampa: 1 (mezzanotte è cambiato!)
```

---

## 3. Anatomia di un Metodo Costante

Quando un metodo è dichiarato con `const` in coda:

```cpp
void StampaSecondi() const {
    std::cout << sec << std::endl;
}
```

### Cosa controlla il compilatore?
1. **Nessuna scrittura sui campi dati:** Non è permesso scrivere `sec = ...` o alterare qualsiasi variabile membro (a meno che non sia marcata `mutable`).
2. **Nessuna chiamata a metodi non-costanti:** All'interno di un metodo `const`, è possibile invocare solo altri metodi dichiarati a loro volta `const`.
3. **Nessun ritorno di riferimenti non costanti a membri interni:** Non puoi restituire un puntatore (`T*`) o un riferimento (`T&`) non costante a un campo interno, altrimenti violeresti l'incapsulamento della costanza.

### Dietro le quinte: il puntatore `this`

In ogni metodo di classe, il compilatore passa implicitamente un puntatore all'istanza chiamante chiamato `this`:

* In un metodo **normale** di una classe `C`:
  $$\text{tipo di } \texttt{this} \implies \mathbf{C* \text{ const}}$$
  *(puntatore costante a dati modificabili)*

* In un metodo **costante** di una classe `C`:
  $$\text{tipo di } \texttt{this} \implies \mathbf{const\ C* \text{ const}}$$
  *(puntatore costante a dati COSTANTI)*

Poiché i campi dati vengono dereferenziati tramite `this->campo`, l'accesso diventa automaticamente di sola lettura.

---

## 4. Oggetti Costanti (`const Object`)

Un'istanza di classe può essere istanziata come `const`:

```cpp
const orario LE_TRE(15 * 3600); // Oggetto "congelato" dopo la nascita
```

### La regola fondamentale per oggetti `const`:
> Su un'istanza dichiarata `const` è possibile invocare **esclusivamente**:
> 1. I **Costruttori** (durante la fase di creazione).
> 2. Il **Distruttore** (al termine del ciclo di vita).
> 3. I **Metodi dichiarati esplicitamente `const`**.

### Esempio di compilazione ed errore tipico:

```cpp
const orario LE_TRE(15 * 3600);

LE_TRE.StampaSecondi(); // OK: StampaSecondi() è const

orario t = LE_TRE.UnOraPiuTardi(); 
// Se UnOraPiuTardi() NON ha 'const' nella dichiarazione:
// -> ERRORE DI COMPILAZIONE!
// Il compilatore rifiuta la chiamata anche se il metodo non modifica i campi.
```

#### Perché fallisce se manca `const`?
Il compilatore ragiona solo in base alla **firma** del metodo (*signature check*), non ispeziona il corpo della funzione per decidere se consentire la chiamata. Se la firma non contiene `const`, il metodo viene classificato come potenzialmente mutatore e rigettato su istanze costanti.

---

## 5. L'Eccezione: I Costruttori

I costruttori **non possono essere dichiarati `const`**:

```cpp
class orario {
    // ERRORE: sintassi non permessa
    orario() const; 
};
```

* **Motivazione logica:** Il costruttore ha proprio il compito primario di inizializzare e scrivere i campi dati dell'oggetto. Se fosse `const`, non potrebbe configurare lo stato iniziale.
* Nonostante non siano `const`, i costruttori sono le uniche funzioni membro abilitate a operare su un oggetto che diventerà `const` subito dopo il completamento dell'inizializzazione.

---

## 6. Best Practices & "Const Correctness"

1. **Principio di minimo privilegio:** Se un metodo si limita a leggere campi, calcolare valori derivati o stampare, **deve sempre** essere marcato `const`.
2. **Passaggio per riferimento costante:** L'uso corretto di `const` nei metodi è fondamentale quando si passano oggetti per riferimento costante nelle funzioni:
   ```cpp
   void elabora(const orario& o) {
       // Se o.Ore() non fosse 'const', questa riga NON compilerebbe!
       std::cout << "Ora: " << o.Ore() << std::endl; 
   }
   ```
3. **Overloading basato su const:** È possibile sovraccaricare un metodo in base alla costanza:
   ```cpp
   int& operatore[](size_t i);       // Usato da oggetti non-const (lettura/scrittura)
   const int& operatore[](size_t i) const; // Usato da oggetti const (sola lettura)
   ```