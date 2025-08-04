#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 100

// Function to load users from file
void load_users_from_file(char users[][MAX_NAME_LENGTH], int *num_users) {
    FILE *file = fopen("users.txt", "r");
    if (file != NULL) {
        while (fgets(users[*num_users], MAX_NAME_LENGTH, file) != NULL) {
            // Remove the newline character from the input
            users[*num_users][strcspn(users[*num_users], "\n")] = 0;
            (*num_users)++;
            if (*num_users >= MAX_USERS) {
                break;
            }
        }
        fclose(file);
    }
}


// Function to save users to file
void save_users_to_file(char users[][MAX_NAME_LENGTH], int num_users) {
    FILE *file = fopen("users.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < num_users; i++) {
            fprintf(file, "%s\n", users[i]);
        }
        fclose(file);
    }
}

// Function to check if a user exists
int user_exists(char name[], char users[][MAX_NAME_LENGTH], int num_users) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(name, users[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to add a new user
void add_new_user(char users[][MAX_NAME_LENGTH], int *num_users, char name[]) {
    if (!user_exists(name, users, *num_users)) {
        strcpy(users[*num_users], name);
        (*num_users)++;
        save_users_to_file(users, *num_users);
    } else {
        printf("User already exists.\n");
    }
}

// Function to handle user input
int handle_user_input(char users[][MAX_NAME_LENGTH], int *num_users) {
    char name[MAX_NAME_LENGTH];
    printf("Enter your name (or type 'load' to load a saved name, 'save' to save a new name, or 'exit' to exit): ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    if (strcmp(name, "load") == 0) {
        printf("Enter the name of the saved user: ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0;
    } else if (strcmp(name, "save") == 0) {
        printf("Enter the new user's name: ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0;
        add_new_user(users, num_users, name);
    } if (strcmp(name, "exit") == 0) {
        return 0;
    } else {
        if (user_exists(name, users, *num_users)) {
            printf("Correct! Your name is in the list.\n");
        } else {
            printf("Sorry, your name is not in the list.\n");
        }
    }
    return 1;
}

int main() {
    char users[MAX_USERS][MAX_NAME_LENGTH];
    int num_users = 0;

    while (1) {
        if (handle_user_input(users, &num_users) == 0) {
            break;
        };
    }

    return 0;
}