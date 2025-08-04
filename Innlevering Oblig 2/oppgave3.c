#include <stdio.h>

// Definerer funskjonen for start, slutt og faktora
void sjekk_tall(int start, int slutt, int faktor) {
    for (int startTall = start; startTall <= slutt; startTall++) { // Holder kontroll over når løkken er nådd slutten av ønsket sluttverdi
        char* PvO; // Ønsker en 'peker' som kan holde på en verdi for hver av itrasjonene av løkken

        if (startTall % 2 == 0) { // Vi vil vite om startTall har en restverdi på 0
            PvO = "et Partall"; // PvO får en verdi hvis 'startTall' er 0
        }
        else if (startTall % 2 != 0) { // Vil vite om startTall ikke har en restverdi på 0
            PvO = "et Oddetall"; // Gir PvO en annen verdi hvis 'startTall' ikke er 0
        }
        
        char* Efaktor; // Ønsker en 'peker' som holder på en verdi for hver av iterasjonene av løkken

        if (startTall % faktor == 0) { // Vil skjekke om startTall og tallet gitt i faktor er en faktor for hverandre.
            Efaktor = "er en faktor"; // Efaktor får verdi hvis 'startTall' gir 0 fra faktor
        }
        else if (startTall % faktor != 0) { // Set om 'startTall' ikke er en faktor
            Efaktor = "er ikke en faktor"; // Efaktor får verdi hvsi 'startTall' gir noe annet en 0 fra faktor
        }
        printf("%d er %s og %d %s \n", startTall, PvO, faktor, Efaktor);
    }
}

int main() { 
    sjekk_tall(1, 10, 2); // Kaller til skjekk_tall, og gitt verdi for start, slutt, og faktor
    return 0;
}

// Fikk litt hjelp fra ChatGPT