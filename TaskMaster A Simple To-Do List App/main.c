/*
Author: [Islam Gomaa]
Description: [To Do List App]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "fun.h"


// Main function
int main(void) {
    char user[6], pass[6];
    const char stored_user[6] = "admin";
    const char stored_pass[6] = "admin";
    int compare_user, compare_password;

    printf("*******************************************\n");
    printf("* Welcome to the To-Do List App           *\n");
    printf("*******************************************\n");

    // Authentication loop for username
    while (1) {
        printf("Enter your username: ");
        gets(user);

        compare_user = strcmp(user, stored_user);
        if (compare_user == 0) {
            break;
        } else {
            printf("Wrong username. Please try again.\n");
        }
        printf("-------------------------------------------\n");
    }

    // Authentication loop for password
    if (compare_user == 0) {
        for (int i = 1; i < 4; i++) {
            printf("Enter your password: ");
            hide_string_input(pass, 5);
            compare_password = strcmp(pass, stored_pass);

            if (compare_password == 0) {
                printf("\n***** Authentication Successful *****\n");
                break;
            } else {
                printf("Wrong password. You have %d attempt(s) left.\n", 3 - i);
                if (i == 3) {
                    printf("Account locked due to multiple incorrect attempts.\n");
                    return -1;
                }
            }
            printf("-------------------------------------------\n");
        }
    }

    if (compare_password == 0) {
        handle_choice();
    }

    return 0;
}

