#include "helper2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to get the current timestamp in "YYYY-MM-DD HH:MM:SS" format
char *get_current_timestamp() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Allocate memory for the formatted string
    char *timestamp = (char *)malloc(20 * sizeof(char));
    if (timestamp == NULL) {
        return NULL; // Memory allocation failed
    }

    // Format the current time to "YYYY-MM-DD HH:MM:SS"
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", t);
    
    return timestamp;  // Return the formatted timestamp
}

// Function to check if a date is in the future
int is_date_in_future(const char *date_str) {
    struct tm tm_date = {0};
    strptime(date_str, "%Y-%m-%d %H:%M:%S", &tm_date);

    time_t input_time = mktime(&tm_date);
    time_t current_time = time(NULL);

    // Return true (1) if the input time is in the future, otherwise false (0)
    if (input_time > current_time) {
        return 1;
    }
    return 0;
}

// Function to safely copy a string with memory allocation (avoiding buffer overflow)
char *safe_string_copy(const char *source) {
    if (source == NULL) {
        return NULL; // Return NULL if the source is invalid
    }

    // Allocate memory for the new string based on the source length
    char *destination = (char *)malloc((strlen(source) + 1) * sizeof(char));
    if (destination == NULL) {
        return NULL; // Memory allocation failed
    }

    strcpy(destination, source); // Copy the string

    return destination;  // Return the copied string
}

// Function to calculate the age based on the date of birth
int calculate_age(const char *dob) {
    struct tm birthdate = {0};
    strptime(dob, "%Y-%m-%d", &birthdate);

    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    int age = current_time->tm_year + 1900 - birthdate.tm_year;

    // Adjust if the birthday hasn't occurred yet this year
    if (current_time->tm_mon < birthdate.tm_mon || 
        (current_time->tm_mon == birthdate.tm_mon && current_time->tm_mday < birthdate.tm_mday)) {
        age--;
    }

    return age;  // Return the calculated age
}

// Function to log messages to a log file with timestamp
void log_message(const char *log_file, const char *message) {
    FILE *file = fopen(log_file, "a");
    if (file == NULL) {
        return;  // If file can't be opened, return
    }

    char *timestamp = get_current_timestamp();
    if (timestamp != NULL) {
        fprintf(file, "[%s] %s\n", timestamp, message);  // Log the message with timestamp
        free(timestamp);  // Free allocated memory for timestamp
    }

    fclose(file);  // Close the log file
}

// Function to generate a random alphanumeric string of a given length
char *generate_random_string(int length) {
    if (length <= 0) {
        return NULL;  // Invalid length
    }

    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char *random_string = (char *)malloc((length + 1) * sizeof(char));

    if (random_string == NULL) {
        return NULL;  // Memory allocation failed
    }

    for (int i = 0; i < length; i++) {
        random_string[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    random_string[length] = '\0';  // Null-terminate the string
    return random_string;  // Return the generated string
}

