
cmake_minimum_required(VERSION 3.10.2)

include(addTest.cmake)

MarsvinAddTest(
    NAME test_marsvin_status_code
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_status_code.cpp
            ../core/src/marsvin_status_code.cpp
    INCLUDE_DIR ../core/include
)

MarsvinAddTest(
    NAME test_marsvin_exception
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_exception.cpp
            ../core/src/marsvin_exception.cpp
            ../core/src/marsvin_status_code.cpp
    INCLUDE_DIR ../core/include
)

MarsvinAddTest(
    NAME test_marsvin_instance_counter
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_instance_counter.cpp
    INCLUDE_DIR ../core/include
)

MarsvinAddTest(
    NAME test_marsvin_base_matrix
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_base_matrix.cpp
    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/core/include
    LINK_LIBRARIES marsvin
)

MarsvinAddTest(
    NAME test_marsvin_matrix
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_matrix.cpp
    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/core/include
    LINK_LIBRARIES marsvin
)

MarsvinAddTest(
    NAME test_marsvin_vector
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_vector.cpp
    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/core/include
    LINK_LIBRARIES marsvin
)

MarsvinAddTest(
    NAME test_marsvin_lud_partial_pivoting
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_lud_partial_pivoting.cpp
    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/core/include
    LINK_LIBRARIES marsvin
)

MarsvinAddTest(
    NAME test_marsvin_tools
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_tools.cpp
    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/core/include
    LINK_LIBRARIES marsvin
)

MarsvinAddTest(
    NAME test_marsvin_forward_substitution
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_forward_substitution.cpp
    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/core/include
    LINK_LIBRARIES marsvin
)

MarsvinAddTest(
    NAME test_marsvin_backward_substitution
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_backward_substitution.cpp
    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/core/include
    LINK_LIBRARIES marsvin
)

MarsvinAddTest(
    NAME test_marsvin_lower_inverse
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_lower_inverse.cpp
    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/core/include
    LINK_LIBRARIES marsvin
)

MarsvinAddTest(
    NAME test_marsvin_upper_inverse
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_upper_inverse.cpp
    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/core/include
    LINK_LIBRARIES marsvin
)
