#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototype for the display_recommendation function
void display_recommendation(int recommendation_id);

int main() {
    // Creating a mock "recommendations.txt" file for testing
    FILE *file = fopen("recommendations.txt", "w");
    if (!file) {
        printf("Error creating recommendations file.\n");
        return 1;
    }

    // Writing some mock recommendations data to the file
    fprintf(file, "#ID 1\n");
    fprintf(file, "This is recommendation 1.\n");
    fprintf(file, "Additional details for recommendation 1.\n");
    fprintf(file, "#ID 2\n");
    fprintf(file, "This is recommendation 2.\n");
    fprintf(file, "Additional details for recommendation 2.\n");
    fprintf(file, "#ID 3\n");
    fprintf(file, "This is recommendation 3.\n");
    fprintf(file, "Additional details for recommendation 3.\n");

    fclose(file);

    // Test case 1: Display recommendation with ID 1
    printf("Test Case 1: Display recommendation ID 1\n");
    display_recommendation(1);
    printf("\n");

    // Test case 2: Display recommendation with ID 2
    printf("Test Case 2: Display recommendation ID 2\n");
    display_recommendation(2);
    printf("\n");

    // Test case 3: Display recommendation with ID 3
    printf("Test Case 3: Display recommendation ID 3\n");
    display_recommendation(3);
    printf("\n");

    // Test case 4: Test a non-existing recommendation ID
    printf("Test Case 4: Display recommendation ID 4 (non-existing)\n");
    display_recommendation(4);
    printf("\n");

    // Test case 5: Test an empty file (remove recommendations.txt before this test)
    // To simulate an empty file, delete "recommendations.txt" before running this test
    remove("recommendations.txt");
    printf("Test Case 5: Display recommendation with an empty file\n");
    display_recommendation(1);
    printf("\n");

    return 0;
}
