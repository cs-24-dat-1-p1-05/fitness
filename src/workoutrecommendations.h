#include "user.h"

/* struct to hold workout plan */
typedef struct {
    int id;
    char name[50];
    char recommendations[1000];
} workout_recommendations;

/* Workout recommendation functions */

int cooper_test(void);
int strength_training_with_equipment(void);
int strength_training_without_equipment(void);
int walking_test(void);
int select_assessment(int activity, int location);
int calculate_id(user_t user);
char* retrieve_workoutrecommendations(int recommendation_id);
int get_user_feedback(void);

/* Functions from other modules */
/* Function to calculate fitness level based on BMI, WTH and fitness assessment*/
int calculate_fitness_level(user_t user);

/* Function to get feedback from recurring user*/
int get_user_feedback();

/* Function to get preferences - goals, location, type of workout */
// int getUserPreferences();

//void giveInitialRecommendations();
//void giveAdaptedRecommendations();
//void displayRecommendations(workoutRecommendations *plan);


