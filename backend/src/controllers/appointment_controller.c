#include "appointment_controller.h"
#include "appointment_service.h"
#include "utils/helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to handle creating an appointment
void create_appointment(const char *patient_id, const char *doctor_id, const char *appointment_time) {
    // Validate input
    if (validate_input(patient_id, doctor_id, appointment_time)) {
        // Call service layer to create appointment
        int result = create_appointment_service(patient_id, doctor_id, appointment_time);
        if (result == 0) {
            printf("Appointment created successfully!\n");
        } else {
            printf("Failed to create appointment.\n");
        }
    } else {
        printf("Invalid appointment data provided.\n");
    }
}

// Function to handle retrieving an appointment by ID
void get_appointment(int appointment_id) {
    // Call service layer to get appointment data
    Appointment *appointment = get_appointment_service(appointment_id);
    if (appointment != NULL) {
        printf("Appointment ID: %d\n", appointment->appointment_id);
        printf("Patient ID: %d\n", appointment->patient_id);
        printf("Doctor ID: %d\n", appointment->doctor_id);
        printf("Appointment Time: %s\n", appointment->appointment_time);
        printf("Status: %s\n", appointment->status);
    } else {
        printf("Appointment not found.\n");
    }
}

// Function to handle updating an appointment (e.g., rescheduling)
void update_appointment(int appointment_id, const char *new_time, const char *new_status) {
    // Call service layer to update appointment
    int result = update_appointment_service(appointment_id, new_time, new_status);
    if (result == 0) {
        printf("Appointment updated successfully!\n");
    } else {
        printf("Failed to update appointment.\n");
    }
}

// Function to handle canceling an appointment
void cancel_appointment(int appointment_id) {
    // Call service layer to cancel appointment
    int result = cancel_appointment_service(appointment_id);
    if (result == 0) {
        printf("Appointment canceled successfully.\n");
    } else {
        printf("Failed to cancel appointment.\n");
    }
}

// Function to handle appointments listing
void list_appointments() {
    // Call service layer to retrieve all appointments
    AppointmentList *appointments = get_all_appointments_service();
    if (appointments != NULL) {
        for (int i = 0; i < appointments->count; i++) {
            printf("Appointment ID: %d, Patient ID: %d, Doctor ID: %d, Time: %s, Status: %s\n",
                   appointments->appointments[i].appointment_id,
                   appointments->appointments[i].patient_id,
                   appointments->appointments[i].doctor_id,
                   appointments->appointments[i].appointment_time,
                   appointments->appointments[i].status);
        }
    } else {
        printf("No appointments found.\n");
    }
}

// Helper function to validate input data
int validate_input(const char *patient_id, const char *doctor_id, const char *appointment_time) {
    if (patient_id == NULL || doctor_id == NULL || appointment_time == NULL) {
        return 0; // Invalid input
    }
    return 1; // Valid input
}

