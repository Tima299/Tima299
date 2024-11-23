#include "appointment_repository.h"
#include "database/connection.h"
#include "appointment_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to create a new appointment
int create_appointment_repository(Appointment *appointment) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return -1;  // Error in connection
    }

    // Prepare SQL query
    const char *query = "INSERT INTO appointments (patient_id, doctor_id, appointment_time, status) "
                        "VALUES (%d, %d, '%s', '%s')";

    // Format query with appointment data
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query,
             appointment->patient_id, appointment->doctor_id,
             appointment->appointment_time, appointment->status);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to create appointment: %s\n", mysql_error(conn));
        return -1;  // Query execution failed
    }

    mysql_close(conn);  // Close the connection
    return 0;  // Success
}

// Function to get an appointment by ID
Appointment *get_appointment_by_id_repository(int appointment_id) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return NULL;  // Error in connection
    }

    // Prepare SQL query
    const char *query = "SELECT appointment_id, patient_id, doctor_id, appointment_time, status "
                        "FROM appointments WHERE appointment_id = %d";

    // Format query with appointment_id
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query, appointment_id);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to fetch appointment: %s\n", mysql_error(conn));
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

    // Allocate memory for Appointment object and populate data
    Appointment *appointment = (Appointment *)malloc(sizeof(Appointment));
    appointment->appointment_id = atoi(row[0]);
    appointment->patient_id = atoi(row[1]);
    appointment->doctor_id = atoi(row[2]);
    appointment->appointment_time = strdup(row[3]);
    appointment->status = strdup(row[4]);

    mysql_free_result(result);  // Free the result
    mysql_close(conn);  // Close the connection

    return appointment;  // Return the populated appointment object
}

// Function to update an existing appointment
int update_appointment_repository(Appointment *appointment) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return -1;  // Error in connection
    }

    // Prepare SQL query for update
    const char *query = "UPDATE appointments SET patient_id = %d, doctor_id = %d, "
                        "appointment_time = '%s', status = '%s' WHERE appointment_id = %d";

    // Format query with updated appointment data
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query,
             appointment->patient_id, appointment->doctor_id,
             appointment->appointment_time, appointment->status, appointment->appointment_id);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to update appointment: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;  // Query execution failed
    }

    mysql_close(conn);  // Close the connection
    return 0;  // Success
}

// Function to delete an appointment by ID
int delete_appointment_repository(int appointment_id) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return -1;  // Error in connection
    }

    // Prepare SQL query for deletion
    const char *query = "DELETE FROM appointments WHERE appointment_id = %d";

    // Format query with appointment_id
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query, appointment_id);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to delete appointment: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;  // Query execution failed
    }

    mysql_close(conn);  // Close the connection
    return 0;  // Success
}

// Function to list all appointments
AppointmentList *get_all_appointments_repository() {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return NULL;  // Error in connection
    }

    // Prepare SQL query
    const char *query = "SELECT appointment_id, patient_id, doctor_id, appointment_time, status "
                        "FROM appointments";

    // Execute the query
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Failed to fetch appointments: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;  // Query execution failed
    }

    MYSQL_RES *result = mysql_store_result(conn);  // Store result of the query
    if (result == NULL) {
        fprintf(stderr, "Failed to retrieve result: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    AppointmentList *appointments = (AppointmentList *)malloc(sizeof(AppointmentList));
    appointments->count = 0;

    // Loop through all rows in the result and populate the appointments list
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)) != NULL) {
        appointments->appointments[appointments->count].appointment_id = atoi(row[0]);
        appointments->appointments[appointments->count].patient_id = atoi(row[1]);
        appointments->appointments[appointments->count].doctor_id = atoi(row[2]);
        appointments->appointments[appointments->count].appointment_time = strdup(row[3]);
        appointments->appointments[appointments->count].status = strdup(row[4]);
        appointments->count++;
    }

    mysql_free_result(result);  // Free the result
    mysql_close(conn);  // Close the connection

    return appointments;  // Return the populated list of appointments
}

