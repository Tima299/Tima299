#include "patient_repository.h"
#include "database/connection.h"
#include "patient_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to create a new patient
int create_patient_repository(Patient *patient) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return -1;  // Error in connection
    }

    // Prepare SQL query for inserting patient data
    const char *query = "INSERT INTO patients (first_name, last_name, email, phone_number, address, dob) "
                        "VALUES ('%s', '%s', '%s', '%s', '%s', '%s')";

    // Format query with patient's data
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query,
             patient->first_name, patient->last_name, patient->email,
             patient->phone_number, patient->address, patient->dob);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to create patient: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;  // Query execution failed
    }

    mysql_close(conn);  // Close the connection
    return 0;  // Success
}

// Function to get a patient by ID
Patient *get_patient_by_id_repository(int patient_id) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return NULL;  // Error in connection
    }

    // Prepare SQL query
    const char *query = "SELECT patient_id, first_name, last_name, email, phone_number, address, dob "
                        "FROM patients WHERE patient_id = %d";

    // Format query with patient_id
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query, patient_id);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to fetch patient: %s\n", mysql_error(conn));
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

    // Allocate memory for Patient object and populate data
    Patient *patient = (Patient *)malloc(sizeof(Patient));
    patient->patient_id = atoi(row[0]);
    patient->first_name = strdup(row[1]);
    patient->last_name = strdup(row[2]);
    patient->email = strdup(row[3]);
    patient->phone_number = strdup(row[4]);
    patient->address = strdup(row[5]);
    patient->dob = strdup(row[6]);

    mysql_free_result(result);  // Free the result
    mysql_close(conn);  // Close the connection

    return patient;  // Return the populated patient object
}

// Function to update an existing patient
int update_patient_repository(Patient *patient) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return -1;  // Error in connection
    }

    // Prepare SQL query for update
    const char *query = "UPDATE patients SET first_name = '%s', last_name = '%s', email = '%s', phone_number = '%s', "
                        "address = '%s', dob = '%s' WHERE patient_id = %d";

    // Format query with updated patient data
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query,
             patient->first_name, patient->last_name, patient->email,
             patient->phone_number, patient->address, patient->dob, patient->patient_id);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to update patient: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;  // Query execution failed
    }

    mysql_close(conn);  // Close the connection
    return 0;  // Success
}

// Function to delete a patient by ID
int delete_patient_repository(int patient_id) {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return -1;  // Error in connection
    }

    // Prepare SQL query for deletion
    const char *query = "DELETE FROM patients WHERE patient_id = %d";

    // Format query with patient_id
    char formatted_query[1024];
    snprintf(formatted_query, sizeof(formatted_query), query, patient_id);

    // Execute the query
    if (mysql_query(conn, formatted_query)) {
        fprintf(stderr, "Failed to delete patient: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;  // Query execution failed
    }

    mysql_close(conn);  // Close the connection
    return 0;  // Success
}

// Function to list all patients
PatientList *get_all_patients_repository() {
    MYSQL *conn = get_db_connection();  // Get database connection
    if (conn == NULL) {
        return NULL;  // Error in connection
    }

    // Prepare SQL query
    const char *query = "SELECT patient_id, first_name, last_name, email, phone_number, address, dob "
                        "FROM patients";

    // Execute the query
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Failed to fetch patients: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;  // Query execution failed
    }

    MYSQL_RES *result = mysql_store_result(conn);  // Store result of the query
    if (result == NULL) {
        fprintf(stderr, "Failed to retrieve result: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    PatientList *patients = (PatientList *)malloc(sizeof(PatientList));
    patients->count = 0;

    // Loop through all rows in the result and populate the patients list
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)) != NULL) {
        patients->patients[patients->count].patient_id = atoi(row[0]);
        patients->patients[patients->count].first_name = strdup(row[1]);
        patients->patients[patients->count].last_name = strdup(row[2]);
        patients->patients[patients->count].email = strdup(row[3]);
        patients->patients[patients->count].phone_number = strdup(row[4]);
        patients->patients[patients->count].address = strdup(row[5]);
        patients->patients[patients->count].dob = strdup(row[6]);
        patients->count++;
    }

    mysql_free_result(result);  // Free the result
    mysql_close(conn);  // Close the connection

    return patients;  // Return the populated list of patients
}

