#ifndef DOCTOR_SERVICE_H
#define DOCTOR_SERVICE_H

#include "doctor_repository.h"
#include "doctor_model.h"
#include "specialization_model.h"
#include "hospital_model.h"

// Function to initialize the Doctor Service layer
void doctor_service_init();

// Function to create a new doctor in the system
int doctor_service_create(Doctor* doctor);

// Function to update an existing doctor's information
int doctor_service_update(Doctor* doctor);

// Function to delete a doctor from the system
int doctor_service_delete(int doctor_id);

// Function to retrieve a doctor by their ID
Doctor* doctor_service_get_by_id(int doctor_id);

// Function to get all doctors by a specific specialization
DoctorList* doctor_service_get_by_specialization(int specialization_id);

// Function to get all doctors by their affiliated hospital
DoctorList* doctor_service_get_by_hospital(int hospital_id);

// Function to retrieve all doctors in the system
DoctorList* doctor_service_get_all();

// Function to search for doctors by their name
DoctorList* doctor_service_search_by_name(const char* name);

// Function to assign a specialization to a doctor
int doctor_service_assign_specialization(int doctor_id, int specialization_id);

// Function to assign a hospital to a doctor
int doctor_service_assign_hospital(int doctor_id, int hospital_id);

// Function to count the total number of doctors in the system
int doctor_service_count();

// Function to validate a doctor's data before saving
int doctor_service_validate(Doctor* doctor);

// Function to handle the error logging related to doctor operations
void doctor_service_log_error(const char* error_message);

#endif // DOCTOR_SERVICE_H

