#include <stdio.h>

int main() {

    int tall = 19;
    char bokstav = 'z'  ;
    
    void *ptr = &bokstav;

    printf("Jeg peker til verdien: %c\n", *(char *)ptr);


    return 0;
}