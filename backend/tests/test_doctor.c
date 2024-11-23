#include <stdio.h>
#include <assert.h>
#include "doctor_service.h"
#include "specialization_service.h"
#include "hospital_service.h"

// Mock database setup - this could be an in-memory DB or mock functions for unit testing
MYSQL *mock_db_connection;

void setUp() {
    // Initialize mock database connection for the tests
    mock_db_connection = init_db_connection();
    // Setup database schema, mocks, etc.
    // This step could involve creating mock tables or using mock data for testing
}

void tearDown() {
    // Clean up mock database connection and any test data
    mysql_close(mock_db_connection);
}

// Test creating a new doctor
void test_create_doctor() {
    // Arrange
    int specialization_id = 1;  // Example specialization ID
    int hospital_id = 2;       // Example hospital ID
    const char *first_name = "John";
    const char *last_name = "Doe";
    const char *email = "john.doe@example.com";
    const char *phone_number = "+1234567890";
    int years_of_experience = 5;

    // Act
    Doctor *new_doctor = create_doctor(mock_db_connection, specialization_id, hospital_id, first_name, last_name, email, phone_number, years_of_experience);

    // Assert
    assert(new_doctor != NULL);
    assert(new_doctor->specialization_id == specialization_id);
    assert(new_doctor->hospital_id == hospital_id);
    assert(strcmp(new_doctor->first_name, first_name) == 0);
    assert(strcmp(new_doctor->last_name, last_name) == 0);
    assert(strcmp(new_doctor->email, email) == 0);
    assert(strcmp(new_doctor->phone_number, phone_number) == 0);
    assert(new_doctor->years_of_experience == years_of_experience);

    printf("Test Create Doctor passed!\n");

    // Cleanup
    free_doctor(new_doctor);
}

// Test retrieving a doctor by ID
void test_get_doctor_by_id() {
    // Arrange
    int doctor_id = 1;  // Example doctor ID
    Doctor *expected_doctor = create_doctor(mock_db_connection, 1, 2, "John", "Doe", "john.doe@example.com", "+1234567890", 5);

    // Act
    Doctor *retrieved_doctor = get_doctor_by_id(mock_db_connection, doctor_id);

    // Assert
    assert(retrieved_doctor != NULL);
    assert(retrieved_doctor->doctor_id == expected_doctor->doctor_id);
    assert(retrieved_doctor->specialization_id == expected_doctor->specialization_id);
    assert(retrieved_doctor->hospital_id == expected_doctor->hospital_id);
    assert(strcmp(retrieved_doctor->first_name, expected_doctor->first_name) == 0);
    assert(strcmp(retrieved_doctor->last_name, expected_doctor->last_name) == 0);

    printf("Test Get Doctor by ID passed!\n");

    // Cleanup
    free_doctor(expected_doctor);
    free_doctor(retrieved_doctor);
}

// Test updating a doctor's details
void test_update_doctor_details() {
    // Arrange
    int doctor_id = 1;  // Example doctor ID
    const char *new_phone_number = "+0987654321";  // New phone number for the doctor

    // Act
    int result = update_doctor_details(mock_db_connection, doctor_id, new_phone_number);

    // Assert
    assert(result == 1);  // Assuming 1 indicates success

    // Fetch the updated doctor to verify the phone number update
    Doctor *updated_doctor = get_doctor_by_id(mock_db_connection, doctor_id);
    assert(updated_doctor != NULL);
    assert(strcmp(updated_doctor->phone_number, new_phone_number) == 0);

    printf("Test Update Doctor Details passed!\n");

    // Cleanup
    free_doctor(updated_doctor);
}

// Test deleting a doctor
void test_delete_doctor() {
    // Arrange
    int doctor_id = 1;  // Example doctor ID

    // Act
    int result = delete_doctor(mock_db_connection, doctor_id);

    // Assert
    assert(result == 1);  // Assuming 1 indicates success

    // Try fetching the deleted doctor to ensure they no longer exist
    Doctor *deleted_doctor = get_doctor_by_id(mock_db_connection, doctor_id);
    assert(deleted_doctor == NULL);

    printf("Test Delete Doctor passed!\n");
}

int main() {
    // Set up mock database and tests
    setUp();

    // Run tests
    test_create_doctor();
    test_get_doctor_by_id();
    test_update_doctor_details();
    test_delete_doctor();

    // Tear down mock database after tests
    tearDown();

    printf("All tests passed successfully!\n");
    return 0;
}

