#include <stdio.h>
#include <string.h>
#include "user.h"
#include "workoutrecommendations.h"

#define MAX_
// Function to calculate BMI
float calculate_bmi(int height, float weight) {
    float height_in_meters = height / 100.0;
    return weight / (height_in_meters * height_in_meters);
}

// Function to categorize BMI
const char* calculate_bmi_category(float bmi) {
    if (bmi < 18.5) return "Underweight";
    if (bmi < 24.9) return "Normal weight";
    if (bmi < 29.9) return "Overweight";
    return "Obese";
}

// Function to calculate Waist-to-Hip Ratio (WHR)
float calculate_whr(int waist, int hip) {
    return (float)waist / hip;
}

// Function to print user details
void print_user(user_t user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Gender: %s\n", user.gender == 1 ? "Male" : "Female");
    printf("Height: %d cm\n", user.height);
    printf("Weight: %f kg\n", user.weight);
    printf("Hip: %d cm\n", user.hip);
    printf("Waist: %d cm\n", user.waist);
    printf("Location: %d\n", user.location);
    printf("Preferences: %d\n", user.preferences);
    printf("Exercise Purpose: %s\n", user.exercise_purpose);
    printf("Exercise Days per Week: %d\n", user.exercise_days_per_week);

    // Calculate and print BMI and category
    printf("Fitness Assessment (BMI): %.2f\n", user.fitness_assessment_bmi);
    printf("BMI Category: %s\n", calculate_bmi_category(user.fitness_assessment_bmi));

    // Calculate and print WHR and health risk
    printf("Fitness Assessment (WHR): %.2f\n", user.fitness_assessment_whr);
    if (user.gender == 1) {  // Male
        if (user.fitness_assessment_whr < 0.95) {
            printf("WHR Health Risk: Low\n");
        } else if (user.fitness_assessment_whr >= 0.95 && user.fitness_assessment_whr < 1.0) {
            printf("WHR Health Risk: Moderate\n");
        } else {
            printf("WHR Health Risk: High\n");
        }
    } else if (user.gender == 2) {  // Female
        if (user.fitness_assessment_whr < 0.80) {
            printf("WHR Health Risk: Low\n");
        } else if (user.fitness_assessment_whr >= 0.80 && user.fitness_assessment_whr < 0.85) {
            printf("WHR Health Risk: Moderate\n");
        } else {
            printf("WHR Health Risk: High\n");
        }
    }
    printf("Recommendation ID: %d\n", user.recommendation_id);
}

// Function to load user details
user_t load_user(void) {
    user_t new_user;

    printf("Please enter your name:\n");
    scanf("%s", new_user.name);

    printf("Please enter your age:\n");
    scanf("%d", &new_user.age);

    printf("Please enter your gender (1 for Male, 2 for Female):\n");
    scanf("%d", &new_user.gender);

    printf("Please enter your height (in cm):\n");
    scanf("%d", &new_user.height);

    printf("Please enter your weight (in kg):\n");
    scanf("%f", &new_user.weight);

    printf("Please enter your hip measurement (in cm):\n");
    scanf("%d", &new_user.hip);

    printf("Please enter your waist measurement (in cm):\n");
    scanf("%d", &new_user.waist);

    // Switch for Location
    printf("Please select your location:\n");
    printf("1. Home/outdoor (no equipment) \n2. Gym (with equipment)\n");
    int location_choice;
    scanf("%d", &location_choice);
    switch (location_choice) {
        case 1:
            new_user.location = 1;
            break;
        case 2:
            new_user.location = 2;
            break;
        default:
            new_user.location = 1; // Default to Home if input is invalid
            printf("Invalid choice, defaulting to Home.\n");
            break;
    }

    // Switch for Preferences
    printf("Please select your exercise preferences:\n");
    printf("1. Running\n2. Walking\n3. Strength training\n4. Combination\n");
    int preferences_choice;
    scanf("%d", &preferences_choice);
    switch (preferences_choice) {
        case 1:
            new_user.preferences = 1;
            break;
        case 2:
            new_user.preferences = 2;
            break;
        case 3:
            new_user.preferences = 3;
            break;
        case 4:
            new_user.preferences = 4;
            break;
        default:
            new_user.preferences = 3; // Default to Combination if input is invalid
            printf("Invalid choice, defaulting to Combination.\n");
            break;
    }

    // Switch for Exercise Purpose
    printf("Please select your exercise purpose:\n");
    printf("1. Weight Loss\n2. Muscle Gain\n3. Enhance cardio\n4. General Health\n\n");
    int exercise_purpose_choice;
    scanf("%d", &exercise_purpose_choice);
    switch (exercise_purpose_choice) {
        case 1:
            strcpy(new_user.exercise_purpose, "Weight Loss");
            break;
        case 2:
            strcpy(new_user.exercise_purpose, "Muscle Gain");
            break;
        case 3:
            strcpy(new_user.exercise_purpose, "Improve Cardio");
            break;
        case 4:
            strcpy(new_user.exercise_purpose, "General Health");
        break;
        default:
            strcpy(new_user.exercise_purpose, "General Health"); // Default to General Health if input is invalid
            printf("Invalid choice, defaulting to General Health.\n");
            break;
    }

    printf("Please enter how many days you exercise per week:\n");
    scanf("%d", &new_user.exercise_days_per_week);

    // Calculate BMI and WHR
    new_user.fitness_assessment_bmi = calculate_bmi(new_user.height, new_user.weight);
    new_user.fitness_assessment_whr = calculate_whr(new_user.waist, new_user.hip);
    new_user.fitness_level = calculate_fitness_level(new_user);
    new_user.recommendation_id = calculate_id(new_user);

    new_user.feedback = 0;

    return new_user;
}

// Function to save user details to a text file
void save_user(user_t user) {
    FILE *file = fopen("users.txt", "a"); // Open file in append mode
    if (file == NULL) {
        printf("Error: Could not open file to save data.\n");
        return;
    }

    // Write user details to the file
    fprintf(file, "Name: %s\n", user.name);
    fprintf(file, "Age: %d\n", user.age);
    fprintf(file, "Gender: %s\n", user.gender == 1 ? "Male" : "Female");
    fprintf(file, "Height: %d cm\n", user.height);
    fprintf(file, "Weight: %f kg\n", user.weight);
    fprintf(file, "Hip: %d cm\n", user.hip);
    fprintf(file, "Waist: %d cm\n", user.waist);
    fprintf(file, "Location: %d\n", user.location);
    fprintf(file, "Preferences: %d\n", user.preferences);
    fprintf(file, "Exercise Purpose: %s\n", user.exercise_purpose);
    fprintf(file, "Exercise Days per Week: %d\n", user.exercise_days_per_week);
    fprintf(file, "Fitness Assessment (BMI): %.2f\n", user.fitness_assessment_bmi);
    fprintf(file, "BMI Category: %s\n", calculate_bmi_category(user.fitness_assessment_bmi));
    fprintf(file, "Fitness Assessment (WHR): %.2f\n", user.fitness_assessment_whr);
    if (user.gender == 1) {  // Male
        if (user.fitness_assessment_whr < 0.95) {
            fprintf(file, "WHR Health Risk: Low\n");
        } else if (user.fitness_assessment_whr >= 0.95 && user.fitness_assessment_whr < 1.0) {
            fprintf(file, "WHR Health Risk: Moderate\n");
        } else {
            fprintf(file, "WHR Health Risk: High\n");
        }
    } else if (user.gender == 2) {  // Female
        if (user.fitness_assessment_whr < 0.80) {
            fprintf(file, "WHR Health Risk: Low\n");
        } else if (user.fitness_assessment_whr >= 0.80 && user.fitness_assessment_whr < 0.85) {
            fprintf(file, "WHR Health Risk: Moderate\n");
        } else {
            fprintf(file, "WHR Health Risk: High\n");
        }
    }
    fprintf(file, "Recommendation ID: %d\n", user.recommendation_id);
    fprintf(file, "\n----------------------------\n");

    fclose(file);  // Close the file
}

// Function to remove trailing newline or spaces
void strip_newline_and_spaces(char *str) {
    // Remove trailing newline, if any
    str[strcspn(str, "\n")] = 0;

    // Remove trailing spaces
    int len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t')) {
        str[len - 1] = '\0';
        len--;
    }
}

// Function to handle returning user logic
user_t returning_user(const char *name) {
    user_t user = {0};
    FILE *file = fopen("users.txt", "r");  // Open file in read mode
    if (file == NULL) {
        printf("Error: Could not open file to read data.\n");
        return user;
    }

    char line[MAX_LINE_LENGTH];
    int user_found = 0;

    // Loop through each line in the file
    while (fgets(line, sizeof(line), file)) {
        strip_newline_and_spaces(line);  // Clean up the line

        // Look for a match with the name
        if (strstr(line, name) != NULL) {
            user_found = 1;
            printf("User Found: %s\n", name);

            // Print all details of the found user
            do {
                printf("%s\n", line);
            } while (fgets(line, sizeof(line), file) && line[0] != '\n');
            break;
        }
    }

    fclose(file);  // Close the file

    if (!user_found) {
        printf("User not found!\n");
    }

    return user;
}
void display_recommendation(int recommendation_id) {
    FILE *file = fopen("recommendations.txt", "r");
    if (!file) {
        printf("Error opening recommendations file.\n");
        return;
    }

    char line[256];
    int current_id = 0;
    int is_in_recommendation = 0;

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#') {
            current_id++;
        }

        if (current_id == recommendation_id) {
            // Print the recommendation
            printf("%s", line);
            is_in_recommendation = 1;
        }

        // After printing the recommendation, print until we hit the next recommendation ID.
        if (current_id == recommendation_id && line[0] == '#') {
            break;
        }
    }

    if (!is_in_recommendation) {
        printf("No recommendation found with ID %d\n", recommendation_id);
    }

    fclose(file);
}