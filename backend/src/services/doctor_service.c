#include "doctor_service.h"
#include "doctor_repository.h"
#include "specialization_repository.h"
#include "hospital_repository.h"
#include "doctor_model.h"
#include "specialization_model.h"
#include "hospital_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to create a new doctor
int create_doctor_service(Doctor *doctor) {
    // Validate the input
    if (doctor == NULL || doctor->first_name == NULL || doctor->last_name == NULL || doctor->specialization_id == 0 || doctor->hospital_id == 0) {
        printf("Invalid doctor data\n");
        return -1;  // Invalid input data
    }

    // Check if the specialization exists
    Specialization *specialization = get_specialization_by_id_repository(doctor->specialization_id);
    if (specialization == NULL) {
        printf("Specialization not found\n");
        return -1;  // Specialization does not exist
    }

    // Check if the hospital exists
    Hospital *hospital = get_hospital_by_id_repository(doctor->hospital_id);
    if (hospital == NULL) {
        printf("Hospital not found\n");
        return -1;  // Hospital does not exist
    }

    // Check if the doctor already exists (based on the unique combination of name and specialization)
    Doctor *existing_doctor = get_doctor_by_name_specialization_repository(doctor->first_name, doctor->last_name, doctor->specialization_id);
    if (existing_doctor != NULL) {
        printf("Doctor already exists in this specialization\n");
        return -1;  // Doctor already exists
    }

    // Create the doctor in the repository
    int result = create_doctor_repository(doctor);
    if (result != 0) {
        printf("Failed to create doctor\n");
        return -1;  // Failed to create doctor
    }

    printf("Doctor created successfully\n");
    return 0;  // Success
}

// Function to update doctor's information
int update_doctor_service(int doctor_id, Doctor *updated_doctor) {
    // Validate the input
    if (updated_doctor == NULL || updated_doctor->first_name == NULL || updated_doctor->last_name == NULL || updated_doctor->specialization_id == 0 || updated_doctor->hospital_id == 0) {
        printf("Invalid updated doctor data\n");
        return -1;  // Invalid input data
    }

    // Check if the doctor exists
    Doctor *existing_doctor = get_doctor_by_id_repository(doctor_id);
    if (existing_doctor == NULL) {
        printf("Doctor not found\n");
        return -1;  // Doctor does not exist
    }

    // Check if the specialization exists
    Specialization *specialization = get_specialization_by_id_repository(updated_doctor->specialization_id);
    if (specialization == NULL) {
        printf("Specialization not found\n");
        return -1;  // Specialization does not exist
    }

    // Check if the hospital exists
    Hospital *hospital = get_hospital_by_id_repository(updated_doctor->hospital_id);
    if (hospital == NULL) {
        printf("Hospital not found\n");
        return -1;  // Hospital does not exist
    }

    // Update the doctor details in the repository
    int result = update_doctor_repository(doctor_id, updated_doctor);
    if (result != 0) {
        printf("Failed to update doctor\n");
        return -1;  // Update failed
    }

    printf("Doctor updated successfully\n");
    return 0;  // Success
}

// Function to get a doctor by ID
Doctor *get_doctor_by_id_service(int doctor_id) {
    // Fetch the doctor details from the repository
    Doctor *doctor = get_doctor_by_id_repository(doctor_id);
    if (doctor == NULL) {
        printf("Doctor not found\n");
        return NULL;  // Doctor not found
    }

    return doctor;  // Return the doctor details
}

// Function to get all doctors
DoctorList *get_all_doctors_service() {
    // Fetch all doctors from the repository
    DoctorList *doctor_list = get_all_doctors_repository();
    if (doctor_list == NULL || doctor_list->count == 0) {
        printf("No doctors found\n");
        return NULL;  // No doctors found
    }

    return doctor_list;  // Return the list of all doctors
}

// Function to get doctors by specialization
DoctorList *get_doctors_by_specialization_service(int specialization_id) {
    // Fetch doctors by specialization from the repository
    DoctorList *doctor_list = get_doctors_by_specialization_repository(specialization_id);
    if (doctor_list == NULL || doctor_list->count == 0) {
        printf("No doctors found for this specialization\n");
        return NULL;  // No doctors found for this specialization
    }

    return doctor_list;  // Return the list of doctors
}

// Function to delete a doctor by ID
int delete_doctor_service(int doctor_id) {
    // Fetch the doctor details to ensure it exists before deletion
    Doctor *doctor = get_doctor_by_id_repository(doctor_id);
    if (doctor == NULL) {
        printf("Doctor not found\n");
        return -1;  // Doctor does not exist
    }

    // Delete the doctor from the repository
    int result = delete_doctor_repository(doctor_id);
    if (result != 0) {
        printf("Failed to delete doctor\n");
        return -1;  // Deletion failed
    }

    printf("Doctor deleted successfully\n");
    return 0;  // Success
}

