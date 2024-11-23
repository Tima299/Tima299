#ifndef SPECIALIZATION_SERVICE_H
#define SPECIALIZATION_SERVICE_H

#include "specialization_repository.h"
#include "specialization_model.h"
#include <stdbool.h>

// Initialize the Specialization service
void specialization_service_init();

// Service function to create a new specialization
int specialization_service_create(const char* specialization_name);

// Service function to update an existing specialization
int specialization_service_update(int specialization_id, const char* specialization_name);

// Service function to delete a specialization
int specialization_service_delete(int specialization_id);

// Service function to get a specialization by ID
Specialization* specialization_service_get_by_id(int specialization_id);

// Service function to get a list of all specializations
SpecializationList* specialization_service_get_all();

// Service function to get specialization by name
Specialization* specialization_service_get_by_name(const char* name);

// Service function to validate and create specialization
int specialization_service_validate_and_create(const char* specialization_name);

// Service function to check if a specialization exists
bool specialization_service_exists(int specialization_id);

// Service function to fetch specializations linked to a doctor
SpecializationList* specialization_service_get_by_doctor_id(int doctor_id);

// Service function to handle errors related to specialization operations
void specialization_service_log_error(const char* error_message);

// Utility function to perform validation checks before performing any operation
bool specialization_service_validate_input(const char* name);

#endif // SPECIALIZATION_SERVICE_H

