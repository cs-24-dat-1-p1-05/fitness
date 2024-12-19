#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "user.h"


// Mock implementation of calculate_bmi_category


// Function to test
void save_user(user_t user);

void test_save_user() {
    // Test setup: Prepare a user_t object
    user_t test_user = {
        .name = "John Doe",
        .age = 30,
        .gender = 1,
        .height = 175,
        .weight = 70.5,
        .hip = 90,
        .waist = 80,
        .location = 101,
        .preferences = 3,
        .exercise_purpose = "General Fitness",
        .fitness_assessment_bmi = 23.0,
        .fitness_assessment_whr = 0.88,
        .recommendation_id = 42
    };

    // Test action: Call the function to save user data
    save_user(test_user);

    // Verify the results: Read the file and check its content
    FILE *file = fopen("users.txt", "r");
    assert(file != NULL && "users.txt file should exist after save_user");

    char buffer[256];
    int found_name = 0, found_age = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, "Name: John Doe")) {
            found_name = 1;
        }
        if (strstr(buffer, "Age: 30")) {
            found_age = 1;
        }
    }

    fclose(file);

    // Assertions
    assert(found_name && "Name was not found in the file");
    assert(found_age && "Age was not found in the file");

    printf("Test passed: save_user function works as expected.\n");
}

int main() {
    // Run the test
    test_save_user();

    // Clean up after the test
    remove("users.txt");

    return 0;
}
