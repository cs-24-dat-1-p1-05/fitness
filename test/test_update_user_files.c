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

int buffer;
// Helper to compare file content line by line
void assert_file_content(const char *actual, const char *expected) {
    char actual_line[MAX_LINE_LENGTH];
    char expected_line[MAX_LINE_LENGTH];
    FILE *actual_stream = fmemopen((void *)actual, strlen(actual), "r");
    FILE *expected_stream = fmemopen((void *)expected, strlen(expected), "r");

    while (fgets(actual_line, sizeof(actual_line), actual_stream) &&
           fgets(expected_line, sizeof(expected_line), expected_stream)) {
        assert(strcmp(actual_line, expected_line) == 0);
    }

    assert(feof(actual_stream) && feof(expected_stream)); // Ensure both reached EOF
    fclose(actual_stream);
    fclose(expected_stream);

}



int main() {
    const char *name = "John Doe";   // Example name
    int recommendation_id = 12345;
    test_update_user_file(name, recommendation_id);
    return 0;
}
void test_update_user_file(const char *name, int recommendation_id) {
    FILE *file = fopen("users.txt", "r+");  // Open for reading and writing
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    long pos = -1;
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        pos = ftell(file);
        if (strncmp(line, "Name: ", 6) == 0 && strstr(line, name)) {
            found = 1;
            break;
        }
    }

    if (found) {
        // Move the file pointer back to where the recommendation ID is
        fseek(file, pos, SEEK_SET);
        while (fgets(line, sizeof(line), file)) {
            if (strncmp(line, "Recommendation ID: ", 19) == 0) {
                // Overwrite the recommendation ID line
                fseek(file, -strlen(line), SEEK_CUR);
                fprintf(file, "Recommendation ID: %d\n", recommendation_id);
                break;
            }
        }
    }

    fclose(file);
}