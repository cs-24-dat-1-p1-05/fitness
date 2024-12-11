#include <stdio.h>
#include <stdlib.h>
#include "workoutrecommendations.h"  // Include the header file for the recommendations
#include "user.h"

int main() {
    int user_choice;
    user_t user;
    user_t new_user;

    printf("Welcome to the Fitness Tracker!\n");
    printf("\nSelect an option:\n");
    printf("1. Create new user\n");
    printf("2. View existing user\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &user_choice);

    if (user_choice == 2) {
        char name[100];
        printf("Enter the name of the existing user: ");
        scanf("%s", name);

        // Assuming you have a function to check and load user data
        // For now, let's assume user data is found and display recommendations

        int recommendation_id = calculate_id(user);
        printf("Recommendation ID: %d\n", recommendation_id);

        // Display the recommendation based on the ID
        display_recommendation(recommendation_id);

    } else if (user_choice == 1) {
        user_t user = load_user();
        save_user(user);
    } else if (user_choice == 3) {
        // Exit the program
        printf("Exiting the program...\n");
        return 0;
    }

    return 0;
}