// user.h
#ifndef USER_H
#define USER_H
#define MAX_LINE_LENGTH 1024

// Structure to hold user information
typedef struct {
    char name[100];
    int age;
    int gender; // 1 for male, 2 for female
    int height;
    float weight;
    int hip;
    int waist;
    int location; // 1 for home, 2 for gym
    int preferences; // 1 for running, 2 for walking, 3 for strength, 4 for combination
    char exercise_purpose[50];
    float fitness_assessment_bmi;
    float fitness_assessment_whr;
    int fitness_level;
    int recommendation_id;
} user_t;

// Function declarations
void print_user(user_t user);
user_t load_user(void);
void save_user(user_t user);
float calculate_bmi(int height, float weight);
const char* calculate_bmi_category(float bmi);
float calculate_whr(int waist, int hip);
void strip_newline_and_spaces(char *str);
void trim_newline(char *str);
user_t returning_user(const char *name);
void update_user_file(const char *name, int recommendation_id);


#endif // USER_H
