#include "user.h"

// Functions declarations
int select_assessment(int activity, int location);
int cooper_test(void);
int strength_training_with_equipment(void);
int strength_training_without_equipment(void);
int walking_test(void);
int calculate_id(user_t user);
int calculate_fitness_level(user_t user);
int get_user_feedback();
void display_recommendation(int recommendation_id);
int adjust_recommendation(user_t *user, int feedback);
