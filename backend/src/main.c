#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "doctor_controller.h"
#include "patient_service.h"
#include "appointment_service.h"
#include "utils/helper1.h"
#include "utils/helper2.h"

// MySQL connection details (to be replaced with actual credentials or configuration)
#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "IlIl20040422#"
#define DB_NAME "doctor_management"

// Function to initialize the database connection
MYSQL* init_db_connection() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        exit(EXIT_FAILURE);
    }

    return conn;
}

// Main function to initialize controllers, services, and database
int main() {
    // Initialize MySQL database connection
    MYSQL *conn = init_db_connection();
    printf("Database connection established successfully.\n");

    // Initialize controllers and services (using the integration functions)
    DoctorController *doctor_controller = create_doctor_controller(conn);
    PatientService *patient_service = create_patient_service(conn);
    AppointmentService *appointment_service = create_appointment_service(conn);

    // Example usage of some functions
    // (Simulate getting patient information, doctor details, etc.)
    int patient_id = 1;  // Example patient ID
    int doctor_id = 2;   // Example doctor ID

    Patient *patient = get_patient_details(patient_service, patient_id);
    Doctor *doctor = get_doctor_details(doctor_controller, doctor_id);

    if (patient != NULL && doctor != NULL) {
        printf("Patient Name: %s %s\n", patient->first_name, patient->last_name);
        printf("Doctor Name: Dr. %s %s\n", doctor->first_name, doctor->last_name);

        // Create an appointment example
        Appointment *new_appointment = create_appointment(appointment_service, patient_id, doctor_id, "2024-12-25 10:00:00", "Scheduled");

        // Perform any required business logic or database operations

        // Example of logging the action
        log_message("app.log", "Appointment created successfully.");
    }

    // Clean up and close the connection
    free_patient(patient);
    free_doctor(doctor);
    free_appointment(new_appointment);
    mysql_close(conn);

    printf("Application terminated successfully.\n");
    return 0;
}

