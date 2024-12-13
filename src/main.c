#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "workoutrecommendations.h"  // Include the header file for the recommendations
#include "user.h"

int main() {
    int user_choice;

    // Infinite loop until user chooses to exit
    do {
        // Display main menu options
        printf("Welcome to the Fitness Tracker!\n");
        printf("\nSelect an option:\n");
        printf("1. Create new user\n");
        printf("2. View existing user\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        // Read user choice (needs to be correctly handled)
        if (scanf("%d", &user_choice) != 1) {
            // Clear the input buffer in case of invalid input
            while(getchar() != '\n');
            printf("Invalid input, please enter a number between 1 and 3.\n");
            continue;
        }

        if (user_choice == 1) {
            // Creating a new user
            user_t new_user = load_user();  // Load user data from input
            save_user(new_user);            // Save the new user to the file
            printf("New user created successfully.\n");

        } else if (user_choice == 2) {
            // Viewing an existing user
            char name[100];
            printf("Enter the name of the existing user: ");
            scanf("%99s", name);

            // Attempt to load the user data
            user_t existing_user = returning_user(name);


            if (existing_user.recommendation_id > 0) {
                printf("User Found: %s\n", existing_user.name);
                printf("Recommendation ID: %d\n", existing_user.recommendation_id);
                display_recommendation(existing_user.recommendation_id);

            } else if (strcmp(existing_user.name, "") == 0) {
                printf("User %s not found in the database.\n", name);
            } else {
                printf("No valid recommendation found for user %s.\n", name);
            }
            int feedback = get_user_feedback();
            switch (feedback) {
                case -1:
                    printf("Feedback noted: Last workout was too hard. Adjusting recommendations...\n");
                    existing_user.recommendation_id -= 1;
                break;
                case 1:
                    printf("Feedback noted: Last workout was too easy. Adjusting recommendations...\n");

                    existing_user.recommendation_id += 1;
                break;
                case 0:
                    printf("Feedback noted: Last workout was not effective. Suggestions will be updated.\n");
                    existing_user.recommendation_id += 0;
                break;
                default:
                    printf("Invalid feedback. Please try again later.\n");
                break;
            }
            printf("Would you like to see the updated recommendation? (1 for Yes, 0 for No): ");
            int view_updated;
            if (scanf("%d", &view_updated) != 1) {
                while (getchar() != '\n');  // Clear input buffer
                printf("Invalid input. Skipping updated recommendation.\n");
                continue;
            }

            if (view_updated == 1) {
                printf("Updated Recommendation ID: %d\n", existing_user.recommendation_id);
                display_recommendation(existing_user.recommendation_id);
            } else {
                printf("Skipping updated recommendation. Returning to main menu.\n");
            }

        } else if (user_choice == 3) {
            // Exit the program
            printf("Exiting the program...\n");

        } else {
            // Handle invalid choice
            printf("Invalid choice, please try again.\n");

        }


    } while (user_choice != 3);  // Loop until the user chooses to exit by entering 3

    return 0;  // Proper closing of the main function
}