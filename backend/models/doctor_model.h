#ifndef DOCTOR_MODEL_H
#define DOCTOR_MODEL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// Doctor model class to represent doctor details
class DoctorModel {
public:
    // Constructor to initialize a doctor object
    DoctorModel(int id, const std::string& fName, const std::string& lName, int specId, int hospId, const std::string& phone, 
                const std::string& email, int experience)
        : doctor_id(id), first_name(fName), last_name(lName), specialization_id(specId), hospital_id(hospId), 
          phone_number(phone), email(email), years_of_experience(experience) {}

    // Getter methods for doctor details
    int getDoctorId() const { return doctor_id; }
    std::string getFirstName() const { return first_name; }
    std::string getLastName() const { return last_name; }
    int getSpecializationId() const { return specialization_id; }
    int getHospitalId() const { return hospital_id; }
    std::string getPhoneNumber() const { return phone_number; }
    std::string getEmail() const { return email; }
    int getYearsOfExperience() const { return years_of_experience; }

    // Setter methods for updating doctor details
    void setPhoneNumber(const std::string& phone) { phone_number = phone; }
    void setEmail(const std::string& newEmail) { email = newEmail; }

    // Display doctor information
    void displayDoctorInfo() const {
        std::cout << "Doctor ID: " << doctor_id << std::endl;
        std::cout << "Name: " << first_name << " " << last_name << std::endl;
        std::cout << "Specialization ID: " << specialization_id << std::endl;
        std::cout << "Hospital ID: " << hospital_id << std::endl;
        std::cout << "Phone: " << phone_number << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Years of Experience: " << years_of_experience << std::endl;
    }

private:
    int doctor_id;              // Unique identifier for the doctor
    std::string first_name;     // Doctor's first name
    std::string last_name;      // Doctor's last name
    int specialization_id;      // Reference to specialization
    int hospital_id;            // Reference to hospital
    std::string phone_number;   // Contact phone number
    std::string email;          // Email address
    int years_of_experience;    // Number of years of practice
};

#endif  // DOCTOR_MODEL_H

