#include <stdio.h>
#include "workoutrecommendations.h"  // Include the header files
#include "user.h"

int main() {

    int user_choice;

    // Loop until user chooses Exit
    do {
        // Display and prompt for user choice
        printf("Welcome to the Fitness Tracker!\n");
        printf("\nSelect an option:\n");
        printf("1. Create new user\n");
        printf("2. View existing user\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        // Read user choice
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

            // Displaying initial recommendation
            if (existing_user.recommendation_id > 0) {
                printf("Recommendation ID: %d\n", existing_user.recommendation_id);
                display_recommendation(existing_user.recommendation_id);

                // Handle user feedback and potentially adjust recommendations
                int feedback = get_user_feedback();
                adjust_recommendation(&existing_user, feedback);

                // Updating user.txt file with the new recommendation id
                update_user_file(name, existing_user.recommendation_id);
                // Optionally display updated recommendation
                printf("\nWould you like to view the updated recommendation? (1 for Yes, 2 for No): ");
                int choice;
                if (scanf("%d", &choice) == 1 && choice == 1) {
                    printf("Updated Recommendation:\n");
                    display_recommendation(existing_user.recommendation_id);
                }
            } else {
                printf("No valid recommendation found for user %s.\n", name);
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
