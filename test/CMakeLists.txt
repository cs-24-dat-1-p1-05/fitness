add_executable(test_load_user test_load_user.c)
add_executable(test_save_user test_save_user.c)
add_executable(test_returning_user test_returning_user.c)
add_executable(test_update_user_files test_update_user_files.c)
add_executable(test_calculate_id
        test_calculate_id.c)
add_executable(test_display_recommendation
        test_display_recommendation.c)
add_executable(test_adjust_recommendation
        test_adjust_recommendation.c)
add_executable(test_2 test.c)


target_link_libraries(test_load_user recommendation)
target_link_libraries(test_save_user recommendation)
target_link_libraries(test_returning_user recommendation)
target_link_libraries(test_update_user_files recommendation)
target_link_libraries(test_calculate_id recommendation)
target_link_libraries(test_display_recommendation recommendation)
target_link_libraries(test_adjust_recommendation recommendation)
target_link_libraries(test_2 recommendation)


# Optionally, add a custom target for running tests
add_custom_target(run_tests COMMAND test_load_user test_save_user test_returning_user test_update_user_files test_calculate_id test_display_recommendation test_adjust_recommendation)
add_custom_target(final_test COMMAND test_2)