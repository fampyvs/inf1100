/* Lag en funksjon i C som tar 2 helltall som argumenter og bytter verdiene mellom disse
heltallene. Funksjonen skal ikke returnere noe. Endringene på heltallene skal også være
synlig/gyldige på utsiden av funksjonen. */

#include <stdio.h>

void byttVerdi(int *verdi_1, int *verdi_2) {
    printf("Verdiene %d og %d skal bytte plass. \n", *verdi_1, *verdi_2);

// Må bruke pointers for å kunne bytte på veridene.
    int temp = *verdi_1; 
    *verdi_1 = *verdi_2;
    *verdi_2 = temp;
}

int main() {
    int verdi_1 = 4, verdi_2 = 12;
    byttVerdi(&verdi_1, &verdi_2);
    printf("Verdiene har nå bytter plass. %d og %d\n", verdi_1, verdi_2);
}

// Fikk hjelp fra KI for å finne feil og lære meg om pekere.