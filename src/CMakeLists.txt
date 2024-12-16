
add_executable(fitness main.c workoutrecommendations.c user.c
       )

add_library(recommendation workoutrecommendations.c user.c)
target_include_directories(recommendation PUBLIC  .)
