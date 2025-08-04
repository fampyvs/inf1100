/* Lag en funksjon i C som beregner gjennomsnittet av en tabell(array) med heltall, hvor det minste
tallet og det største tallet er tatt bort. Tabellen(arrayet) er ikke sortert.
F.eks. [3,5,2,8,1] vil gi gjennomsnittet 3.333…. */

/*Finn minimums- og maksimumsverdien i arrayen.
Summer tallene, trekk fra min og max verdiene, gjør utregning */


#include <stdio.h>

// Programmet regner ut hele arrayet med tall, trekker fra min og max og deler på resterende antall tall i arrayet.
double gjennomSnitt(int *tall, int lengde) {

    int min = tall[0];
    int max = tall[0];
    int sum = 0;
    int i = 0;

// Her finner jeg min og max verdiene i arrayet og summerer alle tallen.
    for (i = 0; i < lengde; i++) {
        if (min > tall[i]) {
            min = tall[i];
        }
        if (max < tall[i]){
            max = tall[i];
        }
        sum += tall[i];
    }
// Har summert alle tallene i arrayet, deretter trekker vi fra min og max. Deler med lengden av arrayet - 2
    sum -= (min + max);
    double snitt = (float)sum / (lengde - 2);
    return snitt;
}

int main() {
    int tall[] = {1, 3, 8, 9, 2, 6};
    int lengde = sizeof(tall) / sizeof(tall[0]); // Her gjør vi litt magi, der vi deler på første tall i arrayet og på magiskt vis blir riktig svar???
    double GjennomSnitt = gjennomSnitt(tall, lengde);
    printf("%.3f\n", GjennomSnitt);
    return 0;
}

// Ki ble brukt for å lære meg om arrays og fremgangsmåten, altså hva jeg måtte gjøre for å løse oppgaven, og for å rette opp feil i koden.