// gcc -o oppgave4 oppgave4.c -lm
#include <stdio.h>
#include <math.h>

double avstand(int x1, int y1, int x2, int y2) { // Funksjon som tar inn 4 heltall og returnerer et desimaltall
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); // Returnerer kvadratroten av summen av kvadratene til forskjellen mellom x1 og x2 og y1 og y2
}

int main() { 
    double a = avstand(4, 6, 5, 8); // Kaller funksjonen med tall gitt i avstand som argumenter
    printf("Avstanden mellom punktene er: %f\n", a);
    return 0;
}

// Fikk litt hjelp fra ChatGPT
