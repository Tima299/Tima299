#ifndef SPECIALIZATION_REPOSITORY_H
#define SPECIALIZATION_REPOSITORY_H

#include "specialization_model.h"
#include <stdbool.h>

// Function to initialize the Specialization repository
void specialization_repository_init();

// Function to create a new specialization in the database
int specialization_repository_create(Specialization* specialization);

// Function to update an existing specialization in the database
int specialization_repository_update(Specialization* specialization);

// Function to delete a specialization from the database
int specialization_repository_delete(int specialization_id);

// Function to retrieve a specialization by its ID
Specialization* specialization_repository_get_by_id(int specialization_id);

// Function to retrieve all specializations from the database
SpecializationList* specialization_repository_get_all();

// Function to retrieve a specialization by its name
Specialization* specialization_repository_get_by_name(const char* name);

// Function to check if a specialization exists by ID
bool specialization_repository_exists(int specialization_id);

// Function to fetch specializations linked to a doctor
SpecializationList* specialization_repository_get_by_doctor_id(int doctor_id);

// Function to validate a specialization before saving
int specialization_repository_validate(Specialization* specialization);

// Function to handle errors related to specialization data operations
void specialization_repository_log_error(const char* error_message);

#endif // SPECIALIZATION_REPOSITORY_H

