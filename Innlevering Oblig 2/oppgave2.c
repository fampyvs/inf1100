#include <stdio.h>

// Definerer funskjonen som konverterer bokstaver
char konverter(char tegn) {
    if (tegn >= 'A' && tegn <= 'Z') { // Skjekker om det er stor bokstav
        return tegn + 32; // Konverterer stor bokstav til liten
    }   else if (tegn >= 'a' && tegn <= 'z') { // Skjekker om det er liten bokstav
        return tegn - 32; // Konverterer liten bokstav til stor
    }
}

int main() {
    char tegn = 'g'; // Tegn for konvertering blir gitt
    char konvertert = konverter(tegn); // Kaller til funskjonen, får returverdi og konvertert tegn i ny variabel
    printf("%c\n", konvertert);
    return 0;
}

// Fikk litt hjelp fra ChatGPT
