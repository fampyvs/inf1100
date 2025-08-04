#include <stdio.h>


double resultat;
double konvertering() { 
    printf("Hvor mange kilogram ønsker du å konvertere?\n"); 
        
        float KgV;
        scanf("%f", &KgV); 
            printf("Du har valgt %.2f Kg.\n", KgV); 
            printf("Hva ønsker du å konvertere til, 1 for Centner, 2 for Newton og 3 for Karat?\n"); // Skriver ut spørsmål
        
        int KonV;
        scanf("%d", &KonV); // Tar inn input fra bruker
            printf("Du har valgt %d. ", KonV);

        if (KonV == 1) { // Sjekker om valget er 1
        
            double resultat;
            resultat = KgV * 0.01; // Regner ut resultatet
            printf("%.2f kilogram tilsvarer %g centner\n", KgV, resultat);
        } else if (KonV == 2) { // Sjekker om valget er 2
            
            double resultat;
            resultat = KgV * 9.8;
            printf("%.2f kilogram tilsvarer %g newton\n", KgV, resultat);
        } else if (KonV == 3) { // Sjekker om valget er 3
            
            double resultat;
            resultat = KgV * 5000;
            printf("%.2f kilogram tilsvarer %g karat\n", KgV, resultat);
        return resultat; // Returnerer resultatet
        } else {
            
            printf("Du har valgt et ugyldig valg, prøv igjen.\n");
            konvertering();
        }
}

int main() {
    double a = konvertering(); {
    int b = 0; {
        printf("Ønsker du å gjøre en ny konvertering, 1 for ja og andre tegn for nei.\n");
            scanf("%d", &b);
            
            if (b == 1) {
                main();
                
            }   
            else {
                printf("Takk for at du brukte programmet!\n");
            }
        }
    }
}