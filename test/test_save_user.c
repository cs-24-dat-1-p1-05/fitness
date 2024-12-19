#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "workoutrecommendations.h"

void test_save_user() {
    // Create a user for testing
    user_t test_user = {
        .name = "John",
        .age = 25,
        .gender = 1,
        .height = 180,
        .weight = 75.5f,
        .hip = 90,
        .waist = 80,
        .location = 2,
        .preferences = 3,
    };
    strcpy(test_user.exercise_purpose, "Weight Loss");
    test_user.fitness_assessment_bmi = calculate_bmi(test_user.height, test_user.weight);
    test_user.fitness_assessment_whr = calculate_whr(test_user.waist, test_user.hip);
    test_user.recommendation_id = calculate_id(test_user);

    // Expected output string
    char expected_output[] =
        "Name: John\n"
        "Age: 25\n"
        "Gender: Male\n"
        "Height: 180 cm\n"
        "Weight: 75.500000 kg\n"
        "Hip: 90 cm\n"
        "Waist: 80 cm\n"
        "Location: 2\n"
        "Preferences: 3\n"
        "Exercise Purpose: Weight Loss\n"
        "Fitness Assessment (BMI): %.2f\n"
        "BMI Category: %s\n"
        "Fitness Assessment (WHR): %.2f\n"
        "WHR Health Risk: %s\n"
        "Recommendation ID: %d\n"
        "----------------------------\n";

    // File handling
    const char *filename = "test_users.txt";
    if (freopen(filename, "w", stdout) == NULL) {
        perror("Error redirecting stdout to file");
        exit(EXIT_FAILURE);
    }

    // Call save_user function
    save_user(test_user);

    // Restore stdout
    fclose(stdout);

    // Read the output from the file
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening test file");
        exit(EXIT_FAILURE);
    }

    char output[1024] = {0};
    fread(output, sizeof(char), sizeof(output) - 1, file);
    fclose(file);

    // Create the expected string dynamically
    char bmi_category[50];
    strcpy(bmi_category, calculate_bmi_category(test_user.fitness_assessment_bmi));
    char whr_health_risk[50];
    if (test_user.gender == 1) {
        if (test_user.fitness_assessment_whr < 0.95) {
            strcpy(whr_health_risk, "Low");
        } else if (test_user.fitness_assessment_whr >= 0.95 && test_user.fitness_assessment_whr < 1.0) {
            strcpy(whr_health_risk, "Moderate");
        } else {
            strcpy(whr_health_risk, "High");
        }
    } else {
       if (test_user.fitness_assessment_whr < 0.80) {
            strcpy(whr_health_risk, "Low");
       } else if (test_user.fitness_assessment_whr >= 0.80 && test_user.fitness_assessment_whr < 0.85) {
            strcpy(whr_health_risk, "Moderate");
       } else {
            strcpy(whr_health_risk, "High");
       }
    }

    char expected[1024];
    snprintf(expected, sizeof(expected), expected_output,
             test_user.fitness_assessment_bmi, bmi_category,
             test_user.fitness_assessment_whr, whr_health_risk,
             test_user.recommendation_id);

    // Compare the output
    if (strcmp(output, expected) != 0) {
        printf("Test failed! Expected:\n%s\nGot:\n%s\n", expected, output);
        exit(EXIT_FAILURE);
    }

    printf("Test passed!\n");

    // Cleanup
    remove(filename);
}

int main() {
    // Just call test_save_user without passing any arguments
    test_save_user();
    return 0;
}
