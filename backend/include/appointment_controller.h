#ifndef APPOINTMENT_CONTROLLER_H
#define APPOINTMENT_CONTROLLER_H

#include "../src/services/appointment_service.h"


// Function to handle creating a new appointment
void handle_create_appointment(int patient_id, int doctor_id, const char *appointment_time, const char *status);

// Function to handle retrieving an appointment by ID
void handle_get_appointment_by_id(int appointment_id);

// Function to handle updating an appointment
void handle_update_appointment(int appointment_id, int patient_id, int doctor_id, const char *appointment_time, const char *status);

// Function to handle deleting an appointment
void handle_delete_appointment(int appointment_id);

// Function to handle fetching all appointments
void handle_get_all_appointments();

#endif // APPOINTMENT_CONTROLLER_H

