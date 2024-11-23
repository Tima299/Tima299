#include "appointment_controller.h"
#include "appointment_service.h"
#include <stdio.h>
#include <string.h>

// Handle a request to schedule a new appointment
void handle_schedule_appointment_request(const char* patient_id, const char* doctor_id,
                                         const char* appointment_time, const char* status) {
    Appointment new_appointment;
    new_appointment.patient_id = atoi(patient_id);
    new_appointment.doctor_id = atoi(doctor_id);
    strcpy(new_appointment.appointment_time, appointment_time);
    strcpy(new_appointment.status, status);

    // Call the service to schedule the appointment
    if (schedule_appointment(&new_appointment) == 0) {
        printf("Successfully scheduled the appointment.\n");
    } else {
        printf("Failed to schedule the appointment.\n");
    }
}

// Handle a request to update an appointment status
void handle_update_appointment_status_request(const char* appointment_id, const char* new_status) {
    int app_id = atoi(appointment_id);

    // Call the service to update the appointment status
    if (update_appointment_status(app_id, new_status) == 0) {
        printf("Successfully updated the appointment status.\n");
    } else {
        printf("Failed to update the appointment status.\n");
    }
}

// Handle a request to cancel an appointment
void handle_cancel_appointment_request(const char* appointment_id) {
    int app_id = atoi(appointment_id);

    // Call the service to cancel the appointment
    if (cancel_appointment(app_id) == 0) {
        printf("Successfully canceled the appointment.\n");
    } else {
        printf("Failed to cancel the appointment.\n");
    }
}

// Handle a request to get all appointments for a patient
void handle_get_patient_appointments_request(const char* patient_id) {
    int patient_id_int = atoi(patient_id);

    // Call the service to get appointments
    if (get_patient_appointments(patient_id_int) == 0) {
        printf("Successfully retrieved patient appointments.\n");
    } else {
        printf("Failed to retrieve patient appointments.\n");
    }
}

