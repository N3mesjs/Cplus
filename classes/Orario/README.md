# Container Classes
Classi che contengono istanze di piu oggetti
Quindi classi con classi annidate.

vedi file [bolletta](bolletta.h)

# Pointers
## NULL initializzation
In C++ per inizializzare un puntatore a null abbiamo diverse metodologie:

```cpp
int* p = nullptr;       // consigliato, da C++11
int* p = NULL;          // compatibile con il vecchio stile C
int* p = 0;             // vecchio stile C++
int* p{};               // inizializzazione uniforme: valore nullo
int* p = {};             // equivalente
```
