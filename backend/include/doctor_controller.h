#ifndef DOCTOR_CONTROLLER_H
#define DOCTOR_CONTROLLER_H

#include "doctor_service.h"
#include "appointment_service.h"
#include "doctor_model.h"
#include "appointment_model.h"

// Structure to represent a doctor controller
typedef struct {
    DoctorService* doctor_service;
    AppointmentService* appointment_service;
} DoctorController;

// Function to initialize the DoctorController
DoctorController* doctor_controller_init(DoctorService* doctor_service, 
                                         AppointmentService* appointment_service);

// Function to create a new doctor
int doctor_controller_create(DoctorController* controller, 
                             const char* first_name, 
                             const char* last_name, 
                             const char* email, 
                             const char* phone_number, 
                             const char* specialization, 
                             const char* hospital, 
                             int years_of_experience);

// Function to get doctor details by ID
Doctor* doctor_controller_get_by_id(DoctorController* controller, int doctor_id);

// Function to update doctor's information
int doctor_controller_update(DoctorController* controller, 
                             int doctor_id, 
                             const char* first_name, 
                             const char* last_name, 
                             const char* email, 
                             const char* phone_number, 
                             const char* specialization, 
                             const char* hospital, 
                             int years_of_experience);

// Function to list all appointments for a doctor
AppointmentList* doctor_controller_list_appointments(DoctorController* controller, int doctor_id);

// Function to check availability for a specific date and time
int doctor_controller_check_availability(DoctorController* controller, 
                                          int doctor_id, 
                                          const char* appointment_time);

// Function to assign a patient to an appointment with a doctor
int doctor_controller_assign_patient_to_appointment(DoctorController* controller, 
                                                    int doctor_id, 
                                                    int patient_id, 
                                                    const char* appointment_time);

// Function to clean up the doctor controller
void doctor_controller_free(DoctorController* controller);

#endif // DOCTOR_CONTROLLER_H

