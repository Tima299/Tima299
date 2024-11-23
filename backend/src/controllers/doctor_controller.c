#include "doctor_controller.h"
#include "doctor_service.h"
#include "utils/helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a doctor
void create_doctor(const char *first_name, const char *last_name, const char *specialization, const char *hospital) {
    // Validate input data
    if (validate_doctor_input(first_name, last_name, specialization, hospital)) {
        // Call the service layer to create the doctor
        int result = create_doctor_service(first_name, last_name, specialization, hospital);
        if (result == 0) {
            printf("Doctor created successfully!\n");
        } else {
            printf("Error: Failed to create doctor.\n");
        }
    } else {
        printf("Error: Invalid doctor data.\n");
    }
}

// Function to retrieve doctor information by ID
void get_doctor(int doctor_id) {
    // Call the service layer to get doctor details
    Doctor *doctor = get_doctor_service(doctor_id);
    if (doctor != NULL) {
        printf("Doctor ID: %d\n", doctor->doctor_id);
        printf("Name: %s %s\n", doctor->first_name, doctor->last_name);
        printf("Specialization: %s\n", doctor->specialization);
        printf("Hospital: %s\n", doctor->hospital);
    } else {
        printf("Error: Doctor not found.\n");
    }
}

// Function to update a doctor's information
void update_doctor(int doctor_id, const char *new_specialization, const char *new_hospital) {
    // Validate the new information
    if (validate_doctor_input(NULL, NULL, new_specialization, new_hospital)) {
        // Call the service layer to update the doctor's info
        int result = update_doctor_service(doctor_id, new_specialization, new_hospital);
        if (result == 0) {
            printf("Doctor updated successfully!\n");
        } else {
            printf("Error: Failed to update doctor.\n");
        }
    } else {
        printf("Error: Invalid input for updating doctor.\n");
    }
}

// Function to delete a doctor by ID
void delete_doctor(int doctor_id) {
    // Call the service layer to delete the doctor
    int result = delete_doctor_service(doctor_id);
    if (result == 0) {
        printf("Doctor deleted successfully.\n");
    } else {
        printf("Error: Failed to delete doctor.\n");
    }
}

// Function to validate input data for creating or updating doctor
int validate_doctor_input(const char *first_name, const char *last_name, const char *specialization, const char *hospital) {
    if (first_name == NULL || last_name == NULL || specialization == NULL || hospital == NULL) {
        return 0; // Invalid input
    }
    return 1; // Valid input
}

// Function to list all doctors
void list_doctors() {
    // Call the service layer to retrieve all doctors
    DoctorList *doctors = get_all_doctors_service();
    if (doctors != NULL) {
        for (int i = 0; i < doctors->count; i++) {
            printf("Doctor ID: %d, Name: %s %s, Specialization: %s, Hospital: %s\n",
                   doctors->doctors[i].doctor_id,
                   doctors->doctors[i].first_name,
                   doctors->doctors[i].last_name,
                   doctors->doctors[i].specialization,
                   doctors->doctors[i].hospital);
        }
    } else {
        printf("No doctors found.\n");
    }
}

