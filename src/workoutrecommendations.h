
/* struct to hold workout plan */
typedef struct {
    int id;
    char name[50];
    char recommendations[1000];
} workoutRecommendations;

/* Workout recommendation functions */


void retrieveWorkoutRecommendations(User user);
int calculateID(User user);

/* Functions from other modules */
/* Function to calculate fitness level based on BMI, WTH and fitness assessment*/
int calculateFitnessLevel();

/* Function to get feedback from recurring user*/
int getUserFeedback();

/* Function to get preferences - goals, location, type of workout */
// int getUserPreferences();

//void giveInitialRecommendations();
//void giveAdaptedRecommendations();
//void displayRecommendations(workoutRecommendations *plan);


