#ifndef DOCTOR_REPOSITORY_H
#define DOCTOR_REPOSITORY_H

#include "doctor_model.h"
#include "specialization_model.h"
#include "hospital_model.h"

// Function to initialize the Doctor Repository
void doctor_repository_init();

// Function to add a new doctor to the database
int doctor_repository_add(Doctor* doctor);

// Function to update an existing doctor's information in the database
int doctor_repository_update(Doctor* doctor);

// Function to delete a doctor from the database
int doctor_repository_delete(int doctor_id);

// Function to get a doctor by their ID
Doctor* doctor_repository_get_by_id(int doctor_id);

// Function to get all doctors by a specific specialization
DoctorList* doctor_repository_get_by_specialization(int specialization_id);

// Function to get all doctors working at a specific hospital
DoctorList* doctor_repository_get_by_hospital(int hospital_id);

// Function to retrieve all doctors
DoctorList* doctor_repository_get_all();

// Function to search doctors by name
DoctorList* doctor_repository_search_by_name(const char* name);

// Function to assign a specialization to a doctor
int doctor_repository_assign_specialization(int doctor_id, int specialization_id);

// Function to assign a hospital to a doctor
int doctor_repository_assign_hospital(int doctor_id, int hospital_id);

// Function to count the total number of doctors
int doctor_repository_count();

// Function to free memory allocated for doctor lists
void doctor_repository_free(DoctorList* doctor_list);

#endif // DOCTOR_REPOSITORY_H

