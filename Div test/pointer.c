#include <stdio.h>

void multi(int *tallet);

int main() {
    int ettall = 17;
    int *pettall = &ettall;
    printf("Før: %d\n", ettall);
    multi(pettall);
    printf("Etter: %d\n", ettall);

    return 0;
}

void multi(int *tallet) {
    *tallet = (*tallet)*2;
}