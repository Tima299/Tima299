#include "appointment_service.h"
#include "appointment_repository.h"
#include "doctor_repository.h"
#include "patient_repository.h"
#include "specialization_repository.h"
#include "appointment_model.h"
#include "doctor_model.h"
#include "patient_model.h"
#include "specialization_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to create a new appointment
int create_appointment_service(Appointment *appointment) {
    // Validate the input
    if (appointment == NULL || appointment->patient_id == 0 || appointment->doctor_id == 0) {
        printf("Invalid input data\n");
        return -1;
    }

    // Check if patient exists
    Patient *patient = get_patient_by_id_repository(appointment->patient_id);
    if (patient == NULL) {
        printf("Patient not found\n");
        return -1;  // Patient does not exist
    }

    // Check if doctor exists
    Doctor *doctor = get_doctor_by_id_repository(appointment->doctor_id);
    if (doctor == NULL) {
        printf("Doctor not found\n");
        return -1;  // Doctor does not exist
    }

    // Check if the doctor is available at the given time
    if (is_doctor_available_for_appointment(doctor, appointment->appointment_time) == 0) {
        printf("Doctor is not available at this time\n");
        return -1;  // Doctor not available
    }

    // Create the appointment in the repository
    int result = create_appointment_repository(appointment);
    if (result != 0) {
        printf("Failed to create appointment\n");
        return -1;  // Appointment creation failed
    }

    printf("Appointment created successfully\n");
    return 0;  // Success
}

// Function to check if a doctor is available for a given appointment time
int is_doctor_available_for_appointment(Doctor *doctor, const char *appointment_time) {
    // Get all appointments for the doctor and check for conflicts
    AppointmentList *appointments = get_appointments_by_doctor_repository(doctor->doctor_id);
    if (appointments == NULL) {
        return 1;  // No appointments exist for the doctor
    }

    for (int i = 0; i < appointments->count; i++) {
        if (strcmp(appointments->appointments[i].appointment_time, appointment_time) == 0) {
            return 0;  // Conflict found, doctor is not available
        }
    }

    return 1;  // No conflict, doctor is available
}

// Function to update the status of an appointment
int update_appointment_status_service(int appointment_id, const char *new_status) {
    // Validate the new status
    if (new_status == NULL || (strcmp(new_status, "confirmed") != 0 && strcmp(new_status, "cancelled") != 0 && strcmp(new_status, "completed") != 0)) {
        printf("Invalid status\n");
        return -1;  // Invalid status
    }

    // Update the appointment status in the repository
    int result = update_appointment_status_repository(appointment_id, new_status);
    if (result != 0) {
        printf("Failed to update appointment status\n");
        return -1;  // Update failed
    }

    printf("Appointment status updated successfully\n");
    return 0;  // Success
}

// Function to fetch appointments by patient ID
AppointmentList *get_appointments_by_patient_service(int patient_id) {
    // Get all appointments for the given patient
    AppointmentList *appointments = get_appointments_by_patient_repository(patient_id);
    if (appointments == NULL) {
        printf("No appointments found for patient\n");
        return NULL;  // No appointments found
    }

    return appointments;  // Return the list of appointments
}

// Function to fetch appointments by doctor ID
AppointmentList *get_appointments_by_doctor_service(int doctor_id) {
    // Get all appointments for the given doctor
    AppointmentList *appointments = get_appointments_by_doctor_repository(doctor_id);
    if (appointments == NULL) {
        printf("No appointments found for doctor\n");
        return NULL;  // No appointments found
    }

    return appointments;  // Return the list of appointments
}

// Function to cancel an appointment
int cancel_appointment_service(int appointment_id) {
    // Update the appointment status to "cancelled"
    return update_appointment_status_service(appointment_id, "cancelled");
}

// Function to list all appointments
AppointmentList *list_all_appointments_service() {
    // Fetch all appointments from the repository
    AppointmentList *appointments = get_all_appointments_repository();
    if (appointments == NULL) {
        printf("No appointments found\n");
        return NULL;
    }

    return appointments;  // Return the list of all appointments
}


