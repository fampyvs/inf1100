/* Lag en funksjon i C som reverserer en tekststreng. I C, så er en tekststreng representert med en
tabell(array) av tegn (characters). Funksjonen skal manipulere tabellen(arrayet) slik at innholdet
er reversert. Dersom funksjonen var kalt opp med tekststrengen "A string", så skal innholdet i
tabellen(arrayet) være "gnirts A". Funksjonen skal ikke returnere noe. Du må manipulere strengen
selv; det er ikke lov å bruke en innebygd funksjon (som strrev på windows). */

#include <stdio.h>

// Programmeet reverserer teksten ved å telle fra begge endene av arrayet og bytter verdiene.
void reversertTekst(char *tekst) {
    int start = 0;
    int slutt = 0;

    // Vil finne slutten av tekst strengen '\0' - 1
    while (tekst[slutt] != '\0') {
        slutt++;
    }
    slutt--;

    // Her vil jeg ha en temp variabel som kan holde på en av tegnene mens vi bytter på start og slutt
    while (start < slutt) {
        char temp = tekst[start];
        tekst[start] = tekst[slutt];
        tekst[slutt] = temp;

        start++;
        slutt--;
    }
}

int main() {
    char tekst[] = "Fin potet";
    printf("%s blir reversert til\n", tekst);
    reversertTekst(tekst);
    printf("%s\n", tekst);
    return 0;
} 

// Ki ble brukt for å lære meg at en array altid slutter med \0, og løse feil i koden.