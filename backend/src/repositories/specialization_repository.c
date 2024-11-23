#include "specialization_repository.h"
#include "database/connection.h"
#include "specialization_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to create a new specialization
int create_specialization_repository(Specialization *specialization) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return -1;  // Error in connection
    }

    // Prepare SQL query for inserting specialization data
    const char *query = "INSERT INTO specializations (specialization_name) "
                        "VALUES ('%s')";

    // Format query with specialization data
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query,
             specialization->specialization_name);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to create specialization: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;  // Query execution failed
    }

    mysql_close(conn);  // Close the connection
    return 0;  // Success
}

// Function to get a specialization by ID
Specialization *get_specialization_by_id_repository(int specialization_id) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return NULL;  // Error in connection
    }

    // Prepare SQL query
    const char *query = "SELECT specialization_id, specialization_name "
                        "FROM specializations WHERE specialization_id = %d";

    // Format query with specialization_id
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query, specialization_id);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to fetch specialization: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;  // Query execution failed
    }

    MYSQL_RES *result = mysql_store_result(conn);  // Store result of the query
    if (result == NULL) {
        fprintf(stderr, "Failed to retrieve result: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    MYSQL_ROW row = mysql_fetch_row(result);
    if (row == NULL) {
        mysql_free_result(result);
        mysql_close(conn);
        return NULL;  // No result found
    }

    // Allocate memory for Specialization object and populate data
    Specialization *specialization = (Specialization *)malloc(sizeof(Specialization));
    specialization->specialization_id = atoi(row[0]);
    specialization->specialization_name = strdup(row[1]);

    mysql_free_result(result);  // Free the result
    mysql_close(conn);  // Close the connection

    return specialization;  // Return the populated specialization object
}

// Function to update an existing specialization
int update_specialization_repository(Specialization *specialization) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return -1;  // Error in connection
    }

    // Prepare SQL query for update
    const char *query = "UPDATE specializations SET specialization_name = '%s' "
                        "WHERE specialization_id = %d";

    // Format query with updated specialization data
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query,
             specialization->specialization_name, specialization->specialization_id);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to update specialization: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;  // Query execution failed
    }

    mysql_close(conn);  // Close the connection
    return 0;  // Success
}

// Function to delete a specialization by ID
int delete_specialization_repository(int specialization_id) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return -1;  // Error in connection
    }

    // Prepare SQL query for deletion
    const char *query = "DELETE FROM specializations WHERE specialization_id = %d";

    // Format query with specialization_id
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query, specialization_id);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to delete specialization: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;  // Query execution failed
    }

    mysql_close(conn);  // Close the connection
    return 0;  // Success
}

// Function to list all specializations
SpecializationList *get_all_specializations_repository() {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return NULL;  // Error in connection
    }

    // Prepare SQL query
    const char *query = "SELECT specialization_id, specialization_name "
                        "FROM specializations";

    // Execute the query
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Failed to fetch specializations: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;  // Query execution failed
    }

    MYSQL_RES *result = mysql_store_result(conn);  // Store result of the query
    if (result == NULL) {
        fprintf(stderr, "Failed to retrieve result: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    SpecializationList *specializations = (SpecializationList *)malloc(sizeof(SpecializationList));
    specializations->count = 0;

    // Loop through all rows in the result and populate the specializations list
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)) != NULL) {
        specializations->specializations[specializations->count].specialization_id = atoi(row[0]);
        specializations->specializations[specializations->count].specialization_name = strdup(row[1]);
        specializations->count++;
    }

    mysql_free_result(result);  // Free the result
    mysql_close(conn);  // Close the connection

    return specializations;  // Return the populated list of specializations
}

