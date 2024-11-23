#include "doctor_management.h"
#include "doctor_service.h"
#include "utils/helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a doctor
void create_doctor_management(const char *first_name, const char *last_name, const char *specialization, const char *hospital) {
    // Validate input data (helper function from utils)
    if (validate_doctor_input(first_name, last_name, specialization, hospital)) {
        // Call the doctor service to create a doctor
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

// Function to update doctor information
void update_doctor_management(int doctor_id, const char *new_specialization, const char *new_hospital) {
    // Validate the input data for updating the doctor
    if (validate_doctor_input(NULL, NULL, new_specialization, new_hospital)) {
        // Call the doctor service to update doctor info
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

// Function to retrieve doctor information by ID
void get_doctor_management(int doctor_id) {
    // Call the doctor service to get doctor details
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

// Function to delete a doctor by ID
void delete_doctor_management(int doctor_id) {
    // Call the doctor service to delete the doctor
    int result = delete_doctor_service(doctor_id);
    if (result == 0) {
        printf("Doctor deleted successfully.\n");
    } else {
        printf("Error: Failed to delete doctor.\n");
    }
}

// Function to list all doctors
void list_doctors_management() {
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

