/*
Author: [Islam Gomaa]
Description: [To Do List App]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define MAX_TASKS 5
#define MAX_TASK_LENGTH 50

// Function prototypes
void hide_string_input(char str[], int n);
void string_input(char str[], int n);
int get_choice();
void handle_choice();
void add_task();
void set_task_state();
int generate_random_int(int min, int max);
void show_urgent_tasks();
void show_non_urgent_tasks();
int find_task_index(int id);
void delete_task(int index);

// Task structure
struct task {
    int id;
    char task_description[MAX_TASK_LENGTH];
    char task_state[MAX_TASK_LENGTH];
    char task_title[MAX_TASK_LENGTH];
};

// Array of tasks and task counter
static struct task tasks[MAX_TASKS];
static int task_count = 0;

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

// Hide string input (for password entry)
void hide_string_input(char str[], int n) {
    int ch, i = 0;
    while ((ch = getch()) != '\r') {
        if (i < n) {
            str[i++] = ch;
            printf("*");
        } else if (ch == '\b' && i > 0) {
            printf("\b \b");
            i--;
        }
    }
    str[i] = '\0';
    printf("\n");
}

// Normal string input
void string_input(char str[], int n) {
    fgets(str, n, stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}

// Get user choice from menu
int get_choice() {
    printf("\n*****************************\n");
    printf("** What do you want to do? **\n");
    printf("1. Add Task.\n");
    printf("2. Delete Task.\n");
    printf("3. Show Tasks.\n");
    printf("4. Exit.\n");
    printf("*****************************\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    // Clear input buffer
    while (getchar() != '\n');

    printf("\n-------------------------------------------\n");
    return choice;
}

// Add task function
void add_task() {
    if (task_count < MAX_TASKS) {
        printf("Enter the task title: ");
        string_input(tasks[task_count].task_title, MAX_TASK_LENGTH);

        printf("Enter the task description: ");
        string_input(tasks[task_count].task_description, MAX_TASK_LENGTH);

        set_task_state();

        tasks[task_count].id = generate_random_int(1, 100);
        task_count++;
        printf("\nTask added successfully!\n\n");
    } else {
        printf("\nMaximum number of tasks reached.\n\n");
    }
    printf("-------------------------------------------\n");
}

// Set task state (urgent/non-urgent)
void set_task_state() {
    char input[20];
    printf("Enter the task state (urgent/non-urgent): ");
    string_input(input, 20);

    if (strcmp(input, "urgent") == 0) {
        strcpy(tasks[task_count].task_state, "urgent");
    } else if (strcmp(input, "non-urgent") == 0) {
        strcpy(tasks[task_count].task_state, "non-urgent");
    } else {
        printf("Invalid state. Please enter 'urgent' or 'non-urgent'.\n");
        set_task_state();
    }
    printf("-------------------------------------------\n");
}

// Generate a random integer between min and max
int generate_random_int(int min, int max) {
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}

// Show urgent tasks
void show_urgent_tasks() {
    static int i = 0;
    if (i < task_count) {
        if (strcmp(tasks[i].task_state, "urgent") == 0) {
            printf("Task ID: %d\n", tasks[i].id);
            printf("Title: '%s'\n", tasks[i].task_title);
            printf("Description: '%s'\n", tasks[i].task_description);
            printf("State: '%s'\n", tasks[i].task_state);
            printf("\n");
        }
        i++;
        show_urgent_tasks();
    } else {
        i = 0;
    }
    printf("-------------------------------------------\n");
}

// Show non-urgent tasks
void show_non_urgent_tasks() {
    static int i = 0;
    if (i < task_count) {
        if (strcmp(tasks[i].task_state, "non-urgent") == 0) {
            printf("Task ID: %d\n", tasks[i].id);
            printf("Title: '%s'\n", tasks[i].task_title);
            printf("Description: '%s'\n", tasks[i].task_description);
            printf("State: '%s'\n", tasks[i].task_state);
            printf("\n");
        }
        i++;
        show_non_urgent_tasks();
    } else {
        i = 0;
    }
    printf("-------------------------------------------\n");
}

// Delete task by index
void delete_task(int index) {
    if (index != -1) {
        tasks[index] = tasks[task_count - 1];
        task_count--;
        printf("\nTask deleted.\n");
    } else {
        printf("Task not found. Please enter a valid ID.\n");
    }
    printf("-------------------------------------------\n");
}

// Find task index by ID
int find_task_index(int id) {
    static int index_to_find = 0;

    if (index_to_find >= task_count) {
        index_to_find = 0;
        return -1;
    }

    if (tasks[index_to_find].id == id) {
        int found_index = index_to_find;
        index_to_find = 0;
        return found_index;
    }

    index_to_find++;
    return find_task_index(id);
}

// Handle user choice and call appropriate functions
void handle_choice() {
    int choice = get_choice();

    switch (choice) {
        case 1:
            add_task();
            handle_choice();
            break;
        case 2:
            printf("Enter the task ID to delete: ");
            int id_to_delete;
            scanf("%d", &id_to_delete);
            while (getchar() != '\n');  // Clear input buffer
            
            int index = find_task_index(id_to_delete);
            delete_task(index);
            
            handle_choice();
            break;
        case 3:
            show_urgent_tasks();
            show_non_urgent_tasks();
            handle_choice();
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            handle_choice();
            break;
    }
}

