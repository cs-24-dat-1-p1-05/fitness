add_executable(test_load_user test_load_user.c user.c workoutrecommendations.c)
add_executable(test_save_user test_save_user.c user.c workoutrecommendations.c)
add_executable(test_returning_user test_returning_user.c user.c workoutrecommendations.c)
add_executable(test_update_user_files test_update_user_files.c user.c workoutrecommendations.c)
add_executable(test_calculate_id user.c workoutrecommendations.c
        test_calculate_id.c)
add_executable(test_display_recommendation user.c workoutrecommendations.c
        test_display_recommendation.c)
add_executable(test_adjust_recommendation user.c workoutrecommendations.c
        test_adjust_recommendation.c)

# Optionally, add a custom target for running tests
add_custom_target(run_tests COMMAND test_load_user test_save_user test_returning_user test_update_user_files test_calculate_id test_display_recommendation test_adjust_recommendation)