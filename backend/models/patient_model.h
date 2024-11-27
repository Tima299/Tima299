#ifndef PATIENT_MODEL_H
#define PATIENT_MODEL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// Patient model class to represent patient details
class PatientModel {
public:
    // Constructor to initialize a patient object
    PatientModel(int id, const std::string& fName, const std::string& lName, const std::string& email,
                const std::string& phone, const std::string& addr, const std::string& birthDate)
        : patient_id(id), first_name(fName), last_name(lName), email(email), phone_number(phone),
          address(addr), date_of_birth(birthDate) {}

    // Getter methods for patient details
    int getPatientId() const { return patient_id; }
    std::string getFirstName() const { return first_name; }
    std::string getLastName() const { return last_name; }
    std::string getEmail() const { return email; }
    std::string getPhoneNumber() const { return phone_number; }
    std::string getAddress() const { return address; }
    std::string getDateOfBirth() const { return date_of_birth; }

    // Setter methods for updating patient details
    void setPhoneNumber(const std::string& phone) { phone_number = phone; }
    void setEmail(const std::string& newEmail) { email = newEmail; }
    void setAddress(const std::string& newAddress) { address = newAddress; }

    // Display patient information
    void displayPatientInfo() const {
        std::cout << "Patient ID: " << patient_id << std::endl;
        std::cout << "Name: " << first_name << " " << last_name << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Phone: " << phone_number << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Date of Birth: " << date_of_birth << std::endl;
    }

private:
    int patient_id;           // Unique identifier for the patient
    std::string first_name;   // Patient's first name
    std::string last_name;    // Patient's last name
    std::string email;        // Patient's email address
    std::string phone_number; // Patient's phone number
    std::string address;      // Patient's address
    std::string date_of_birth; // Patient's date of birth
};

#endif  // PATIENT_MODEL_H

