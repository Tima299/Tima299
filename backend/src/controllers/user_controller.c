#include "user_controller.h"
#include "user_service.h"
#include "utils/helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a user
void create_user_management(const char *username, const char *password, const char *role) {
    // Validate input data
    if (validate_user_input(username, password, role)) {
        // Call the user service to create a user
        int result = create_user_service(username, password, role);
        if (result == 0) {
            printf("User created successfully!\n");
        } else {
            printf("Error: Failed to create user.\n");
        }
    } else {
        printf("Error: Invalid user data.\n");
    }
}

// Function to update user information
void update_user_management(int user_id, const char *new_username, const char *new_password, const char *new_role) {
    // Validate input data for updating user
    if (validate_user_input(new_username, new_password, new_role)) {
        // Call the user service to update user information
        int result = update_user_service(user_id, new_username, new_password, new_role);
        if (result == 0) {
            printf("User updated successfully!\n");
        } else {
            printf("Error: Failed to update user.\n");
        }
    } else {
        printf("Error: Invalid data for updating user.\n");
    }
}

// Function to authenticate a user
void authenticate_user_management(const char *username, const char *password) {
    // Call the user service to authenticate the user
    int result = authenticate_user_service(username, password);
    if (result == 1) {
        printf("Authentication successful!\n");
    } else {
        printf("Error: Invalid credentials.\n");
    }
}

// Function to get user information by ID
void get_user_management(int user_id) {
    // Call the user service to get user details
    User *user = get_user_service(user_id);
    if (user != NULL) {
        printf("User ID: %d\n", user->user_id);
        printf("Username: %s\n", user->username);
        printf("Role: %s\n", user->role);
    } else {
        printf("Error: User not found.\n");
    }
}

// Function to delete a user by ID
void delete_user_management(int user_id) {
    // Call the user service to delete the user
    int result = delete_user_service(user_id);
    if (result == 0) {
        printf("User deleted successfully.\n");
    } else {
        printf("Error: Failed to delete user.\n");
    }
}

// Function to list all users
void list_users_management() {
    // Call the service layer to retrieve all users
    UserList *users = get_all_users_service();
    if (users != NULL) {
        for (int i = 0; i < users->count; i++) {
            printf("User ID: %d, Username: %s, Role: %s\n",
                   users->users[i].user_id,
                   users->users[i].username,
                   users->users[i].role);
        }
    } else {
        printf("No users found.\n");
    }
}

