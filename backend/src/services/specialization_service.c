#include "specialization_service.h"
#include "specialization_repository.h"
#include "specialization_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new specialization
int create_specialization_service(Specialization *specialization) {
    // Validate specialization input
    if (specialization == NULL || specialization->specialization_name == NULL) {
        printf("Invalid specialization data\n");
        return -1;  // Invalid input
    }

    // Check if the specialization already exists (assuming specialization names must be unique)
    Specialization *existing_specialization = get_specialization_by_name_repository(specialization->specialization_name);
    if (existing_specialization != NULL) {
        printf("Specialization already exists\n");
        return -1;  // Specialization already exists
    }

    // Create the specialization record in the repository
    int result = create_specialization_repository(specialization);
    if (result != 0) {
        printf("Failed to create specialization\n");
        return -1;  // Failed to create specialization
    }

    printf("Specialization created successfully\n");
    return 0;  // Success
}

// Function to update specialization information
int update_specialization_service(int specialization_id, Specialization *updated_specialization) {
    // Validate updated specialization input
    if (updated_specialization == NULL || updated_specialization->specialization_name == NULL) {
        printf("Invalid updated specialization data\n");
        return -1;  // Invalid input
    }

    // Check if the specialization exists
    Specialization *existing_specialization = get_specialization_by_id_repository(specialization_id);
    if (existing_specialization == NULL) {
        printf("Specialization not found\n");
        return -1;  // Specialization not found
    }

    // Update the specialization details in the repository
    int result = update_specialization_repository(specialization_id, updated_specialization);
    if (result != 0) {
        printf("Failed to update specialization\n");
        return -1;  // Update failed
    }

    printf("Specialization updated successfully\n");
    return 0;  // Success
}

// Function to get a specialization by ID
Specialization *get_specialization_by_id_service(int specialization_id) {
    // Fetch specialization details from the repository
    Specialization *specialization = get_specialization_by_id_repository(specialization_id);
    if (specialization == NULL) {
        printf("Specialization not found\n");
        return NULL;  // Specialization not found
    }

    return specialization;  // Return the specialization details
}

// Function to get all specializations
SpecializationList *get_all_specializations_service() {
    // Fetch all specializations from the repository
    SpecializationList *specialization_list = get_all_specializations_repository();
    if (specialization_list == NULL || specialization_list->count == 0) {
        printf("No specializations found\n");
        return NULL;  // No specializations found
    }

    return specialization_list;  // Return the list of all specializations
}

// Function to delete a specialization by ID
int delete_specialization_service(int specialization_id) {
    // Fetch the specialization details to ensure it exists before deletion
    Specialization *specialization = get_specialization_by_id_repository(specialization_id);
    if (specialization == NULL) {
        printf("Specialization not found\n");
        return -1;  // Specialization not found
    }

    // Delete the specialization record from the repository
    int result = delete_specialization_repository(specialization_id);
    if (result != 0) {
        printf("Failed to delete specialization\n");
        return -1;  // Deletion failed
    }

    printf("Specialization deleted successfully\n");
    return 0;  // Success
}

// Function to get a specialization by name
Specialization *get_specialization_by_name_service(const char *specialization_name) {
    // Fetch specialization details from the repository by name
    Specialization *specialization = get_specialization_by_name_repository(specialization_name);
    if (specialization == NULL) {
        printf("Specialization not found\n");
        return NULL;  // Specialization not found
    }

    return specialization;  // Return the specialization details
}

