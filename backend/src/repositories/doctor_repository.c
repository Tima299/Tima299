#include "doctor_repository.h"
#include "database/connection.h"
#include "doctor_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to create a new doctor
int create_doctor_repository(Doctor *doctor) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return -1;  // Error in connection
    }

    // Prepare SQL query for inserting doctor data
    const char *query = "INSERT INTO doctors (first_name, last_name, specialization_id, hospital_id, phone_number, email, years_of_experience) "
                        "VALUES ('%s', '%s', %d, %d, '%s', '%s', %d)";

    // Format query with doctor's data
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query,
             doctor->first_name, doctor->last_name, doctor->specialization_id,
             doctor->hospital_id, doctor->phone_number, doctor->email, doctor->years_of_experience);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to create doctor: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;  // Query execution failed
    }

    mysql_close(conn);  // Close the connection
    return 0;  // Success
}

// Function to get a doctor by ID
Doctor *get_doctor_by_id_repository(int doctor_id) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return NULL;  // Error in connection
    }

    // Prepare SQL query
    const char *query = "SELECT doctor_id, first_name, last_name, specialization_id, hospital_id, phone_number, email, years_of_experience "
                        "FROM doctors WHERE doctor_id = %d";

    // Format query with doctor_id
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query, doctor_id);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to fetch doctor: %s\n", mysql_error(conn));
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

    // Allocate memory for Doctor object and populate data
    Doctor *doctor = (Doctor *)malloc(sizeof(Doctor));
    doctor->doctor_id = atoi(row[0]);
    doctor->first_name = strdup(row[1]);
    doctor->last_name = strdup(row[2]);
    doctor->specialization_id = atoi(row[3]);
    doctor->hospital_id = atoi(row[4]);
    doctor->phone_number = strdup(row[5]);
    doctor->email = strdup(row[6]);
    doctor->years_of_experience = atoi(row[7]);

    mysql_free_result(result);  // Free the result
    mysql_close(conn);  // Close the connection

    return doctor;  // Return the populated doctor object
}

// Function to update an existing doctor
int update_doctor_repository(Doctor *doctor) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return -1;  // Error in connection
    }

    // Prepare SQL query for update
    const char *query = "UPDATE doctors SET first_name = '%s', last_name = '%s', specialization_id = %d, hospital_id = %d, "
                        "phone_number = '%s', email = '%s', years_of_experience = %d WHERE doctor_id = %d";

    // Format query with updated doctor data
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query,
             doctor->first_name, doctor->last_name, doctor->specialization_id,
             doctor->hospital_id, doctor->phone_number, doctor->email,
             doctor->years_of_experience, doctor->doctor_id);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to update doctor: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;  // Query execution failed
    }

    mysql_close(conn);  // Close the connection
    return 0;  // Success
}

// Function to delete a doctor by ID
int delete_doctor_repository(int doctor_id) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return -1;  // Error in connection
    }

    // Prepare SQL query for deletion
    const char *query = "DELETE FROM doctors WHERE doctor_id = %d";

    // Format query with doctor_id
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query, doctor_id);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to delete doctor: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;  // Query execution failed
    }

    mysql_close(conn);  // Close the connection
    return 0;  // Success
}

// Function to list all doctors
DoctorList *get_all_doctors_repository() {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return NULL;  // Error in connection
    }

    // Prepare SQL query
    const char *query = "SELECT doctor_id, first_name, last_name, specialization_id, hospital_id, phone_number, email, years_of_experience "
                        "FROM doctors";

    // Execute the query
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Failed to fetch doctors: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;  // Query execution failed
    }

    MYSQL_RES *result = mysql_store_result(conn);  // Store result of the query
    if (result == NULL) {
        fprintf(stderr, "Failed to retrieve result: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    DoctorList *doctors = (DoctorList *)malloc(sizeof(DoctorList));
    doctors->count = 0;

    // Loop through all rows in the result and populate the doctors list
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)) != NULL) {
        doctors->doctors[doctors->count].doctor_id = atoi(row[0]);
        doctors->doctors[doctors->count].first_name = strdup(row[1]);
        doctors->doctors[doctors->count].last_name = strdup(row[2]);
        doctors->doctors[doctors->count].specialization_id = atoi(row[3]);
        doctors->doctors[doctors->count].hospital_id = atoi(row[4]);
        doctors->doctors[doctors->count].phone_number = strdup(row[5]);
        doctors->doctors[doctors->count].email = strdup(row[6]);
        doctors->doctors[doctors->count].years_of_experience = atoi(row[7]);
        doctors->count++;
    }

    mysql_free_result(result);  // Free the result
    mysql_close(conn);  // Close the connection

    return doctors;  // Return the populated list of doctors
}

