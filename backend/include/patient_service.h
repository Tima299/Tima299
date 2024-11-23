#ifndef PATIENT_SERVICE_H
#define PATIENT_SERVICE_H

#include "patient_repository.h"
#include "patient_model.h"
#include "appointment_model.h"
#include "notification_model.h"

// Function to initialize the Patient Service layer
void patient_service_init();

// Function to create a new patient in the system
int patient_service_create(Patient* patient);

// Function to update an existing patient's information
int patient_service_update(Patient* patient);

// Function to delete a patient from the system
int patient_service_delete(int patient_id);

// Function to retrieve a patient by their ID
Patient* patient_service_get_by_id(int patient_id);

// Function to retrieve all patients
PatientList* patient_service_get_all();

// Function to retrieve patients by their appointment status
PatientList* patient_service_get_by_appointment_status(const char* status);

// Function to search for patients by name
PatientList* patient_service_search_by_name(const char* name);

// Function to schedule an appointment for a patient
int patient_service_schedule_appointment(int patient_id, int doctor_id, const char* appointment_time);

// Function to cancel an existing appointment
int patient_service_cancel_appointment(int patient_id, int appointment_id);

// Function to send a notification to a patient
int patient_service_send_notification(int patient_id, const char* message, const char* notification_type);

// Function to validate patient data before saving
int patient_service_validate(Patient* patient);

// Function to handle errors related to patient operations
void patient_service_log_error(const char* error_message);

#endif // PATIENT_SERVICE_H

