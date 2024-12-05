#include "workoutrecommendations.h"
#include <stdio.h>
#include <string.h>

int calculateID(User user) {
    int id = 0;

    if (strcmp(user.exercisePurpose, "Lose Weight") == 0) {
        id = 1;  /* Starting range for weight loss programs */
    } else if (strcmp(user.exercisePurpose, "Improve Cardio") == 0) {
        id = 11;  /* Starting range for cardio programs */
    } else if (strcmp(user.exercisePurpose, "Build Muscle") == 0) {
        id = 21; /* Starting range for muscle-building programs */
    } else if (strcmp(user.exercisePurpose, "Maintain fitness") == 0) {
    id = 31; /* Starting range for maintaining fitness programs */
}

    /* Basing baseID on fitnesslevel. Assumes fitness level is an int, beginner = 1 etc
     * -1, so level 1 makes no change, level 2 makes 1, and so on */
    id += user.fitnessLevel - 1;
    id += user.feecback;

    /* Adjust further based on preferences */
    if (strcmp(user.exercise_preferences, "At Home, Walking") == 0) {
        return id;
    } else if (strcmp(user.exercise_preferences, "At Home, Running") == 0) {
        return id + 1;
    } else if (strcmp(user.exercise_preferences, "At Home, Strength") == 0) {
        return id  + 2;
    } else if (strcmp(user.exercise_preferences, "At Home, Both") == 0) {
        return id + 3;
    } else if (strcmp(user.exercise_preferences, "Gym, Both") == 0) {
        return id + 4;
    }

    return id;

}


void retrieveWorkoutRecommendations(User user) {

    int id = calculateID(user);

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








/* void giveInitialRecommendation() {

    char goal[20], location[20], workoutType[20];
    /* Retrieve user fitness level (initial input module) */
    /*int fitnessLevel = calculateFitnessLevel();

    /* Retrieve user preferences (initial input module) */
    /*int preferences = getUserPreferences(goal, location, workoutType);

    /* Get workout recommendations based on user fitness level and preferences */
    /*retrieveWorkoutPlans();

    // Display the initial recommendations
    printf("\n--- Initial Workout Recommendations ---\n");
    displayRecommendations();

}

void giveAdaptedRecommendations() {

    int fitnesslevel;
    workoutRecommendations workouts[10];

    /* Calls feedback function from secondary input module */
    /*int feedback = getUserFeedback();

    /* Adjust recommendations based on feedback */
    /*if (feedback == 1) {
        printf("Finding easier workout recommendations...\n");
    } else if (feedback == 2) {
        printf("Finding harder workout recommendations...\n");
    } else {
        printf("Finding new, similar workout recommendations...\n");
    }
}
*/