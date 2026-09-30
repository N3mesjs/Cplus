# Classes in C++

## Definition vs Implementation
Si ha una separazione netta tra dichiarazione e implementazione delle classi.

Nel file .h o header file si ha la dichiarazione della classe e delle funzioni
ed e una buona usanza mettere in un file .cpp con nome uguale per correttezza
le sue implementazioni delle funzioni, sara poi il linker(traduttore a linguaggio
macchina) a trovare il file delle relative implementazioni.

Quindi quando importiamo una classe in un file basta fare l'include del file
header e quindi relativo alla definizione