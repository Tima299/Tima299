#ifndef APPOINTMENT_REPOSITORY_H
#define APPOINTMENT_REPOSITORY_H

#include "appointment_model.h"

// Function to create a new appointment
int create_appointment(const Appointment* appointment);

// Function to get appointment by ID
Appointment* get_appointment_by_id(int appointment_id);

// Function to update an existing appointment
int update_appointment(int appointment_id, const Appointment* appointment);

// Function to delete an appointment
int delete_appointment(int appointment_id);

// Function to get all appointments for a patient
Appointment** get_appointments_by_patient_id(int patient_id, int* count);

// Function to get all appointments for a doctor
Appointment** get_appointments_by_doctor_id(int doctor_id, int* count);

#endif // APPOINTMENT_REPOSITORY_H

