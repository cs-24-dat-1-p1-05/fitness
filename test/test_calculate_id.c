#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "workoutrecommendations.h"
#include "user.h"

// Define the structure user_t

// Function to test


void test_calculate_id() {
    // Test case 1: Weight Loss, Fitness Level 1, Preferences 1, Location 1
    user_t user1 = {"",0, 0,0,0,0,0,1,1,"Weight Loss",0,0,1};
    int result1 = calculate_id(user1);
    printf("Test 1: Expected: 2, Got: %d\n", result1);
    assert(result1 == 2);  // id = 1 + 0 + 1 = 2

    // Test case 2: Muscle Gain, Fitness Level 2, Preferences 2, Location 2
    user_t user2 = {"", 0, 0, 0, 0, 0, 0,2,2,"Muscle Gain",0,0,2};
    int result2 = calculate_id(user2);
    assert(result2 == 24);  // id = 19 + 2 + 3 = 24

    // Test case 3: Improve Cardio, Fitness Level 2, Preferences 3, Location 1
    user_t user3 = {"", 0, 0, 0, 0, 0, 0,1,3,"Improve Cardio",0,0,2};
    int result3 = calculate_id(user3);
    assert(result3 == 45);  // id = 37 + 2 + 6 = 46

    // Test case 4: General Health, Fitness Level 2, Preferences 4, Location 2
    user_t user4 = {"", 0, 0, 0, 0, 0, 0,2,4,"General Health",0,0,2};
    int result4 = calculate_id(user4);
    assert(result4 == 72);  // id = 55 + 2 + 15 = 72

    // Test case 5: Muscle Gain, Fitness Level 1, Preferences 3, Location 2
    user_t user5 = {"", 0, 0, 0, 0, 0, 0,2,3,"Muscle Gain",0,0,1};
    int result5 = calculate_id(user5);
    assert(result5 == 29);  // id = 19 + 1 + 9 = 29

    // Test case 6: Improve Cardio, Fitness Level 2, Preferences 4, Location 1
    user_t user6 = {"", 0, 0, 0, 0, 0, 0,1,4,"Improve Cardio",0,0,2};
    int result6 = calculate_id(user6);
    assert(result6 == 51);  // id = 37 + 2 + 12 = 51

    // Test case 7: Weight Loss, Fitness Level 2, Preferences 2, Location 1
    user_t user7 = {"", 0, 0, 0, 0, 0, 0,1,2,"Weight Loss",0,0,2};
    int result7 = calculate_id(user7);
    assert(result7 == 6);  // id = 1 + 2 + 3 = 6

    printf("All tests passed!\n");
}

int main() {
    test_calculate_id();
    return 0;
}
