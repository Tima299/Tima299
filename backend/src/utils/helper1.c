#include "helper1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to validate a given email address format
int validate_email(const char *email) {
    // Simple validation using basic email format check
    const char *email_regex = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$";
    
    if (email == NULL || strlen(email) == 0) {
        printf("Email is required.\n");
        return 0;  // Invalid email
    }
    
    // Using a regex or custom check to validate email (for simplicity, just length and format check)
    if (strstr(email, "@") == NULL || strstr(email, ".") == NULL) {
        printf("Invalid email format.\n");
        return 0;  // Invalid email
    }

    return 1;  // Valid email
}

// Function to validate phone number format
int validate_phone_number(const char *phone_number) {
    // Basic phone number validation for length and digits (assuming international format)
    if (phone_number == NULL || strlen(phone_number) < 10 || strlen(phone_number) > 15) {
        printf("Phone number should be between 10 and 15 digits.\n");
        return 0;  // Invalid phone number
    }

    for (int i = 0; i < strlen(phone_number); i++) {
        if (phone_number[i] < '0' || phone_number[i] > '9') {
            printf("Phone number should contain only digits.\n");
            return 0;  // Invalid phone number
        }
    }

    return 1;  // Valid phone number
}

// Function to format a date (assuming Date is in "YYYY-MM-DD" format)
char *format_date(const char *date) {
    // This function can format or validate a date string, here's a basic check for now
    if (date == NULL || strlen(date) != 10) {
        return NULL;  // Invalid date
    }

    // Basic validation to check if the format is "YYYY-MM-DD"
    for (int i = 0; i < 10; i++) {
        if ((i == 4 || i == 7) && date[i] != '-') {
            return NULL;  // Invalid date separator
        } else if (i != 4 && i != 7 && (date[i] < '0' || date[i] > '9')) {
            return NULL;  // Invalid date character
        }
    }

    // Return a copy of the date if it's valid
    char *formatted_date = (char *)malloc(11 * sizeof(char)); // Allocate memory for the date string
    if (formatted_date != NULL) {
        strcpy(formatted_date, date); // Copy the valid date
    }

    return formatted_date;  // Return the formatted date
}

// Function to check if a string is empty
int is_empty_string(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return 1;  // String is empty
    }
    return 0;  // String is not empty
}

// Function to free dynamically allocated memory
void safe_free(void *ptr) {
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;
    }
}

// A helper function to compare two strings safely (case insensitive)
int compare_strings_case_insensitive(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) {
        return -1;  // One or both strings are NULL
    }

    int result = strcasecmp(str1, str2);
    if (result == 0) {
        return 1;  // Strings are equal
    }

    return 0;  // Strings are not equal
}

