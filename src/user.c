#include <stdio.h>
#include <string.h>
#include "user.h"

#include <stdlib.h>

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
void trim_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}
// Function to handle returning user logic
user_t returning_user(const char *name) {
    FILE *file = fopen("users.txt", "r");
    user_t user;
    char line[256];
    int found = 0;

    if (file == NULL) {
        printf("Error: Unable to open user data file.\n");
        exit(1);
    }

    // Initialize user with default values in case not found
    user_t not_found_user = {"", 0, 0, 0, 0, 0, 0, 0, 0, "", 0, 0, 0, -1};

    while (fgets(line, sizeof(line), file)) {
        trim_newline(line);

        // Check for the "Name" line
        if (strncmp(line, "Name: ", 6) == 0) {
            char user_name[50];
            strcpy(user_name, line + 6); // Extract name after "Name: "

            if (strcasecmp(user_name, name) == 0) {
                // Name matches; start parsing the user details
                strcpy(user.name, user_name);
                found = 1;

                // Read the rest of the user's data
                while (fgets(line, sizeof(line), file) && strncmp(line, "----------------------------", 28) != 0) {
                    trim_newline(line);

                    if (sscanf(line, "Age: %d", &user.age) == 1) continue;
                    if (strstr(line, "Gender: ") && strstr(line, "Female")) {
                        user.gender = 0;  // Assuming Female = 0
                        continue;
                    } else if (strstr(line, "Gender: ") && strstr(line, "Male")) {
                        user.gender = 1;  // Assuming Male = 1
                        continue;
                    }
                    if (sscanf(line, "Height: %d cm", &user.height) == 1) continue;
                    if (sscanf(line, "Weight: %f", &user.weight) == 1) continue;
                    if (sscanf(line, "Hip: %d cm", &user.hip) == 1) continue;
                    if (sscanf(line, "Waist: %d cm", &user.waist) == 1) continue;
                    if (sscanf(line, "Location: %d", &user.location) == 1) continue;
                    if (sscanf(line, "Preferences: %d", &user.preferences) == 1) continue;
                    if (sscanf(line, "Exercise Purpose: %49[^\n]", user.exercise_purpose) == 1) continue;
                    if (sscanf(line, "Exercise Days per Week: %d", &user.exercise_days_per_week) == 1) continue;
                    if (sscanf(line, "Fitness Assessment (BMI): %f", &user.fitness_assessment_bmi) == 1) continue;
                    if (sscanf(line, "Fitness Assessment (WHR): %f", &user.fitness_assessment_whr) == 1) continue;
                    if (sscanf(line, "Recommendation ID: %d", &user.recommendation_id) == 1) continue;
                }

                // Exit the loop as the user is found
                break;
            }
        }
    }

    fclose(file);

    // If the user is not found, return a default user
    if (!found) {
        return not_found_user;
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