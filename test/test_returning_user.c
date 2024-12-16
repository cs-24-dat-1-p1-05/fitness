#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "user.h"
int found = 0;


// Helper function to create a mock users.txt file
void create_mock_users_file(const char *content) {
    FILE *file = fopen("users.txt", "w");
    if (file != NULL) {
        fprintf(file, "%s", content);
        fclose(file);
    } else {
        perror("Failed to create mock users.txt");
    }
}

// Cleanup function to delete the mock users.txt file
void remove_mock_users_file() {
    remove("users.txt");
}

// Test for a user that exists in the file
void test_user_found() {
    // Mock data
    const char *mock_data =
        "Name: John Doe\n"
        "Age: 30\n"
        "Gender: Male\n"
        "Height: 180 cm\n"
        "Weight: 75.5\n"
        "Hip: 95 cm\n"
        "Waist: 80 cm\n"
        "Location: 123\n"
        "Preferences: 456\n"
        "Exercise Purpose: General Fitness\n"
        "Exercise Days per Week: 3\n"
        "Fitness Assessment (BMI): 23.3\n"
        "Fitness Assessment (WHR): 0.84\n"
        "Recommendation ID: 1\n"
        "----------------------------\n";

    create_mock_users_file(mock_data);

    // Call the function to test
    user_t user = returning_user("John Doe");

    // Assertions to verify user fields
    assert(strcmp(user.name, "John Doe") == 0);
    assert(user.age == 30);
    assert(user.gender == 1);  // Assuming Male = 1
    assert(user.height == 180);
    assert(user.weight == 75.5f);
    assert(user.hip == 95);
    assert(user.waist == 80);
    assert(user.location == 123);
    assert(user.preferences == 456);
    assert(strcmp(user.exercise_purpose, "General Fitness") == 0);
    assert(user.exercise_days_per_week == 3);
    assert(user.fitness_assessment_bmi == 23.3f);
    assert(user.fitness_assessment_whr == 0.84f);
    assert(user.recommendation_id == 1);

    printf("Test user_found passed.\n");

    remove_mock_users_file();
}

// Test for a user that does not exist in the file
void test_user_not_found() {
    // Mock data with a different user
    const char *mock_data =
        "Name: Jane Smith\n"
        "Age: 25\n"
        "Gender: Female\n"
        "----------------------------\n";

    create_mock_users_file(mock_data);

    // Call the function to test
    user_t user = returning_user("Nonexistent User");

    // Assertions to verify default user values
    assert(strcmp(user.name, "") == 0);
    assert(user.age == 0);
    assert(user.gender == 0);
    assert(user.height == 0);
    assert(user.weight == 0.0f);
    assert(user.hip == 0);
    assert(user.waist == 0);
    assert(user.location == 0);
    assert(user.preferences == 0);
    assert(strcmp(user.exercise_purpose, "") == 0);
    assert(user.exercise_days_per_week == 0);
    assert(user.fitness_assessment_bmi == 0.0f);
    assert(user.fitness_assessment_whr == 0.0f);
    assert(user.recommendation_id == -1);

    printf("Test user_not_found passed.\n");

    remove_mock_users_file();
}

// Main function to run all tests
int main() {
    test_user_found();
    test_user_not_found();
    printf("All tests passed!\n");
    return 0;
}
