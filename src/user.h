#ifndef user_H
#define user_H

// Structure for user information
typedef struct {
    char name[50];
    int age;
    int gender;
    int height;  // in cm
    int weight;  // in kg
    int hip;     // in cm
    int waist;   // in cm
    int location;
    int preferences;
    char exercise_purpose[50];
    int exercise_days_per_week;
    float fitness_assessment_bmi;
    float fitness_assessment_whr;
} user_t;

// Function prototypes
float calculate_bmi(int height, int weight);  // Calculate BMI
const char* calculate_bmi_category(float bmi); // Categorize BMI
float calculate_whr(int waist, int hip);      // Calculate WHR
void print_user(user_t user);                 // Print user details
user_t load_user(void);                       // Load user details from input
void save_user(user_t user);                  // Save user data to a file
int returning_user(char *name);               // Load and print details of a returning user

#endif
