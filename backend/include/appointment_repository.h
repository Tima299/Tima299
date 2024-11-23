#ifndef APPOINTMENT_REPOSITORY_H
#define APPOINTMENT_REPOSITORY_H

#include "appointment_model.h"
#include "doctor_model.h"
#include "patient_model.h"
#include <stdbool.h>

// Initializes the Appointment Repository (sets up any necessary database connections)
void appointment_repository_init();

// Create a new appointment record in the database
int appointment_repository_create(Appointment* appointment);

// Update an existing appointment record in the database
int appointment_repository_update(int appointment_id, Appointment* updated_appointment);

// Delete an appointment from the database
int appointment_repository_delete(int appointment_id);

// Retrieve an appointment by its ID
Appointment* appointment_repository_get_by_id(int appointment_id);

// Retrieve all appointments for a specific patient
AppointmentList* appointment_repository_get_by_patient_id(int patient_id);

// Retrieve all appointments for a specific doctor
AppointmentList* appointment_repository_get_by_doctor_id(int doctor_id);

// Retrieve all appointments scheduled for a specific date
AppointmentList* appointment_repository_get_by_date(const char* date);

// Get the waitlist for a particular doctor on a specific date
AppointmentList* appointment_repository_get_waitlist(int doctor_id, const char* date);

// Check if a patient already has an appointment on a specific date
bool appointment_repository_is_patient_appointments_on_date(int patient_id, const char* date);

// Handle any database errors related to appointments
void appointment_repository_log_error(const char* error_message);

#endif // APPOINTMENT_REPOSITORY_H

