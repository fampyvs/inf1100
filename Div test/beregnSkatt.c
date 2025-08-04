#include <stdio.h>

// Skatt. mindre enn 40 000 gir null skatt
// Over 40 000 til 600 000 gir 35% - 48%

float beregningSkatt(int inntekt) {
    if (inntekt < 40000) {
        return 0;

    } else if (inntekt >= 40000 && inntekt <= 600000) {
        return inntekt * 0.35;

    } else {
        return inntekt * 0.48;
    }
}



int main() {
    float skatt = beregningSkatt(5350000);
    printf("%.2f kr blir skatten din\n", skatt);
    return 0;
}
