#include <stdio.h>

// Funksjonen for å kalkulere tverrsummen av et tall til vi har bare ett tall
int tverrsum(int tall) {

    int sum = 0;
    while (tall > 9) { // Målet er å redusere nummeret lå lenge det er større enn 9.

        sum = 0;
        while (tall > 0) { // I denne loopen ønsker jeg å ta ut ett tall om gangen for så å summere det

            sum += tall % 10; // Mod 10 vil altid ta ut det siste nummret i et tall, og legge det til summen
            tall = tall / 10; // Dividerer med 10 for å fjerne det siste nummeret
        }

        tall = sum; // For å skjekke om sum ikke er større en 9 
    }

    return sum;
}


int main() {
    int tallet = 3452;
    int svar = tverrsum(tallet);
    printf("Tverrsummen av %d er %d\n", tallet, svar);
    return 0;
}

// Fikk litt hjelp fra ChatGPT
