#include "appointment_repository.h"
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

// MySQL database connection
extern MYSQL *conn;  // Make sure this connection is initialized before usage

// Function to create a new appointment
int create_appointment(const Appointment* appointment) {
    char query[1024];
    sprintf(query, "INSERT INTO appointments (patient_id, doctor_id, appointment_time, status) "
                    "VALUES (%d, %d, '%s', '%s');", 
                    appointment->patient_id, appointment->doctor_id, 
                    appointment->appointment_time, appointment->status);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        return -1; // Indicating failure
    }

    return 0; // Success
}

// Function to get an appointment by ID
Appointment* get_appointment_by_id(int appointment_id) {
    char query[256];
    sprintf(query, "SELECT * FROM appointments WHERE appointment_id = %d;", appointment_id);
    
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        return NULL;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (!row) {
        return NULL;  // No result
    }

    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->appointment_id = atoi(row[0]);
    appointment->patient_id = atoi(row[1]);
    appointment->doctor_id = atoi(row[2]);
    appointment->appointment_time = row[3];  // Assuming it's a string, you can convert to a datetime type if needed
    appointment->status = row[4];
    
    mysql_free_result(result);

    return appointment;
}

// Function to update an existing appointment
int update_appointment(int appointment_id, const Appointment* appointment) {
    char query[1024];
    sprintf(query, "UPDATE appointments SET patient_id = %d, doctor_id = %d, appointment_time = '%s', status = '%s' "
                    "WHERE appointment_id = %d;", 
                    appointment->patient_id, appointment->doctor_id, 
                    appointment->appointment_time, appointment->status, appointment_id);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        return -1;
    }

    return 0;
}

// Function to delete an appointment
int delete_appointment(int appointment_id) {
    char query[256];
    sprintf(query, "DELETE FROM appointments WHERE appointment_id = %d;", appointment_id);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        return -1;
    }

    return 0;
}

// Function to get all appointments by patient ID
Appointment** get_appointments_by_patient_id(int patient_id, int* count) {
    char query[256];
    sprintf(query, "SELECT * FROM appointments WHERE patient_id = %d;", patient_id);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        return NULL;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    *count = mysql_num_rows(result);
    
    Appointment **appointments = malloc(sizeof(Appointment*) * (*count));
    int index = 0;

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        Appointment *appointment = malloc(sizeof(Appointment));
        appointment->appointment_id = atoi(row[0]);
        appointment->patient_id = atoi(row[1]);
        appointment->doctor_id = atoi(row[2]);
        appointment->appointment_time = row[3];
        appointment->status = row[4];

        appointments[index++] = appointment;
    }

    mysql_free_result(result);
    return appointments;
}

// Function to get all appointments by doctor ID
Appointment** get_appointments_by_doctor_id(int doctor_id, int* count) {
    char query[256];
    sprintf(query, "SELECT * FROM appointments WHERE doctor_id = %d;", doctor_id);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        return NULL;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    *count = mysql_num_rows(result);

    Appointment **appointments = malloc(sizeof(Appointment*) * (*count));
    int index = 0;

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        Appointment *appointment = malloc(sizeof(Appointment));
        appointment->appointment_id = atoi(row[0]);
        appointment->patient_id = atoi(row[1]);
        appointment->doctor_id = atoi(row[2]);
        appointment->appointment_time = row[3];
        appointment->status = row[4];

        appointments[index++] = appointment;
    }

    mysql_free_result(result);
    return appointments;
}

