#ifndef SPECIALIZATION_MODEL_H
#define SPECIALIZATION_MODEL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// Specialization model class to represent specialization data
class SpecializationModel {
public:
    // Constructor to initialize specialization object
    SpecializationModel(int id, const std::string& name)
        : specialization_id(id), specialization_name(name) {}

    // Getter methods for specialization attributes
    int getSpecializationId() const { return specialization_id; }
    std::string getSpecializationName() const { return specialization_name; }

    // Setter methods to modify specialization attributes
    void setSpecializationName(const std::string& name) { specialization_name = name; }

    // Display specialization information
    void displaySpecializationInfo() const {
        std::cout << "Specialization ID: " << specialization_id << std::endl;
        std::cout << "Specialization Name: " << specialization_name << std::endl;
    }

private:
    int specialization_id;  // Unique identifier for the specialization
    std::string specialization_name; // Name of the specialization (e.g., Dermatology)
};

#endif  // SPECIALIZATION_MODEL_H

