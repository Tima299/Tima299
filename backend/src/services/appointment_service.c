#include "appointment_service.h"
#include "appointment_repository.h"
#include <stdio.h>
#include <stdlib.h>

// Function to schedule a new appointment
int schedule_appointment(const Appointment* appointment) {
    // Check if the doctor is available at the requested time
    Appointment* existing_appointment = get_appointments_by_doctor_id(appointment->doctor_id, NULL);
    if (existing_appointment != NULL) {
        printf("Error: Doctor is already booked at the requested time.\n");
        return -1; // Doctor is unavailable at this time
    }

    // Create the appointment in the database
    if (create_appointment(appointment) != 0) {
        printf("Error: Unable to create appointment.\n");
        return -1; // Failed to create appointment
    }

    printf("Appointment scheduled successfully.\n");
    return 0; // Success
}

// Function to update an existing appointment
int update_appointment_status(int appointment_id, const char* new_status) {
    // Fetch the appointment
    Appointment* appointment = get_appointment_by_id(appointment_id);
    if (appointment == NULL) {
        printf("Error: Appointment not found.\n");
        return -1; // Appointment not found
    }

    // Update the appointment status
    appointment->status = new_status;

    // Update the database
    if (update_appointment(appointment_id, appointment) != 0) {
        printf("Error: Failed to update appointment.\n");
        return -1; // Failed to update appointment
    }

    printf("Appointment status updated successfully.\n");
    return 0; // Success
}

// Function to cancel an appointment
int cancel_appointment(int appointment_id) {
    // Delete the appointment
    if (delete_appointment(appointment_id) != 0) {
        printf("Error: Failed to cancel appointment.\n");
        return -1; // Failed to cancel appointment
    }

    printf("Appointment canceled successfully.\n");
    return 0; // Success
}

// Function to get all appointments for a patient
int get_patient_appointments(int patient_id) {
    int count = 0;
    Appointment** appointments = get_appointments_by_patient_id(patient_id, &count);

    if (appointments == NULL || count == 0) {
        printf("Error: No appointments found for this patient.\n");
        return -1; // No appointments found
    }

    // Print all appointments
    for (int i = 0; i < count; i++) {
        printf("Appointment ID: %d, Doctor ID: %d, Time: %s, Status: %s\n", 
               appointments[i]->appointment_id, appointments[i]->doctor_id,
               appointments[i]->appointment_time, appointments[i]->status);
    }

    return 0; // Success
}

