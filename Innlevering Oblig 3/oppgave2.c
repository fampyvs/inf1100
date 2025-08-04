/* For å kunne gå opp til eksamen må 4 av 6 obligatoriske arbeidskrav være godkjent. I tillegg så må
arbeidskrav 3 eller 6 (eller begge) være godkjent.
Lag en funksjon i C som returnerer True dersom studenten kan gå opp til eksamen og False
dersom studenten ikke får gå opp til eksamen. Funksjonen tar et argument som er en
tabell(array). Beskriv i koden hvordan du velger å sette opp tabellen(arrayet). */

#include <stdio.h>
#include <stdbool.h>

// Funksjonen skjekker om studenten har bestått 4 av 6 arbeidskrav fra et array.
bool eksamen(char arbeidskrav1[], char arbeidskrav2[]) {
    // Definerer int i for å skjekke gjennom hvert element i arrayet. 
    int godkjent = 0;

// Sjekker om arbeidskrav er >= 4 for student 1
    for (int i = 0; i < 6; i++) {
        if (arbeidskrav1[i] == 1) godkjent++; {
        }
    }
    if (godkjent >= 4 && (arbeidskrav1[2] == 1 || arbeidskrav1[5] == 1)) {
        return true;
    } else {
        return false;
    }

// Skjekker om arbeidskrav er >= 4 for student 2
    for (int i = 0; i < 6; i++) {
        if (arbeidskrav2[i] == 1) godkjent++; {
        }
    } 
    if (godkjent >= 4 && (arbeidskrav2[2] == 1 || arbeidskrav2[5] == 1)) {
        return true;
    } else {
        return false;
    }
}


int main() {
    char arbeidskrav1[6] = {1, 1, 0, 1, 1, 0}; // Setter opp arrayet med 6 som blir representert med sann (1) eller usann (0)
    char arbeidskrav2[6] = {1, 1, 1, 0, 0, 1};
    if (eksamen(arbeidskrav1, arbeidskrav2)) {
        printf("Student 1 kan gå opp til eksamen\n");
    } else {
        printf("Student 1 kan ikke gå opp til eksamen\n");
    }
    if (eksamen(arbeidskrav2, arbeidskrav1)) {
        printf("Student 2 kan gå opp til eksamen\n");
    } else {
        printf("Student 2 kan ikke gå opp til eksamen\n");
    }
}

// Fikk hjelp fra KI for å finne feil og hjelpe meg med å forstå oppgaven.
