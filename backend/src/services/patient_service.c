#include "patient_service.h"
#include "patient_repository.h"
#include "appointment_repository.h"
#include "case_history_repository.h"
#include "patient_model.h"
#include "appointment_model.h"
#include "case_history_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new patient
int create_patient_service(Patient *patient) {
    // Validate patient input
    if (patient == NULL || patient->first_name == NULL || patient->last_name == NULL || patient->dob == NULL) {
        printf("Invalid patient data\n");
        return -1;  // Invalid input
    }

    // Check if the patient already exists (based on email or phone number, assuming they must be unique)
    Patient *existing_patient = get_patient_by_email_or_phone_repository(patient->email, patient->phone_number);
    if (existing_patient != NULL) {
        printf("Patient with this email or phone number already exists\n");
        return -1;  // Patient already exists
    }

    // Create the patient record in the repository
    int result = create_patient_repository(patient);
    if (result != 0) {
        printf("Failed to create patient\n");
        return -1;  // Failed to create patient
    }

    printf("Patient created successfully\n");
    return 0;  // Success
}

// Function to update patient information
int update_patient_service(int patient_id, Patient *updated_patient) {
    // Validate updated patient input
    if (updated_patient == NULL || updated_patient->first_name == NULL || updated_patient->last_name == NULL || updated_patient->dob == NULL) {
        printf("Invalid updated patient data\n");
        return -1;  // Invalid input
    }

    // Check if the patient exists
    Patient *existing_patient = get_patient_by_id_repository(patient_id);
    if (existing_patient == NULL) {
        printf("Patient not found\n");
        return -1;  // Patient not found
    }

    // Update patient details in the repository
    int result = update_patient_repository(patient_id, updated_patient);
    if (result != 0) {
        printf("Failed to update patient\n");
        return -1;  // Update failed
    }

    printf("Patient updated successfully\n");
    return 0;  // Success
}

// Function to get a patient by ID
Patient *get_patient_by_id_service(int patient_id) {
    // Fetch patient details from the repository
    Patient *patient = get_patient_by_id_repository(patient_id);
    if (patient == NULL) {
        printf("Patient not found\n");
        return NULL;  // Patient not found
    }

    return patient;  // Return the patient details
}

// Function to get all patients
PatientList *get_all_patients_service() {
    // Fetch all patients from the repository
    PatientList *patient_list = get_all_patients_repository();
    if (patient_list == NULL || patient_list->count == 0) {
        printf("No patients found\n");
        return NULL;  // No patients found
    }

    return patient_list;  // Return the list of all patients
}

// Function to delete a patient by ID
int delete_patient_service(int patient_id) {
    // Fetch the patient details to ensure it exists before deletion
    Patient *patient = get_patient_by_id_repository(patient_id);
    if (patient == NULL) {
        printf("Patient not found\n");
        return -1;  // Patient not found
    }

    // Delete the patient's associated appointments and case history
    int result = delete_patient_appointments_repository(patient_id);
    if (result != 0) {
        printf("Failed to delete patient appointments\n");
        return -1;  // Failed to delete patient appointments
    }

    result = delete_patient_case_history_repository(patient_id);
    if (result != 0) {
        printf("Failed to delete patient case history\n");
        return -1;  // Failed to delete case history
    }

    // Finally, delete the patient record from the repository
    result = delete_patient_repository(patient_id);
    if (result != 0) {
        printf("Failed to delete patient\n");
        return -1;  // Deletion failed
    }

    printf("Patient deleted successfully\n");
    return 0;  // Success
}

// Function to get a patient's appointments
AppointmentList *get_patient_appointments_service(int patient_id) {
    // Fetch appointments for the patient
    AppointmentList *appointments = get_patient_appointments_repository(patient_id);
    if (appointments == NULL || appointments->count == 0) {
        printf("No appointments found for this patient\n");
        return NULL;  // No appointments found
    }

    return appointments;  // Return the list of appointments
}

// Function to get a patient's case history
CaseHistoryList *get_patient_case_history_service(int patient_id) {
    // Fetch case history for the patient
    CaseHistoryList *case_history = get_patient_case_history_repository(patient_id);
    if (case_history == NULL || case_history->count == 0) {
        printf("No case history found for this patient\n");
        return NULL;  // No case history found
    }

    return case_history;  // Return the case history
}

