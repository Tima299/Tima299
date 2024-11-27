#ifndef APPOINTMENT_MODEL_H
#define APPOINTMENT_MODEL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Appointment model class to represent appointment details
class AppointmentModel {
public:
    // Constructor to initialize appointment details
    AppointmentModel(int id, int patientId, int doctorId, const std::string& time, const std::string& status)
        : appointment_id(id), patient_id(patientId), doctor_id(doctorId), appointment_time(time), status(status) {}

    // Getter methods for appointment details
    int getAppointmentId() const { return appointment_id; }
    int getPatientId() const { return patient_id; }
    int getDoctorId() const { return doctor_id; }
    std::string getAppointmentTime() const { return appointment_time; }
    std::string getStatus() const { return status; }

    // Setter methods to modify appointment details
    void setAppointmentTime(const std::string& time) { appointment_time = time; }
    void setStatus(const std::string& newStatus) { status = newStatus; }

    // Display appointment information
    void displayAppointment() const {
        std::cout << "Appointment ID: " << appointment_id << std::endl;
        std::cout << "Patient ID: " << patient_id << std::endl;
        std::cout << "Doctor ID: " << doctor_id << std::endl;
        std::cout << "Appointment Time: " << appointment_time << std::endl;
        std::cout << "Status: " << status << std::endl;
    }

private:
    int appointment_id;  // Unique identifier for the appointment
    int patient_id;      // Reference to the patient associated with the appointment
    int doctor_id;       // Reference to the doctor for the appointment
    std::string appointment_time;  // Date and time of the appointment
    std::string status;  // Appointment status (e.g., Scheduled, Completed, Cancelled)
};

#endif  // APPOINTMENT_MODEL_H

