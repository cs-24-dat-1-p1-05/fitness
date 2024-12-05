//
// Created by Celina Ottesen on 02/12/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    int gender;
    int height;
    int weight;
    int hip;
    int waist;
    int location;
    int preferences;
    int fitness_assessment;
}user_t;

void print_user(user_t user);

user_t load_user(void);
void returning_user(const char *name);
void save_user(user_t user);
void read_user(user_t user);



int main(void){
    printf("Welcome to the fitness trainer\n");

    char response;
    printf("Are you a new user? y/n");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        printf("\nGreat! Let's set up your profile.\n");
        user_t user = load_user();
        printf("\nThank you for entering your details!\n");
        print_user(user);

        save_user(user);
    } else if (response == 'n' || response == 'N') {
        char name[50];
        printf("\nWelcome back!\n");
        printf ("Please enter your name:",name);
        scanf("%49s", name);
        returning_user(name);
    } else {
        printf("\nInvalid input. Please restart the program and try again.\n");
    }
    return 0;
}

void print_user(user_t user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Gender: %d\n", user.gender);
    printf("Height: %d\n", user.height);
    printf("Weight: %d\n", user.weight);
    printf("HIP: %d\n", user.hip);
    printf("Waist: %d\n", user.waist);
    printf("Location: %d\n", user.location);
    printf("Preferences: %d\n", user.preferences);
}

user_t load_user(void) {
    user_t new_user;
    printf("Please enter your name: ");
    getchar(); // Clear newline from buffer
    fgets(new_user.name, sizeof(new_user.name), stdin);
    new_user.name[strcspn(new_user.name, "\n")] = '\0';

    do {
        printf("Please enter your age (0-120): ");
        scanf("%d", &new_user.age);
        if (new_user.age < 0 || new_user.age > 120)
            printf("Invalid age. Please try again.\n");
    } while (new_user.age < 0 || new_user.age > 120);
    do {
        printf("Please enter your gender (0 for Male, 1 for Female): ");
        scanf("%d", &new_user.gender);
        if (new_user.gender != 0 && new_user.gender != 1)
            printf("Invalid gender. Please try again.\n");
    } while (new_user.gender != 0 && new_user.gender != 1);

    printf("Please enter your height:\n");
    scanf("%d", &new_user.height);
    printf("Please enter your weight:\n");
    scanf("%d", &new_user.weight);
    printf("Please enter your hip:\n");
    scanf("%d", &new_user.hip);
    printf("Please enter your waist:\n");
    scanf("%d", &new_user.waist);
    printf("Please enter your location:\n");
    scanf("%d", &new_user.location);
    printf("Please enter your preferences:\n");
    scanf("%d", &new_user.preferences);
    return new_user;
}

void returning_user(const char *name) {
    if (user_exists(name)) {
        printf("Fetching your details...\n");
        read_user(name);
    } else {
        printf("No profile found for %s. Please create a new profile.\n", name);
    }
}

    char line[256];
    char current_name[50];
    int user_found = 0;

    while (fgets(line, sizeof(line), file)) {
        // Check if the current line contains the name
        if (sscanf(line, "Name: %49[^\n]", current_name) == 1) {
            if (strcmp(current_name, name) == 0) {
                user_found = 1;
                printf("User Found: %s\n", current_name);
                printf("%s", line); // Print the "Name" line

                // Print the next 9 lines (details of the user)
                for (int i = 0; i < 9; i++) {
                    if (fgets(line, sizeof(line), file)) {
                        printf("%s", line);
                    }
                }
                break;
            }
        }
    }

    if (!user_found) {
        printf("User with name '%s' not found.\n", name);
    }

}
void save_user(user_t user) {
    FILE *file = fopen("/Users/celina/Documents/GitHub/fitness/User/user.txt", "a"); // Open file in append mode
    if (file == NULL) {
        printf("Error: Could not open file to save data.\n");
        return;
    }

    fprintf(file, "Name: %s\n", user.name);
    fprintf(file, "Age: %d\n", user.age);
    fprintf(file, "Gender: %s\n", user.gender == 0 ? "Male" : "Female");
    fprintf(file, "Height: %d cm\n", user.height);
    fprintf(file, "Weight: %d kg\n", user.weight);
    fprintf(file, "Hip: %d cm\n", user.hip);
    fprintf(file, "Waist: %d cm\n", user.waist);
    fprintf(file, "Location: %d\n", user.location);
    fprintf(file, "Preferences: %d\n", user.preferences);
    fprintf(file, "Fitness Assessment: %d\n", user.fitness_assessment);
    fprintf(file, "---------------------------\n");

    fclose(file);
}

