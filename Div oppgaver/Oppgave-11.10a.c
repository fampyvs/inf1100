//
//
// The next two lines are preprocessor directives
#include <stdio.h>
#define STOP 0

// Function : Main
// Description : prompt for input, then countdown
int main(void)
{
    // Variable declarations
    int counter;    // Holds intermediant counter values
    int startPoint; // Starting point for count down

    // Prompt the user for input
    printf("===== Countdown Program =====\n");
    printf("Enter a positive integer: ");
    scanf("%d", &startPoint);

    // Countdown from the input number to 0
    for (counter = startPoint; counter >= STOP; counter--)
        printf("%c\n", counter + 'A');
}