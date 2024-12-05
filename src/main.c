#include "workoutrecommendations.h"
#include <stdio.h>
#include <string.h>

int main(void) {

    int main() {
        User user;

        /* Exampel */
        printf("Welcome to the fitness trainer!\n");

        /* Collect user input */
        user = load_user();

        /* Calculate fitness level and get feedback */
        user.fitnessLevel = calculateFitnessLevel(user);
        user.feedback = getUserFeedback();

        // Fetch and display workout recommendations
        retrieveWorkoutRecommendations(user);

        return 0;
    }


    //giveInitialRecommendations();

    //giveAdaptedRecommendations();

    return 0;
}