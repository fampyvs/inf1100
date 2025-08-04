#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    char correct_names[][100] = {"John", "Alice", "Bob", "Charlie"};
    int num_correct_names = sizeof(correct_names) / sizeof(correct_names[0]);

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    // Remove the newline character from the input
    name[strcspn(name, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < num_correct_names; i++) {
        if (strcmp(name, correct_names[i]) == 0) {
            printf("Correct! Your name is in the list.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Sorry, your name is not in the list.\n");
    }

    return 0;
}