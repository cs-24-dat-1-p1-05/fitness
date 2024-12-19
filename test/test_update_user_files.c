#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LINE_LENGTH 256

// The function under test
void test_update_user_file(const char *name, int recommendation_id);

// Helper to create a test file
void create_test_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error creating test file");
        exit(EXIT_FAILURE);
    }
    fputs(content, file);
    fclose(file);
}

// Helper to read the contents of a file into a buffer
void read_file_contents(const char *filename, char *buffer, size_t buffer_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error reading test file");
        exit(EXIT_FAILURE);
    }
    fread(buffer, 1, buffer_size - 1, file);
    buffer[buffer_size - 1] = '\0';
    fclose(file);
}

// Helper to compare file content line by line
void assert_file_content(const char *actual, const char *expected) {
    // Print lengths of both strings
    printf("Length of actual content: %zu\n", strlen(actual));
    printf("Length of expected content: %zu\n", strlen(expected));

    char actual_line[MAX_LINE_LENGTH];
    char expected_line[MAX_LINE_LENGTH];
    FILE *actual_stream = fmemopen((void *)actual, strlen(actual), "r");
    FILE *expected_stream = fmemopen((void *)expected, strlen(expected), "r");

    int line_number = 1;
    while (fgets(actual_line, sizeof(actual_line), actual_stream) &&
           fgets(expected_line, sizeof(expected_line), expected_stream)) {
        // Print the actual and expected lines with added markers for visibility
        printf("Actual Line %d: '%s'\n", line_number, actual_line);
        printf("Expected Line %d: '%s'\n", line_number, expected_line);

        if (strcmp(actual_line, expected_line) != 0) {
            printf("Mismatch at line %d:\n", line_number);
            printf("Actual:   '%s'\n", actual_line);
            printf("Expected: '%s'\n", expected_line);
            assert(0); // Trigger assertion failure
        }
        line_number++;
           }

    // Check for EOF in both streams
    if (!(feof(actual_stream) && feof(expected_stream))) {
        printf("File length mismatch. Remaining content:\n");
        if (!feof(actual_stream)) {
            printf("Actual (remaining):\n");
            while (fgets(actual_line, sizeof(actual_line), actual_stream)) {
                printf("'%s'", actual_line);
            }
        }
        if (!feof(expected_stream)) {
            printf("Expected (remaining):\n");
            while (fgets(expected_line, sizeof(expected_line), expected_stream)) {
                printf("'%s'", expected_line);
            }
        }
        assert(0); // Trigger assertion failure
    }

    fclose(actual_stream);
    fclose(expected_stream);
}



int main() {
    const char *initial_content = "Name: John Doe\nRecommendation ID: 123\n";
    const char *expected_content = "Name: John Doe\nRecommendation ID: 12345\n";

    // Create test file with initial content
    create_test_file("users.txt", initial_content);

    // Update file
    const char *name = "John Doe";
    int recommendation_id = 12345;
    test_update_user_file(name, recommendation_id);

    // Verify the file content
    char buffer[1024];
    read_file_contents("users.txt", buffer, sizeof(buffer));

    printf("Updated file content:\n%s", buffer);
    assert_file_content(buffer, expected_content);

    printf("Test passed successfully.\n");
    return 0;
}



void test_update_user_file(const char *name, int recommendation_id) {
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    char temp_content[1024] = ""; // Buffer to hold the updated file content
    int found = 0;

    // Read and update lines in memory
    while (fgets(line, sizeof(line), file)) {
        printf("Read line: '%s'\n", line);  // Debug output

        if (!found && strncmp(line, "Name: ", 6) == 0 && strstr(line, name)) {
            strcat(temp_content, line); // Add the name line
            fgets(line, sizeof(line), file); // Read the next line (Recommendation ID)
            sprintf(line, "Recommendation ID: %d\n", recommendation_id); // Update it
            found = 1;
        }
        strcat(temp_content, line); // Add the line to temp_content
    }

    fclose(file);

    // Debug output of the entire updated content
    printf("Updated content:\n%s\n", temp_content);

    // Write updated content back to the file
    file = fopen("users.txt", "w");
    if (!file) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fputs(temp_content, file);
    fclose(file);
}


