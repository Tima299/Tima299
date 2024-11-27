#ifndef APPOINTMENT_SERVICE_H
#define APPOINTMENT_SERVICE_H

#include "appointment_repository.h"
#include "doctor_repository.h"
#include "patient_repository.h"
#include "notification_service.h"
#include "doctor_model.h"
#include "patient_model.h"
#include "appointment_model.h"

// Structure to represent an appointment service
typedef struct {
    AppointmentRepository* appointment_repo;
    DoctorRepository* doctor_repo;
    PatientRepository* patient_repo;
    NotificationService* notification_service;
} AppointmentService;

// Function to initialize AppointmentService
AppointmentService* appointment_service_init(AppointmentRepository* appointment_repo,
                                            DoctorRepository* doctor_repo,
                                            PatientRepository* patient_repo,
                                            NotificationService* notification_service);

// Function to create a new appointment
int appointment_service_create(AppointmentService* service, 
                               int patient_id, 
                               int doctor_id, 
                               const char* appointment_time);

// Function to update appointment status (e.g., from 'Pending' to 'Confirmed')
int appointment_service_update_status(AppointmentService* service, 
                                      int appointment_id, 
                                      const char* status);

// Function to cancel an appointment and send notifications
int appointment_service_cancel(AppointmentService* service, 
                               int appointment_id);

// Function to get appointment details by ID
Appointment* appointment_service_get_by_id(AppointmentService* service, int appointment_id);

// Function to get all appointments for a specific patient
AppointmentList* appointment_service_get_by_patient(AppointmentService* service, int patient_id);

// Function to get all appointments for a specific doctor
AppointmentList* appointment_service_get_by_doctor(AppointmentService* service, int doctor_id);

// Function to add a patient to the waitlist if appointment is full
int appointment_service_add_to_waitlist(AppointmentService* service, 
                                        int patient_id, 
                                        int doctor_id, 
                                        const char* appointment_time);

// Function to handle appointment creation with proper validation
int appointment_service_create_with_validation(AppointmentService* service, 
                                              int patient_id, 
                                              int doctor_id, 
                                              const char* appointment_time);

// Function to check availability of a doctor
int appointment_service_check_doctor_availability(AppointmentService* service, 
                                                  int doctor_id, 
                                                  const char* appointment_time);

// Function to clean up the appointment service
void appointment_service_free(AppointmentService* service);

#endif // APPOINTMENT_SERVICE_H

