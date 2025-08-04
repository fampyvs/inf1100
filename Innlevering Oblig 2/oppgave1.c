#include <stdio.h>

// Funskjon for triangel, skriver ut gitt tegn, for gitt antall linjer
void triangel(char tegn, int antall_linjer) {
    int tegnStart = 1; // Ønsker å starte første linje med ett tegn
    
    while (tegnStart <= antall_linjer) { // Kontrollerer om vi har nådd antall linjer som er gitt
        int linjeStart = 0; 
        
        while (linjeStart < tegnStart) { // Printer ut et tegn, bestemt av hvilken linje du er på.
            printf("%c", tegn); linjeStart++;
        }
        printf("\n"); tegnStart++;
    } 
}

int main() {
    triangel('*', 5); // Skriver ut et triangel med 5 linjer av '*'
    return 0;
}

// Fikk litt hjelp fra ChatGPT