#include <stdio.h>
#include <assert.h>
#include "appointment_service.h"
#include "patient_service.h"
#include "doctor_service.h"

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

// Test creating an appointment
void test_create_appointment() {
    // Arrange
    int patient_id = 1;  // Example patient ID
    int doctor_id = 2;   // Example doctor ID
    const char *appointment_time = "2024-12-25 10:00:00"; // Example appointment time
    const char *status = "Scheduled";  // Status of the appointment

    // Act
    Appointment *new_appointment = create_appointment(mock_db_connection, patient_id, doctor_id, appointment_time, status);

    // Assert
    assert(new_appointment != NULL);
    assert(new_appointment->patient_id == patient_id);
    assert(new_appointment->doctor_id == doctor_id);
    assert(strcmp(new_appointment->appointment_time, appointment_time) == 0);
    assert(strcmp(new_appointment->status, status) == 0);

    printf("Test Create Appointment passed!\n");

    // Cleanup
    free_appointment(new_appointment);
}

// Test retrieving an appointment by ID
void test_get_appointment_by_id() {
    // Arrange
    int appointment_id = 1;  // Example appointment ID
    Appointment *expected_appointment = create_appointment(mock_db_connection, 1, 2, "2024-12-25 10:00:00", "Scheduled");

    // Act
    Appointment *retrieved_appointment = get_appointment_by_id(mock_db_connection, appointment_id);

    // Assert
    assert(retrieved_appointment != NULL);
    assert(retrieved_appointment->appointment_id == expected_appointment->appointment_id);
    assert(retrieved_appointment->patient_id == expected_appointment->patient_id);
    assert(retrieved_appointment->doctor_id == expected_appointment->doctor_id);
    assert(strcmp(retrieved_appointment->status, expected_appointment->status) == 0);

    printf("Test Get Appointment by ID passed!\n");

    // Cleanup
    free_appointment(expected_appointment);
    free_appointment(retrieved_appointment);
}

// Test canceling an appointment
void test_cancel_appointment() {
    // Arrange
    int appointment_id = 1;  // Example appointment ID

    // Act
    int result = cancel_appointment(mock_db_connection, appointment_id);

    // Assert
    assert(result == 1);  // Assuming 1 indicates success in the cancellation process

    // Fetch the appointment to ensure its status is updated
    Appointment *canceled_appointment = get_appointment_by_id(mock_db_connection, appointment_id);
    assert(canceled_appointment != NULL);
    assert(strcmp(canceled_appointment->status, "Cancelled") == 0);

    printf("Test Cancel Appointment passed!\n");

    // Cleanup
    free_appointment(canceled_appointment);
}

// Test appointment status update
void test_update_appointment_status() {
    // Arrange
    int appointment_id = 1;  // Example appointment ID
    const char *new_status = "Completed";  // New status for the appointment

    // Act
    int result = update_appointment_status(mock_db_connection, appointment_id, new_status);

    // Assert
    assert(result == 1);  // Assuming 1 indicates success

    // Fetch the updated appointment to verify the status change
    Appointment *updated_appointment = get_appointment_by_id(mock_db_connection, appointment_id);
    assert(updated_appointment != NULL);
    assert(strcmp(updated_appointment->status, new_status) == 0);

    printf("Test Update Appointment Status passed!\n");

    // Cleanup
    free_appointment(updated_appointment);
}

int main() {
    // Set up mock database and tests
    setUp();

    // Run tests
    test_create_appointment();
    test_get_appointment_by_id();
    test_cancel_appointment();
    test_update_appointment_status();

    // Tear down mock database after tests
    tearDown();

    printf("All tests passed successfully!\n");
    return 0;
}

