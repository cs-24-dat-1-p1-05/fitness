#include "workoutrecommendations.h"
#include "user.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEMP_FILE "temp_users.txt"

/* Function to calculate the Cooper test result */
int cooper_test() {
    float distance;
    printf("Enter the distance you ran in 12 minutes (meters): ");
    scanf("%f", &distance);

    if (distance < 1000) {
        return 0;
    } if (distance < 2000) {
        return 1;
    } if (distance > 2000) {
        return 2;
    }
        return 0;
    }

/* Function to calculate strength training results with equipment */
int strength_training_with_equipment() {
    int reps;
    printf("Enter the number of bench press, shoulder press or squat repetitions at 60 percent of your 1 rep max weight: ");
    scanf("%d", &reps);

    if (reps < 5) {
        return 0;
    } if (reps < 10) {
        return 1;
    } if (reps > 10) {
        return 2;
    }
        return 0;
    }

/* Function to calculate strength training results without equipment */
int strength_training_without_equipment() {
    int reps;
    printf("Enter the number of pushups, situps or splitsquats you can perform in one set: ");
    scanf("%d", &reps);

    if (reps < 10) {
        return 0;
    } if (reps < 20) {
        return 1;
    } if (reps > 20) {
        return 2;
    }
        return 0;
    }

/* Function to calculate the walking test result */
int walking_test() {
    float distance;
    printf("Enter the distance you walked in 6 minutes (meters): ");
    scanf("%f", &distance);

    if (distance < 300) {
        return 0;
    } if (distance < 500) {
        return 1;
    } if (distance > 500) {
        return 2;
    }
    return 0;
}

/* Function to select and perform the appropriate fitness assessment */
int select_assessment(int activity, int location) {
    if (activity == 1) {
        printf("Selected assessment: Cooper Test\n");
        return cooper_test();
    } if (activity == 3) {
        if (location  == 2) {
            printf("Selected assessment: Strength Training (with equipment)\n");
            return strength_training_with_equipment();
        } if (location  == 1) {
            printf("Selected assessment: Strength Training (without equipment)\n");
            return strength_training_without_equipment();
        }
    } else if (activity == 2) {
        printf("Selected assessment: Walking Test\n");
        return walking_test();
    } else if (activity == 4) {
        if (location  == 2) {
            printf("Selected assessments: Cooper Test and Strength Training (with equipment)\n");
            return cooper_test()+strength_training_with_equipment()/2;
        } if (location  == 1) {
            printf("Selected assessments: Cooper Test and Strength Training (without equipment)\n");
            return cooper_test()/strength_training_without_equipment()/2;
        }
    } else {
        printf("Error: Invalid activity.\n");
        return 0;
    }
    return 0;
}

int calculate_fitness_level(user_t user) {

    int fitness_level = 1;

    /* BMI contribution */
    if (user.fitness_assessment_bmi < 24.9) {
        fitness_level++;
    }

    /* WHR contribution */
    if ((user.gender == 1 && user.fitness_assessment_whr < 0.95) ||
        (user.gender == 2 && user.fitness_assessment_whr < 0.8)) {
        fitness_level++;
        }

    fitness_level += select_assessment(user.preferences, user.location);

    return fitness_level;
}

int calculate_id(user_t user) {

    int id = 0;

    if (strcmp(user.exercise_purpose, "Weight Loss") == 0) {
        id = 1;  /* Starting range for weight loss programs */
    } else if (strcmp(user.exercise_purpose, "Muscle Gain") == 0) {
        id = 4;  /* Starting range for cardio programs */
    } else if (strcmp(user.exercise_purpose, "Improve Cardio") == 0) {
        id = 8; /* Starting range for muscle-building programs */
    } else if (strcmp(user.exercise_purpose, "General Health") == 0) {
    id = 12; /* Starting range for maintaining fitness programs */
}

    /* Basing baseID on fitnesslevel. Assumes fitness level is an int, beginner = 1 etc
     * -1, so level 1 makes no change, level 2 makes 1, and so on */
    id += user.fitness_level - 1;
    id += user.feedback;

    /* Adjust further based on preferences */
    if (user.preferences == 1) {
        return id;
    } if (user.preferences == 2) {
        return id + 1;
    } if (user.preferences == 3 && user.location == 1) {
        return id  + 2;
    } if (user.preferences == 3 && user.location == 2) {
        return id  + 2;
    }if (user.preferences == 4 && user.location == 1) {
        return id + 4;
    } if (user.preferences == 4 && user.location == 2) {
        return id + 5;
    }

    return id;

}


void retrieveWorkoutRecommendations(user_t user) {

    int id = calculate_id(user);

    FILE *file = fopen("fitnessdatabse.txt", "r");
    if (!file) {
        printf("Error: Could not open the fitness database file");
        return;
    }

    char text[256];
    int currentID = 0;

    printf("\n--- Workout Recommendation ---\n");
    while (fgets(text, sizeof(text), file)) {
        if (strncmp(text, "#ID", 3) == 0) {
            sscanf(text, "#ID %d:", &currentID);
        }

        if (currentID == id) {
            printf("%s", text);
            while (fgets(text, sizeof(text), file) && strncmp(text, "#ID", 3) != 0) {
                printf("%s", text);
            }
            break;
        }
    }

    fclose(file);
}

int get_user_feedback() {
    printf("How was the last workout?\n");
    printf("1. Too hard\n2. Too easy\n3. Not effective\nEnter your feedback: ");
    int feedback;
    scanf("%d", &feedback) != 1 || (feedback != -1 && feedback != 1 && feedback != 0);

    if (feedback == 1) {
        return -1;
    } if (feedback == 2) {
        return 1;
    }
    return 0;
}
int adjust_recommendation(user_t *user, int feedback) {
    printf("Adjusting recommendation for user: %s\n", user->name);
    printf("Initial Recommendation ID: %d\n", user->recommendation_id);

    if (feedback == -1) { // Too hard
        if (user->recommendation_id > 1) {
            user->recommendation_id -= 1; // Assign an easier program
        }
    } else if (feedback == 1) { // Too easy
        user->recommendation_id += 1; // Assign a more challenging program
    } else if (feedback == 0) { // Not effective
        // Change to a program in the same category but different focus
        if (user->recommendation_id % 2 == 0) { // Even ID: switch to odd
            user->recommendation_id -= 1;
        } else { // Odd ID: switch to even
            user->recommendation_id += 1;
        }
    }

    // Enforce valid minimum value
    if (user->recommendation_id < 1) {
        printf("Recommendation ID is invalid. Resetting to minimum valid value (1).\n");
        user->recommendation_id = 1;
    }

    printf("Final Recommendation ID: %d\n", user->recommendation_id);
    return user->recommendation_id;
}



void update_user_file(const char *name, int recommendation_id) {
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        perror("Error opening users.txt for reading");
        exit(EXIT_FAILURE);
    }

    FILE *temp_file = fopen("users_temp.txt", "w");
    if (!temp_file) {
        perror("Error opening temporary file for writing");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LINE_LENGTH];
    char current_user[100] = "";
    int is_target_user = 0;
    int recommendation_updated = 0;
    int user_found = 0;

    printf("Starting update for user: %s\n", name);
    printf("Target Recommendation ID: %d\n", recommendation_id);

    // Process each line
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("Processing line: %s", buffer);

        // Detect user block by name
        if (strncmp(buffer, "Name:", 5) == 0) {
            sscanf(buffer, "Name: %99[^\n]", current_user);
            is_target_user = (strcmp(current_user, name) == 0);
            user_found |= is_target_user; // Mark user as found if matched
            printf("Current user: %s (Is target: %d)\n", current_user, is_target_user);
        }

        // Update "Recommendation ID" for the target user
        if (is_target_user && strncmp(buffer, "Recommendation ID:", 18) == 0) {
            printf("Found Recommendation ID for user %s: %s", name, buffer);
            snprintf(buffer, sizeof(buffer), "Recommendation ID: %d\n", recommendation_id);
            recommendation_updated = 1;
            printf("Updated line: %s", buffer);
        }

        // Write the current line to the temp file
        fputs(buffer, temp_file);
    }

    // If the target user was processed but no Recommendation ID found, add it
    if (is_target_user && !recommendation_updated) {
        printf("No Recommendation ID found for user %s. Adding new Recommendation ID: %d\n", name, recommendation_id);
        fprintf(temp_file, "Recommendation ID: %d\n", recommendation_id);
    }

    // If the target user wasn't found, print a message
    if (!user_found) {
        printf("User '%s' not found in the file. No changes made.\n", name);
    }

    fclose(file);
    fclose(temp_file);

    // Replace the original file with the updated one
    if (rename("users_temp.txt", "users.txt") != 0) {
        perror("Error replacing users.txt with updated file");
        // Clean up the temporary file
        remove("users_temp.txt");
        exit(EXIT_FAILURE);
    }

    printf("Successfully updated Recommendation ID for user %s to %d.\n", name, recommendation_id);
}

