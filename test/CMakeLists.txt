
cmake_minimum_required(VERSION 3.10.2)

include(addTest.cmake)

MarsvinAddTest(
    NAME test_marsvin_error_code
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_error_code.cpp
            ../core/src/marsvin_error_code.cpp
    INCLUDE_DIR ../core/include
)

MarsvinAddTest(
    NAME test_marsvin_base_matrix
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_base_matrix.cpp
    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/core/include
)


