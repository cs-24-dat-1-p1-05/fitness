#include <stdio.h>
#include <stdlib.h>
#include "user.h"

int main(void) {
    printf("Welcome to the fitness trainer\n");

    char response;
    printf("Are you a new user? y/n: ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        printf("\nGreat! Let's set up your profile.\n");
        user_t user = load_user();
        printf("\nThank you for entering your details!\n");
        print_user(user);

        save_user(user);
    } else if (response == 'n' || response == 'N') {
        char name[50];
        printf("\nPlease enter your name: ");
        scanf("%s", name);

        printf("\nWelcome back, %s!\n", name);
        returning_user(name);
    } else {
        printf("\nInvalid input. Please restart the program and try again.\n");
    }

    return 0;
}
