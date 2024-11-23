#ifndef DOCTOR_MANAGEMENT_H
#define DOCTOR_MANAGEMENT_H

#include "doctor_controller.h"
#include "doctor_service.h"
#include "appointment_service.h"
#include "specialization_service.h"

// Structure to represent the Doctor Management module
typedef struct {
    DoctorController* doctor_controller;      // Controller for handling doctor-related operations
    DoctorService* doctor_service;             // Service for handling doctor data and logic
    AppointmentService* appointment_service;   // Service for managing doctor appointments
    SpecializationService* specialization_service; // Service for managing doctor specializations
} DoctorManagement;

// Function to initialize the Doctor Management system
DoctorManagement* doctor_management_init();

// Function to create a new doctor
int doctor_management_create_doctor(DoctorManagement* manager, 
                                    const char* first_name, 
                                    const char* last_name, 
                                    const char* email, 
                                    const char* phone_number, 
                                    const char* specialization, 
                                    const char* hospital, 
                                    int years_of_experience);

// Function to update doctor information
int doctor_management_update_doctor(DoctorManagement* manager, 
                                     int doctor_id, 
                                     const char* first_name, 
                                     const char* last_name, 
                                     const char* email, 
                                     const char* phone_number, 
                                     const char* specialization, 
                                     const char* hospital, 
                                     int years_of_experience);

// Function to get a doctor's details
Doctor* doctor_management_get_doctor(DoctorManagement* manager, int doctor_id);

// Function to list all appointments for a doctor
AppointmentList* doctor_management_list_appointments(DoctorManagement* manager, int doctor_id);

// Function to check availability of a doctor for scheduling appointments
int doctor_management_check_availability(DoctorManagement* manager, 
                                          int doctor_id, 
                                          const char* appointment_time);

// Function to assign a patient to a doctor’s appointment
int doctor_management_assign_patient_to_appointment(DoctorManagement* manager, 
                                                    int doctor_id, 
                                                    int patient_id, 
                                                    const char* appointment_time);

// Function to clean up the Doctor Management system
void doctor_management_free(DoctorManagement* manager);

#endif // DOCTOR_MANAGEMENT_H

