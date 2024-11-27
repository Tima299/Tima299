include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/models
)

# Add tests
add_executable(test_appointment test_appointment.c)
add_executable(test_doctor test_doctor.c)

# Link libraries
target_link_libraries(test_appointment doctor_management_backend_lib)
target_link_libraries(test_doctor doctor_management_backend_lib)

# Add tests to CTest
add_test(NAME test_appointment COMMAND test_appointment)
add_test(NAME test_doctor COMMAND test_doctor)

