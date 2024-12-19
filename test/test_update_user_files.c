#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LINE_LENGTH 256

// Include the function being tested
void update_user_file(const char *name, int recommendation_id);

// Helper function to set up a test file
void create_test_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error creating test file");
        exit(EXIT_FAILURE);
    }
    fputs(content, file);
    fclose(file);
}

// Helper function to read the content of a file into a string
char *read_file_content(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error reading test file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);

    char *content = malloc(length + 1);
    if (!content) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    fread(content, 1, length, file);
    content[length] = '\0';
    fclose(file);
    return content;
}

void test_update_user_file() {
    // Test setup: Initial file content
    const char *initial_content =
        "Name: Alice\n"
        "Recommendation ID: 123\n"
        "Name: Bob\n"
        "Age: 30\n";

    const char *expected_content_after_update =
        "Name: Alice\n"
        "Recommendation ID: 456\n"
        "Name: Bob\n"
        "Age: 30\n";

    const char *expected_content_after_add =
        "Name: Alice\n"
        "Recommendation ID: 123\n"
        "Name: Bob\n"
        "Age: 30\n"
        "Recommendation ID: 456\n";

    // Create a test file
    create_test_file("users.txt", initial_content);

    // Test case 1: Update existing recommendation ID for Alice
    update_user_file("Alice", 456);

    // Verify the result
    char *result_content = read_file_content("users.txt");
    assert(strcmp(result_content, expected_content_after_update) == 0);
    free(result_content);

    // Reset the test file
    create_test_file("users.txt", initial_content);

    // Test case 2: Add a new recommendation ID for Bob
    update_user_file("Bob", 456);

    // Verify the result
    result_content = read_file_content("users.txt");
    assert(strcmp(result_content, expected_content_after_add) == 0);
    free(result_content);

    printf("All test cases passed!\n");
}

int main() {
    test_update_user_file();
    return 0;
}
