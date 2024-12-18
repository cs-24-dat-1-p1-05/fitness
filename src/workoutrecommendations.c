#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "workoutrecommendations.h"
#include "user.h"

#define TEMP_FILE "temp_users.txt"

// Function to select and perform the appropriate fitness assessment
int select_assessment(int activity, int location) {
    if (activity == 1) {
        printf("Selected assessment: Cooper Test\n");
        return cooper_test(); // Returns the result from assessment
    } if (activity == 3) {
        if (location  == 2) {
            printf("Selected assessment: Strength Training (with equipment)\n");
            return strength_training_with_equipment(); // Returns the result from assessment
        } if (location  == 1) {
            printf("Selected assessment: Strength Training (without equipment)\n");
            return strength_training_without_equipment(); // Returns the result from assessment
        }
    } else if (activity == 2) {
        printf("Selected assessment: Walking Test\n");
        return walking_test(); // Returns the result from assessment
    } else if (activity == 4) {
        if (location  == 2) {
            printf("Selected assessments: Cooper Test and Strength Training (with equipment)\n");
            return cooper_test() + strength_training_with_equipment() / 2; // Returns the result from assessment
        } if (location  == 1) {
            printf("Selected assessments: Cooper Test and Strength Training (without equipment)\n");
            return cooper_test() + strength_training_without_equipment() / 2; // Returns the result from assessment
        }
    } else {
        printf("Error: Invalid activity.\n");
        return 0;
    }
    return 0;
}

// Function to calculate the Cooper test result
int cooper_test() {
    float distance;
    printf("Enter the approximate distance you can run in 12 minutes (meters): ");
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

// Function to calculate strength training results with equipment
int strength_training_with_equipment() {
    int reps;
    printf("Enter the number of bench press, shoulder press or squat repetitions at approximately 60 percent of your 1 rep max weight: ");
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

// Function to calculate strength training results without equipment
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

// Function to calculate the walking test result
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

// Function to calculate the ID for the workout recommendation
int calculate_id(user_t user) {

    int id = 0;

    // Checks the user's exercise purpuse
    if (strcmp(user.exercise_purpose, "Weight Loss") == 0) {
        id = 1;  // Starting range for weight loss programs
    } else if (strcmp(user.exercise_purpose, "Muscle Gain") == 0) {
        id = 19;  // Starting range for muscle-building programs
    } else if (strcmp(user.exercise_purpose, "Improve Cardio") == 0) {
        id = 37; // Starting range for cardio programs
    } else if (strcmp(user.exercise_purpose, "General Health") == 0) {
        id = 55; // Starting range for maintaining fitness programs
}

    // Adjust further based on preferences
    if (user.preferences == 1) {
        return id + 0;
    } if (user.preferences == 2) {
        return id + 3;
    } if (user.preferences == 3 && user.location == 1) {
        return id + 6;
    } if (user.preferences == 3 && user.location == 2) {
        return id + 9;
    }if (user.preferences == 4 && user.location == 1) {
        return id + 12;
    } if (user.preferences == 4 && user.location == 2) {
        return id + 15;
    }

    // Basing id on fitness_level
    id += user.fitness_level;

    return id;
}

int calculate_fitness_level(user_t user) {

    int fitness_level = 1;

    // BMI contribution
    if (user.fitness_assessment_bmi < 24.9) {
        fitness_level++;
    }

    // WHR contribution
    if ((user.gender == 1 && user.fitness_assessment_whr < 0.95) ||
        (user.gender == 2 && user.fitness_assessment_whr < 0.8)) {
        fitness_level++;
        }

    fitness_level += select_assessment(user.preferences, user.location);

    return fitness_level;
}

int get_user_feedback() {
    printf("How was the last workout?\n");
    printf("1. Too hard\n2. Too easy\n3. Not effective\nEnter your feedback: ");
    int feedback;
    scanf("%d", &feedback);

    if (feedback == 1) {
        printf("Feedback noted: Last workout was too hard. Finding more suitable recommendations...\n");
        return -1;
    } if (feedback == 2) {
        printf("Feedback noted: Last workout was too easy. Finding more suitable recommendations...\n");
        return 1;
    }
    printf("Feedback noted: Last workout was not effective. Finding similar recommendations...\n");
    return 0;
}

void display_recommendation(int recommendation_id) {
    FILE *file = fopen("recommendations.txt", "r");
    if (!file) {
        printf("Error opening recommendations file.\n");
        return;
    }

    char line[256];
    int current_id = 0;
    int is_in_recommendation = 0; // Boolean flag to indicate we're in the correct block

    while (fgets(line, sizeof(line), file)) {
        // Check if this line starts a new recommendation block
        if (strncmp(line, "#ID", 3) == 0) {
            // Parse the ID from the line
            sscanf(line, "#ID %d", &current_id);

            // Check if this is the desired recommendation ID
            if (current_id == recommendation_id) {
                is_in_recommendation = 1; // Start printing lines from this block
            } else if (is_in_recommendation) {
                // Reached a new block; stop printing
                break;
            } else {
                is_in_recommendation = 0; // Ensure we don't print from other blocks
            }
            continue; // Move to the next line
        }

        // Print lines if we are inside the desired recommendation block
        if (is_in_recommendation) {
            printf("%s", line);
        }
    }

    if (!is_in_recommendation) {
        printf("No recommendation found with ID %d\n", recommendation_id);
    }

    fclose(file);
}


int adjust_recommendation(user_t *user, int feedback) {

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

    return user->recommendation_id;
}

