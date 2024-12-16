#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "workoutrecommendations.h"

void test_load_user() {
    // Simulate user input by redirecting stdin
    FILE *input = freopen("input.txt", "w", stdin);
    if (!input) {
        perror("Error creating input.txt");
        exit(EXIT_FAILURE);
    }

    // Write test input to simulate user interaction
    fprintf(input, "John\n25\n1\n180\n75.5\n90\n80\n2\n3\n1\n5\n");
    fclose(input);

    input = freopen("input.txt", "r", stdin);
    if (!input) {
        perror("Error opening input.txt");
        exit(EXIT_FAILURE);
    }

    // Load user data
    user_t test_user = load_user();

    // Validate results
    if (strcmp(test_user.name, "John") != 0) {
        printf("Test failed: name mismatch. Expected: John, Got: %s\n", test_user.name);
        exit(EXIT_FAILURE);
    }
    if (test_user.age != 25) {
        printf("Test failed: age mismatch. Expected: 25, Got: %d\n", test_user.age);
        exit(EXIT_FAILURE);
    }
    if (test_user.gender != 1) {
        printf("Test failed: gender mismatch. Expected: 1 (Male), Got: %d\n", test_user.gender);
        exit(EXIT_FAILURE);
    }
    if (test_user.height != 180) {
        printf("Test failed: height mismatch. Expected: 180, Got: %d\n", test_user.height);
        exit(EXIT_FAILURE);
    }
    if (test_user.weight != 75.5f) {
        printf("Test failed: weight mismatch. Expected: 75.5, Got: %.2f\n", test_user.weight);
        exit(EXIT_FAILURE);
    }
    if (test_user.hip != 90) {
        printf("Test failed: hip mismatch. Expected: 90, Got: %d\n", test_user.hip);
        exit(EXIT_FAILURE);
    }
    if (test_user.waist != 80) {
        printf("Test failed: waist mismatch. Expected: 80, Got: %d\n", test_user.waist);
        exit(EXIT_FAILURE);
    }
    if (test_user.location != 2) {
        printf("Test failed: location mismatch. Expected: 2 (Gym), Got: %d\n", test_user.location);
        exit(EXIT_FAILURE);
    }
    if (test_user.preferences != 3) {
        printf("Test failed: preferences mismatch. Expected: 3 (Strength Training), Got: %d\n", test_user.preferences);
        exit(EXIT_FAILURE);
    }
    if (strcmp(test_user.exercise_purpose, "Weight Loss") != 0) {
        printf("Test failed: exercise purpose mismatch. Expected: Weight Loss, Got: %s\n", test_user.exercise_purpose);
        exit(EXIT_FAILURE);
    }

    // Verify BMI, WHR, and other calculated values (assuming example calculations are available)
    float expected_bmi = calculate_bmi(180, 75.5);
    if (test_user.fitness_assessment_bmi != expected_bmi) {
        printf("Test failed: BMI mismatch. Expected: %.2f, Got: %.2f\n", expected_bmi, test_user.fitness_assessment_bmi);
        exit(EXIT_FAILURE);
    }

    float expected_whr = calculate_whr(80, 90);
    if (test_user.fitness_assessment_whr != expected_whr) {
        printf("Test failed: WHR mismatch. Expected: %.2f, Got: %.2f\n", expected_whr, test_user.fitness_assessment_whr);
        exit(EXIT_FAILURE);
    }

    // Assuming calculate_id is deterministic for the input
    int expected_id = calculate_id(test_user);
    if (test_user.recommendation_id != expected_id) {
        printf("Test failed: Recommendation ID mismatch. Expected: %d, Got: %d\n", expected_id, test_user.recommendation_id);
        exit(EXIT_FAILURE);
    }

    printf("All tests passed!\n");

    // Cleanup
    fclose(input);
    remove("input.txt");
}

int main() {
    test_load_user();
    return 0;
}
