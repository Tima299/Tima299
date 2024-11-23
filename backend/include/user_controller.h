#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include "user_service.h"
#include "user_model.h"
#include <stdbool.h>

// Initialize the User Controller
void user_controller_init();

// Controller function to create a new user
int user_controller_create(const char* username, const char* password, const char* role);

// Controller function to update user information
int user_controller_update(int user_id, const char* username, const char* password, const char* role);

// Controller function to fetch a user by ID
User* user_controller_get_by_id(int user_id);

// Controller function to fetch a user by username
User* user_controller_get_by_username(const char* username);

// Controller function to delete a user
int user_controller_delete(int user_id);

// Controller function to authenticate a user based on username and password
bool user_controller_authenticate(const char* username, const char* password);

// Controller function to validate user data before creating or updating
bool user_controller_validate_input(const char* username, const char* password, const char* role);

// Controller function to list all users
UserList* user_controller_get_all();

// Controller function to handle user-specific error logging
void user_controller_log_error(const char* error_message);

#endif // USER_CONTROLLER_H

